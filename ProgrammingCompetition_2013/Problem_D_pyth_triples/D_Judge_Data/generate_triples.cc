#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

#define Max 100000

ofstream triplesin;
ofstream triplesout;
unsigned int dataset[Max];
int nofall;
int noftriples;
int maxnumber;
	
//
// this function generates the input data set with noftriples triples
// and the total of nofall numbers
//

void generate()
{
	int i, j;
	unsigned int u, v, x, y, z, maxuv;
	int a, b;
	
	triplesin << nofall << endl;
	// generate random pythagorean triples
	for (i = 0; i < noftriples; i++)
	{
		maxuv = floor ( sqrt((double)maxnumber/5.0) );
		u = 1+ rand() % maxuv;
		v = 1+ rand() % maxuv;
		x = u*u + 2*u*v;
		dataset[3*i] = x;
		y = 2*v*v + 2*u*v;
		dataset[3*i+1] = y;
		z = u*u + 2*v*v + 2*u*v;
		dataset[3*i+2] = z;
		//cout << x << " " << y << " " << z << endl;
	}	
	//cout << endl;
	
	// generate more random numbers from the range
	
	for ( j = noftriples*3 ; j < nofall ; j++)
	{
		dataset[j] = 1+rand() % maxnumber;
	}
	// permute randomly
	for (i = 0; i < nofall ; i++)
	{
		// two random indices
		a = rand() % nofall;
		b = rand() % nofall;
		// swap
		z = dataset[a];
		dataset[a] = dataset[b];
		dataset[b] = z;
	}
	for (i = 0; i < nofall ; i++)
		triplesin << dataset[i] << endl;
}

// removes duplicate numbers

void cleanup()
{
	int i, nofdups;
	nofdups = 0;
	for (i = 1 ; i < nofall ; i++)
	{
		if (dataset[i] == dataset[i-1])
			++nofdups;
		dataset[i-nofdups] = dataset[i];
	}
	nofall = nofall - nofdups;
}

// finds all pythagorean triples

void findtriples()
{
	int i,j,k;
	long int x,y,z,diff;
	
	for (i = 0; i < nofall-2; i++)
	{
		x = dataset[i];
		j = i+1;
		k = i+2;
		while (k < nofall)
		{
			y = dataset[j];
			z = dataset[k];
			//cout << x << " " << y << " " << z << endl;
			diff = x*x + y*y - z*z;
			if (diff > 0)
				k++;
				else
				{
					if ( x*x + y*y == z*z)
					{
						triplesout << x << " " << y << " " << z << endl;
						//cout << x << " " << y << " " << z << endl;
					}
					j++;
				}
		}
	}
	//cout << endl;
}


int main () {

	srand(time(0));
  	triplesin.open ("triples.in");
	triplesout.open ("triples.out");
	
	noftriples = 10; nofall = 40; maxnumber = 300;
	generate();
	std::sort(dataset,dataset+nofall);
	cleanup();
	findtriples();
	triplesout << endl;

	noftriples = 20; nofall = 100; maxnumber = 9000;
	generate();
	std::sort(dataset,dataset+nofall);
	cleanup();
	findtriples();
	triplesout << endl;

	noftriples = 1000; nofall = 50000; maxnumber = 200000;
	generate();
	std::sort(dataset,dataset+nofall);
	cleanup();
	findtriples();

	triplesin << 0 << endl;
	triplesin.close();	
	triplesout.close();
  	return 0;
}