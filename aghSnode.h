#ifndef AGHSNODE_H
  #define AGHSNODE_H
  

template<typename TYPE>
class aghSnode {

 protected:

TYPE data;
aghSnode<TYPE> *next;

 public:

aghSnode() : next(NULL) {}
aghSnode(TYPE _data, aghSnode *_ptr) : next(_ptr), data(_data) {}
virtual ~aghSnode() { next = NULL; }


aghSnode<TYPE>& operator=(aghSnode<TYPE>& pattern) { 
this->data = pattern.data;
this->next  = pattern.next;
return *this; }

void set_data(TYPE _data) { this->data = _data; }
TYPE& get_data(void) { return data; }
void set_next(aghSnode<TYPE> *nptr) { this->next = nptr; }
aghSnode<TYPE>* get_next(void) {return next; }
virtual void set_prev(aghSnode<TYPE>*) { }  //magiczna sztuczka

};

#endif
