#include <stdio.h>

#include <algorithm>
#include <iostream>
using namespace std;

int fun(int x, int n, int *a) {
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (a[mid] <= x) {
            ans = mid;
            left = mid + 1;
        } else
            right = mid - 1;
    }
    return ans;
}
int main() {
    int n;
    while (cin >> n) {
        int *cat = new int[n];
        for (int i = 0; i < n; i++) scanf("%d", &cat[i]);
        sort(cat, cat + n);

        int len = n * (n - 1) / 2;  //中位数应该在的位置
        int rMid = (len + 1) / 2;
        int left = 0;
        int right = cat[n - 1] - cat[0];
        int re;
        while (left <= right) {
            int num = 0;
            int mid = (left + right) / 2;
            for (int i = 0; i < n; i++) {
                int ans = fun(cat[i] + mid, n, cat);
                if (ans != -1) {
                    num += (ans - i);
                }
            }
            if (num >= rMid) {
                re = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << re << endl;
    }
    return 0;
}