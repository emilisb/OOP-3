//
//  Person.hpp
//  Uzduotis 3
//
//  Created by Emilis Baliukonis on 21/05/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <string>

class Person {
public:
    inline std::string getFirstName() const { return firstName; }
    inline std::string getLastName() const { return lastName; }
    
    inline bool operator<(const Person& rhs) const {
        if (firstName == rhs.firstName) {
            return lastName < rhs.lastName;
        }
        
        return firstName < rhs.firstName;
    }
    
    inline bool operator>(const Person& rhs) const {
        if (firstName == rhs.firstName) {
            return lastName > rhs.lastName;
        }
        
        return firstName > rhs.firstName;
    }
    
    inline bool operator==(const Person& rhs) const {
        return firstName == rhs.firstName && lastName == rhs.lastName;
    }
    
    inline bool operator!=(const Person& rhs) const {
        return firstName != rhs.firstName || lastName != rhs.lastName;
    }
protected:
    Person(std::string _firstName, std::string _lastName) : firstName(_firstName), lastName(_lastName) { }
private:
    std::string firstName;
    std::string lastName;
};

#endif /* Person_hpp */
