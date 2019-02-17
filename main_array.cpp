//
//  main.cpp
//  Objektinis2
//
//  Created by Emilis Baliukonis on 13/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

#define EXIT_COMMAND "/q"

struct Student {
    string firstName;
    string lastName;
    unsigned int *homeworkResults;
    unsigned int numHomeworkResults = 0;
    unsigned int examResult = 0;
    double finalResult = 0;
};

void resizeArray(unsigned int *&oldArray, size_t &size) {
    size_t newSize = size * 2;
    unsigned int *newArray = new unsigned int[newSize];

    memcpy(newArray, oldArray, size * sizeof(unsigned int));
    size = newSize;

    delete [] oldArray;
    oldArray = newArray;
}

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

                student.numHomeworkResults = distr(eng);
                student.homeworkResults = new unsigned int[student.numHomeworkResults];

                for (int i = 0; i < student.numHomeworkResults; i++) {
                    student.homeworkResults[i] = distr(eng);
                }

                student.examResult = distr(eng);
            } else {
                size_t resultsArrSize = 10;
                student.homeworkResults = new unsigned int[resultsArrSize];

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
                        student.homeworkResults[student.numHomeworkResults] = homeworkResult;
                        student.numHomeworkResults++;

                        if (student.numHomeworkResults == resultsArrSize) {
                            resizeArray(student.homeworkResults, resultsArrSize);
                        }
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

int maxFirstNameLength(const vector<Student> &students) {
    int length = 6; // default value is length of string "Vardas"

    for (auto &student : students) {
        length = std::max(static_cast<int>(student.firstName.length()), length);
    }

    return length + 3;
}

int maxLastNameLength(const vector<Student> &students) {
    int length = 7; // default value is length of string "Pavarde"

    for (auto &student : students) {
        length = std::max(static_cast<int>(student.lastName.length()), length);
    }

    return length + 3;
}

void printResults(const vector<Student> &students, char mode) {
    int firstNameLength = maxFirstNameLength(students);
    int lastNameLength = maxLastNameLength(students);
    string modeLabel = (mode == 'v' ? "Vid." : "Med.");
    string finalResultLabel = "Galutinis (" + modeLabel + ")";

    cout << std::left
    << std::setw(firstNameLength) << "Vardas"
    << std::setw(lastNameLength) << "Pavardė"
    << std::setw(finalResultLabel.length()) << finalResultLabel
    << endl;

    string separator = string(firstNameLength + lastNameLength + finalResultLabel.length(), '-');

    cout << separator << endl;

    for (auto &student : students) {
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

void calculateAverage(vector<Student> &students) {
    for (auto &student : students) {
        unsigned int sum = 0;
        double average = 0;

        if (student.numHomeworkResults) {
            for (int i = 0; i < student.numHomeworkResults; i++) {
                sum += student.homeworkResults[i];
            }

            average = (double)sum / student.numHomeworkResults;
        }

        student.finalResult = 0.4 * average + 0.6 * student.examResult;
    }
}

void calculateMedian(vector<Student> &students) {
    for (auto &student : students) {
        double median = 0;

        if (student.numHomeworkResults) {
            std::sort(student.homeworkResults, student.homeworkResults + student.numHomeworkResults);

            if (student.numHomeworkResults % 2 != 0) {
                median = student.homeworkResults[student.numHomeworkResults/2];
            } else {
                median = (double)(student.homeworkResults[(student.numHomeworkResults-1)/2] + student.homeworkResults[student.numHomeworkResults/2])/2.0;
            }
        }

        student.finalResult = 0.4 * median + 0.6 * student.examResult;
    }
}

bool getUseRandom() {
    char input = '\0';

    while (input != 't' && input != 'n') {
        cout
        << "Ar norite naudoti atsitiktinius pažymius?" << endl
        << "t - taip" << endl
        << "n - ne" << endl;
        cin >> input;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return input == 't';
}

int main(int argc, const char * argv[]) {
    bool useRandom = getUseRandom();
    vector<Student> students = getStudents(useRandom);
    char mode = getMode();

    if (mode == 'v') {
        calculateAverage(students);
    } else if (mode == 'm') {
        calculateMedian(students);
    }

    printResults(students, mode);

    return 0;
}
