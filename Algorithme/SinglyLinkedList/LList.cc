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

  void init()
  {
    cnt = 0;
    head = tail = curr = new Link<E>();
  }

  void removeAll()
  {
    while(head->next != NULL)
      {
	curr = head;
	head = head->next;
	delete curr;
      }
  }
  
public:
  LList()
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
    while(curr != tail)
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
    curr->next = new Link<E>(it, curr->next);
    cnt++;
    if(curr == tail) tail = curr->next;
  }

  void append(const E& it)
  {
    tail->next = new Link<E>(it, NULL);
    tail = tail->next;
    cnt++;
  }

  E remove() 
  {
    assert(curr->next != NULL);

    E item = curr->next->element;
    Link<E>* temp = curr->next;
    if(curr->next == tail) tail = curr;
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
    curr = tail;
  }

  void prev()
  {
    if(curr == head) cout << "Curr already points to Head";
    else
      {
	Link<E>* temp = head;
	while(temp->next != curr)
	  {
	    temp = temp->next;
	  }
	curr = temp;
      }
  }

  void next()
  {
    if(curr != tail)
      {
	curr = curr->next;
      }
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
    int i = 0;
    curr = head;
    while(i != pos)
      {
	curr = curr->next;
	i++;
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
