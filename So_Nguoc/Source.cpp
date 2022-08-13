#include <iostream>
using namespace std;
int main() {
    int max = 0;
    int sds;
    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            int so = i * j;
            int temp = so;
            sds = 0;
            while (temp) {
                sds = sds * 10 + temp % 10;
                temp /= 10;
            }
            if (sds == so) {
                if (max < sds) max = sds;
            }
        }
    }
    cout << "\nSo nguoc max: " << max;
}