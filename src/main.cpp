//
//  main.cpp
//  Objektinis2
//
//  Created by Emilis Baliukonis on 13/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#define UNITS "ms"
#define MAX_STUDENTS 100000

#include <string>

#include "code/StudentCollection.hpp"

#include "code/Console/Console.hpp"
#include "code/Console/Table.hpp"
#include "code/Console/Row.hpp"
#include "code/Timer.hpp"

using std::string;

int main(int argc, const char * argv[]) {
    const bool useProfiler = Console::getBoolWithQuestion("Ar norite atlikti spartos testą?");
    
    if (useProfiler) {
        Table table(9);
        table.setSeparatorRow(1);
        table.addRow( { "Kont.", "Str.", "N", "Skait.", "Skaiciav.", "Rikiav.", "Rūsiav.", "Rasymas", "Viso" } );
        
        for (int numOfStudents = 10; numOfStudents <= MAX_STUDENTS; numOfStudents*= 10) {
            StudentCollection collection;
            collection.finalResultMode = 'v';
            
            string filename = "data/" + std::to_string(numOfStudents) + ".txt";
            collection.generateRandomFile(filename, numOfStudents);
            
            Timer totalTimer;
            totalTimer.start();
            
            Timer timer;
            timer.start();
            collection.loadFromFile(filename);
            string time2 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.calculateFinal();
            string time3 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.sortByName();
            string time4 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.pushByType();
            string time5 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.writeGroupedStudentsToFile("data/bad_students.txt", "data/good_students.txt");
            string time6 = std::to_string(timer.duration()) + UNITS;
            
            string time7 = std::to_string(totalTimer.duration()) + UNITS;
            
            table.addRow( { CONTAINER, "Push", std::to_string(numOfStudents), time2, time3, time4, time5, time6, time7 } );
        }
        
        for (int numOfStudents = 10; numOfStudents <= MAX_STUDENTS; numOfStudents*= 10) {
            StudentCollection collection;
            collection.finalResultMode = 'v';
            
            string filename = "data/" + std::to_string(numOfStudents) + ".txt";
            
            Timer totalTimer;
            totalTimer.start();
            
            Timer timer;
            timer.start();
            collection.loadFromFile(filename);
            string time2 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.calculateFinal();
            string time3 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.sortByName();
            string time4 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.moveBadStudents();
            string time5 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.writeMovedBadStudentsToFile("data/bad_students.txt", "data/good_students.txt");
            string time6 = std::to_string(timer.duration()) + UNITS;
            
            string time7 = std::to_string(totalTimer.duration()) + UNITS;
            
            table.addRow( { CONTAINER, "Remove", std::to_string(numOfStudents), time2, time3, time4, time5, time6, time7 } );
        }
        
        for (int numOfStudents = 10; numOfStudents <= MAX_STUDENTS; numOfStudents*= 10) {
            StudentCollection collection;
            collection.finalResultMode = 'v';
            
            string filename = "data/" + std::to_string(numOfStudents) + ".txt";
            
            Timer totalTimer;
            totalTimer.start();
            
            Timer timer;
            timer.start();
            collection.loadFromFile(filename);
            string time2 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.calculateFinal();
            string time3 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.sortByName();
            string time4 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.setTypeByFinalResult();
            string time5 = std::to_string(timer.duration()) + UNITS;
            
            timer.start();
            collection.writeStudentsByTypeToFile("data/bad_students.txt", "data/good_students.txt");
            string time6 = std::to_string(timer.duration()) + UNITS;
            
            string time7 = std::to_string(totalTimer.duration()) + UNITS;
            
            table.addRow( { CONTAINER, "Flag", std::to_string(numOfStudents), time2, time3, time4, time5, time6, time7 } );
        }
        
        table.print();
    } else {
        StudentCollection collection;
        const bool useFile = Console::getBoolWithQuestion("Ar norite skaityti pažymius iš failo?");
        
        if (useFile) {
            collection.loadFromFile("data/kursiokai.txt");
        } else {
            const bool useRandom = Console::getBoolWithQuestion("Ar norite naudoti atsitiktinius duomenis?");
            collection.loadFromConsole(useRandom);
        }
        
        collection.finalResultMode = Console::getCharWithQuestion("Ar norite naudoti vidurkį ar medianą?", "vidurkį", "medianą", 'v', 'm');
        
        collection.calculateFinal();
        
        collection.sortByName();
        collection.printResults();
    }
    
    return 0;
}
