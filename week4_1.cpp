#include "iostream"
#include "cmath"
#include "cstring"
using namespace std;
string s;
string a="a";
string str;
int main() {
    while (cin >> s)
    {
         str=a+s;
    int sum = 0;
    int length = str.size();
    for (int i = 1; i < length; i++) {
        int t1 = abs(str[i] - str[i - 1]);
        if (t1 < 13) {
            sum += t1;
        } else {
            sum += 26 - t1;
        }
    }
    cout<<sum<<endl;
    }
}
