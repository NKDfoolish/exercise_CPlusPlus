#include <iostream>
using namespace std;
int main() {
    int x, * p;
    x = 10;
    
    p = &x;
    *p = 5;

    return 0;
}