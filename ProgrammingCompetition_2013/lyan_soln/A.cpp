// A.cpp

#include <deque>
#include <iostream>
using namespace std;

int main()
{
    int n;
    bool first = true;
    while (cin >> n) {
        if (n == 0) break;
        if (!first) cout << endl;
        deque<int> dq;
        int sum = 0;
        for (int i=0; i<4; ++i) {
            int v; cin >> v;
            dq.push_back(v);
            sum += v;
        }
        cout << sum / 4 << endl;
        for (int i=4; i<n; ++i) {
            int v; cin >> v;
            sum -= dq.front(); dq.pop_front();
            sum += v; dq.push_back(v);
            cout << sum / 4 << endl;
        }
        first = false;
    }
}
