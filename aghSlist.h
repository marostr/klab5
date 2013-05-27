#ifndef AGHSLIST_H
  #define AGHSLIST_H
	//!!!!!!!!!!!!	
	using namespace std;
	#include <string>

	//!!!!!!!!!!!!	

template<typename TYPE>
class aghSlist : public aghContainer<TYPE> {

 private:

aghSnode<TYPE>* hptr; //< wskaznik na poczatek listy

 public:

aghSlist<TYPE>(int size=0): hptr(NULL) {}
~aghSlist<TYPE>() { while(this->size()>0) remove(0); }
//kon. kop!!
//op= !!

bool insert(int _index, TYPE const &_val);
TYPE& at(int _index) const;
int size(void) const;
bool remove(int _index);


};



template<typename TYPE>
bool aghSlist<TYPE>::insert(int _index, TYPE const &_val)
{	
aghSnode<TYPE> *tptr = (this->hptr),*tptr2;
int counter=0;

if(_index<0) return false;
else if( _index==0 ) //przypadek 1 - poczatek listy
{
std::cout<<"przypadek 1\n";	
	if(hptr==NULL) tptr=NULL;
	else tptr=hptr;                    //zapamietaj nastepnik glowy

	hptr = new aghSnode<TYPE>;         //glowa = nowy
	hptr->set_next(tptr);              //nowy nastepny = pamietany
	hptr->set_data(_val);               //ustawianie wartosci	
}
else if(_index < this->size() ) // przypadek 2 - srodek listy
{
std::cout<<"przypadek 2\n";

	while(counter != _index-1) //petla idaca na poz jedna przed rzadanym indexem
	{
		tptr = tptr->get_next();
		counter++;
	}

	tptr2=tptr->get_next(); //zapamietaj kolejny element po miejscu gdzie wstawiamy
	tptr->set_next( new aghSnode<TYPE> ); // wstaw nowy element w odpowiednie miej.
	tptr->get_next()->set_data( _val );                 //ustawienie jego wartosci
	tptr->get_next()->set_next(tptr2);                 //ustawienie jego nastepnika
}
else // przypadek 3 - wstawianie na koncu
{
std::cout<<"przypadek 3\n";	
	while( tptr->get_next()!=NULL ) {tptr=tptr->get_next(); cout<<"*";} //ustawiamy wskaznik na koniec listy
	for(int i=this->size()-1; i<_index; ++i) //az dojdziemy do odpowiendiego indexu
		{
			tptr->set_next(new aghSnode<TYPE>); //alokacja kolejych el
			tptr=tptr->get_next();				//przest wskaznik
			tptr->set_data(INT_MIN);
	    }
	tptr->set_data(_val);
}
return true;	

	
}

//----------------------------------------------------------------------

template<typename TYPE>
bool aghSlist<TYPE>::remove(int _index)
{
if( ( _index >= this->size() ) || (_index < 0) ) return false;

aghSnode<TYPE> *tptr = hptr, *tptr2;
if( ( _index == 0 ) ) //usuwanie 0wego elementu 
{
	hptr = hptr->get_next();
	delete tptr;
	return true;
}

int counter=0;
while(_index-1 != counter++)
{
tptr = tptr->get_next();
}
tptr2=tptr->get_next();
tptr->set_next( tptr->get_next()->get_next() );
delete tptr2;

return true;
}

//-----------------------------------------------------------------------------

template<typename TYPE>
TYPE& aghSlist<TYPE>::at(int _index) const
{
if( (_index>= this->size() ) || (_index < 0) ) throw std::string("at() - index poza lista");


aghSnode<TYPE> *tptr = hptr; //< tymczasowy ptr
int counter=0;


while(counter!=_index)
{
	if( (tptr==NULL) ) throw std::string("at() - wsk == NULL ");; //jak wskaznik jest nullem
	tptr= tptr->get_next();
	counter++;
}


return tptr->get_data();
}

//---------------------------------------------------------------------------

template<typename TYPE>
int aghSlist<TYPE>::size(void) const
{
aghSnode<TYPE> *tptr;
int counter=0;

if( !(this->hptr) ) return 0; //jak jest nullem

tptr = this->hptr; //ustaw na poczatek listy

do{
counter++;
tptr=tptr->get_next();
}while( tptr ); //dopoki nastepny wskaznik nie wskazuje na null

return counter;
}



#endif
