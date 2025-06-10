#include "TextBox.hpp"
#include <iostream>

int main() {
    // create a TextBox and call draw
    TextBox tb("Hello", 10.0f, 5.0f);

    // Fix the code to call both draws by using types
    std::cout << "Calling Rectangle's draw\n";
    static_cast<Rectangle&>(tb).draw();
    std::cout<< "Calling Text's draw:\n";
    static_cast<Text&>(tb).draw();

    // try with virtual inheritance
    std::cout<< "Calling draw via virtual inheritance:\n";
    tb.draw();


}
