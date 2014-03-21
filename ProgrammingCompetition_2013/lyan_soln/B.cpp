// B.cpp

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;

map<string, set<string> > adj;
set<string> names;

void solve()
{
    int E; cin >> E;
    names.clear(); adj.clear();
    for (int i = 0; i < E; ++i) {
        string a, b;
        cin >> a >> b;
        names.insert(a); names.insert(b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    string root = "Marcelo";
    vector<string> friends;
    for (set<string>::const_iterator it = names.begin();
        it != names.end(); ++it) {
        string candidate = *it;
        if (root == candidate || adj[root].count(candidate))
            continue;
        int cnt = 0;
        for (set<string>::const_iterator it2 = names.begin();
            it2 != names.end(); ++it2) {
                string person = *it2;
                if (adj[root].count(person) && adj[candidate].count(person))
                    cnt++;
            }
        if (cnt >= 2) friends.push_back(candidate);
        }
    sort(friends.begin(), friends.end());
    cout << friends.size() << endl;
    for (int i = 0; i < friends.size(); ++i) {
        cout << friends[i] << endl;
    }
}

int main()
{
    int T; cin >> T;
    while (T--)
        solve();
}
