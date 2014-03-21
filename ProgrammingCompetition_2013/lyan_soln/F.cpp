// F.cpp
//
// two pointers, left and right
// if more than 2 char, make right equal to left
// else make a[n/2-1] and a[n/2] equal to the max of the two

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

long long to_int(const string &s)
{
    long long ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}

int main()
{
    string meter, next;
    while (cin >> meter) {
        if (meter == "0") break;
        next = meter;

        int i, j;
        long long start = to_int(meter);
        int carry = 0;
        i = 0; j = next.size()-1;
        while (i < j) {
            if (next[j] > next[i]) { carry = 1; }
            else if (next[j] < next[i]) { carry = 0; }
            next[j] = next[i];
            i++; j--;
        }
        if (carry) {
            int n = meter.size();
            i = (n-1)/2, j = n/2;
            while (i >= 0) {
                if (next[i] < '9') { next[i]++; if (i != j) next[j]++; break; }
                next[i] = next[j] = '0';
                i--; j++;
            }
        }
        long long ans = to_int(next);
        assert(ans >= start);
        cout << ans - start << endl;
    }
}

// Accepted
