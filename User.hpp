#ifndef USER_HPP
#define USER_HPP

#include "Element.hpp"
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>

class User : public Element {

    int id;
    std::string name;

public:
    User() {}

    User(int id_, std::string name_) : id(id_), name(name_) {}

    int getId() {
        return id;
    }

    std::string getUser() {
        return name;
    }

    void save(cereal::BinaryOutputArchive &oarchive) {
        oarchive(id, name);
    }

    void load(cereal::BinaryInputArchive &iarchive) {
        iarchive(id, name);
    }
   

};
#endif