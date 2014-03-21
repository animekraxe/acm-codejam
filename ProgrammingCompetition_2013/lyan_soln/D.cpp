// D.cpp

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int64;

const int N = 100000;
int a[N+5];
int64 b[N+5];

int main()
{
    int n;
    bool first = true;
    while (cin >> n) {
        if (n == 0) break;
        //cout << "n = " << n << endl;
        for (int i=0; i<n; ++i) {
            cin >> a[i];
        }
        sort(a, a+n);
        n = unique(a, a+n) - a;

        for (int i=0; i<n; ++i) {
            b[i] = (int64)a[i] * a[i];
        }

        if (!first) cout << endl;
        first = false;
        for (int k=0; k<n; ++k) {  // try x from low to high
            int i=k+1, j=i+1;
            while (j < n) {
                if (b[j] - b[i] == b[k]) {
                    cout << a[k] << ' ' << a[i] << ' ' << a[j] << endl;
                    ++i; ++j;
                } else if (b[j] - b[i] > b[k]) { ++i; }
                else { ++j; }
            }
        }
    }
}

