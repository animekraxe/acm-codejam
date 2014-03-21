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
        int i, diffi = -1;
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
                diffi = i;
                if (s1[i] != '$') {
                    if (s1[i+1] == '$') {
                        result.push_back(s1[i]);
                    }
                    else {
                        result.push_back(s1[i]+1);
                    }
                }
                break;
            } else {
                result.push_back(s1[i]);
            }
        }

        string tmp;
        for (i = 0; i < result.size(); i++)
            tmp.push_back(result[i]);
        tmp.push_back('$');

        //cout << "tmp = " << tmp << "s2 = " << s2 << endl;

        if (tmp == s2) {
            if (s1[diffi+1] != '$' && s1[diffi+2] == '$') {
                cout << vs[n/2-1] << endl;
            } else {
                string s = vs[n/2-1] + '$';
                int chk = 0;
                if (s[diffi+1] != 'Z') {
                    s[diffi+1] += 1;
                    for (i = 0; i < diffi+2; i++)
                        cout << s[i];
                    cout << endl;
                } else {
                    while (s[diffi+1]=='Z') {
                        diffi++;
                    }
                    //    cout << "lalalala    diffi = " << diffi << endl;
                    if (s[diffi+1] == '$') {
                        cout << vs[n/2-1] << endl;
                    } else {
                        if (s[diffi+2] != '$')
                            s[diffi+1] += 1;
                        for (i = 0; i < diffi+2; i++)
                            cout << s[i];
                        cout << endl;
                    }
                }
            }
        } else {
            for (i = 0; i < result.size(); i++)
                cout << result[i];
            cout << endl;
        }
    }
    return 0;
}

