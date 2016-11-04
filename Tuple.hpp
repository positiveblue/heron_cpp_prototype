#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <map>
#include <sstream>
#include "Element.hpp"
#include "IPluggableSerializer.hpp"


class Tuple {
    
    std::map<std::string, Element* > elements;

public:
    Tuple() {}

    Element* Get(std::string name) {
        return elements[name];
    }

    void Set(std::string name, Element *e) {
        elements[name] = e;
    }

    void serialize(IPluggableSerializer serializer, std::stringstream &ss) {
        cereal::BinaryOutputArchive oarchive (ss);

    }

};


#endif
