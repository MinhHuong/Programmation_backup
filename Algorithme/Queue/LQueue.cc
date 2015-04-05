#include "LQueue.h"
#include <assert.h>

template<typename E>
LQueue<E>::LQueue() 
{
  size = 0;
  front = rear = new Link<E>();
}

template<typename E>
LQueue<E>::~LQueue() 
{
  clear();
  delete front;
}

template<typename E>
void LQueue<E>::clear()
{
  while(front->next != NULL)
    {
      rear = front;
      front = front->next;
      delete rear;
    }
  rear = front;
  size = 0;
}

template<typename E>
void LQueue<E>::enqueue(const E& it)
{
  rear = rear->next = new Link<E>(it, NULL);
  size++;
}

template<typename E>
E LQueue<E>::dequeue() 
{
  assert(size != 0);

  E item = front->next->element;
  Link<E>* temp = front->next;
  front = front->next;
  if(front == rear) rear = front;
  delete temp;
  size--;

  return item;
}

template<typename E>
E& LQueue<E>::frontValue() const
{
  assert(size != 0);
  return front->next->element;
}

template<typename E>
int LQueue<E>::length() const
{
  return size;
}
