#include <iostream>
#include <string>
using namespace std;


string insert(string str, string ch, int position) {
    string start = str.substr(0, position);
    string end = str.substr(position, str.length());
    return start + ch + end;
}


int isSubstring(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (s2[i + j] != s1[j]) {
                break;
            }
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}

string processString() {
    string s1, s2;
    int holder;
    string outPut = "";

    cout << "Nhap tu khoa: ";
    getline(cin, s1);

    do
    {
        cout << "Nhap ten sach: ";
        getline(cin, s2);
        outPut = outPut + "\n" + s2;
    } while (s2 != ".");
    
    int lensub = s1.length();
    holder = isSubstring(s1, outPut);
    outPut = insert(outPut, "[", holder);
    int holder_2 = lensub + holder + 1;
    outPut = insert(outPut, "]", holder_2);

    while (true)
    {
        string s3 = outPut.substr(0, holder_2 + 1);
        string s4 = outPut.substr(holder_2 + 1, outPut.length());
        int holder_3 = isSubstring(s1, s4);

        if (holder_3 == -1) {
            break;
        }

        s4 = insert(s4, "[", holder_3);
        s4 = insert(s4, "]", holder_3 + lensub + 1);
        outPut = s3 + s4;
        int temp_holder = holder_2 + holder_3 + 1;
        holder_2 = temp_holder + lensub + 1;
    }

    return outPut;
}

int main() {

    cout << processString();

    return 0;
}