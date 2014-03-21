#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

int main()
{
    while(true)
    {
        int N;
        cin >> N;
        if(N == 0) break;
        
        set <string> names;
        for(int i = 0; i < N; ++i)
        {
            string name;
            cin >> name;
            names.insert(name);
        }
        
        
        int i = 0;
        set <string>::iterator it = names.begin();
        while(i < names.size() / 2)
        {
            ++i;
            ++it;
        }
        --it;
        
        string lower = *it;
        ++it;
        string upper = *it;
        
        unsigned originalUpperSize = upper.size();
        
        while(upper.size() < lower.size())
            upper += string(1, 'Z' + 1);
        
        string partition;
        for(i = 0; i < lower.size(); ++i)
        {
            if(lower[i] == upper[i])
            {
                partition += string(1, lower[i]);
            }
            else if(lower[i] + 1 == upper[i])
            {
                if(i == lower.size() - 1)
                    partition += string(1, lower[i]);
                else
                {
                    partition += string(1, lower[i]);
                    ++i;
                    while(i < lower.size() && lower[i] == 'Z')
                    {
                        partition += string(1, 'Z');
                        ++i;
                    }
                    if(i < lower.size() - 1)
                        partition += string(1, lower[i] + 1);
                    else if(i == lower.size() - 1)
                        partition += string(1, lower[i]);
                }

                break;
            }
            else
            {
                if(i == lower.size() - 1)// && i < originalUpperSize - 1)
                    partition += string(1, lower[i]);
                else
                    partition += string(1, lower[i] + 1);
                break;
            }
        }
        
        cout << partition << endl;
        
        /*
        names.insert(partition);
        it = names.begin();
        for(i = 0; i < names.size(); ++i)
        {
            if(*it == partition) break;
            ++it;
        }
        ++i;
        assert(i == (names.size() + 1) / 2);
        */
    }

    return 0;
}
