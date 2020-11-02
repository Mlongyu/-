#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int n;
string s;
int main() {
    while (cin >> n) {
        int sz = n;
        cin >> s;
        int cnt=0;
        //cout<<s[0]<<endl<<s[1]<<endl;
        for (int i = 0; i < sz - 1; i++) {
            if (i% 2 == 0) {
                //cout<<s[i]<<" "<<s[i+1]<<endl;
                if (s[i] == s[i + 1]) {
                    s.erase(i+1, 1);
                    i--;
                    sz--;
                    cnt++;
                }
            }
        }
        if (sz%2)
        {
            s.erase(sz-1,1);
            cnt++;
        }
        
        cout<<cnt<<endl<<s<<endl;
    }
}