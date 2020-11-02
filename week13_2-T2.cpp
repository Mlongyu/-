#include "iostream"
using namespace std;
int main() {
    int n, i, j, k, t, a[5001], m = 0;
    while (cin >> n >> k) {
        for (i = 1; i <= n; i++) {
            t = 0;
            for (j = 1; j <= k; j++) {
                if (i % j == 0) t++;
            }
            if (t % 2 == 1) {
                a[m] = i;
                m++;
            }
        }
        for (i = 0; i < m - 1; i++) cout << a[i]<<',';
        cout << a[i] << endl;
    }
}