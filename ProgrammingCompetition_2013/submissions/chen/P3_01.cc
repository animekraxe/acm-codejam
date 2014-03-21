#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;



int main()
{
    int n;
    while (cin >> n && n)
    {
        int i;
        vector<string> vs;
        for (i = 0; i < n; i++) {
            string s;
            cin >> s;
            vs.push_back(s);
        }

        sort(vs.begin(), vs.end());

        string s1 = vs[n/2-1] + '$';
        string s2 = vs[n/2] + '$';

        //cout << s1 <<" vs " << s2 << endl;

        vector<char> result;
        for (i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i]) {
                if (s1[i] != '$') {
                    result.push_back(s1[i]+1);
                }
                break;
            } else {
                result.push_back(s1[i]);
            }
        }

        for (i = 0; i < result.size(); i++)
            cout << result[i];
        cout << endl;
    }
    return 0;
}

