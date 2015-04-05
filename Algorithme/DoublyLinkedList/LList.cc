#include "List.cc"
#include <iostream>
#include <assert.h>
#include <unistd.h>

using namespace std;

template<typename E> class LList : public List<E> {
private:
  Link<E>* head;    // pointer to Header
  Link<E>* tail;    // pointer to Last
  Link<E>* curr;    // pointer to Current pos
  int cnt;          // length
  static const int defaultSize = 20;

  void init()
  {
    cnt = 0;
    tail = new Link<E>();
    head = curr = new Link<E>(NULL, tail);
    tail->prev = head;
  }

  void removeAll()
  {
    while(head->next != tail)
      {
	curr = head;
	head = head->next;
	head->prev = NULL;
	delete curr;
      }
  }
  
public:
  LList(int size = defaultSize)
  {
    init();
  }

  ~LList()
  {
    removeAll();
  }

  void print()
  {
    curr = head;
    while(curr->next != tail)
      {
	cout << curr->next->element << " ";
	curr = curr->next;
      }
    cout << endl;
    curr = head;
  }

  void clear()
  {
    removeAll();
    init();
  }

  void insert(const E& it)
  {
    curr->next = curr->next->prev = new Link<E>(it, curr, curr->next);
    cnt++;
  }

  void append(const E& it)
  {
    tail->prev->next = tail->prev = new Link<E>(it, tail->prev, tail);
    cnt++;
  }

  E remove() 
  {
    assert(curr->next != tail);

    E item = curr->next->element;
    Link<E>* temp = curr->next;
    curr->next->next->prev = curr;
    curr->next = curr->next->next;
    delete temp;
    cnt--;

    return item;
  }

  void moveToStart()
  {
    curr = head;
  }

  void moveToEnd()
  {
    curr = tail->prev;
  }

  void prev()
  {
    if(curr == head) 
      cout << "Curr already points to Head" << endl;
    else
      curr = curr->prev;
  }

  void next()
  {
    if(curr->next == tail) 
      cout << "Curr already points to the end of the list" << endl;
    else
      curr = curr->next;
  }

  int length() const
  {
    return cnt;
  }

  int currPos() const
  {
    int pos = 0;
    Link<E>* temp = head;
    while(temp != curr)
      {
	pos++;
	temp = temp->next;
      }
    return pos;
  }

  void moveToPos(int pos)
  {
    assert(pos < cnt);

    int distance = pos-currPos();

    if(distance > 0)
      {
	while(distance != 0)
	  {
	    curr = curr->next;
	    distance--;
	  }
      }
    else if(distance < 0)
      {
	while(distance != 0)
	  {
	    curr = curr->prev;
	    distance++;
	  }
      }
    else
      {
	cout << "Curr already points to position " << pos << endl;
      }
  }

  const E& getValue() const
  {
    assert(curr->next != NULL);
    return curr->next->element;
  }

  void inverse(LList<E>& linv)
  { 
    this->moveToEnd();
    
    while(this->head != this->curr)
      {
	this->prev();
	linv.append(this->getValue());
      }
  }

  void inverse2()
  {
    moveToStart();

    Link<E>* item = NULL;
    while(curr != tail)
      {
	item = new Link<E>(curr->next->element, item);
	remove();
	cnt++;
      }
    Link<E>* temp = head;
    curr = head = tail = new Link<E>(item);
    delete temp;
    
    for(int i = 0 ; i < cnt ; i++)
      {
	tail = tail->next;
      }
  }

};
