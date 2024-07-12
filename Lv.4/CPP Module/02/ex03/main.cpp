#include <iostream>
#include "Point.hpp"

#define MAX (2147483648.0f/256)
#define MIN (1.0f/256)

int main(){
    Point a(0,0);
    Point b(MAX,MAX);
    Point c(MAX,0);
    Point pt1(-1,-1);

    std::cout<<std::boolalpha;
    std::cout<< bsp(a,b,c,pt1) <<std::endl;
    std::cout<< (Fixed(MAX-1)-Fixed(MIN) == Fixed(MAX-1)) <<std::endl;
}


// int main( void )
// {
// 	Point	o(10, 5);

// 	if (bsp(Point(0, 0), Point(20, 0), Point(10, 20), o) == true)
// 		std::cout << "Point o is inside triangle" << std::endl;
// 	else
// 		std::cout << "Point o is outside triangle" << std::endl;
	
// 	if (bsp(Point(0, 0), Point(-20, 0), Point(-10, 20), o) == true)
// 		std::cout << "Point o is inside triangle" << std::endl;
// 	else
// 		std::cout << "Point o is outside triangle" << std::endl;
	
// 	if (bsp(Point(0, 0), Point(-20, 0), Point(-10, -20), o) == true)
// 		std::cout << "Point o is inside triangle" << std::endl;
// 	else
// 		std::cout << "Point o is outside triangle" << std::endl;

// 	if (bsp(Point(0, 0), Point(20, 0), Point(10, -20), o) == true)
// 		std::cout << "Point o is inside triangle" << std::endl;
// 	else
// 		std::cout << "Point o is outside triangle" << std::endl;

// 	return 0;
// }