#ifndef AGHDLIST_H
  #define AGHDLIST_H
  
	#include <string>
	
template <typename TYPE>
class aghDlist : public aghSlist<TYPE> {
	
	aghDnode* hptr;	//wskaznik na poczatek listy

public:

	aghDlist(): hptr(NULL) {}
	aghDlist(const aghContainer<TYPE> &pattern);
	~aghDlist<TYPE>() { this->clear(); hptr = NULL; }
	//kon. kop!!

	bool insert(int _index, TYPE const& _val);
	bool remove(int _index);

	aghDlist<TYPE>& operator=(const aghContainer<TYPE> &right);

};

//----------------------------------------------------------------------

template <typename TYPE>
void aghDlist<TYPE>::insert(int _index, TYPE const& _val)
{
	aghDnode<TYPE> *tptr = (this->hptr),*tptr2;
	int counter=0;

	if(_index<0) return false;
		else if( _index==0 ) //przypadek 1 - poczatek listy
		{
//std::cout<<"przypadek 1\n";	
			if(hptr==NULL) tptr=NULL;
			else tptr=hptr;                    //zapamietaj nastepnik glowy

			hptr = new aghSnode<TYPE>;         //glowa = nowy
			hptr->set_next(tptr);              //nowy nastepny = pamietany
			hptr->set_prev(NULL);				//nowy poprzedni = NULL
			hptr->set_data(_val);               //ustawianie wartosci	
			tptr->set_prev(hptr);				//poprzednik bylej glowy
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
	
		tptr2->set_prev(tptr->get_next());					//ustawienie poprzednika nastepnej wartosci
		
		}
	
		else // przypadek 3 - wstawianie na koncu
		{
			//std::cout<<"przypadek 3\n";	
			while( tptr->get_next()!=NULL ) tptr=tptr->get_next();  //ustawiamy wskaznik na koniec listy
			for(int i=this->size()-1; i<_index; ++i) //az dojdziemy do odpowiendiego indexu
			{
				tptr->set_next(new aghDnode<TYPE>); //alokacja kolejych el
				tptr->get_next()->set_prev(tptr);	//nastepnik pokazuje na obecny wskaznik
				tptr=tptr->get_next();			//przest wskaznik
				tptr->set_data(INT_MIN);
			}
			tptr->set_data(_val);
		}
return true;	

}

//----------------------------------------------------------------------

template <typename TYPE>
void aghDlist<TYPE>::remove(int _index)
{//tu sie da raczej jedna petla ogarnac
	if( ( _index >= this->size() ) || (_index < 0) ) return false;

	aghDnode<TYPE> *tptr = hptr, *tptr2;
	if( ( _index == 0 ) ) //usuwanie 0wego elementu 
	{
		hptr = hptr->get_next();
		delete tptr;
		hptr->set_prev(NULL);
		return true;
	}

	int counter=0;
	while(_index-1 != counter++)
	{
		tptr = tptr->get_next();
	}
	tptr2=tptr->get_next();
	tptr->set_next( tptr->get_next()->get_next() );
	tptr->get_next->set_prev(tptr);
	delete tptr2;

return true;
}

//----------------------------------------------------------------------

aghDlist<TYPE>& aghDlist<TYPE>::operator=(const aghContainer<TYPE> &right)
{
	if( &right == this);
	else
		{
			if( !(this->isEmpty() )) this->clear();
			for(int i=0; i < right.size(); i++)
				this->append(right[i]);
		}
return *this;
}

//----------------------------------------------------------------------

template<typename TYPE>
aghDlist<TYPE>::aghDlist(const aghContainer<TYPE> &pattern)
{
	if(pattern.size()==0) this->hptr = NULL;	
	for(int i=0; i<pattern.size(); i++)
		this->append(pattern.at(i));
}



#endif
