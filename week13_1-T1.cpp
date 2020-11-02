#include "cstring"
#include "iostream"
using namespace std;
string s;
int n;
int main() {
    while (cin >> n) {
        cin >> s;
        int cnt = 0;
        char str[n];
        str[0] = s[0];
        for (int i = 0; i < n; i++) {
            if ((1 + i) * i / 2 > n) {
                break;
            }
            str[i] = s[(1 + i) * i / 2];
            cnt=i;
        }
        for (int i = 0; i < cnt; i++) {
            cout << str[i];
        }
        cout << endl;
    }
}