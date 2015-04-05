#include "AQueue.h"
#include <assert.h>

template<typename E>
AQueue<E>::AQueue(int s)
{
  size = s+1;
  front = 1;
  rear = 0;
  listArray = new E[size];
}

template<typename E>
AQueue<E>::~AQueue()
{
  delete[] listArray;
}

template<typename E>
void AQueue<E>::clear()
{
  rear = 0;
  front = 1;
}

template<typename E>
void AQueue<E>::enqueue(const E& it)
{
  assert( (rear+2) % size != front );

  rear = (rear+1) % size;
  listArray[rear] = it;
}

template<typename E>
E AQueue<E>::dequeue()
{
  assert( length() != 0 );

  E item = listArray[front];
  front = (front+1) % size;
  return item;
}

template<typename E>
E& AQueue<E>::frontValue() const
{
  return listArray[front];
}

template<typename E> 
int AQueue<E>::length() const 
{
  return ( (rear+size) - front + 1 ) % size;
}
