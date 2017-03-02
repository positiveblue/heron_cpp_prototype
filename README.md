# Heron C++ prototype 

[Heron](http://twitter.github.io/heron/) is realtime analytics platform developed by Twitter. It is the direct successor of Apache Storm, built to be backwards compatible with Storm's topology API but with a wide array of architectural improvements.

Back in september 2016, I attended to a talk given by [Karthik](https://twitter.com/karthikz), lead of the real time analytics at Twitter.
After the talk I talked with Karthik to see if I could get involved in the project. Heron is mainly written in Java, Python and C++ but the only
robust API for the users is in Java. They had just started to writte a lite version for python and given that many companies have their infastructure in C++ having this platform in C++ would be great.

The main concept of Heron is Tuple. This tuples are implemented in Java as a map/array of objects. They are serialized, sent throw the network and deserialized using the features and flexibility that the JVM proporcinate. In C++ the arquitecture has to be a bit more complicated.

In this repository you can find a prototype of how a possible C++ implementation could look like. It is totally deattached of the Heron code but it is a good guide of what is necesary in a real-world implementation.

## Arquitecture
The main features that I implemented are:

- *Element:* A pure virtual class with two main methods: save and load. They are going to be used for the serialization/deserealization part. It uses a C++ library called [Cereal]() for it.
- *Basic types:* It is an Element wrapper for some basic types (String, Int, Double)
- *Tuple:* A tuple is a colection (unordered_map) of *Elements*
- *Serializer:* A pluggable serializer to define how tuples are serialize/deserialize (user defined)


## Example

Here is an example of how it looks like. I implemented two auxiliar clases *Tweet* and *User* to ilustrate it.

First, we create the elements that we want to work with:
```cpp
    // Elements
    std::shared_ptr<Element> eInt(new Int(15));
    std::shared_ptr<Element> eDouble(new Double(3.14159));
    std::shared_ptr<Element> eString(new String("Jordi"));
```

We Set them in a tuple:
```cpp
// Tuple
    Tuple tuple;

    tuple.Set("Worker", eString);
    tuple.Set("Salary", eInt);
    tuple.Set("Phi", eDouble);
```

Using dependency injection we serialize the tuple (the user would have to define the order a tuple is serialized/deserialized)
```cpp
    ////////////////////////
    //* Sending a tuple *//
    //////////////////////


    // sstream: Will contain the serialization of a tuple
    std::stringstream os;

    // Serializer
    IPluggableSerializer *CSerializer = new CerealSerializer();

    tuple.serialize(CSerializer, os);
    
    writeToFile("serialize.out", os);
```

Deserialize the tuple can be done casting the values:
```cpp
    //////////////////////////
    //* Recieving a tuple *//
    ////////////////////////

    std::stringstream is;
    readFromFile("serialize.out", is);

    Tuple new_tuple;
    new_tuple.deserialize(CSerializer, is);

    auto Salary = 
        std::static_pointer_cast<Int>(new_tuple.Get("Salary"));
    auto Phi = 
        std::static_pointer_cast<Double>(new_tuple.Get("Phi"));
    auto Worker = 
        std::static_pointer_cast<String>(new_tuple.Get("Worker"));

    std::cout << "Salary: " << Salary->getValue() << std::endl;
    std::cout << "Phi: " << Phi->getValue() << std::endl;
    std::cout << "Worker: " << Worker->getValue() << std::endl;
```

Well, this is more a proof of concept than a real-world implementation. If someone finds it interesting enough to integrate it in Heron I will be glad to help but I am busy right now with other projects so I could not do it alone.

## License

This software is licensed under the same license as Heron. Learn more about it [here](https://github.com/jomsdev/heron_cpp_prototype/blob/master/LICENSE)
