#include "aghInclude.h"


int main(void)
{
aghSlist<int> L1;

L1.insert(0,1);
L1.insert(1,2);
L1.insert(2,4);
L1.insert(3,5);
L1.insert(4,13);
L1.insert(5,12);
L1.insert(6,4);
L1.insert(7,-1320);
L1.insert(9,33);
L1.insert(11,2);
L1.insert(15,3);
L1.insert(30,3);



std::cout<<"po wstawianiu";

/*std::cout<< L1.size() <<"\n";

L1.remove(0);

std::cout<< L1.size() <<"\n";

L1.remove(29);

std::cout<< L1.size() <<"\n";

L1.remove(10);
L1.remove(27);
*/
std::cout<< L1.size() <<"\n";

try{
std::cout<<L1.at(0);
cout<<"\n"<<L1.at(30);
cout<<"\n"<<L1.at(20);
}	
catch(std::string &e)
{	
std::cout<<e;	
}
}
