#include "Stack.cc"
#include "Link.cc"

template<typename E> class LStack : public Stack<E> {
private:
  Link<E>* top;
  int size;

public:
  LStack()
  {
    size = 0;
    top = NULL;
  }

  ~LStack()
  {
    clear();
  }

  void clear()
  {
    Link<E>* temp;
    while(top != NULL)
      {
	temp = top;
	top = top->next;
	delete temp;
      }
  }

  void push(const E& it)
  {
    top = new Link<E>(it, top);
    size++;
  }

  E pop()
  {
    assert(top != NULL);

    E it = top->element;

    Link<E>* temp = top;
    top = top->next;
    delete temp;
    size--;

    return it;
  }

  const E& topValue() const
  {
    return top->element;
  }

  int length() const
  {
    return size;
  }
};
