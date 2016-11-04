#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <sstream>
#include <iostream>
#include <cereal/archives/binary.hpp>


class Element {

    virtual void save(cereal::BinaryOutputArchive &oarchive) = 0;

    virtual void load(cereal::BinaryInputArchive &iarchive) = 0;

};
#endif


