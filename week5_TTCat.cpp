#include <iostream>
using namespace std;
long long t;
int n, q;
long long city[1000010], a[1000010];
int main() {
    while (cin >> n >> q) {
        for (int i = 0; i < n; i++) {
            cin >> city[i];
        }
        a[0] = city[0];
        for (int i = 1; i < n; i++) {
            a[i] = city[i] - city[i - 1];
        }
        int l, r, c;
        while (q--) {
            cin >> l >> r >> c;
            a[l - 1] += c;
            a[r] -= c;
        }
        cout << a[0] << " ";
        t = a[0];
        for (int i = 1; i < n; i++) {
            t = t + a[i];
            cout << t << " ";
        }
        cout << endl;
    }
}
