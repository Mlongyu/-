#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;

int main() {
    string s;
    int n, ans = -1;
    while (cin >> n >> s) {
        for (int i = 0; i < n; i++)
            if (s[i] > s[i + 1]) {
                ans = i;
                s.erase(i, 1);
                break;
            }
        cout << s << endl;
        /*for (int i = 0; i < n; i++)
            if (i != ans) printf("%c", s[i]);*/
        return 0;
    }
}