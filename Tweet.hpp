#ifndef TWEET_HPP
#define TWEET_HPP

#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>
#include "Element.hpp"

class Tweet : public Element {

    int id;
    std::string text;

public:
    Tweet(int id_, std::string text_) : id(id_), text(text_) {}

    int getId() {
        return id;
    }

    std::string getText() {
        return text;
    }


    void save(cereal::BinaryOutputArchive &oarchive) {
        oarchive(id, text);
    }

    void load(cereal::BinaryInputArchive &iarchive) {
        iarchive(id, text);
    }
};
#endif