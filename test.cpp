#include <iostream>
#include <cereal/cereal.hpp>

#include "types.h"

int main() {
    Element* eInt = new Int(15);
    Element* eString = new String("Jordi");
    
    std::cout << "hello world" << std::endl;
}