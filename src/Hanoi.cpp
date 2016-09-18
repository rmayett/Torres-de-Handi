#include "Hanoi.h"
/**
Constructor calcula el numero 
de movimientos
resive el numero de discos 
no regresa nada
*/
Hanoi::Hanoi(int Discos)
{
	this->Discos= Discos;
	this->NumMovimientos=pow(2,this->Discos);
}
/*
Resuelve el juego de las Torres 
de Hanoi con N discos
no recibe ni regresa nada
*/
void Hanoi::Resolver()
{

	if (this->Discos%2 == 0)
	{
		ResolverPar();		
	}else
	{
		ResolverImpar();
	}
}
/*Resuelve el juego de las torres de Hanoi para 
N discos donde N es par 
no recibe ni regresa nada*/
void Hanoi::ResolverPar(){
	for (int i = 1; i < this->NumMovimientos; ++i)
		{
			
			int O=(this->origen.empty())?INFINITY:this->origen.top();
			int A=(this->auxiliar.empty())?INFINITY:this->auxiliar.top();
			int D=(this->destino.empty())?INFINITY:this->destino.top();



			if (i%3==1)
			{//movimento entre origen y auxiliar
				if (O>A)
				{
					this->origen.push(this->auxiliar.top());
					this->auxiliar.pop();
				}else
				{
					this->auxiliar.push(this->origen.top());
					this->origen.pop();				
				}
			}
			if (i%3==2)
			{//movimento entre origen y destino
				if ( O>D)
				{
					this->origen.push(this->destino.top());
					this->destino.pop();			
				}else
				{
					this->destino.push(this->origen.top());
					this->origen.pop();
				}	
			}
			if (i%3==0)
			{//movimento entre destino y auxiliar
				if ( A>D)
				{
					this->auxiliar.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->auxiliar.top());
					this->auxiliar.pop();
				}
			}			
			this->MostrarMov(this->origen,this->auxiliar,this->destino);
		}
}
/*Resuelve el juego de las torres de Hanoi para 
N discos donde N es impar 
no recibe ni regresa nada*/
void Hanoi::ResolverImpar(){
	for (int i = 1; i < this->NumMovimientos; ++i){
			int O=(this->origen.empty())?INFINITY:this->origen.top();
			int A=(this->auxiliar.empty())?INFINITY:this->auxiliar.top();
			int D=(this->destino.empty())?INFINITY:this->destino.top();
			if (i%3==1)
			{//movimento entre origen y destino
				
				if ( O>D)
				{

					this->origen.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->origen.top());
					this->origen.pop();
				}	
			}
			if (i%3==2)
			{//movimento entre origen y auxiliar
				
				if (O>A)
				{
					this->origen.push(this->auxiliar.top());
					this->auxiliar.pop();
				}else
				{
					this->auxiliar.push(this->origen.top());
					this->origen.pop();
				}
			}
			if (i%3==0)
			{//movimento entre destino y auxiliar
				if ( A>D)
				{
					this->auxiliar.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->auxiliar.top());
					this->auxiliar.pop();					
				}
			}			
		this->MostrarMov(this->origen,this->auxiliar,this->destino);
		}	

}
/*Llena la primera torre con los valores de los discos
no recibe ni regresa nada*/
void Hanoi::LlenarTorre()
{
	for(int i= this->Discos; i>0 ; --i)
	{
		this->origen.push(i);
	}
}
/*muestra todos los movimientos para resolver las torres de hanoi 
recibe las 3 torres*/
void Hanoi::MostrarMov(std::stack<int> origenaux,std::stack<int> aux,std::stack<int> destinoaux)
{	
	std::cout<<"_______________________________________________"<<std::endl;	
	int mayor;
	if(this->origenaux.size() > this->aux.size() && this->origenaux.size() > this->destinoaux.size())
	{
		mayor=origenaux.size();
	}else if(this->aux.size() > this->origenaux.size() && this->aux.size() > this->destinoaux.size())
	{
		mayor=aux.size();
	}else
	{
		mayor=destinoaux.size();	
	}	
	if (mayor==0)
	{
		Imprime(mayor+2,origenaux,aux,destinoaux);
	}
	if (mayor==1)
	{
		Imprime(mayor+1,origenaux,aux,destinoaux);
	}
	else{
		Imprime(mayor,origenaux,aux,destinoaux);
	}
}
/*Imprime los mmoviemntos para resolver las torres 
recibe el numero de elementos de las torre mayor y las torres*/
void Hanoi::Imprime(int mayor,std::stack<int> origenaux,std::stack<int> aux,std::stack<int> destinoaux){
	std::stack<int> auxO;
	std::stack<int> auxA;	
	std::stack<int> auxD;
	for(int i=mayor; i>0 ;i--)
	{
		if(i<=origenaux.size())
		{
			std::cout<<origenaux.top()<<" ";
			auxO.push(origenaux.top());
			origenaux.pop();	
		}else{
			std::cout<<"*"<<" ";
		}
		if(i<=aux.size())
		{
			std::cout<<aux.top()<<" ";
			auxA.push(aux.top());
			aux.pop();	
		}else{
			std::cout<<"*"<<" ";
		}
		if(i<=destinoaux.size())
		{
			std::cout<<destinoaux.top()<<std::endl;
			auxD.push(destinoaux.top());
			destinoaux.pop();	
		}else{
			std::cout<<"*"<<std::endl;
		}		
	}
}