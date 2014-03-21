#include <iostream>
#include <vector>
using namespace std;

void average(vector<unsigned int> v, int N)
{
	unsigned int g = 4;
	unsigned int rtotal, h;
	unsigned int t = N-3;
	for(unsigned int j = 0; j < t; ++j, rtotal = 0)
	{
		h = j + g;
		for(unsigned int i = j; i < h; ++i)
		{
			rtotal += v[i];
		}
		cout << rtotal/g << endl;
	}
}

int main()
{
	unsigned int n, x;
	vector< vector<unsigned int> > m;
	vector< unsigned int > N;
	while(cin >> n && n != 0)
	{
		N.push_back(n);
		vector <unsigned int> v;
		for(unsigned int i = 0; i < n; ++i)
		{
			cin >> x;
			v.push_back(x);
		}
		m.push_back(v);
	}
	unsigned int size = N.size();
	for(unsigned int i = 0; i < size; ++i)
	{
		average(m[i], N[i]);
		if(i != size -1)cout << endl;
	}
	
}
