#ifndef AGHDLIST_H  
	#define AGHDLIST_H

#include "aghContainer.h"
using namespace std;

template <typename TYPE>
class aghDnode {

	TYPE obj;
	aghDnode* previous;
	aghDnode* next;

public:

	aghDnode();
	aghDnode(TYPE, aghDnode*, aghDnode*);

	void setObj(TYPE _obj) { obj = _obj; }
	void setPrevious(aghDnode* _previous) { previous = _previous; }
	void setNext(aghDnode* _next) { next = _next; }
	TYPE& getObj() const { return obj; }
	aghDnode* getPrevious() const { return previous; }
	aghDnode* getNext() const { return next; }
};


template <typename TYPE>
aghDnode<TYPE>::aghDnode()
{
	previous = NULL;
	next = NULL;
}

//-------------------------------------

template <typename TYPE>
aghDnode<TYPE>::aghDnode(TYPE _obj, aghDnode* _previous, aghDnode* _next) : obj(_obj)
{
	setPrevious(_previous);
	setNext(_next);
}
