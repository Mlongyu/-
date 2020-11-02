#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

deque<long long> q;
long long n, k;

int main() {
    std::ios::sync_with_stdio(false);
    while (~scanf("%lld %lld", &n, &k)) {  //忘了加"~"
        vector<int> a(n);
        for (long long i = 0; i < n; i++) scanf("%d", &a[i]);

        for (long long i = 0; i < k - 1; i++)  //先放进去前k-1个
        {
            while (!q.empty() && a[q.back()] > a[i]) q.pop_back();
            q.push_back(i);
        }
        for (long long i = k - 1; i < n; i++) {
            while (!q.empty() && a[q.back()] > a[i]) q.pop_back();
            q.push_back(i);
            if (i - q.front() + 1 > k) q.pop_front();
            printf("%d ", a[q.front()]);
        }
        q.clear();
        cout << endl;
        for (long long i = 0; i < k - 1; i++)  //先放进去前k-1个
        {
            while (!q.empty() && a[q.back()] < a[i]) q.pop_back();
            q.push_back(i);
        }
        for (long long i = k - 1; i < n; i++) {
            while (!q.empty() && a[q.back()] < a[i]) q.pop_back();
            q.push_back(i);
            if (i - q.front() + 1 > k) q.pop_front();
            printf("%d ", a[q.front()]);
        }
        cout << endl;
    }
}