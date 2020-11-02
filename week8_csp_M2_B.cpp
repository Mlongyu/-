#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    cin >> str;
    bool visited[26] = {false};
    long long location[26];
    long long _left = 0, _right = -1;
    long long len = str.size();
    for (long long i = 0; i < len; i++) {
        if (visited[str[i] - 'A'] == true) {
            for (long long j = _left; j < location[str[i] - 'A']; j++) {
                visited[str[j] - 'A'] = false;
            }
            _left = location[str[i] - 'A'] + 1;
            location[str[i] - 'A'] = i;
        }
        if (str[i] == '?') {
            if ((i - _left + 1) == 26) {
                _right = i;
                break;
            } else
                continue;
        } else {
            visited[str[i] - 'A'] = true;
            location[str[i] - 'A'] = i;
        }
        if ((i - _left + 1) == 26) {
            _right = i;
            break;
        }
    }
    if (_right == -1)
        cout << -1;
    else {
        long long now = 0;
        for (long long i = _left; i <= _right; i++) {
            if (str[i] == '?')
                for (long long j = now; j < 26; j++) {
                    if (visited[j] == false) {
                        cout << (char)(j + 'A');
                        now = j + 1;
                        break;
                    }
                }
            else
                cout << str[i];
        }
    }
    str.clear();
}
