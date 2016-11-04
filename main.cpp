#include <iostream>     /* cout */
#include <sstream>
#include <cereal/archives/binary.hpp>

#include "Element.hpp"
#include "Tweet.hpp"
#include "User.hpp"

#include "Serializer.hpp"
#include "Tuple.hpp"


/* initialize random seed: */



Tweet* newTweet() {
    int id = 1;
    std::string text = "Important Tweet";
    return new Tweet(id, text);
}

User* newUser() {
    int id = 0;
    std::string name = "Jordi";
    return new User(id, name);

}



int main() {
    // Create the objects, both share Element as father
    User* user = newUser();
    Tweet* tweet = newTweet();
   
    // Put them in a Tuple (map, vector, whatever)
    Tuple tuple;
    tuple.Set("User", user);
    tuple.Set("Tweet", tweet);

    // Recover them, in this cas using key-value. 
    // The user needs to know to which type he wants to cast
    User* recoverdUser = static_cast<User*>(tuple.Get("User"));
    Tweet* recoveredTweet = static_cast<Tweet*>(tuple.Get("Tweet"));


    // In order to Serialize we are going to use a Serializer
    // The serializer is only for this kind of tuples 
    // This means the user knows the order of the things
    Serializer serializer = Serializer();
    std::stringstream ss;

    // The tuple has a method to serialize 
    // But the user give use the implementation
    // of the Serializer (with IPlugableSeralizer as father)
    cereal::BinaryOutputArchive oarchive (ss);
    
    {
        user->save(oarchive);
        tweet->save(oarchive);
    }

    {
        cereal::BinaryInputArchive iarchive(ss); // Create an input archive

        User deserialized_user = User(1, "Vidit") ;
        iarchive(deserialized_user); // Read the data from the archive

         std::cout << "deserialized_user: " << deserialized_user.getId() << std::endl;
    }

    




    
    // Serializer serializer = Serializer();


}