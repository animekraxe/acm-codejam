#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
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
        
        string partition;
        for(i = 0; i < lower.size(); ++i)
        {
            if(lower[i] == upper[i])
            {
                partition += string(1, lower[i]);
            }
            else if(lower[i] + 1 == upper[i])
            {
                partition += string(1, lower[i]);
                /*
                while(i < lower.size() && lower[i] == 'Z')
                {
                    partition += 'Z';
                    ++i;
                }
                
                if(i < lower.size() - 1)
                {
                    partition += string(1, lower[i] + 1);
                }
                else
                    partition += 'A';
                */
                break;
            }
            else
            {
                partition += string(1, lower[i] + 1);
                break;
            }
        }
        
        cout << partition << endl;
        
        
        /*
        int i = 0;
        set <string>::iterator it = names.begin();
        while(i < names.size() / 2)
        {
            ++i;
            ++it;
        }
        
        string midpoint = *it;
        
        string incremented = midpoint;
        ++incremented[incremented.size() - 1];
        if(incremented[incremented.size() - 1] > 'Z' || names.find(incremented) != names.end())
        {
            incremented = midpoint;
            incremented += 'A';
        }
        
        cout << incremented << endl;
        */
        
        /*
        map <string, int> m_names;
        int i = 0;
        for(set <string>::iterator it = names.begin(); it != names.end(); ++it)
        {
            m_names[*it] = i;
            ++i;
        }
        */
        
        /*
        string partion = "";
        char next = 'A';
        char lower = 'A';
        char upper = 'Z';
        while(true)
        {
            next = (lower + upper) / 2;
            int index = 
        }
        */
    }

    return 0;
}
