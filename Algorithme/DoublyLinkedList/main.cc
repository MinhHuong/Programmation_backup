#include "LList.cc"

using namespace std;

int main()
{
  int size = 10;
  LList<int> IntList(size);
  for(int i = 0 ; i < size ; i++)
    {
      IntList.append(i+1);
    }
  IntList.print();

  cout << IntList.currPos() << endl;
  IntList.moveToPos(5);
  cout << IntList.currPos() << endl;
  cout << IntList.getValue() << endl;

  return EXIT_SUCCESS;
}
