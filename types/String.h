/*
 * Copyright 2015 Twitter, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __STRING_HERON_TYPE_H_
#define __STRING_HERON_TYPE_H_

#include <sstream>
#include "Element.h"
#include "cereal/archives/binary.hpp"

class String : public Element {

    std::string _value;

public:

    String() {}

    String(std::string value) : _value(value) {}

    std::string getValue() {
        return _value;
    } 

    void save(cereal::BinaryOutputArchive &oarchive) const {
        oarchive(_value);
    }

    void load(cereal::BinaryInputArchive &iarchive) {
        iarchive(_value);
    }

};

// Register DerivedClassOne
CEREAL_REGISTER_TYPE(String);

// Register DerivedClassOne
CEREAL_REGISTER_POLYMORPHIC_RELATION(Element, String);

#endif