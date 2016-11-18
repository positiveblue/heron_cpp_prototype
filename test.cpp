#include <iostream>
#include <sstream>
#include <cereal/cereal.hpp>

#include "types.h"
#include "CerealSerializer.h"

int main() {
    // sstream: Will contain the serialization of a tuple
    std::stringstream ss;

    // Elements
    Element* eInt = new Int(15);
    Element* eString = new String("Jordi");

    // Serializer
    CerealSerializer CSerializer;


    

    std::cout << "hello world" << std::endl;
}