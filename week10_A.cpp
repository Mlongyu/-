#include "cmath"
#include "iostream"
using namespace std;
long long times, n, target, tot;
int main() {
    while (cin >> n >> target) {
        times = 0;
        if (target % n) {
            cout << "-1" << endl;
            continue;
        } else if (target == n) {
            cout << "0" << endl;
            continue;
        } else {
            tot = target / n;
            while (tot % 3 == 0) {
                times++;
                tot /= 3;
            }
            while (tot % 2 == 0) {
                times++;
                tot /= 2;
            }
            if (tot > 1) {
                cout << "-1" << endl;
            } else {
                cout << times << endl;
            }
            /*double _log = log(tot) / log(2);
            if ((_log - (long long)_log) != 0) {
                cout << "-1" << endl;
                continue;
            } else {
                times += (long long)_log;
                cout << times << endl;
            }*/
        }
    }
}