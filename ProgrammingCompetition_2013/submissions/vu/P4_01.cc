#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> count_sort(vector<unsigned int> & v)
{
	vector<bool> b(200000, false);
	vector<unsigned int> v2;
	unsigned int size = v.size();
	for(unsigned int i = 0; i < size; ++i)
	{
		b[v[i]] = true;
	} 
	
	for(unsigned int i = 0; i < 200000; ++i)
	{
		if(b[i]) v2.push_back(i);
	}
	return v2;
}

void funct(vector<unsigned int> s, unsigned int N)
{	
	unsigned int stop = N-2;
	unsigned int i = 0;
	for(;i < stop; ++i)
	{
		for(unsigned int j = i +1; j < N-1; ++j)
		{
			for(unsigned int k = j +1; k < N; ++k)
				if((s[i] * s[i])+(s[j] *s[j]) == s[k] * s[k])
				cout << s[i] << ' ' <<  s[j] << ' ' << s[k] << endl; 
		}
	}
}

int main()
{
		vector<unsigned int> N;
		vector< vector<unsigned int> > s;
		unsigned int n, x;
		while(cin >> n && n != 0)
		{
		N.push_back(n);
		vector<unsigned int> v;
		for(unsigned int i = 0; i < n; ++i)
		{
			cin >> x;
			v.push_back(x);
		}
		 s.push_back(v);
		}
		
		
		unsigned int size =s.size();
		for(unsigned int i = 0; i < size; ++i)
		{
			funct(count_sort(s[i]), N[i]);
			if(i != size -1)cout << endl;
		}
		return 0;
}
