#include <iostream>
#include <sstream>
#include <cereal/cereal.hpp>

#include "types.h"
#include "Tuple.h"

#include "IPluggableSerializer.h"
#include "CerealSerializer.h"


int main() {
    // sstream: Will contain the serialization of a tuple
    std::stringstream ss;

    // Elements
    Element* eInt = new Int(15);
    Element* eString = new String("Jordi");

    // Tuple
    Tuple tuple;

    
    tuple.Set("Worker", eString);
    tuple.Set("Salary", eInt);


    // Serializer
    IPluggableSerializer *CSerializer = new CerealSerializer();

    tuple.serialize(CSerializer, ss);
    
    std::cout << "Cross your fingers" << std::endl;

    tuple.deserialize(CSerializer, ss);
}