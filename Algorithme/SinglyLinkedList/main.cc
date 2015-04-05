#include "LList.cc"
#include <assert.h>

template<typename E>
void sortedMergedList(LList<E> L1, LList<E> L2, LList<E>& result)
{
  L1.moveToStart();
  L2.moveToStart();

  while(L1.length() != 0 && L2.length() != 0)
    {
      if(L1.getValue() > L2.getValue()) 
	{
	  result.append(L2.remove());
	}
      else
	{
	  result.append(L1.remove());
	}
    }

  while(L1.length() != 0)
    {
      result.append(L1.remove());	
    }
  
  while(L2.length() != 0)
    {
      result.append(L2.remove());	
    }
}

using namespace std;

int main()
{
  LList<int> IntList1;
  LList<int> IntList2;

  IntList1.append(5);
  IntList1.append(10);
  IntList1.append(11);
  IntList1.append(20);
  IntList1.append(20);

  IntList1.print();
  IntList2.append(5);
  IntList2.append(8);
  IntList2.append(9);
  IntList2.append(13);
  IntList2.append(13);
  IntList2.append(14);
  IntList2.print();

  LList<int> IntListRes;
  sortedMergedList(IntList1, IntList2, IntListRes);
  IntListRes.print();

  return 0;
}
