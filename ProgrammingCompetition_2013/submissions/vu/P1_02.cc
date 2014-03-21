#include <iostream>
#include <vector>
using namespace std;

void average(vector<uint> v, int N)
{
	uint g = 4;
	uint rtotal, h;
	uint t = N-3;
	for(uint j = 0; j < t; ++j, rtotal = 0)
	{
		h = j + g;
		for(uint i = j; i < h; ++i)
		{
			rtotal += v[i];
		}
		cout << rtotal/g << endl;
	}
}

int main()
{
	uint n, x;
	vector< vector<uint> > m;
	vector< uint > N;
	while(cin >> n && n != 0)
	{
		N.push_back(n);
		vector <uint> v;
		for(uint i = 0; i < n; ++i)
		{
			cin >> x;
			v.push_back(x);
		}
		m.push_back(v);
	}
	uint size = N.size();
	for(uint i = 0; i < size; ++i)
	{
		average(m[i], N[i]);
		if(i != size -1)cout << endl;
	}
	
}
