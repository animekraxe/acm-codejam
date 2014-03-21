// G.cpp

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
using namespace std;

typedef pair<int,int> pii;

int main()
{
    int N, A, B;
    int K[1005], DA[1005], DB[1005];
    pii teams[1005];
    while (cin >> N >> A >> B) {
        if (N == 0) break;
        for (int i = 0; i < N; ++i) {
            cin >> K[i] >> DA[i] >> DB[i];
            teams[i] = pii(DB[i] - DA[i], i);
        }
        sort(teams, teams+N);
        // use B as from begin to end
        int ans = 0;
        int idx = 0;
        while (idx < N && B > 0) {
            int diff = teams[idx].first;
            int pos = teams[idx].second;
            int demand = K[pos];
            if (diff > 0) break;
            if (B >= demand) {
                ans += demand * DB[pos];
                B -= demand; K[pos] -= demand; idx++;
            } else {
                ans += B * DB[pos];
                K[pos] -= B; B = 0;
            }
        }
        // use A from end to begin
        for (idx = N-1; idx >= 0; --idx) {
            int pos = teams[idx].second;
            int demand = K[pos];
            if (A >= demand) {
                ans += demand * DA[pos];
                A -= demand; K[pos] -= demand;
            } else {
                ans += A * DA[pos];
                K[pos] -= A; A = 0;
                break;
            }
        }
        // use B if still teams
        for (idx = N-1; idx >= 0; --idx) {
            int pos = teams[idx].second;
            int demand = K[pos];
            assert(B >= demand);
            ans += demand * DB[pos];
            B -= K[pos];
        }
        cout << ans << endl;
    }
}
