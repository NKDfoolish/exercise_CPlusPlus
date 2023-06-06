/*
 * @author: Nguyen Khanh Duy - 21522004
 * @Date: 28/03/2023
 * @Topic: Link List
 * @Mode: Share
*/

#include <iostream>
#include <string>
using namespace std;

//declare struct
struct Student {
	string ID;
	string Name;
	float GPA;
	Student* pNext = nullptr;
};

//declare function
Student* createStudent(string id, string name, float gpa);
void addStudent(Student* listStudent, Student* newStudent);
void InputStudent(Student* listStudent);
void InputListStudent(Student* listStudent);
void OutputStudent(Student* student);
void OutputListStudent(Student* listStudent);
void deleteList(Student* listStudent);
void sortList(Student* listStudent);
void countMaxGPAStudent(Student* listStudent);


//run main
int main() {
	bool run = 1;
	Student* listStudent = new Student();

	while (run)
	{
		cout << "========= MENU =========\n";
		cout << "1.Type list of student.\n";
		cout << "2.Show list of student.\n";
		cout << "3.Delete list of student.\n";
		cout << "4.Sort list of student (ASC by ID).\n";
		cout << "5.Quantity of student has the MaxGPA.\n";
		cout << "6.Exit program.\n";
		cout << "========= END ==========\n";

		int choose;
		cout << "Your choose: "; cin >> choose; 
		switch (choose)
		{
		case 1:
			InputListStudent(listStudent);
			break;

		case 2:
			if (listStudent->pNext == nullptr)
			{
				cout << "Empty list!!!\n";
			}
			else {
				OutputListStudent(listStudent);
			}
			break;

		case 3:
			deleteList(listStudent);
			break;

		case 4:
			if (listStudent->pNext == nullptr)
			{
				cout << "Empty list!!!\n";
			}
			else {
				sortList(listStudent);
			}
			break;

		case 5:
			if (listStudent->pNext == nullptr)
			{
				cout << "Empty list!!!\n";
			}
			else {
				countMaxGPAStudent(listStudent);
			}
			break;
			
		case 6:
			return 0;
		}
	}
}

Student* createStudent(string id, string name, float gpa) {
	Student* newStudent = new Student();
	newStudent->ID = id;
	newStudent->Name = name;
	newStudent->GPA = gpa;
	newStudent->pNext = nullptr;
	return newStudent;
}

void addStudent(Student* listStudent, Student* newStudent) {
	Student* pointer = listStudent;
	if (pointer->pNext == nullptr)
	{
		listStudent->pNext = newStudent;
	}
	else {
		while (pointer->pNext != nullptr)
		{
			pointer = pointer->pNext;
		}
		pointer->pNext = newStudent;
	}
}

void InputStudent(Student* listStudent) {
	string ID, Name;
	float GPA;
	cout << "Enter ID of student: ";
	getline(cin, ID);
	cout << "Enter Name of student: ";
	getline(cin, Name);
	cout << "Enter GPA of student: ";
	cin >> GPA;
	cin.ignore();
	Student* newStudent = createStudent(ID, Name, GPA);
	addStudent(listStudent, newStudent);
}

void InputListStudent(Student* listStudent) {
	int n;
	cout << "--- CREATE LIST OF STUDENT ---\n\n";
	cout << "Enter quantity of student in list: "; cin >> n; cin.ignore();
	for (int i = 0; i < n; i++)
	{
		InputStudent(listStudent);
	}
}

void OutputStudent(Student* student) {
	cout << "--------------------\n";
	cout << "Student's ID: " << student->ID << endl;
	cout << "Student's Name: " << student->Name << endl;
	cout << "Student's GPA: " << student->GPA << endl;
	cout << "--------------------\n";
}

void OutputListStudent(Student* listStudent) {
	Student* pointer = listStudent;
	while (pointer->pNext != nullptr)
	{
		pointer = pointer->pNext;
		OutputStudent(pointer);
	}
}

void deleteList(Student* listStudent) {
	Student* pointer = listStudent->pNext;
	while (pointer != nullptr)
	{	
		Student* temp = pointer;
		pointer = pointer->pNext;
		delete temp;
	}
	listStudent->pNext = nullptr;
}

void sortList(Student* listStudent) {
	for (Student* k = listStudent->pNext ; k != nullptr; k = k->pNext)
	{
		for (Student* l = k->pNext; l != nullptr; l = l->pNext) {
			if (l->ID.compare(k->ID) < 0) {
				swap(l->ID, k->ID);
				swap(l->Name, k->Name);
				swap(l->GPA, k->GPA);
			}
		}
	}
}

void countMaxGPAStudent(Student* listStudent) {
	float MaxGPA = listStudent->pNext->GPA;
	float count = 0;
	
	for (Student* k = listStudent->pNext; k != nullptr; k = k->pNext)
	{
		if (k->GPA > MaxGPA) {
			MaxGPA = k->GPA;
		}
	}

	for (Student* l = listStudent->pNext; l != nullptr; l = l->pNext)
	{
		if (l->GPA == MaxGPA) {
			count++;
		}
	}
	cout << "Quantity of student in list has the MaxGPA: " << count << endl;
}