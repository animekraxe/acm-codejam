/**
 * Sample solution for Balloons
 *   Steven J Zeil, 10/23/2010
 */
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

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



void odometer (istream& in)
{
  string start;
  in >> start;
  while (start != "0")
    {
      string stop = start;

      // Squeeze in from both ends of the number
      int high = 0;
      int low = start.size()-1;
      while (high < low)
	{
	  if (stop[high] == stop[low])
	    {
	      // Digits match, (e.g., 1021) squeeze tighter
	      ++high;
	      --low;
	    }
	  else
	    {
	      // Corresponding digits do not match
	      if (stop[low] < stop[high])
		{
		  // We can bump up the low digit to match without
		  // carries into the higher digits
		  // e.g.,  5023 => 5025
		  stop[low] = stop[high];
		  ++high;
		  --low;
		}
	      else
		{
		  // If we try bumping up the lower digit, we will have to
		  // go past 0 and then carry into the higher digits
		  // e.g.,  2995 will be advanced to 3000 and we'll then
		  // start over at the outermost digits
		  stop[low] = 0;
		  for (int i = low-1; i >=0; --i)
		    {
		      if (stop[i] == '9')
			stop[i] = '0';
		      else
			{
			  stop[i] = stop[i] + 1;
			  break;
			}
		    }
		  high = 0;
		  low = stop.size() - 1;
		}
	    }
	}
      
      
      long long startV, stopV;
      istringstream numbers (start + " " + stop);
      numbers >> startV >> stopV;
      cout << stopV-startV << endl;

      in >> start;
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
		odometer (in);
	}
	else
		odometer(cin);

	return 0;
}




