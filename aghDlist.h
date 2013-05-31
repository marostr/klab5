#ifndef AGHDLIST_H
  #define AGHDLIST_H
	//!!!!!!!!!!!!	
	#include <string>

	//!!!!!!!!!!!!	

template<typename TYPE>
class aghDlist : public aghSlist<TYPE> {


aghDnode<TYPE>* hptr; //< wskaznik na poczatek listy

 public:

	aghDlist<TYPE>(int size=0): hptr(NULL) {}
	aghDlist(const aghContainer<TYPE> &pattern);
	~aghDlist<TYPE>() { this->clear(); hptr = NULL; }
	//kon. kop!!


	bool insert(int _index, TYPE const &_val);
	TYPE& at(int _index) const;
	int size(void) const;
	bool remove(int _index);

	aghDlist<TYPE>& operator=(const aghContainer<TYPE> &right);

};


template<typename TYPE>
aghDlist<TYPE>::aghDlist(const aghContainer<TYPE> &pattern)
{
	if(pattern.size()==0) this->hptr = NULL;
	this->clear();	
	for(int i=0; i<pattern.size(); i++)
		this->append(pattern.at(i));

}

template<typename TYPE>
bool aghDlist<TYPE>::insert(int _index, TYPE const &_val)
{	
	aghDnode<TYPE> *tptr = (this->hptr),*tptr2;
	int counter=0;

	if(_index<0) return false;
	else if (_index==0 && hptr==NULL)
	{
		hptr = new aghDnode<TYPE>;
		hptr->set_data(_val);
		hptr->set_next(NULL);
		hptr->set_prev(NULL);
	}
		else if( _index==0 && hptr != NULL) //przypadek 1 - poczatek listy
	{
//std::cout<<"przypadek 1\n";	
		hptr = new aghDnode<TYPE>;         //glowa = nowy
		hptr->set_next(tptr);              //nowy nastepny = pamietany
		hptr->set_prev(NULL);				//glowa poprzedni = null
		hptr->set_data(_val);               //ustawianie wartosci
		tptr->set_prev(hptr);				//byla glowa poprzedni = nowa glowa
	}
else if(_index < this->size() ) // przypadek 2 - srodek listy
{
//std::cout<<"przypadek 2\n";

	while(counter != _index-1) //petla idaca na poz jedna przed rzadanym indexem
	{
		tptr = tptr->get_next();
		counter++;
	}

	tptr2=tptr->get_next(); //zapamietaj kolejny element po miejscu gdzie wstawiamy
	tptr->set_next( new aghDnode<TYPE> ); // wstaw nowy element w odpowiednie miej.
	tptr->get_next()->set_data( _val );                 //ustawienie jego wartosci
	tptr->get_next()->set_next(tptr2);                 //ustawienie jego nastepnika
	tptr->get_next()->set_prev(tptr);					//ustawienie jego poprzednika
	tptr=tptr->get_next();								//zmiana wskaznika na nastepny
	tptr2->set_prev(tptr);								//zmiana poprzednika nastepnego elementu
}
else // przypadek 3 - wstawianie na koncu
{
//std::cout<<"przypadek 3\n";	
	while( tptr->get_next()!=NULL ) tptr=tptr->get_next();  //ustawiamy wskaznik na koniec listy
	for(int i=this->size()-1; i<_index; ++i) //az dojdziemy do odpowiendiego indexu
		{
			tptr->set_next(new aghDnode<TYPE>); //alokacja kolejych el
			tptr->get_next()->set_prev(tptr);
			tptr=tptr->get_next();				//przest wskaznik
			//tptr->set_data(INT_MIN);
	    }
	tptr->set_data(_val);
}
return true;	

	
}

//----------------------------------------------------------------------

template<typename TYPE>
bool aghDlist<TYPE>::remove(int _index)
{//tu sie da raczej jedna petla ogarnac
if( ( _index >= this->size() ) || (_index < 0) ) return false;

aghDnode<TYPE> *tptr = hptr, *tptr2;
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
TYPE& aghDlist<TYPE>::at(int _index) const
{
if( (_index>= this->size() ) || (_index < 0) ) throw aghException(-1,"Index out of range!");


aghDnode<TYPE> *tptr = hptr; //< tymczasowy ptr
int counter=0;


while(counter!=_index)
{
	if( (tptr==NULL) ) throw aghException(0,"at(): Pointer == NULL" ); //jak wskaznik jest nullem
	tptr= tptr->get_next();
	counter++;
}


return tptr->get_data();
}

//---------------------------------------------------------------------------

template<typename TYPE>
int aghDlist<TYPE>::size(void) const
{
aghDnode<TYPE> *tptr;
int counter=0;

if( !(this->hptr) ) return 0; //jak jest nullem

tptr = this->hptr; //ustaw na poczatek listy

do{
counter++;
tptr=tptr->get_next();
}while( tptr ); //dopoki nastepny wskaznik nie wskazuje na null

return counter;
}

//----------------------------------------------------------------------

template<typename TYPE>
aghDlist<TYPE>& aghDlist<TYPE>::operator=(const aghContainer<TYPE> &right)
{



if( &right == this);
else
	{
	if( !(this->isEmpty() )) this->clear();
	for(int i=0; this->size()<right.size(); i++)
		this->append(right[i]);
	}
return *this;
}

#endif
