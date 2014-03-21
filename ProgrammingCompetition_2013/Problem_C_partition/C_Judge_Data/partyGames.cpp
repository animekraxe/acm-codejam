/**
 *  party Games sample solution
 *  Steven Zeil, Old Dominion University
 *   9/13/2012
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
  string name1 = names[mid-1];
  string name2 = names[mid];
  int match = 0;
  while (match < name1.size() && match < name2.size()
	 && name1[match] == name2[match]) {
    ++match;
  }
  if (match < name1.size())
    {
      char c = name1[match];
      ++c;
      name1[match] = c;
      name1 = name1.substr(0, match+1);
    }
  else
    {
      char c = name1[match-1];
      ++c;
      name1[match-1] = c;
    }
  cout << name1 << endl;
}


void partyGames (istream& in)
{
  int N;
  cin >> N;
  while (N > 0)
    {
      solve(N, in);
      cin >> N;
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
