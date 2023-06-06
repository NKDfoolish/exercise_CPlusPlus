#include <iostream>
using namespace std;

int main() {
	string fullName = "Nguyen Khanh Duy";
	/*int lenName = fullName.length();
	cout << "Lenght of Name : " << lenName;*/

	string fullName_other = "Hoang Cam Ly";
	/*fullName.swap(fullName_other);
	cout << "full_name : " << fullName << endl;
	cout << "full_name other : " << fullName_other << endl;*/

	//cout << fullName_other.compare(fullName);

	string holder = "";
	/*holder = fullName.substr(0, 6);
	cout << holder;*/

	/*cout << fullName.size();*/

	/*fullName.resize(10);
	cout << fullName;*/

	/*holder = fullName.replace(7, 5, "Hoang Hai");
	cout << holder;*/

	//cout << fullName.append(fullName_other);
	//cout << fullName.append("???");

	/*holder = fullName.at(7);
	cout << holder;*/

	string keyword = "Duy";
	/*int result = fullName.find(keyword,0);
	cout << result;*/
	/*int result = fullName.find("Duy");
	cout << result;*/

	/*fullName = "Duuuydhfc";
	int result = fullName.find_first_not_of("Duy");
	cout << result;*/

	/*int result = fullName.find_first_of("Huy");
	cout << result;*/

	/*fullName.insert(7, "Duy");
	cout << fullName;*/
	
	/*fullName.push_back('D');
	cout << fullName;*/

	/*fullName.pop_back();
	cout << fullName;*/

	string temp = "David BackBen";
	/*temp.assign(fullName,7,5);
	cout << fullName << endl;
	cout << temp;*/

	/*char empty[15];
	int len = temp.copy(empty, 4, 6);
	empty[len] = '\0';
	cout << empty;*/

	/*char box[15];
	char source[] = "Duy";
	strcpy_s(box, source);
	cout << box;*/

	/*cout << *temp.begin();*/

	/*temp.back() = 'L';
	cout << temp;*/

	/*fullName.clear();
	cout << fullName;*/

	/*fullName.erase(7, 5);
	cout << fullName;*/

	/*string str = "Hello, World!";
	cout << "String: " << str << endl;

	cout << "First character: " << str.front() << endl;
	cout << "Last character: " << *(str.end() - 1) << endl;*/

	// convert string to char : c_str()

	/*string name = "NKD";
	cout << strlen(name.c_str());*/

	/*fullName_other = fullName;
	cout << fullName_other << endl;
	fullName = "LOL";
	cout << fullName_other << endl;
	cout << fullName << endl;*/


	return 0;
}