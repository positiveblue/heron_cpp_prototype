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
    // sstream: Will contain the serialization of a tuple
    std::stringstream ss;

    // Elements
    Element* eInt = new Int(15);
    Element* eString = new String("Jordi");

    // Tuple
    Tuple tuple;

    
    tuple.Set("Worker", eString);
    tuple.Set("Salary", eInt);


    // Serializer
    IPluggableSerializer *CSerializer = new CerealSerializer();

    tuple.serialize(CSerializer, ss);
    
    std::cout << "Cross your fingers" << std::endl;

    writeToFile("serialize.out", ss);

}