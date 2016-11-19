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

#ifndef __HERON_TUPLE_H_
#define __HERON_TUPLE_H_

#include <sstream>
#include "../types/types.h"
#include "../serializer/IPluggableSerializer.h"

class Tuple {
    
    std::map<std::string, std::shared_ptr<Element> > elements;

public:

    Tuple() {}

    std::shared_ptr<Element>  Get(std::string name);
    
    void Set(std::string name, std::shared_ptr<Element> e);

    void serialize(IPluggableSerializer *serializer, std::stringstream &ss);

    void deserialize(IPluggableSerializer *serializer, std::stringstream &ss);

};


#endif