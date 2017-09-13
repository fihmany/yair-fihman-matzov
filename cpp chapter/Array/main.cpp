#include <iostream>
#include "SafeArray.h"
int main() {
    try {
        SafeArray<int> a(15);
        a[0] = 2;
        a[1] = 3;
    }
    catch (const Out_Of_Range_Exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}