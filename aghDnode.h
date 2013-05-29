#ifndef AGHDLIST_H  
	#define AGHDLIST_H

template <typename TYPE>
class aghDnode : public aghSnode<TYPE> {

	aghDnode* prev;

public:

	aghDnode() : aghSnode<TYPE>(), prev(NULL) {}
	aghDnode(TYPE _data, aghDnode* _prev, aghDnode* _next) : aghSnode<TYPE>(_data, _next), prev(_prev) {}
	~aghDnode() { prev = NULL; }

	void set_prev(aghDnode* _prev) { prev = _prev; }
	aghDnode<TYPE>* get_prev() const { return prev; }
};

#endif
