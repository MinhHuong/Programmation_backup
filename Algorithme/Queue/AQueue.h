#ifndef AQUEUE_H
#define AQUEUE_H

#include "Queue.h"

template<typename E> class AQueue : public Queue<E> {
 private:
  int size;
  int front;
  int rear;
  E* listArray;
  static const int defaultSize = 20;

 public:
  AQueue(int s = defaultSize);
  
  ~AQueue();

  virtual void clear();

  virtual void enqueue(const E&);

  virtual E dequeue();

  virtual E& frontValue() const;

  virtual int length() const;
};

#endif
