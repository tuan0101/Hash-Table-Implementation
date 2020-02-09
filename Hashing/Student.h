#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student
{
private:
	//static const int size = 75;

public:
	int studentID;
	int originalPos;
	int hashKey;
	string name;
	Student *next;

	//default constructor
	Student();
	//constructor with 4 parameters
	Student(int ID, int originalPos, int hashKey, string name);
	~Student();

	//hash student ID to get the table index
	int hashing(int ID, int size);

	/*
	if there is no student stored in the index, display "empty"
	if there are one or more students in the index, display them like a list
	*/
	void Add(int ID, int originalPos, int hashKey, string name);

	//Print the whole hash table to the console as needed for testing
	void printTable();

	//dis play student's information to the console
	void toString();

	//write the student's information to StudentHashTable.txt file
	void writeToFile(ofstream &myFile);
};

