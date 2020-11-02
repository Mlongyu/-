#include "iostream"
using namespace std;
int main() {
    int n, a[1010];
    while (cin >> n) {
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0) {
                if (a[i]!= a[i - 1]) {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}