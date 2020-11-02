#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int n;
int cnt[15];
int tot = 0;
struct card {
    string name;
    int sum, key;
    int key1, key2, key3, key4, key5;
    bool operator<(card p);
} cards[100001];

bool card::operator<(card p) {
    if (key != p.key)
        return key > p.key;  //牌型比较
    else {
        switch (key) {
            case 8:
            case 1:
            case 7:
                if (sum != p.sum)
                    return sum > p.sum;
                else
                    return name < p.name;
            case 2:
                if (key1 != p.key1)
                    return key1 > p.key1;
                else {
                    if (sum != p.sum)
                        return sum > p.sum;
                    else
                        return name < p.name;
                }
            case 3:
                if (key1 != p.key1)
                    return key1 > p.key1;
                else {
                    if (key2 != p.key2)
                        return key2 > p.key2;
                    else {
                        if (sum != p.sum)
                            return sum > p.sum;
                        else
                            return name < p.name;
                    }
                }
            case 4:
                if (key3 != p.key3)
                    return key3 > p.key3;
                else {
                    if (sum != p.sum)
                        return sum > p.sum;
                    else
                        return name < p.name;
                }
            case 5:
                if (key3 != p.key3)
                    return key3 > p.key3;
                else {
                    if (key4 != p.key4)
                        return key4 > p.key4;
                    else
                        return name < p.name;
                }
            case 6:
                if (key5 != p.key5)
                    return key5 > p.key5;
                else {
                    if (sum != p.sum)
                        return sum > p.sum;
                    else
                        return name < p.name;
                }
        }
    }
}
void add(string name, string str) {
    card p;
    memset(cnt, 0, sizeof(cnt));
    int size = str.size();
    int t;
    int sum = 0, key = 1, key1 = 0, key2 = 0, key3 = 0, key4 = 0, key5 = 0;
    int max = -1, min = 15;
    for (int i = 0; i < size; ++i) {
        t = 0;
        switch (str[i]) {
            case '0':
                t = 0;
                break;
            case '1':
                t = 10;
                cnt[t]++;
                break;
            case 'A':
                t = 1;
                cnt[t]++;
                break;
            case 'J':
                t = 11;
                cnt[t]++;
                break;
            case 'Q':
                t = 12;
                cnt[t]++;
                break;
            case 'K':
                t = 13;
                cnt[t]++;
                break;
            default:
                t = str[i] - '0';
                cnt[t]++;
                break;  // 2~9
        }
        sum += t;
        if (t) {
            switch (cnt[t]) {
                case 2:
                    if (key1)
                        key2 = t;
                    else
                        key1 = t;
                    break;
                case 3:
                    if (key1 == t) {
                        key1 = 0;
                        key3 = t;
                    } else {
                        key2 = 0;
                        key3 = t;
                    }
                    break; 
                case 4:
                    key3 = 0;
                    key5 = t;
                    break;
            }
            if (t > max) max = t;
            if (t < min) min = t;
        }
    }
    if (key5)
        key = 6;
    else if (key3) {
        key4 = (key1 == 0) ? key2 : key1;
        if (key4) {
            key1 = key2 = 0;
            key = 5;
        } else
            key = 4;
    } else if (key1 || key2) {
        if (key1 && key2) {
            key = 3;
            if (key1 < key2) swap(key1, key2);
        } else {
            key1 = key1 > 0 ? key1 : key2;
            key = 2;
        }
    } else if ((max - min) == 4) {
        key = 7;
    } else if (cnt[1] && cnt[10] && cnt[11] && cnt[12] && cnt[13]) {
        key = 8;
    } else
        key = 1;
    p.key = key;
    p.key1 = key1;
    p.key2 = key2;
    p.key3 = key3;
    p.key4 = key4;
    p.key5 = key5;
    p.name = name;
    p.sum = sum;
    cards[tot] = p;
    ++tot;
}
int main() {
    string s1, s2;
    while (cin >> n) {
        tot = 0;
        while (n--) {
            cin >> s1 >> s2;
            add(s1, s2);
        }
        sort(cards, cards + tot);
        for (int i = 0; i < tot; ++i) cout << cards[i].name << endl;
    }
    return 0;
}