#include <iostream>
#include <cstdlib>
#include <string>

#define LENGTH 2*1000000
#define MAX 100000

using namespace std;

struct round
{
  int num;      // 1 or 2
  string input; // digits or characters
};

void checkLimitString(string s)
{
  if(s.size() > LENGTH) 
    {
      cout << "Your string has passed the limit ! Program exits !" << endl;
      exit(-1);
    }
}

void checkLimitAmount(int nb, string type)
{
  if(nb < 1 || nb > MAX)
    {
      cout << "Invalid amount of " << type << " ! Program exits !" << endl;
      exit(-1);
    }
}

bool isSubString(string org, string comp)
{
  return ( org.find(comp) != string::npos );
}

int main()
{
  /********** Number of barbarians **********/
  int nbBarb;
  cin >> nbBarb; checkLimitAmount(nbBarb, "barbarians");

  /********** The word of each barbarian **********/
  string barbWords[nbBarb];
  cin.ignore();
  for(int i = 0 ; i < nbBarb ; i++)
    {
      getline(cin, barbWords[i]); checkLimitString(barbWords[i]);
    }

  /********** Number of rounds **********/
  int nbRound;
  cin >> nbRound; checkLimitAmount(nbRound, "rounds");
 
  /********** Input for each row **********/
  int nbTarzanWord = 0;
  round roundTab[nbRound];
  cin.ignore();
  for(int i = 0 ; i < nbRound ; i++)
    {
      cin >> roundTab[i].num;
      if(roundTab[i].num == 1) nbTarzanWord++;

      cin >> roundTab[i].input; checkLimitString(roundTab[i].input);
    }

  /********** Play game, print the results **********/
  string tarzanWords[nbTarzanWord];
  int j = 0;
  int numBarb;
  int cpt = 0;
  for(int i = 0 ; i < nbRound ; i++)
    {
      if(roundTab[i].num == 1)
	{
	  tarzanWords[j] = roundTab[i].input;
	  j++;
	}

      if(roundTab[i].num == 2)
	{
	  numBarb = atoi( (roundTab[i].input).c_str() ); // string to int
	  
	  for(int m = 0 ; m < j ; m++)
	    {
	      if(isSubString(tarzanWords[m], barbWords[numBarb-1])) cpt++;
	    }

	  cout << cpt << endl;
	  cpt = 0;
	}
    }
  
  
  return EXIT_SUCCESS;
}
