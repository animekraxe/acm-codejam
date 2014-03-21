// Fslow.cpp
//
// expect to TLE

#include <iostream>
#include <string>
using namespace std;

bool is_pal(long long n, int len)
{
    int digits[20] = {0};
    int p = 0;
    while (n) {
        digits[p++] = n % 10;
        n /= 10;
    }
    for (int i = 0, j = len-1; i < j; ++i, --j)
        if (digits[i] != digits[j])
            return false;
    return true;
}

long long to_int(const string &s)
{
    long long ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        ans = 10 * ans + s[i] - '0';
    }
    return ans;
}

int main()
{
    string meter;
    while (cin >> meter) {
        if (meter == "0") break;
        int len = meter.length();
        long long val = to_int(meter);
        long long incr = 0;
        while (!is_pal(val, len)) {
            val++; incr++;
        }
        cout << incr << endl;
    }
}
