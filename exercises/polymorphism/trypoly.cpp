#include "Polygons.hpp"
#include <iostream>

int main() {
    // create a Pentagon, call its perimeter method
    Pentagon pent(10);
    std::cout<<"Pentagon perimeter:\t"<<pent.computePerimeter()<<"\n";

    // create a Hexagon, call its perimeter method
    Hexagon hex(50);
    std::cout<<"Hexagon perimeter:\t"<<hex.computePerimeter()<<"\n";

    // create a Hexagon, call the perimeter method through a reference to Polygon
    Hexagon hex2(50);
    RegularPolygon &ref = hex2;
    std::cout << "Base class method call:\t"<< ref.computePerimeter()<<"\n";

    // retry virtual method
    // no code here, cause replacing method with a virtual one changes the 
    //behevior of the previous code
    return 0;
}
