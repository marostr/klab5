#ifndef AGHDLIST_H
  #define AGHDLIST_H
	//!!!!!!!!!!!!	
	#include <string>
	
	//!!!!!!!!!!!!	

template<typename TYPE>
class aghDlist : public aghSlist<TYPE> {


//aghDnode<TYPE>* hptr; //< wskaznik na poczatek listy

 public:

	aghDlist<TYPE>(int size=0)  {this->hptr = NULL;}
	aghDlist(const aghContainer<TYPE> &pattern);
	~aghDlist<TYPE>() { this->clear(); this->hptr = NULL; }
	//kon. kop!!


	bool insert(int _index, TYPE const &_val);
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
//static casty rzutuja wskaznik klasy bazowej na wskaznik klasy pochodnej
//zeby mozna bylo uzywac starych metod klasy bazowej bez zmiany ciala klasy
//skoro i tak pracujemy na wezlach podwojnych, wiec te operacje sa bezpieczne
	aghSnode<TYPE> *tptr = (this->hptr),*tptr2;
	int counter=0;

	if(_index<0) return false;
	else if (_index==0 && this->hptr==NULL)	//przypadek 0 - lista pusta
	{
		this->hptr = new aghDnode<TYPE>;
		this->hptr->set_data(_val);
		this->hptr->set_next(NULL);
	        static_cast<aghDnode<TYPE>*>(this->hptr)->set_prev(NULL);
	}
		else if( _index==0 && this->hptr != NULL) //przypadek 1 - poczatek listy
	{
		this->hptr = new aghDnode<TYPE>;         //glowa = nowy
		this->hptr->set_next(tptr);              //nowy nastepny = pamietany
   		static_cast<aghDnode<TYPE>*>(this->hptr)->set_prev(NULL);	//glowa poprzedni = null
		this->hptr->set_data(_val);               //ustawianie wartosci
		static_cast<aghDnode<TYPE>*>(this->hptr)->set_prev(this->hptr);	//byla glowa poprzedni = nowa glowa
	}
	else if(_index < this->size() ) // przypadek 2 - srodek listy
	{

		while(counter != _index-1) //petla idaca na poz jedna przed rzadanym indexem
		{
			tptr = tptr->get_next();
			counter++;
		}

		tptr2=tptr->get_next(); //zapamietaj kolejny element po miejscu gdzie wstawiamy
		tptr->set_next( new aghDnode<TYPE> ); // wstaw nowy element w odpowiednie miej.
		tptr->get_next()->set_data( _val );                 //ustawienie jego wartosci
		tptr->get_next()->set_next(tptr2);                 //ustawienie jego nastepnika
		static_cast<aghDnode<TYPE>*>(tptr->get_next())->set_prev(tptr);	//ustawienie jego poprzednika
		tptr=tptr->get_next();					//zmiana wskaznika na nastepny
		static_cast<aghDnode<TYPE>*>(tptr2)->set_prev(tptr);	//zmiana poprzednika nastepnego elementu
		}
		else // przypadek 3 - wstawianie na koncu
		{
			while( tptr->get_next()!=NULL ) tptr=tptr->get_next();  //ustawiamy wskaznik na koniec listy
			for(int i=this->size()-1; i<_index; ++i) //az dojdziemy do odpowiendiego indexu
				{
					tptr->set_next(new aghDnode<TYPE>); //alokacja kolejych el
					static_cast<aghDnode<TYPE>*>(tptr->get_next())->set_prev(tptr);
					tptr=tptr->get_next();				//przest wskaznik
				}
		tptr->set_data(_val);
	}
return true;	
}

//----------------------------------------------------------------------

template<typename TYPE>
bool aghDlist<TYPE>::remove(int _index)
	{
	if( ( _index >= this->size() ) || (_index < 0) ) return false;

	aghSnode<TYPE> *tptr , *tptr2;
	tptr = this->hptr;
	
	if( ( _index == 0 ) ) //usuwanie 0wego elementu 
	{
		this->hptr = this->hptr->get_next();
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


//---------------------------------------------------------------------------


template<typename TYPE>
aghDlist<TYPE>& aghDlist<TYPE>::operator=(const aghContainer<TYPE> &right)
{

	if( &right == this);
	else
		{
			if( !(this->isEmpty() )) this->clear();
			for(int i=0; i<right.size(); i++)
				this->append(right[i]);
		}
return *this;
}

#endif
