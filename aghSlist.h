#ifndef AGHSLIST_H
  #define AGHSLIST_H
	//!!!!!!!!!!!!	
	using namespace std;	

template<typename TYPE>
class aghSlist : public aghContainer<TYPE> {

 private:

aghSnode<TYPE>* hptr; //< wskaznik na poczatek listy

 public:

aghSlist<TYPE>(int size=0);
~aghSlist<TYPE>();

bool insert(int _index, TYPE const &_val);
TYPE& at(int _index) const;
int size(void) const;
bool remove(int _index);


};

template<typename TYPE>
bool aghSlist<TYPE>::remove(int _index)
{
if( ( _index >= this->size ) || (_index < 0) ) return false;

aghSnode<TYPE> *tptr = hptr;
int counter=0;

while(counter != _index)
{

}


}

//-----------------------------------------------------------------------------

template<typename TYPE>
TYPE& aghSlist<TYPE>::at(int _index) const
{
if( (_index>= this->size() ) || (_index < 0) ) throw -1;

aghSnode<TYPE>* tptr; //< tymczasowy ptr
int counter=0;
tptr = hptr;

do{
	if( (!tptr) ) throw -1; //jak wskaznik jest nullem
	tptr= tptr->get_ptr();
	counter++;

}while(counter!=_index);


return tptr->get_data();
}

//---------------------------------------------------------------------------

template<typename TYPE>
int aghSlist<TYPE>::size(void) const
{
aghSnode<TYPE> *tptr;
int counter=0;

if( !(this->hptr) ) return 0;

tptr = this->hptr; //ustaw na poczatek listy

do{
counter++;
}while( tptr->get_ptr() ); //dopoki nastepny wskaznik nie wskazuje na null

return counter;
}



#endif
