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
#include "Student.hpp"
#include "ConsoleInput.hpp"

using std::cout;
using std::cin;
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
        cout << "Vardas (arba /q jeigu norite baigti vesti duomenis): ";
        cin >> student.firstName;
        if (student.firstName != EXIT_COMMAND) {
            cout << endl << "Pavardė: ";
            cin >> student.lastName;
            
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
                    cout << endl << "Namų darbų rez. (arba 0 jei norite baigti vesti duomenis): ";
                    cin >> homeworkResult;
                    if (cin.fail()) {
                        // discard 'bad' character(s)
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Bad input!" << endl;
                    } else if (homeworkResult != 0) {
                        student.homeworkResults.push_back(homeworkResult);
                    } else {
                        fillingHomework = false;
                    }
                }
                
                cout << endl << "Egzamino rez.: ";
                cin >> student.examResult;
                cout << endl;
            }
            
            students.push_back(student);
        } else {
            filling = false;
        }
    }
    
    return students;
}

vector<Student> getStudentsFromFile(string filename) {
    vector<Student> students;
    
    std::ifstream file(filename);
    if (!file.fail()) {
        string tempLine;
        std::getline(file, tempLine); // ignore first line
        
        while (!file.eof()) {
            Student student;
            file >> student.firstName >> student.lastName;
            
            if (student.firstName == "") {
                break;
            }
            
            int result;
            for (int i = 0; i < 5; i++) {
                file >> result;
                student.homeworkResults.push_back(result);
            }
            
            file >> student.examResult;
            
            students.push_back(student);
        }
    } else {
        cout << "Failo skaitymo klaida!" << endl;
    }
    
    file.close();
    
    return students;
}

void printResults(StudentCollection collection, char mode) {
    int firstNameLength = collection.maxFirstNameLength();
    int lastNameLength = collection.maxLastNameLength();
    string modeLabel = (mode == 'v' ? "Vid." : "Med.");
    string finalResultLabel = "Galutinis (" + modeLabel + ")";
    
    cout << std::left
    << std::setw(firstNameLength) << "Vardas"
    << std::setw(lastNameLength) << "Pavardė"
    << std::setw(finalResultLabel.length()) << finalResultLabel
    << endl;
    
    string separator = string(firstNameLength + lastNameLength + finalResultLabel.length(), '-');
    
    cout << separator << endl;
    
    for (auto &student : collection.students) {
        cout << std::left
        << std::setw(firstNameLength) << student.firstName
        << std::setw(lastNameLength) << student.lastName
        << std::setw(finalResultLabel.length()) << std::fixed << std::setprecision(2) << student.finalResult
        << endl;
    }
}

char getMode() {
    char mode = '\0';
    
    while (mode != 'm' && mode != 'v') {
        cout
        << "Ar norite naudoti vidurkį (v) ar medianą (m)?" << endl
        << "v - vidurkį" << endl
        << "m - medianą" << endl;
        cin >> mode;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return mode;
}

int main(int argc, const char * argv[]) {
    StudentCollection collection;
    
    bool useFile = ConsoleInput::getBool("Ar norite skaityti pažymius iš failo?");
    
    if (useFile) {
        collection.students = getStudentsFromFile("kursiokai.txt");
    } else {
        bool useRandom = ConsoleInput::getBool("Ar norite naudoti atsitiktinius pažymius?");
        collection.students = getStudents(useRandom);
    }
    
    char mode = getMode();
    
    if (mode == 'v') {
        collection.calculateAverage();
    } else if (mode == 'm') {
        collection.calculateMedian();
    }
    
    collection.sortByName();
    printResults(collection, mode);
    
    return 0;
}
