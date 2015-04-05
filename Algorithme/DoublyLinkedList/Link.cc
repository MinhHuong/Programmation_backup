#include <iostream>
#include <cstdlib>

template<typename E> class Link {
private:
  static Link<E>* freeList;
  
public:
  E element;
  Link<E>* prev;
  Link<E>* next;

  Link(const E& elem, Link<E>* prevVal, Link<E>* nextVal)
  {
    element = elem;
    prev = prevVal;
    next = nextVal;
  }

  Link(Link<E>* prevVal = NULL, Link<E>* nextVal = NULL)
  {
    prev = prevVal;
    next = nextVal;
  }

  void* operator new(size_t) 
  {
    if(freeList == NULL)
      {
	return ::new Link;
      }
    
    Link<E>* temp = freeList;
    freeList = freeList->next;
    return temp;
  }

  void operator delete(void* ptr)
  {
    Link<E>* node = (Link<E>*)ptr;
    node->next = freeList;
    freeList = node;
  }

};

template<typename E> 
Link<E>* Link<E>::freeList = NULL;
