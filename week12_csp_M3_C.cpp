#include "cstring"
#include "iostream"

using namespace std;
string s;
int main() {
    long long n, ct = 0, last = 0, num = 0;
    while (cin >> n) {
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (i && s[i] != s[i - 1])  
            {
                num += ct; 
                ct = 0;
                last = i;
            } else if (last)
            {
                num++;
            }
            ct++;
        }
        long long sum = n * (n - 1) / 2;
        cout<<sum-num<<endl;
        ct = 0, last = 0, num = 0;
    }

    return 0;
}