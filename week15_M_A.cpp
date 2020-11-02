#include "algorithm"
#include "iostream"
using namespace std;
int n, a[100001];
pair<int, int> x[100001];
int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> x[i].first;
            x[i].second = i;
        }
        sort(x, x + n);
        for (int i = 0; i < n; i++) {
            cout << x[i].second +1<< " ";
        }
        cout << endl;
    }
}