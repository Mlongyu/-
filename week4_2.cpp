#include "iostream"
using namespace std;
int dayNum;
int n ;
int a[100001];
int main() {
    while (cin >> dayNum) {
        n=0;
        for (int i = 0; i < dayNum; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < dayNum; i++) {
            if (a[i] <= n) {
                n -= a[i];
            } else {
                a[i] -= n;
                n = 0;
                if (a[i] % 2)  //奇数
                {
                    n++;
                }
            }
        }
        if (n > 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}