// Pointers, Dynamic Memory, and Structs project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int* ROWS;

string filename = "student.txt";
Student* getData(ifstream& file, int& studentCnt, int& testsCnt);
void calcAverage(Student students[], int studentCnt, int testsCnt);
char getLettergrade(double average, double averageArray[], char letter, int RN);

struct Student {
    string name[6];
    int ID[6];
    int grades[6];
};


int main()
{
    int studentCnt;
    int testsCnt;
    ifstream file;

    Student* students[6];
    file.open(filename);
    if (!file.is_open())
    {
        cout << "could not open file, rerun the program and try again.";
        return 0;
    }
      getData(file, studentCnt, testsCnt);

}

Student* getData()
{
 
}
