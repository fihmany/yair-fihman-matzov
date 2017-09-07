#include <iostream>
#include "Fractions.h"
#include "DivideByZeroException.h"
int main() {
    try {
        Fractions a = Fractions(1, 0);
        Fractions b = Fractions(2, 6);
        Fractions c;
        c = (a * b) + 3;
        c.print();
        std::cout << c.to_string() << " " << std::to_string(c.getAsFloat()) << std::endl;
    }
    catch (DivideByZeroException &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }


    return 0;
}