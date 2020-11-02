#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
long long a[3];
int main() {
    while (cin >> a[0] >> a[1] >> a[2]) {
        if(a[0]%2==0||a[1]%2==0||a[2]%2==0){
            cout<<"0"<<endl;
            continue;
        }
        sort(a,a+3);
        cout<<a[0]*a[1]<<endl;
    }

    return 0;
}
