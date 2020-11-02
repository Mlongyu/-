#include "iostream"
using namespace std;
long long T, n, k;

int main() {
    while (cin >> T) {
        while (T--) {
            cin >> n >> k;
            long long t = n * k / (n - 1);
            if (t % n == 0)
                cout << t - 1 << endl;
            else
                cout << t << endl;
        }
    }
}
