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
    void clear() {
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
    int length() const {
        return listSize;
    }
    void print() {
        ElementIntList * tmp = head -> getNext();
        while (tmp != NULL) {
            std::cout << tmp -> getValue() << '\n';
            tmp = tmp -> getNext();
        }
    }
    bool append(const int val) {
        // TO DO
        return true;
    }
    
};