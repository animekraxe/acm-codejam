/**
 * Sample solution for Balloons
 *   Steven J Zeil, 10/23/2010
 */
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;


struct Team {
  int nBalloons;
  int da;
  int db;
};

bool operator< (const Team& left, const Team& right)
{
  int ld = abs(left.da - left.db);
  int rd = abs(right.da - right.db);
  return ld > rd;
}


/**
 * Process a single dataset for the problem.
 * Return true if successful. Return false if we encounter the
 * end of input marker or an unreocverable I/O error,
 */
bool processDataSet (istream& in)
{
  int N, A, B;
  in >> N;
  if (N == 0)
    return false;

  in >> A >> B;
  
  Team* teams = new Team[N];

  for (int i = 0; i < N; ++i)
    in >> teams[i].nBalloons >> teams[i].da >> teams[i].db;

  // Solve

  sort (teams, teams+N);

  long long total = 0;
  for (int i = 0; i < N; ++i)
    {
      int balloonsFromA;
      int balloonsFromB;
      if (teams[i].da < teams[i].db)
	{
	  balloonsFromA = min(teams[i].nBalloons, A);
	  balloonsFromB = teams[i].nBalloons - balloonsFromA;
	}
      else
	{
	  balloonsFromB = min(teams[i].nBalloons, B);
	  balloonsFromA = teams[i].nBalloons - balloonsFromB;
	}
      long long distA = ((long long)balloonsFromA) * (long long)teams[i].da;
      long long distB = ((long long)balloonsFromB) * (long long)teams[i].db;
      A -= balloonsFromA;
      B -= balloonsFromB;
      total += distA + distB;
    }
  cout << total << endl;

  return true;
}



void balloons (istream& in)
{
	bool finished = false;
	while (!finished)
	{
		finished = !processDataSet(in);
	}
}

int main (int argc, char** argv)
{
	// Program should normally read from standard in. But
	// for debugging purposes, it is sometimes easier to
	// give a file name on the command line.
	if (argc > 1)
	{
		ifstream in (argv[1]);
		balloons (in);
	}
	else
		balloons(cin);

	return 0;
}




