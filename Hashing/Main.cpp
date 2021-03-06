/*************************************************************************
* Project: Hash Assignment
* Description: Create a program that reads in the list of students in a
file and put them into an array using a hash function
* Created by <Tuan Pham> on <4/3/2018>
***********************************************************************/

#include "stdafx.h"
#include "Student.h"
#include <fstream>
#include <string>
#include <vector>
#include <List>
//#include <hash_map>

//count the total lines in the file, it's also the number of students.
int GetSize(ifstream& file);

//split each line by comma to get student ID and student name
vector<string> SplitString(string line);

//search and print student's information to the console
void Search(int ID);

ifstream myfile("ListofStudent.txt");
int maxSize = GetSize(myfile);	//get the total number of students
/*
In perfect condition, 100 students will be populated in 100 randomly chosen entries, but that never happen.
If I use the maxSize for the hash table, chances are some parts of hash table are never used.
So I guess I can reduce the maxSize by 25%-30%
*/
const int SIZE = maxSize * 75 / 100;
Student *st = new Student[SIZE];


int main()
{
	int stIndex = 0;	
	int pos = 0;

	vector<string> lineField;	//used to split string for each line in the text file
	string line;

	int studentArray[100];
	ofstream file;
	file.open("StudentHashTable.txt");
	myfile.open("ListofStudent.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line)) {

			lineField = SplitString(line);
			int ID = stoi(lineField[0]);
			string name = lineField[1];

			studentArray[pos] = ID;						//add each studentID to studentArray
			pos++;										//original position of the student in file, starting at 1
			stIndex = st->Hashing(ID, SIZE);			//get the hash key
			st[stIndex].Add(ID, pos, stIndex, name);	//add the student into hash table

		}
		myfile.close();
	}
	else cout << "Unable to open the file" << endl;

	//uncomment this to print the hash table to the console.
	//for (int i = 0; i < SIZE; i++) {
	//	st[i].printTable();
	//}

	//write all student's info to StudentHashTable.txt
	for (int i = 0; i < SIZE; i++) {
		st[i].WriteToFile(file);
	}
	file.close();

	//display the list of 100 students
	cout << "List of student numbers: " << endl;
	for (int i = 0; i < maxSize; i++) {
		cout << i + 1 << ". " << studentArray[i] << "\t";
		if ((i + 1) % 5 == 0) {
			cout << endl;
		}

	}
	
	//give options to search a student
	int lookUP;
	string confirm = "";
	do {
		bool exception = false;
		while (!exception) {
			cout << "choose a number of student you would like to look up: ";
			cin >> lookUP;								//choose the i(th) student from 1 too 100
			if (lookUP > 0 && lookUP < 101) {
				Search(studentArray[lookUP - 1]);		//then search by its student ID
				exception = true;
				break;
			}
			else {
				cout << "Please choose a number from 1 to 100!\n";
			}
		}
		cout << "would you like to continue (Y/N)?";
		cin >> confirm;
	} while (confirm != "N" && confirm != "n");

	return 0;
}

vector<string> SplitString(string line)
{
	vector<string> lineField;
	//find the first comma to determine the studentID
	//convert string to int to assign for studentID variable
	int pos1 = line.find(",");
	lineField.push_back(line.substr(0, pos1));

	//after the first comma is the first name
	//replace the second comma by a space to get the last name
	int pos2 = line.find(",", pos1 + 1);
	line.erase(pos2, 1);
	line.insert(pos2, " ");
	lineField.push_back(line.substr(pos1 + 1));

	return lineField;
}

int GetSize(ifstream& file)
{
	string line;
	int max = 0;
	if (file.is_open())
	{
		while (getline(file, line)) {
			max++;
		}
		file.close();
	}
	else cout << "Unable to open the file" << endl;

	return max;
}

void Search(int ID)
{
	Student *ptr = NULL;
	int index = ptr->Hashing(ID, SIZE);
	ptr = &st[index];
	bool foundName = false;

	//search studentID in case there are many students have the same hash key
	while (ptr != NULL) {
		if (ptr->studentID == ID) {
			ptr->ToString();
			foundName = true;
		}
		ptr = ptr->next;
	}

	if (foundName == false)
	{
		cout << ID << " does not exist";
	}
}





