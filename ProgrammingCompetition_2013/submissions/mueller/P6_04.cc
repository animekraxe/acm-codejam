#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class SortFunctor
{
public:
    bool operator()(const std::pair <int, int>& p1, const std::pair <int, int>& p2) const
    {
        return p1.first < p2.first;
    }
};

int main()
{
    while(true)
    {
        int N, A, B;
        
        cin >> N >> A >> B;
        if(N == 0 && A == 0 && B == 0)
            break;
        if(N == 0)
            continue;
        
        vector <pair <int, int> > data;
        
        for(int i = 0; i < N; ++i)
        {
            int n, a, b;
            cin >> n >> a >> b;
            for(int j = 0; j < n; ++j)
                data.push_back(pair <int, int>(a, b));
        }
        
        vector <pair <int, int> > advantageA;
        for(unsigned i = 0; i < data.size(); ++i)
            advantageA.push_back(pair <int, int>(data[i].second - data[i].first, i));
        sort(advantageA.begin(), advantageA.end(), SortFunctor());
        
        int positive_index = 0;
        for(; positive_index < advantageA.size(); ++positive_index)
            if(advantageA[positive_index].first > 0)
                break;
        
        int numAs = advantageA.size() - positive_index;
        int numBs = positive_index;
        
        int answer = 0;
        
        if(A >= numAs && B >= numBs)
        {
            for(unsigned i = 0; i < data.size(); ++i)
                answer += min(data[i].first, data[i].second);
        }
        else if(A >= numAs)
        {
            int i;
            for(i = 0; i < B && advantageA[i].first < 0; ++i)
            {
                answer += data[advantageA[i].second].second;
            }
            for(; i < advantageA.size(); ++i)
            {
                answer += data[advantageA[i].second].first;
            }
        }
        else
        {
            int i;
            for(i = 0; i < A && advantageA[advantageA.size() - i - 1].first > 0; ++i)
            {
                answer += data[advantageA[advantageA.size() - i - 1].second].first;
            }
            for(; i < advantageA.size(); ++i)
            {
                answer += data[advantageA[advantageA.size() - i - 1].second].second;
            }
        }
        
        cout << answer << endl;
    }

    return 0;
}
