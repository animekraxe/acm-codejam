#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int datasets;
    cin >> datasets;
    for(int i = 0; i < datasets; ++i)
    {
        int N;
        cin >> N;
        map <string, set <string> > friends;
        for(int j = 0; j < N; ++j)
        {
            string a, b;
            cin >> a >> b;
            friends[a].insert(b);
            friends[b].insert(a);
        }
        
        map <string, int> friendsOfFriends;
        for(set <string>::iterator it = friends["Marcelo"].begin(); it != friends["Marcelo"].end(); ++it)
        {
            string hisFriend = *it;
            set <string> foafs = friends[hisFriend];
            for(set <string>::iterator it2 = foafs.begin(); it2 != foafs.end(); ++it2)
                ++friendsOfFriends[*it2];
        }
        
        for(map <string, int>::iterator it = friendsOfFriends.begin(); it != friendsOfFriends.end(); )
        {
            if(it->second < 2 || it->first == "Marcelo" || friends["Marcelo"].find(it->first) != friends["Marcelo"].end())
            {
                map <string, int>::iterator it2 = it;
                ++it2;
                friendsOfFriends.erase(it);
                it = it2;
            }
            else
                ++it;
        }
        
        cout << friendsOfFriends.size() << endl;
        for(map <string, int>::iterator it = friendsOfFriends.begin(); it != friendsOfFriends.end(); ++it)
            cout << it->first << endl;
    }

    return 0;
}
