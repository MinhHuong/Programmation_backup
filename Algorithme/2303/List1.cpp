
//
//  List1.cpp
//  List
//
//  Created by Nguyen Hua Phung on 2/4/15.
//  Copyright (c) 2015 Nguyen Hua Phung. All rights reserved.
//

#include <iostream>

using namespace std;

class IntList {
public:
  virtual ~IntList() {}
    
  virtual void clear() = 0;
  virtual int length() const = 0;
  virtual void print() = 0;
  
  virtual void moveToStart() = 0;
  virtual void moveToEnd() = 0;
  virtual void moveForward() = 0;
  virtual void moveBackward() = 0;

  virtual int getValue() const = 0;
  virtual void insert(int val) = 0;
    
  virtual bool append(const int val) = 0;

  virtual void reverse() = 0;
  virtual void remove() = 0;
};

class ArrayIntList : public virtual IntList {
protected:
  int * arr;
  int maxSize;
  int listSize;
  int curr;
  static const int MAXSIZE = 50;

public:
  ArrayIntList() {
    arr = new int[MAXSIZE];
    maxSize = MAXSIZE;
    listSize = 0;
    curr = 0;
    //std::cout << "create arrar_int_list\n";
  }
  virtual ~ArrayIntList() {
    //std::cout << "delete array_int_list\n";
    delete [] arr;
  }
    
  virtual void clear() {
    listSize = 0;
  }
  virtual int length() const {
    return listSize;
  }
  virtual void print() {
    for (int i = 0; i < listSize; i++) {
      std::cout << arr[i] << '\n';
    }
  }
  virtual bool append(const int val) {
    if(listSize == maxSize) return false;
    arr[listSize] = val;
    listSize++;
    return true;
  }

  virtual void moveForward()
  {
    if(curr == listSize-1) cout << "Already at end of List" << endl;
    else
      curr++;
  }

  virtual void moveBackward()
  {
    if(curr == 0) cout << "Already at head" << endl;
    else
      curr--;
  }

  virtual void moveToStart()
  {
    curr = 0;
  }

  virtual void moveToEnd()
  {
    curr = listSize;
  }

  virtual int getValue() const
  {
    if(curr == listSize) cout << "No value" << endl;
    else
      return arr[curr];
  }

  virtual void insert(int val) 
  {
    if(listSize == maxSize) cout << "List full" << endl;
    else
      {
	for(int i = listSize ; i > curr ; i--)
	  {
	    arr[i] = arr[i-1];
	  }
	arr[curr] = val;
	listSize++;
      }
  }
   
  void swap(int x, int y)
  {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
  }
  
  virtual void reverse()
  {
    int curr2 = listSize-1;
    
    while(curr <= curr2)
      {
	swap(curr, curr2);
	curr++;
	curr2--;
      }

      /*
    for(int i = 0 ; i < listSize/2 ; i++)
      {
	swap(i, listSize-1-i);
	}*/
  }

  virtual void remove()
  {
    if(listSize != 0)
      {
	for(int i = curr ; i < listSize-1 ; i++)
	  {
	    arr[i] = arr[i+1];
	  }
	listSize--;
      }
  }
};

//
//  List2.cpp
//  List
//
//  Created by Nguyen Hua Phung on 3/23/15.
//  Copyright (c) 2015 Nguyen Hua Phung. All rights reserved.
//


class ElementIntList {
private:
  int value;
  ElementIntList * next;
public:
  ElementIntList(ElementIntList * nextEle = NULL) {
    next = nextEle;
  }
  ElementIntList(int val,ElementIntList * nextEle = NULL) {
    value = val;
    next = nextEle;
  }
  ~ElementIntList() {}
  void setValue(int val) {
    value = val;
  }
  int getValue() {
    return value;
  }
  void setNext(ElementIntList * nextEle) {
    next = nextEle;
  }
  ElementIntList * getNext() {
    return next;
  }
};

class LinkedIntList : public virtual IntList {
private:
  ElementIntList * head;
  ElementIntList * last;
  ElementIntList * curr;
  int listSize;
public:
  LinkedIntList() {
    head = last = curr = new ElementIntList();
    listSize = 0;
  }
  ~LinkedIntList() {
    clear();
    delete head;
  }
  virtual void clear() {
    ElementIntList * tmp = head -> getNext();
    while (tmp != NULL) {
      ElementIntList * ttmp = tmp -> getNext();
      delete tmp;
      tmp = ttmp;
    }
    head -> setNext(NULL);
    curr = last = head;
    listSize = 0;
  }
  virtual int length() const {
    return listSize;
  }
  virtual void print() {
    ElementIntList * tmp = head -> getNext();
    while (tmp != NULL) {
      std::cout << tmp -> getValue() << '\n';
      tmp = tmp -> getNext();
    }
  }
  virtual bool append(const int val) {
    last -> setNext (new ElementIntList(val));
    last = last->getNext();
    listSize++;
    return true;
  }

  virtual void moveToStart() 
  {
    curr = head;
  }

  virtual void moveToEnd() 
  {
    curr = last;
  }

  virtual void moveForward() 
  {
    if(curr != last) curr = curr -> getNext();
    else cout << "Curr at end" << endl;
  }
  
  virtual void moveBackward() 
  {
    ElementIntList * temp = head;

    if(curr != head)
      {
	while(temp -> getNext() != curr)
	  {
	    temp = temp->getNext();
	  }
	curr = temp;
      }
    else
      {
	cout << "At head already" << endl;
      }
  }

  virtual int getValue() const 
  {
    if(curr != last) return curr -> getNext() -> getValue();
    else cout << "No value" << endl;
  }

  virtual void insert(int val) 
  {
    curr -> setNext (new ElementIntList(val, curr->getNext()));
    if(curr == last) last = curr -> getNext();
    listSize++;
  }

  virtual void reverse()
  {
    if(head != last)
      {
	curr = last;
	ElementIntList * temp = head -> getNext() ;
	last = temp;
	while(head -> getNext() != curr)
	  {
	    temp = head -> getNext();
	    head -> setNext(temp -> getNext());
	    temp -> setNext(curr -> getNext() );
	    curr -> setNext(temp);
	  }
      }
  }
    
  virtual void remove() 
  {
    if(curr != last)
      {
	if(curr -> getNext() == last) last = curr;
	ElementIntList * temp = curr -> getNext();
	curr -> setNext( curr -> getNext() -> getNext() );
	delete temp;
	listSize--;
      }
    else
      {
	cout << "No remove" << endl;
      }
  }

};

int main(int argc, const char * argv[]) {
  IntList * x = new ArrayIntList();
  x -> append(1);
  x -> append(2);
  x -> append(3);
  x -> append(4);
  x -> append(5);
  x -> append(6);
  x -> append(7);

  x -> print();

  x -> moveToEnd();
  x -> moveBackward();
  x -> remove();
  x -> append(8);
  
  cout << endl;
  x -> print();
  delete x;
  return 0;
}
