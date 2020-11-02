#include "cstring"
#include "iostream"
using namespace std;
long long a;
/*long long root( long long  n )
{
    while( n > 9 )
        n = n%10 + n/10;
    return n;
}*/

int temp;
char num[1001];
int fun(int num) {
    while (num != 0) {
        temp += num % 10;
        num /= 10;
    }
    if (temp >= 10) {
        num = temp;
        temp = 0;
        fun(num);
    }
    return temp;
}
int main() {
    while (cin >> num) {
        /*long long temp = 0;
        while (a >= 10) {
            temp = 0;
            while (1) {
                temp += a % 10;
                a /= 10;
                if (a == 0) {
                    break;
                }
            }
            a = temp;
        }*/
        // cout << root(a)<< endl;
        temp = 0;
        int i = 0;
        int length = strlen(num);
        while (i < length) {
            temp = fun(num[i] - '0');
            i++;
        }

        cout << temp << endl;
    }
}