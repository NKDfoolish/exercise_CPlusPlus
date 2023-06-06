#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string ID;
	string Name;
	float GPA;
};

void Input(Student*& a, int& n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter your ID: "; getline(cin, a[i].ID);
		cout << "Enter your Name: "; getline(cin, a[i].Name);
		cout << "Enter your GPA: "; cin >> a[i].GPA;
		cin.ignore();
	}
}

void Output(Student* a, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "ID : " << a[i].ID << " Name : " << a->Name << " GPA : " << a->GPA << endl;
	}
}

int main() {
	int n = 0;
	cout << "Enter quantity of student: ";
	cin >> n;
	cin.ignore();
	Student* p = new Student[n];
	Input(p, n);
	Output(p, n);
	delete[] p;
	p = NULL;

	return 0;
}