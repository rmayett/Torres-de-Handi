#include "Hanoi.h"
/**
Constructor calcula el numero 
de movimientos
@params Discos ________
@result void
*/
Hanoi::Hanoi(int Discos)
{
	this->Discos= Discos;
	this->NumMovimientos=pow(2,this->Discos);
}
/*
Resuelve el juego de las Torres 
de Hanoi con N discos
@params void
@result void
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
			
			int O=(this->origen.empty())?0:this->origen.top();
			int A=(this->auxiliar.empty())?0:this->auxiliar.top();
			int D=(this->destino.empty())?0:this->destino.top();



			if (i%3==1)
			{//movimento entre origen y auxiliar
				if (O>A)
				{
					this->origen.push(this->auxiliar.top());
					this->auxiliar.pop();
					//this->origenaux.push(origen.top());
				}else
				{
					this->auxiliar.push(this->origen.top());
					this->origen.pop();					
					//this->aux.push(auxiliar.top());
				}
			}
			if (i%3==2)
			{//movimento entre origen y destino
				if ( O>D)
				{
					this->origen.push(this->destino.top());
					this->destino.pop();					
					//this->origenaux.push(origen.top());
				}else
				{
					this->destino.push(this->origen.top());
					this->origen.pop();
					//this->destinoaux.push(destino.top());
				}	
			}
			if (i%3==0)
			{//movimento entre destino y auxiliar
				if ( A>D)
				{
					this->auxiliar.push(this->destino.top());
					this->destino.pop();
					//this->aux.push(auxiliar.top());
				}else
				{
					this->destino.push(this->auxiliar.top());
					this->auxiliar.pop();
					//this->destinoaux.push(destino.top());
				}
			}			
			this->MostrarMov(this->origen,this->auxiliar,this->destino);
		}
}
/*Resuelve el juego de las torres de Hanoi para 
N discos donde N es impar 
no recibe ni regresa nada*/
void Hanoi::ResolverImpar(){
	for (int i = 1; i < this->NumMovimientos; ++i)
		{

			int O=(this->origen.empty())?INFINITY:this->origen.top();
			int A=(this->auxiliar.empty())?INFINITY:this->auxiliar.top();
			int D=(this->destino.empty())?INFINITY:this->destino.top();

			//std::cout<<O<<" "<<A<<" "<<D<<std::endl;
			if (i%3==1)
			{//movimento entre origen y destino
				
				if ( O>D)
				{

					this->origen.push(this->destino.top());
					this->destino.pop();
					//this->origenaux.push(origen.top());
				}else
				{
					this->destino.push(this->origen.top());
					this->origen.pop();
					//this->destinoaux.push(destino.top());
				}	
			}
			if (i%3==2)
			{//movimento entre origen y auxiliar
				
				if (O>A)
				{
					this->origen.push(this->auxiliar.top());
					this->auxiliar.pop();
					//this->origenaux.push(origen.top());
				}else
				{
					this->auxiliar.push(this->origen.top());
					this->origen.pop();
					//this->aux.push(auxiliar.top());
				}
			}
			if (i%3==0)
			{//movimento entre destino y auxiliar
				if ( A>D)
				{
					this->auxiliar.push(this->destino.top());
					this->destino.pop();
					//this->aux.push(auxiliar.top());
				}else
				{
					this->destino.push(this->auxiliar.top());
					this->auxiliar.pop();
					//this->destinoaux.push(destino.top());
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
/**/
void Hanoi::MostrarTorres()
{   
	std::stack<int> auxO;
	std::stack<int> auxA;	
	std::stack<int> auxD;
	int mayor;
	if(this->origen.size() > this->auxiliar.size() && this->origen.size() > this->destino.size())
	{
		mayor=origen.size();
	}else if(this->auxiliar.size() > this->origen.size() && this->auxiliar.size() > this->destino.size())
	{
		mayor=auxiliar.size();
	}else
	{
		mayor=destino.size();	
	}
	for(int i=mayor; i>0 ;--i)
	{
		if(i<=origen.size())
		{
			std::cout<<origen.top()<<" ";
			auxO.push(origen.top());
			origen.pop();	
		}else{
			std::cout<<"*"<<" ";
		}
		if(i<=auxiliar.size())
		{
			std::cout<<auxiliar.top()<<" ";
			auxA.push(auxiliar.top());
			auxiliar.pop();	
		}else{
			std::cout<<"*"<<" ";
		}
		if(i<=destino.size())
		{
			std::cout<<destino.top()<<std::endl;
			auxD.push(destino.top());
			destino.pop();	
		}else{
			std::cout<<"*"<<std::endl;
		}	
	}
}
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
		//std::cout<<"mayor="<<mayor<<std::endl;
	}
}