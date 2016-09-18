#include "Hanoi.h"

int main()
{
	
	std::cout<<"Torres de Hanoi"<<std::endl;
	Hanoi H(3);
	H.LlenarTorre();	
	H.Resolver();
		return 0;
}
