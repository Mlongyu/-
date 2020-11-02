#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct poke  //扑克牌的牌面
{
    char num;
    char color;
};

//各个人的牌
vector<poke> north;
vector<poke> east;
vector<poke> south;
vector<poke> west;
map<char, int> m;
map<char, int> mm;

bool cmp(poke a, poke b) {
    if (a.color == b.color) {
        if ((isdigit(a.num) && isdigit(b.num)) ||
            (isdigit(a.num) && isalpha(b.num)) ||
            (isdigit(b.num) && isalpha(a.num)))
            return a.num < b.num;
        else if (isalpha(a.num) && isalpha(b.num))
            return m[a.num] < m[b.num];
    } else {
        return mm[a.color] < mm[b.color];
    }
}
poke set[52];
int main() {
    char dir;
    string str1, str2, str;
    m['T'] = 1, m['J'] = 2, m['Q'] = 3, m['K'] = 4, m['A'] = 5;
    mm['C'] = 1, mm['D'] = 2, mm['S'] = 3, mm['H'] = 4;
    while (cin >> dir) {
        if (dir == '#') break;
        for (int i = 0; i < 52; i++) {
            cin >> set[i].color >> set[i].num;
        }
        east.clear(), north.clear(), south.clear(), west.clear();
        /*
        cin >> str1 >> str2;
        str = str1 + str2;*/
        if (dir == 'N')  //如果是N发牌，则派牌的顺序是ESWN下面的则照顺时针推出
        {
            for (int i = 0; i < 52; i++) {
                if (i % 4 == 0)
                    east.push_back(set[i]);
                else if (i % 4 == 1)
                    south.push_back(set[i]);
                else if (i % 4 == 2)
                    west.push_back(set[i]);
                else if (i % 4 == 3)
                    north.push_back(set[i]);
            }
        } else if (dir == 'W') {
            for (int i = 0; i < 52; i++) {
                if (i % 4 == 0)
                    north.push_back(set[i]);
                else if (i % 4 == 1)
                    east.push_back(set[i]);
                else if (i % 4 == 2)
                    south.push_back(set[i]);
                else if (i % 4 == 3)
                    west.push_back(set[i]);
            }
        } else if (dir == 'E') {
            for (int i = 0; i < 52; i++) {
                if (i % 4 == 0)
                    south.push_back(set[i]);
                else if (i % 4 == 1)
                    west.push_back(set[i]);
                else if (i % 4 == 2)
                    north.push_back(set[i]);
                else if (i % 4 == 3)
                    east.push_back(set[i]);
            }
        } else if (dir == 'S') {
            for (int i = 0; i < 52; i++) {
                if (i % 4 == 0)
                    west.push_back(set[i]);
                else if (i % 4 == 1)
                    north.push_back(set[i]);
                else if (i % 4 == 2)
                    east.push_back(set[i]);
                else if (i % 4 == 3)
                    south.push_back(set[i]);
            }
        }

        sort(south.begin(), south.end(), cmp);
        sort(west.begin(), west.end(), cmp);
        sort(north.begin(), north.end(), cmp);
        sort(east.begin(), east.end(), cmp);
        cout << "South player:" << endl;
        cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
        for (int i = 0; i < 13; i++)
            cout << "|" << south[i].num << " " << south[i].num;
        cout << "|" << endl;
        for (int i = 0; i < 13; i++) cout << "| " << south[i].color << " ";
        cout << "|" << endl;
        for (int i = 0; i < 13; i++)
            cout << "|" << south[i].num << " " << south[i].num;
        cout << "|" << endl;
        cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
        cout << "West player:" << endl;
        cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
        for (int i = 0; i < 13; i++)
            cout << "|" << west[i].num << " " << west[i].num;
        cout << "|" << endl;
        for (int i = 0; i < 13; i++) cout << "| " << west[i].color << " ";
        cout << "|" << endl;
        for (int i = 0; i < 13; i++)
            cout << "|" << west[i].num << " " << west[i].num;
        cout << "|" << endl;
        cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
        cout << "North player:" << endl;
        cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
        for (int i = 0; i < 13; i++)
            cout << "|" << north[i].num << " " << north[i].num;
        cout << "|" << endl;
        for (int i = 0; i < 13; i++) cout << "| " << north[i].color << " ";
        cout << "|" << endl;
        for (int i = 0; i < 13; i++)
            cout << "|" << north[i].num << " " << north[i].num;
        cout << "|" << endl;
        cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
        cout << "East player:" << endl;
        cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
        for (int i = 0; i < 13; i++)
            cout << "|" << east[i].num << " " << east[i].num;
        cout << "|" << endl;
        for (int i = 0; i < 13; i++) cout << "| " << east[i].color << " ";
        cout << "|" << endl;
        for (int i = 0; i < 13; i++)
            cout << "|" << east[i].num << " " << east[i].num;
        cout << "|" << endl;
        cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
        cout << endl;
    }

    // system("pause");
}

/*
N
CTCAH8CJD4C6D9SQC7S5HAD2HJH9CKD3H6D6D7H3HQH4C5DKHKS9
SJDTS3S7S4C4CQHTSAH2D8DJSTSKS2H5D5DQDAH7C9S8C8S6C2C3
#
*/