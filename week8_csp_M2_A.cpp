#include "algorithm"
#include "cmath"
#include "iostream"
using namespace std;
long long t, n;
long long a[10001];

int main() {
    while (cin >> t) {
        for (long long ii = 0; ii < t; ii++) {
            long long cha[10];
            bool c1, c2, c3;
            c1 = false;
            c2 = false;
            c3 = false;
            cin >> n;
            for (long long i = 0; i < n; i++) {
                cin >> a[i];
            }
            cha[0] = a[0];
            bool NO = false;
            c1 = true;
            for (int i = 1; i < n; i++) {
                if (c1 && !c2 && !c3) {
                    if (a[i] != cha[0]) {
                        cha[1] = a[i];
                        c2 = true;
                    }
                } else if (c1 && c2 && !c3) {
                    if (a[i] != cha[0] && a[i] != cha[1]) {
                        cha[2] = a[i];
                        c3 = true;
                        sort(cha, cha + 3);
                        long long flag = cha[0] + cha[2] - cha[1] * 2;
                        if (flag != 0) {
                            cout << "NO" << endl;
                            NO = true;
                            break;
                        }
                    }
                } else if (c1 && c2 && c3) {
                    if (a[i] != cha[0] && a[i] != cha[1] && a[i] != cha[2]) {
                        cout << "NO" << endl;
                        NO = true;
                        break;
                    }
                }
            }
            if (!NO) {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}