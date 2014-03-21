// C.cpp

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> vec;

int main()
{
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vec.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        string s1 = vec[n/2-1], s2 = vec[n/2];
        int i;
        int n1 = s1.length(), n2 = s2.length();
        for (i = 0; i < n1; ++i) {
            if (i >= n2) break;
            if (s1[i] < s2[i]) break;
        }
        string ans;
        if (i < n1) {
            assert(i < n2);
            if (i == n1 - 1) { ans = s1; }
            else {  // diff at earlier than last of s1
                if (s1[i] + 1 == s2[i]) {
                    if (i == n2 - 1) {
                        int j;
                        for (j = i + 1; j < n1; ++j) {
                            if (s1[j] != 'Z') break;
                        }
                        if (j < n1-1) { ans = s1.substr(0, j+1); ans[ans.length()-1]++; }
                        else { ans = s1; }
                    } else { ans = s2.substr(0, i+1); }
                } else {
                    ans = s1.substr(0, i+1); ans[ans.length()-1]++;
                }
            }
        } else { ans = s1; }
        cout << ans << endl;
    }
}
