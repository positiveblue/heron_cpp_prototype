#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <map>
#include <sstream>

#include "IPluggableSerializer.hpp"




class Serializer : IPluggableSerializer {

public:
    Serializer() {}

    void serialize(std::map<std::string, Element* > &tuple, 
        std::stringstream &ss) {
        
        std::cout << "Serializing..." << std::endl;
    }

    void deserialize(std::stringstream &ss, 
        std::map<std::string, Element* > &tuple) {
        
        std::cout << "Deserializing..." << std::endl;
    }

};

#endif



