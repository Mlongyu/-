#include "cmath"
#include "iostream"
using namespace std;
int q;
int a[501];

int getFirstLen(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (i + 1) * 9 * pow(10, i);
    }
    ans += (n + 1)
    return ans;
}
int getReg(int a1,int max){

}
void get(int target) {
    int lv = log10(target);
    int startLv = pow(10, lv);
    int len1 =getFirstLen(start)

}
int main() {
    while (cin >> q) {
        for (int i = 0; i < q; i++) {
            cin >> a[i];
            get(a[i]);
        }
    }
    return 0;
}