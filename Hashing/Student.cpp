#include "stdafx.h"
#include "Student.h"


Student::Student()
{
	studentID = NULL;
	this->originalPos = NULL;
	this->hashKey = NULL;
	this->name = "empty";
	this->next = NULL;
}


Student::~Student()
{
}

Student::Student(int ID, int originalPos, int hashKey, string name)
{
	studentID = ID;
	this->originalPos = originalPos;
	this->hashKey = hashKey;
	this->name = name;
	this->next = NULL;
}
int Student::Hashing(int ID, int size)
{
	unsigned int index;
	hash<int> h;
	index = h(ID) % size;

	return index;
}

void Student::Add(int ID, int originalPos, int hashKey, string name)
{
	if (studentID == NULL)
	{
		studentID = ID;
		this->originalPos = originalPos;
		this->hashKey = hashKey;
		this->name = name;
		this->next = NULL;
	}
	else
	{
		//add the new student to the end of the list if it has the same hashkey
		Student *ptr = this;
		Student *n = new Student;
		n->studentID = ID;
		n->originalPos = originalPos;
		n->hashKey = hashKey;
		n->name = name;
		n->next = NULL;
		while (ptr->next != NULL) //ptr traverse through the list to find the end
		{
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}

void Student::PrintTable()
{
	Student *student = this;
	if (studentID == NULL)
	{
		cout << "-----------------------------\n";
		cout << "empty\n";
		cout << "-----------------------------\n\n";
	}
	else
	{
		if (student->next == NULL) {
			cout << "-----------------------------\n";
			cout << "Student ID: " << studentID << endl;
			cout << "Student Name: " << name << endl;
			cout << "Student hash key: " << hashKey << endl;
			cout << "Student original position: " << originalPos << endl;
			cout << "-----------------------------\n\n";
		}
		else {
			while (student->next != NULL) {
				cout << "-----------------------------     --->\t";
				student = student->next;
			}
			cout << "-----------------------------\n";
			student = this;
			while (student->next != NULL) {

				cout << "Student ID: " << student->studentID << "\t\t\t";
				student = student->next;
			}
			cout << "Student ID: " << student->studentID << endl;
			student = this;
			while (student->next != NULL) {
				cout << "Student Name: " << student->name << "\t\t";
				student = student->next;
			}
			cout << "Student Name: " << student->name << endl;
			student = this;
			while (student->next != NULL) {
				cout << "Student hash key: " << student->hashKey << "\t\t\t";
				student = student->next;
			}
			cout << "Student hash key: " << student->hashKey << endl;
			student = this;
			while (student->next != NULL) {
				cout << "Student original position: " << student->originalPos << "\t\t";
				student = student->next;
			}
			cout << "Student original position: " << student->originalPos << endl;
			student = this;
			while (student->next != NULL) {
				cout << "-----------------------------     \t";
				student = student->next;
			}
			cout << "-----------------------------\n\n";
		}

	}
}

void Student::WriteToFile(ofstream &myFile)
{
	Student *student = this;
	if (myFile.is_open()) {
		if (studentID == NULL)
		{
			myFile << "-----------------------------\n";
			myFile << "empty\n";
			myFile << "-----------------------------\n\n";
		}
		else
		{
			if (student->next == NULL) {
				myFile << "-----------------------------\n";
				myFile << "Student ID: " << studentID << "\n";
				myFile << "Student Name: " << name << "\n";
				myFile << "Student hash key: " << hashKey << "\n";
				myFile << "Student original position: " << originalPos << "\n";
				myFile << "-----------------------------\n\n";
			}
			else {
				while (student->next != NULL) {
					myFile << "-----------------------------     --->\t";
					student = student->next;
				}
				myFile << "-----------------------------\n";
				student = this;
				while (student->next != NULL) {

					myFile << "Student ID: " << student->studentID << "\t\t\t";
					student = student->next;
				}
				myFile << "Student ID: " << student->studentID << "\n";
				student = this;
				while (student->next != NULL) {
					myFile << "Student Name: " << student->name << "\t\t";
					student = student->next;
				}
				myFile << "Student Name: " << student->name << "\n";
				student = this;
				while (student->next != NULL) {
					myFile << "Student hash key: " << student->hashKey << "\t\t\t";
					student = student->next;
				}
				myFile << "Student hash key: " << student->hashKey << "\n";
				student = this;
				while (student->next != NULL) {
					myFile << "Student original position: " << student->originalPos << "\t\t";
					student = student->next;
				}
				myFile << "Student original position: " << student->originalPos << "\n";
				student = this;
				while (student->next != NULL) {
					myFile << "-----------------------------     \t";
					student = student->next;
				}
				myFile << "-----------------------------\n\n";
			}

		}
		//myFile.close();
	}
	else cout << "Unable to open file";
}

void Student::ToString()
{
	cout << "-----------------------------\n";
	cout << "Student ID: " << studentID << endl;
	cout << "Student Name: " << name << endl;
	cout << "Student hash key: " << hashKey << endl;
	cout << "Student original position: " << originalPos << endl;
	cout << "-----------------------------\n\n";
}

