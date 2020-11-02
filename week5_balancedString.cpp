#include <iostream>
#include <string>
using namespace std;
string s;
int sumQ, sumW, sumE, sumR;
int ans = 100000;
int main() {
    while (cin >> s) {
        sumQ = 0, sumW = 0, sumE = 0, sumR = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == 'Q')
                sumQ++;
            else if (s[i] == 'W')
                sumW++;
            else if (s[i] == 'E')
                sumE++;
            else if (s[i] == 'R')
                sumR++;
        }

        if (sumQ == sumW && sumW == sumE && sumE == sumR)  //当前已经平衡,结束
        {
            cout << "0" << endl;
            continue;
        }
        int left = 0, right = 0;
        while (right <= len - 1) {
            //计算l,r之间的QWER个数
            int sumQQ = 0, sumWW = 0, sumEE = 0, sumRR = 0;
            for (int i = left; i <= right; i++) {
                if (s[i] == 'Q')
                    sumQQ++;
                else if (s[i] == 'W')
                    sumWW++;
                else if (s[i] == 'E')
                    sumEE++;
                else if (s[i] == 'R')
                    sumRR++;
            }
            sumQQ = sumQ - sumQQ;
            sumWW = sumW - sumWW;
            sumEE = sumE - sumEE;
            sumRR = sumR - sumRR;
            int max = 0;
            if (sumQQ > max) max = sumQQ;
            if (sumWW > max) max = sumWW;
            if (sumEE > max) max = sumEE;
            if (sumRR > max) max = sumRR;
            int total = right - left + 1;
            int free = total - ((max - sumQQ) + (max - sumWW) + (max - sumEE) +
                                (max - sumRR));
            //满足要求的
            if (free >= 0 && free % 4 == 0) {
                if (total < ans) ans = total;
                if (left == right) {
                    left++;
                    right++;
                } else
                    left++;
            } else
                right++;
        }
        cout << ans << endl;
        s.clear();
    }
}
