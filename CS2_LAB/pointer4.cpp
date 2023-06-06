#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
	string ID;
	string Name;
	string DOB;
	char Gender;
	float MathScore;
	float PhysicsScore;
	float ChemistryScore;
	float AverageScore;
};

void inputStudent(Student *p) {
	getline(cin, p->ID);
	getline(cin, p->Name);
	getline(cin, p->DOB);
	cin >> p->Gender;
	cin >> p->MathScore;
	cin >> p->PhysicsScore;
	cin >> p->ChemistryScore;
	p->AverageScore = (p->ChemistryScore + p->MathScore + p->PhysicsScore)/3;
}


void outputStudent(Student* p) {
	cout << p->ID << "\t" << p->Name << "\t" << p->DOB << "\t" << p->Gender
		<< "\t" << p->MathScore << "\t" << p->PhysicsScore
		<< "\t" << p->ChemistryScore << "\t" << setprecision(3)<< p->AverageScore;
}

int main() {
	Student* p = new Student;
	inputStudent(p);
	outputStudent(p);

	return 0;
}