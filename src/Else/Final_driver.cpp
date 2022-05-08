#include "Final-Sol.h"
#include <iostream>

int TestFinal(){
    Final fo;
    fo.add(2);
    fo.add(5);
    std::cout << fo << std::endl;
    fo.remove();
    std::cout << fo << std::endl;
    fo.remove();
    std::cout << fo << std::endl;
    fo.add(2);
    fo.add(5);
    fo.add(8);
    fo.add(1);
    std::cout << fo << std::endl;
    fo.flip();
    std::cout << fo << std::endl;
    fo.remove();
    std::cout << fo << std::endl;
    fo.add(9);
    fo.add(42);
    std::cout << fo << std::endl;
    Final fo1 = fo;
    fo1.add(54);
    std::cout << fo1 << std::endl;
    std::cout << fo << std::endl;
    fo1.flip();
    std::cout << fo1 << std::endl;
    std::cout << fo << std::endl;
}
