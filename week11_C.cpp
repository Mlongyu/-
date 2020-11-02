#include "cstring"
#include "iostream"
using namespace std;
string s, s1;
int main() {
    while (getline(cin, s)) {
        s1 = s;
        for (int i = 0; i < s.size(); i++) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                if (s[i] <= 'E') {
                    s1[i] = 'Z' - 4 + (s[i] - 'A');
                } else {
                    s1[i] = s[i] - 5;
                }

            } else {
                s1[i] = s[i];
            }
        }
        cout << s1 << endl;
    }
}