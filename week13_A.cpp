#include <iostream>
using namespace std;
long long n, k, T;

int main() {
    while (cin >> T) {
        while (T--) {
            cin >> n >> k;

            if ((n - k + 1) % 2 == 1 && n - k + 1 > 0) {
                cout << "YES" << endl;
                for (int i = 1; i <= k - 1; i++) cout << "1 ";
                cout << n - k + 1 << endl;

            } else if ((n - 2 * k + 2) % 2 == 0 && n - 2 * k + 2 > 0) {
                cout << "YES" << endl;
                for (int i = 1; i <= k - 1; i++) cout << "2 ";
                cout << n - 2 * k + 2 << endl;

            } else
                cout << "NO" << endl;
        }
    }
}
