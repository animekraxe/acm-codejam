#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int N;
        cin >> N;
        if(N == 0) return 0;
    while(true)
    {
        
        
        int first, second, third, fourth;
        if(N == 1)
        {
            cin >> first;
            break;
        }
        else if(N == 2)
        {
            cin >> first >> second;
            break;
        }
        else if(N == 3)
        {
            cin >> first >> second >> third;
            break;
        }
        cin >> first >> second >> third >> fourth;
        
        N -= 4;
        int ave = (first + second + third + fourth) / 4;
        cout << ave << endl;
        while(N > 0)
        {
            first = second;
            second = third;
            third = fourth;
            cin >> fourth;
            --N;
            ave = (first + second + third + fourth) / 4;
            cout << ave << endl;
        }
        
        cin >> N;
        if(N == 0) break;
        cout << endl;
    }

    return 0;
}
