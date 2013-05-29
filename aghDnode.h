#ifndef AGHDNODE_H  
	#define AGHDNODE_H
	

template <typename TYPE>
class aghDnode {

	TYPE data;
	aghDnode<TYPE> *next;
	aghDnode<TYPE> *prev;

public:

	aghDnode() {prev=NULL; next=NULL; }
	aghDnode(TYPE _data, aghDnode* _prev, aghDnode* _next) : prev(_prev), next(_next), data(_data) {}
	~aghDnode() { prev = NULL; }

	void set_prev(aghDnode* _prev) { prev = _prev; }
	aghDnode<TYPE>* get_prev() const { return prev; }
	void set_data(TYPE _data) { this->data = _data; }
	TYPE& get_data(void) { return data; }
	void set_next(aghDnode<TYPE> *nptr) { this->next = nptr; }
	aghDnode<TYPE>* get_next(void) {return next; }
	
	aghDnode<TYPE>& operator=(aghDnode<TYPE>& pattern) { 
		this->data = pattern.data;
		this->next  = pattern.next;
		this->prev = pattern.prev;
		return *this; }
};

#endif
