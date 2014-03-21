/**
 *  party Games sample solution
 *  Steven Zeil, Old Dominion University
 *   9/28/2012
 **/

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

string toUC (string s)
{
  for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] >= 'a' && s[i] <= 'z')
	s[i] += 'A' - 'a';
    }
  return s;
}


string bump (string s)
{
  int i = 0;
  while (i < s.size() && s[i] == 'Z')
    ++i;
  if (i + 1 < s.size())
    {
      ++(s[i]);
      return s.substr(0, i+1);
    }
  else
    {
      return s;
    }
}

string findSeparator (string name1, string name2)
{
  int match = 0;
  // See how many characters match
  while (match < name1.size() && match < name2.size()
	 && name1[match] == name2[match]) {
    ++match;
  }
  string result = name1;
  if (match + 1 >= name1.size())
    // Made it to the end of name1
    return name1;
  else
    {
      // Stopped inside name1 (and within name2, because name1 < name2)
      char diff1 = name1[match];
      char diff2 = name2[match];
      if (diff1 + 1 < diff2)
	{
	  // If the 1st differing characters are more than 1 apart, we 
	  //   can construct a string of length match+1
	  // E.g. comparing ABCD to ABFG, the desired answer
	  //   is AB + ('C'+1) => ABD
	  ++diff1;  //Note: ++ is safe - diff1 could not be 'Z' 
	            // because diff2 > diff1
	  return name1.substr(0, match) + diff1;
	} else {
	// This is where it gets messy. The first two differing 
	// characters are just one position apart,
	// e.g., AAB... vs AAC... or A... vs B...
	
	if (match + 1 < name2.size())
	  return name2.substr(0, match+1);
	else if (match + 2 == name1.size())
	  {
	    return name1;
	  }
	else
	  {
	    string part1 = name1.substr(0, match+1);
	    string remainder1 = name1.substr(match+1); // must be non-empty
	    remainder1 = bump(remainder1);
	    return part1 + remainder1;
	  }
      }
    }
}

  void solve (int N, istream& in)
  {
    vector<string> names;
    for (int i = 0; i < N; i++)
      {
        string name;
        in >> name;
        name = toUC(name);
        names.push_back (name);
      }
    sort (names.begin(), names.end());

    int mid = names.size() / 2;
    cout << findSeparator(names[mid-1], names[mid]) << endl;
  }

void partyGames (istream& in)
{
  int N;
  in >> N;
  while (N > 0)
    {
      solve(N, in);
      in >> N;
    }
}




// Accept input from standard in or from a file
// named as a command paramter.
int main (int argc, char** argv)
{
  if (argc == 1)
    partyGames(cin);
  else
    {
      ifstream in (argv[1]);
      partyGames (in);
    }
}
