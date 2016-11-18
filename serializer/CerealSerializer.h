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

#ifndef __CEREAL_SERIALIZER_H_
#define __CEREAL_SERIALIZER_H_

#include <sstream>
#include <cereal/archives/binary.hpp>

#include "IPluggableSerializer.h"
#include "../types/types.h"


class CerealSerializer : public IPluggableSerializer {

public:

    void serialize(std::stringstream &ss, 
        std::map<std::string, Element* > &tuple) {
        
        std::cout << "serializing..." << std::endl;
    }

    virtual void deserialize(std::stringstream &ss, 
        std::map<std::string, Element* > &tuple) {
        
        std::cout << "deserializing..." << std::endl;
    }

};

#endif
