#include <cstring>
#include <iostream>
using namespace std;

int t, n;
int a[710];
int _gcd[710][710], l[710][710], r[710][710], f[710][710];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void init() {
    memset(a, 0, sizeof(a));
    memset(_gcd, 0, sizeof(_gcd));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(f, 0, sizeof(f));
}
void init1() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (gcd(a[i], a[j]) > 1) {
                _gcd[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        l[i][i] = 1;
        r[i][i] = 1;
        f[i][i] = 1;
    }
}
int main() {
    while (cin >> t) {
        for (int ii = 1; ii <= t; ii++) {
            cin >> n;
            init();
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
            }
            init1();

            for (int i = n; i >= 1; i--) {
                for (int rr = i; rr <= n; rr++) {
                    for (int k = i; k <= rr; k++) {
                        if (l[i][k] == 1 && r[k][rr] == 1) {
                            f[i][rr] = 1;
                            if (_gcd[k][rr + 1]) {
                                l[i][rr + 1] = 1;
                                f[i][rr + 1] = 1;
                            }
                            if (_gcd[i - 1][k]) {
                                r[i - 1][rr] = 1;
                                f[i - 1][rr] = 1;
                            }
                        }
                    }
                }
            }

            if (f[1][n])
                cout << "Yes\n";
            else
                cout << "No\n";
            system("pause");
        }
    }

    return 0;
}
