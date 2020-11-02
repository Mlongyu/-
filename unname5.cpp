#include "algorithm"
#include "cstring"
#include "iostream"

using namespace std;
int n;
pair<int, pair<string, string>> p[100001];

void deal() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ; i++) {
            p[i].
        }
    }
}
bool cmp() {}
int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            pair<string, string> s;
            string s1, s2;
            cin >> s1 >> s2;
            s = make_pair(s1, s2);
            p[i] = make_pair(i, s);
        }
        deal();
        sort(p, p + n, cmp);
    }
}