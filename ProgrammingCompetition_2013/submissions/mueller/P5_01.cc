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
        string s;
        cin >> s;
        stringstream ss(s);
        long long value;
        ss >> value;
        if(value == 0) break;
        
        long long count = 0;
        
        string left = s.substr(0, s.size() / 2);
        string left_rev = left;
        reverse(left_rev.begin(), left_rev.end());
        string right = s.substr(s.size() / 2 + s.size() % 2);
        string middle = "";
        if(s.size() % 2 == 1)
            middle = string(1, s[s.size() / 2 + 1]);
        
        //cout << "Debug 1: " << left << ' ' << left_rev << ' ' << right << ' ' << middle << endl;
        
        while(true)
        {
        
            long long left_value, left_rev_value, right_value;
            ss.clear();
            ss.str(left);
            ss >> left_value;
            ss.clear();
            ss.str(left_rev);
            ss >> left_rev_value;
            ss.clear();
            ss.str(right);
            ss >> right_value;
            
            //cout << "Debug: " << left_value << ' ' << left_rev_value << ' ' << right_value << endl;
        
            if(left_rev_value >= right_value)
            {
                cout << count + left_rev_value - right_value << endl;
                break;
            }
            else
            {
                right = string(right.size(), '0');
                string limit_s = string("1") + right;
                ss.clear();
                ss.str(limit_s);
                long long limit;
                ss >> limit;
                
                count += limit - right_value;
                
                bool carry = false;
                if(middle != "")
                {
                    if(middle[0] == '9')
                    {
                        middle[0] = '0';
                        carry = true;
                    }
                    else
                        ++middle[0];
                }
                else
                    carry = true;
                
                if(carry)
                    ++left_value;
                
                ss.clear();
                ss.str("");
                ss << left_value;
                left = ss.str();
                if(left.size() < right.size())
                    left = string(right.size() - left.size(), '0') + left;
                
                left_rev = left;
                reverse(left_rev.begin(), left_rev.end());
            }
        }
    }

    return 0;
}
