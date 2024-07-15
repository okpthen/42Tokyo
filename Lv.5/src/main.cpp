#include "irc.hpp"
#include "SocketServer.hpp"

std::vector<std::string> splitStringByNewline(const std::string& input) {
    std::vector<std::string> lines;
    std::stringstream ss(input);
    std::string line;

    while (std::getline(ss, line)) {
        if (!line.empty() && *line.rbegin() == '\r') {
            line.erase(line.size() - 1); // キャリッジリターンを削除
        }
        lines.push_back(line);
    }

    return lines;
}
bool	g_active = true;


static void	server_down(int sig)
{
	if (sig == SIGINT)
		g_active = false;
}

bool	is_all_digit(char *s){
	for(size_t i = 0; s[i] != 0; i++){
		if (s[i] < '0' || '9' < s[i]){
			return (false);
		}
	}
	return (true);
}

int main(int ac, char **av){
	if (ac == 1 || ac > 3 || !is_all_digit(av[1])){
		std::cerr <<"Usage: ./ircserv [port] [password]" <<std::endl;
		return (1);
	}
	Server server;
	SocketServer socket(atoi(av[1]), &server);
	server.s = &socket;
	std::vector<std::pair<std::string, int> > t;
	Command	cmd;
	signal(SIGINT , server_down);

	server.set_pass(av[2]);
	while(g_active){
		t = socket.getCommandVector();
		for(size_t i = 0; i < t.size(); i++){
			std::cout << "\033[1;31m" <<"|" <<t.at(i).first;
			std::cout <<"|" << "\033[0m" <<std::endl;
			cmd.exec_loop(t.at(i).first, server.get_client_from_fd(t.at(i).second), server);
		}
	}
	return (0);
}

