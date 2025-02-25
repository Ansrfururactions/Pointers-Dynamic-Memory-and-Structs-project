// Pointers, Dynamic Memory, and Structs project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Student {
    string name;
    int ID;
    int* grades;
    double* average;
    char* letter;
};

string filename = "student.txt";
Student* getData(ifstream& file, int& studentCnt, int& testsCnt);
void calcAverage(Student students[], int studentCnt, int testsCnt);
void getLettergrade(Student students[], int studentCnt, int testsCnt);
void printreport(Student students[], int studentCnt);


int main()
{
    int studentCnt;
    int testsCnt;
    ifstream file;

    Student* students;
    file.open(filename);
    if (!file.is_open())
    {
        cout << "could not open file, rerun the program and try again.";
        return 0;
    }
    students = getData(file, studentCnt, testsCnt);
    calcAverage(students, studentCnt, testsCnt);
    getLettergrade(students, studentCnt, testsCnt);
    printreport(students, studentCnt);

  
}



Student* getData(ifstream& file, int& studentCnt, int& testsCnt)
{
    file >> studentCnt >> testsCnt;
   
    Student* students = new Student[studentCnt];

        for (int E = 0; E < studentCnt; E++)
        {
            file >> students[E].name >> students[E].ID;
          
            students[E].grades = new int[testsCnt];
            for (int I = 0; I < testsCnt; I++)
            {
                file >> students[E].grades[I];
            }
        }
        return students;
}
void calcAverage(Student students[], int studentCnt, int testsCnt)
{
    for (int r = 0; r < studentCnt; r++)
    {
        double sum = 0;
        students[r].average = new double[studentCnt];
        for (int egg = 0; egg < testsCnt; egg++)
        {
            sum = sum + students[r].grades[egg];
            
        }
        *students[r].average = sum / testsCnt;
    }
}
void getLettergrade(Student students[], int studentCnt, int testsCnt)
{
    for (int r = 0; r < studentCnt; r++)
    {
        students[r].letter = new char[studentCnt];
        
        if (*students[r].average >= 90.0)
        {
            *students[r].letter = 'A';
        }
        else if (*students[r].average >= 80.0)
        {
            *students[r].letter = 'B';
        }
        else if (*students[r].average >= 70.0)
        {
            *students[r].letter = 'C';
        }
        else if (*students[r].average >= 60.0)
        {
            *students[r].letter = 'D';
        }
        else
        {
            *students[r].letter = 'F';
        }
    }
}

void printreport(Student students[], int studentCnt)
{
    for (int N = 0; N <=studentCnt; N++)
    {
        cout << students[N].name << " " << students[N].ID << " " << *students[N].average << " " << *students[N].letter;
        cout << endl;
    }

    const int ptrconst = 6;
    const int ptrconst2 = 6;
    string* ptr[ptrconst];
    int* ptr2[ptrconst2];
    
    for (int N = 0; N < studentCnt; N++)
    {
        *ptr[N] = students[N].name;
    }
    for(int e=0;e<studentCnt; e++)
    {
        *ptr2[e] = students[e].ID;
    }
    for (int D = 0; D < studentCnt; D++)
    {
        delete students[D].grades;
        delete students[D].average;
        delete students[D].letter;
        delete[] ptr;
        delete[] ptr2;
    }
    
}