
#include <iostream>
#include <fstream>
using namespace std;

#define maxN 10000

ofstream runavein;
ofstream runaveout;

void generate(int howmany)
{
	int i;
	int temps[maxN];
	double ave;
	int roundave;
	
	for (i = 0; i < howmany; i++)
	{
		temps[i] = (int) 1 + rand() % 100;
		runavein << temps[i] << endl;
	}
	for (i = 3; i < howmany; i++)
	{
		ave = (double) 0.25 * ( temps[i-3] + temps[i-2] + temps[i-1] + temps[i] );
		roundave = ave;
		runaveout << roundave << endl;
	}
}

int main () {

  	runavein.open ("runave.in");
  	runavein << "Writing this to a file.\n";

  	runaveout.open ("runave.out");
  	runaveout << "Writing this to a file.\n";
	runavein << 10 << endl;
	generate(10);
	runavein << 0 << endl;
	runavein.close();	
  	runaveout.close();
  	return 0;
}