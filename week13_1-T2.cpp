#include "cmath"
#include "cstring"
#include "iostream"
using namespace std;
double n, x, y, r;
double cost;
int main() {
    while (cin >> n) {
        cost = 0;
        for (double i = 0; i < n; i++) {
            cin >> x >> y >> r;
            cost += sqrt(x * x + y * y) * 2 / 50 + r * 1.5;
        }
        cout << ceil(cost) << endl;
    }
}