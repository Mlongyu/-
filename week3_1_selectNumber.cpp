#include <iostream>
#include <vector>
using namespace std;

int T, k, s, n, t;
vector<int> arr;

int solution(vector<int> a, int start, int k, int sum) {
    int length = a.size();
    if (k == 0 && sum == 0) return 1;
    if (k == 0 && sum != 0) return 0;  
    if (start >= length) return 0;
    return solution(a, start + 1, k - 1, sum - a[start]) +
           solution(a, start + 1, k, sum);

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> T >> k >> s;
        for (int i = 0; i < T; i++) {
            cin >> t;
            arr.push_back(t);
        }
        int ans = solution(arr, 0, k, s);
        cout << ans << endl;
        arr.clear();
    }

    return 0;
}