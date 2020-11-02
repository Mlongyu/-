#include "iostream"
using namespace std;
double n, k;
int main() {
    while (cin >> n >> k) {
        int cnt = 1;
        double tot = n;
        double price = 200.00;
        while (cnt <= 20) {
            price *= (1 + k * 0.01);
            tot += n;
            cnt++;
            if (price <= tot) {
                cout << cnt << endl;
                break;
            }
        }
        if (cnt > 20) {
            cout << "Impossible" << endl;
        }
    }
}