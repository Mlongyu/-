#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int n, ind, t;
int main() {
    cin >> t;
    while (scanf("%d%d",&n,&ind)!=EOF) {
        string a(n, 'a');
        a[n - 2] = a[n - 1] = 'b';
        long long ct = 0, sum = 0;
        while (1) {
            ct++;
            sum = ct * (ct + 1) / 2;//爆int会死循环然后TLE
            if (sum >= ind) {
                break;
            }
        }
        swap(a[n - 2], a[n - 2 - ct + 1]);
        swap(a[n-1],a[n - 2 - ct + 1+sum-ind+1]);
        cout<<a<<endl;
        a.clear();
    }
}