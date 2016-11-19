#include <iostream>
#include <sstream>
#include <fstream>  
#include <cereal/cereal.hpp>

#include "types.h"
#include "Tuple.h"

#include "IPluggableSerializer.h"
#include "CerealSerializer.h"

void writeToFile(std::string fname, std::stringstream &ss){  
    std::ofstream myfile;  
    myfile.open (fname, std::ios_base::app);
    myfile << ss.str(); 
    myfile.close();  
}  

void readFromFile(std::string fname, std::stringstream &ss){  
    std::ifstream myfile( fname );
    if ( myfile ) {
        ss << myfile.rdbuf();
        myfile.close();
    }
}  

int main() {
    ////////////////////////
    //* Sending a tuple *//
    //////////////////////


    // sstream: Will contain the serialization of a tuple
    std::stringstream os;

    // Elements
    std::shared_ptr<Element> eInt(new Int(15));
    std::shared_ptr<Element> eDouble(new Double(3.14159));
    std::shared_ptr<Element> eString(new String("Jordi"));

    // Tuple
    Tuple tuple;

    
    tuple.Set("Worker", eString);
    tuple.Set("Salary", eInt);
    tuple.Set("Phi", eDouble);

    // Serializer
    IPluggableSerializer *CSerializer = new CerealSerializer();

    tuple.serialize(CSerializer, os);
    
    writeToFile("serialize.out", os);

    std::cout << "Cross your fingers" << std::endl;

   
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

}