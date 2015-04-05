#ifndef LQUEUE_H
#define LQUEUE_H

#include "Queue.h"
#include "Link.cc"

template<typename E> class LQueue : public Queue<E> {
 private:
  int size;
  Link<E>* front;
  Link<E>* rear;

 public:
  LQueue();

  ~LQueue();

  virtual void clear();

  virtual void enqueue(const E&);

  virtual E dequeue();

  virtual E& frontValue() const;

  virtual int length() const;
};

#endif
