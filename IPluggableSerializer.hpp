#ifndef IPLUGGABLESERIALIZE_HPP
#define IPLUGGABLESERIALIZE_HPP

#include <map>
#include <sstream>
#include <iostream>

#include "Element.hpp"

class IPluggableSerializer {

public:
    virtual void serialize(std::map<std::string, Element* > &tuple, 
       std::stringstream &ss) = 0;

    virtual void deserialize(std::stringstream &ss, 
        std::map<std::string, Element* > &tuple) = 0;

};

#endif



