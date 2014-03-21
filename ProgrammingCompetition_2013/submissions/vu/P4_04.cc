#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


vector<bool> count_sort(vector<unsigned int> & v)
{
	vector<bool> b(200000, false);
	vector<unsigned int> v2;
	unsigned int size = v.size();
	for(unsigned int i = 0; i < size; ++i)
	{
		b[v[i]] = true;
	} 
	
	return b;
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
	unsigned int m, n, a, b, c, n2, m2;
	unsigned int nmax = static_cast<unsigned int> (sqrt(200000)) + 1;
	vector<bool> bools = count_sort(s);
	for(n = 2; n < nmax; ++n)
	{
		n2 = n * n;
		for(m = 1; m < n; ++m)
		{
			m2 = m * m;
			a = n2 - m2;
			b = 2 * m * n;
			c = n2 + m2;
			
			if(bools[a] && bools[b] && bools[c])
			{
				sort3(a, b, c);
				cout << a << ' ' << b << ' ' << c << endl;
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
