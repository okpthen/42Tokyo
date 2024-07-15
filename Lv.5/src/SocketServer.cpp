#include "../inc/SocketServer.hpp"

void	close_and_exit(std::string msg, int *fd){
	std::perror(msg.c_str());
	if (fd != NULL)
		close(*fd);
	exit(EXIT_FAILURE);
}

void	close_and_exit(std::string msg, int *fd, int exit_status){
	std::perror(msg.c_str());
	if (fd != NULL)
		close(*fd);
	exit(exit_status);
}

void	close_and_exit(std::string msg, std::vector<pollfd> &fds){
	std::perror(msg.c_str());
	for(size_t i = 0; i < fds.size(); i++){
        close(fds.at(i).fd);
    }
	exit(EXIT_FAILURE);
}

void	close_and_exit(std::string msg, std::vector<pollfd> &fds, int exit_status){
	std::perror(msg.c_str());
	for(size_t i = 0; i < fds.size(); i++){
        close(fds.at(i).fd);
    }
	exit(exit_status);
}

struct sockaddr_in socket_init(const int &port, int &serv_fd){
	struct sockaddr_in address;
    int opt = 1;

	serv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (serv_fd == -1){
		close_and_exit("Socket Creation Failed", NULL);
	}
    if (setsockopt(serv_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        close_and_exit("Socket Option Set Failed", NULL);
    }
	if (fcntl(serv_fd, F_SETFL, O_NONBLOCK) == -1){
		close_and_exit("fcntl Failed", &serv_fd);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	if (bind(serv_fd, (struct sockaddr *)&address, sizeof(address)) != 0){
		close_and_exit("Bind Failed", &serv_fd);
	}
	if (listen(serv_fd, 10) != 0){
		close_and_exit("Listen Failed", &serv_fd);
	}
	std::cout <<"Listening on Port " <<port <<std::endl;
	return (address);
}

SocketServer::SocketServer() : _port(5000), _serv(NULL){
    this->_address = socket_init(_port, this->_server_fd);
    pollfd tmp;
    tmp.fd = this->_server_fd;
    tmp.events = POLLIN;
    tmp.revents = 0;
    _fds.push_back(tmp);
}

SocketServer::SocketServer(int port, Server *serv) : _port(port) , _serv(serv){
    this->_address = socket_init(_port, this->_server_fd);
    pollfd tmp;
    tmp.fd = this->_server_fd;
    tmp.events = POLLIN;
    tmp.revents = 0;
    _fds.push_back(tmp);
}

SocketServer::~SocketServer(){
    for(size_t i = 0; i < _fds.size(); i++){
        close(_fds.at(i).fd);
    }
}

SocketServer::SocketServer(const SocketServer &other){
    this->_address = other._address;
    this->_port = other._port;
    this->_server_fd = other._server_fd;
    this->_fds = other._fds;
}

SocketServer &SocketServer::operator=(const SocketServer &other){
    if (this != &other){
        this->_address = other._address;
        this->_port = other._port;
        this->_server_fd = other._server_fd;
        this->_fds = other._fds;
    }
    return (*this);
}

void    SocketServer::checkFdStat(){
    if (poll(this->_fds.data(), _fds.size(), -1) < 0){
        close_and_exit("Poll Error", this->_fds);
    }
}

void    SocketServer::addNewClient(){
    int         new_socket;
    socklen_t   addrlen = sizeof(this->_address);

    if (this->_fds.at(0).revents & POLLIN){
        new_socket = accept(this->_fds.at(0).fd, (struct sockaddr *)&(this->_address), &addrlen);
        if (new_socket < 0){
            close_and_exit("Accept Error", this->_fds);
        }
        else{
            std::cout << "New connection, socket fd is " << new_socket << std::endl;
            fcntl(new_socket, F_SETFL, O_NONBLOCK);
            pollfd tmp;
            tmp.fd = new_socket;
            tmp.events = POLLIN;
            tmp.revents = 0;
            _fds.push_back(tmp);
            Client *c = new Client(new_socket);
            this->_serv->add_client(c);
        }
    }
}

std::string SocketServer::getClientCommand(size_t &i){
    char buf[1024];

    int valread = recv(this->_fds.at(i).fd, buf, 1023, 0);
    if (valread < 0){
        std::perror("Read");
        close(this->_fds.at(i).fd);
        this->_serv->remode_client(this->_fds.at(i).fd);
        this->_fds.erase(this->_fds.begin() + i--);
    }
    else if(valread == 0){
        std::cout <<this->_fds.at(i).fd <<": Client disconnected." <<std::endl;
        close(this->_fds.at(i).fd);
        this->_serv->remode_client(this->_fds.at(i).fd);
        this->_fds.erase(this->_fds.begin() + i--);
    }
    else{
        buf[valread] = '\0';
        std::string ret(buf);
        return (ret);
    }
    return ("");
}

std::vector<std::pair<std::string, int> > SocketServer::getCommandVector(){
    std::vector<std::pair<std::string, int> > ret;
    std::string tmp;

    for(size_t i = 1; i < this->_fds.size(); i++){
        if (!this->_serv->get_client_from_fd(this->_fds.at(i).fd)->get_message().empty()){
            this->_fds.at(i).events = POLLIN | POLLOUT;
        }
    }

    this->checkFdStat();
    this->addNewClient();

    for (size_t i = 1; i < this->_fds.size(); i++){
        if(this->_fds.at(i).revents & POLLIN){
            tmp = getClientCommand(i);
            if (tmp != ""){
                std::pair<std::string, int> t;
                t.first = tmp;
                t.second = this->_fds.at(i).fd;
                ret.push_back(t);
            }
        }
        if (this->_serv->get_client_from_fd(this->_fds.at(i).fd) != NULL){
            tmp = this->_serv->get_client_from_fd(this->_fds.at(i).fd)->get_message();
            if((this->_fds.at(i).revents & POLLOUT) && !tmp.empty()){
                send(this->_fds.at(i).fd, tmp.c_str(), tmp.length(), 0);
                this->_serv->get_client_from_fd(this->_fds.at(i).fd)->set_message("");
                this->_fds.at(i).events = POLLIN;
            }
        }
    }
    return (ret);
}

void    SocketServer::remove_fd(int fd){
    for(size_t i = 0; i < this->_fds.size(); i++){
        if (fd == this->_fds.at(i).fd){
            std::cout <<this->_fds.at(i).fd <<": Client disconnected." <<std::endl;
            close(this->_fds.at(i).fd);
            this->_serv->remode_client(this->_fds.at(i).fd);
            this->_fds.erase(this->_fds.begin() + i);
            return ;
        }
    }
}