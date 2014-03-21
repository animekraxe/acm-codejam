#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define MAXSIZE 1010

struct Person {
    string name;
    set<int> friends;
}people[MAXSIZE];


int n, gid;
map<string, int> dict;

void init()
{
    gid = 0;
    dict.clear();
    for (int i = 0; i < MAXSIZE; i++)
        people[i].friends.clear();
}

int getid(string name)
{
    if (dict.find(name) == dict.end()) {
        dict[name] = ++gid;
        people[gid].name = name;
    }
    return dict[name];
}

int main ()
{
    int kase;
    cin >> kase;
    while (kase--) {
        int i, marcelo;
        init();
        string a, b;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a >> b;
            int aid = getid(a);
            int bid = getid(b);
            //cout << a << aid << " " << b << bid << endl;
            people[aid].friends.insert(bid);
            people[bid].friends.insert(aid);
            if (a == "Marcelo") marcelo = aid;
            else if (b == "Marcelo") marcelo = bid;
        }

        vector<string> result;

        for (i = 1; i <= gid; i++) {
            int cnt = 0;
            if (people[i].name != "Marcelo" && people[i].friends.find(marcelo) == people[i].friends.end()) {
                //cout << people[i].name << i << " : ";
                int flag = 0;
                for (set<int>::iterator iter = people[i].friends.begin(); 
                        iter != people[i].friends.end(); iter++)
                {
                    int id = *iter;
                    //cout << id << " ";
                    if (people[id].friends.find(marcelo) != people[id].friends.end())
                        cnt++;
                    if (people[marcelo].friends.find(id) == people[marcelo].friends.end())
                        flag = 1;
                }
                //cout << endl;
                if (cnt >= 2 ) result.push_back(people[i].name);
            }
        }

        sort(result.begin(), result.end());
        cout << result.size() << endl;
        for (i = 0; i < result.size(); i++)
            cout << result[i] << endl;
    }
    return 0;
}

