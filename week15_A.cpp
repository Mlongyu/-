#include <cstring>
#include <iostream>
#include <map>
using namespace std;
map<int, string> mpr;
map<int, string> mpl;
int n;
const int seed = 11;
int func(string &p) {
    int ans = 0;
    int len = p.length() - 1;
    int tmp = seed;
    for (int i = 0; i < len; i++) {
        if (p[i] != ' ') {
            ans += p[i] * tmp;
            tmp *= seed;
        }
    }
    return ans;
}
string s;
string tl;
string tr;
int main() {
    while (getline(cin, s)) {
        if (s == "@END@") break;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ']') {
                tl = s.substr(0, i + 1);
                tr = s.substr(i + 2, s.length());
                mpl.insert(pair<int, string>(func(tl), tr));
                mpr.insert(pair<int, string>(func(tr), tl));
                break;
            }
        }
    }
    cin >> n;
    string f;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, f);
        if (mpr.find(func(f)) != mpr.end()) {
            string tmp;
            tmp = mpr[func(f)];
            int len = tmp.length() - 1;
            for (int j = 1; j < len; j++) cout << tmp[j];
            cout << endl;
        } else if (mpl.find(func(f)) != mpl.end())
            cout << mpl[func(f)] << endl;
        else
            cout << "what?" << endl;
    }
    return 0;
}