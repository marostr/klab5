#ifndef AGHDNODE_H  
	#define AGHDNODE_H
 	#include "aghSnode.h"	

template <typename TYPE>
class aghDnode : public aghSnode<TYPE> {

	aghSnode<TYPE> *prev;

public:

	aghDnode(): aghSnode<TYPE>::aghSnode(), prev(NULL) { }
	~aghDnode() { prev = NULL; }
	aghDnode(const aghDnode<TYPE> &ref) {
	this->prev = ref.get_prev();
	this->next = ref.get_next();
	this->data = ref.get_data();
	}	
	

	void set_prev(aghSnode<TYPE>* _prev) { prev = _prev; }
	aghSnode<TYPE>* get_prev() const { return prev; }
	
	aghDnode<TYPE>& operator=(aghDnode<TYPE>& pattern) { 
		this->data = pattern.data;
		this->next  = pattern.next;
		this->prev = pattern.prev;
		return *this; }
};

#endif
