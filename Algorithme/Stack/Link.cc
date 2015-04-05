#include <cstdlib>

template<typename E> class Link {
private:
  static Link<E>* freeList;
  
public:
  E element;
  Link* next;

  Link(const E& elem, Link* nextVal = NULL)
  {
    element = elem;
    next = nextVal;
  }

  Link(Link* nextVal = NULL)
  {
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
