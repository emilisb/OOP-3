//
//  main.cpp
//  Objektinis2
//
//  Created by Emilis Baliukonis on 13/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <fstream>

#include "StudentCollection.hpp"
#include "Console/Console.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

#define EXIT_COMMAND "/q"

vector<Student> getStudents(bool useRandom) {
    vector<Student> students;
    
    bool filling = true;
    unsigned int homeworkResult;
    
    while (filling) {
        Student student;
        student.firstName = Console::getStringWithQuestion("Vardas (arba /q jeigu norite baigti vesti duomenis):");
        if (student.firstName != EXIT_COMMAND) {
            student.lastName = Console::getStringWithQuestion("Pavardė:");
            
            if (useRandom) {
                std::random_device rd; // obtain a random number from hardware
                std::mt19937 eng(rd()); // seed the generator
                std::uniform_int_distribution<> distr(1, 10); // define the range
                
                int numOfHomework = distr(eng);
                
                for (int i = 0; i < numOfHomework; i++) {
                    student.homeworkResults.push_back(distr(eng));
                }
                
                student.examResult = distr(eng);
            } else {
                bool fillingHomework = true;
                
                while (fillingHomework) {
                    homeworkResult = Console::getIntegerWithQuestion("Namų darbų rez. (arba 0 jei norite baigti vesti duomenis):");
                    if (homeworkResult != 0) {
                        student.homeworkResults.push_back(homeworkResult);
                    } else {
                        fillingHomework = false;
                    }
                }
                
                student.examResult = Console::getIntegerWithQuestion("Egzamino rez:");
            }
            
            students.push_back(student);
        } else {
            filling = false;
        }
    }
    
    return students;
}

int main(int argc, const char * argv[]) {
    StudentCollection collection;
    
    bool useFile = Console::getBoolWithQuestion("Ar norite skaityti pažymius iš failo?");
    
    if (useFile) {
        collection.loadFromFile("kursiokai.txt");
    } else {
        bool useRandom = Console::getBoolWithQuestion("Ar norite naudoti atsitiktinius pažymius?");
        collection.students = getStudents(useRandom);
    }
    
    collection.finalResultMode = Console::getCharWithQuestion("Ar norite naudoti vidurkį ar medianą?", "vidurkį", "medianą", 'v', 'm');
    
    collection.calculateFinal();
    
    collection.sortByName();
    collection.printResults();
    
    return 0;
}
