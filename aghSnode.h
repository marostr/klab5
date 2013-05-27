#ifndef AGHSNODE_H
  #define AGHSNODE_H

template<typename TYPE>
class aghSnode {

 protected:

TYPE data;
aghSnode *ptr;

 public:

aghSnode() : ptr(NULL) {}
aghSnode(TYPE _data, aghSnode *_ptr) : ptr(_ptr), data(_data) {}
~aghSnode() { ptr = NULL; }


aghSnode<TYPE>& operator=(aghSnode<TYPE>& pattern) { 
this->data = pattern.data;
this->ptr  = pattern.ptr;
return *this; }

void set_data(TYPE _data) { this->data = _data; }
TYPE& get_data(void) { return data; }
void set_next(aghSnode<TYPE> *nptr) { this->ptr = nptr; }
aghSnode<TYPE>* get_next(void) {return ptr; }


};

#endif
