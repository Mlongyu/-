#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int n, d;
int a[101];
pair<int, int> p[101];
pair<int, int> r[101];
int main() {
    while (cin >> n >> d) {
        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }
        for (int i = 0; i < n; i++) {
            int t = p[i].first;
            while (t < d) {
                t += p[i].second;
            }
            r[i].first = t;
            r[i].second = i;
        }
        sort(r, r + n);
        cout << r[0].second+1 << endl;
        
    }
}