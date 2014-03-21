#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define LL long long

string str;
int glen;

LL vint2ll(vector<int> s)
{
    LL sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum = sum * 10 + s[i];
    return sum;
}

void ll2vint(LL x, vector<int> &v)
{
    v.clear();
    while (x) {
        v.push_back(x % 10);
        x /= 10;
    }
    int nlen = v.size();
    for (int i = 0; i < glen - nlen; i++)
        v.push_back(0);

    int len = v.size();
    for (int i = 0; i < len / 2; i++) {
        int tmp = v[i];
        v[i] = v[len-1-i];
        v[len-1-i] = tmp;
    }
}

LL powten(int x)
{
    LL res = 1;
    while (x--)
        res *= 10;
    return res;
}

int isPal(vector<int> v)
{
    int len = v.size();
    for (int i = 0; i < len / 2; i++)
        if (v[i] != v[len-1-i])
            return 0;
    return 1;
}

void str2vint(string &s, vector<int> &v)
{
    for (int i = 0; i < s.size(); i++)
        v.push_back(s[i] - '0');
}

int main()
{
    while (cin>>str) {
        vector<int> v;
        LL ans = 0;
        str2vint(str, v);
        glen = str.size();

        //cout << "glen = " << glen << endl;

        if (vint2ll(v) == 0) break;

        while (true) {
            int i;
            int len = v.size();
            if (isPal(v)) break;

            /*
            for (i = 0; i < len; i++)
                cout << v[i];
            cout << endl;
            */

            for (i = 0; i < len/2; i++)
            {
                int x = v[i];
                int y = v[len-1-i];
                int tmp;
                if (x == y) continue;
                if (x < y) {
                    tmp = x+10-y;
                } else {
                    tmp = x-y;
                }
                tmp = powten(i) * tmp;
                //cout << "tmp = " << tmp << endl;
                ans += tmp;
                LL xx = vint2ll(v);
                xx += tmp;
                ll2vint(xx, v);
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}

