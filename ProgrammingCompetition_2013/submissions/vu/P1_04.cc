#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;


pair< vector<bool>, vector<unsigned int> > count_sort(vector<unsigned int> & v)
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
	
	return make_pair(b, v2);
}



void sort3(unsigned int & a, unsigned int & b,unsigned int & c)
{
	vector <unsigned int> v;
	v.push_back(a); v.push_back(b); v.push_back(c);
	sort(v.begin(), v.end());
	a = v[0]; b = v[1]; c = v[2];
	 
}

void funct2(vector<unsigned int > s, unsigned int N)
{
	unsigned int a,a2, b2,  b, c;

	pair< vector<bool>, vector<unsigned int> > p  = count_sort(s);
	vector<bool> bools = p.first;
	vector<unsigned int> v = p.second;
	unsigned int size = v.size();
	unsigned int size2 = size -1;
	for(unsigned int i = 0; i < size2; ++i)
	{
		a = v[i];
		a2 = a * a;
		for(unsigned int j = i+1; j < size; ++j)
		{
			b = v[j];
			b2 = b * b;
			c = (unsigned int) sqrt(a2 + b2);
			if(c * c == b2 + a2)
			{
				if(bools[c])
				{
					sort3(a, b, c);
					cout << a << ' ' << b << ' ' << c << endl;	
				}
			}
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
			funct2(s[i], N[i]);
			if(i != size -1)cout << endl;
		}
		
	
		
		return 0;
}
