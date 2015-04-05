#include "Stack.cc"

template<typename E> class AStack : public Stack<E> {
private:
  int maxSize;
  int top;
  E* listArray;
  static const int defaultSize = 20;
  
public:
  AStack(int max = defaultSize)
  {
    maxSize = max;
    listArray = new E[maxSize];
    top = 0;
  }

  ~AStack()
  {
    delete[] listArray;
  }

  void clear()
  {
    top = 0;
  }

  void push(const E& it)
  {
    assert(top != maxSize); // if Stack is full
    
    listArray[top] = it;
    top++;
  }

  E pop()
  {
    assert(top != 0); // Stack is empty
    
    return listArray[--top];
  }

  const E& topValue() const
  {
    assert(top != 0);

    return listArray[top-1];
  }

  int length() 
  {
    return top;
  }
};
