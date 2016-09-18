/*Rodrigo Mayett Guzman 
El programa muestra los pasos para resolver el juego "Torres de Handi"
*/
#include <iostream>
#include <stack>
#include <cmath>

class Hanoi
{
private:
	int Discos;
	int NumMovimientos;
	std::stack<int> origen;
	std::stack<int> auxiliar;
	std::stack<int> destino;;
	std::stack<int> origenaux;
	std::stack<int> aux;
	std::stack<int> destinoaux;
public:
	Hanoi(int Discos);
	void Resolver();
	void ResolverPar();
	void ResolverImpar();
	void LlenarTorre();
	void MostrarTorres();
	void Imprime(int mayor,std::stack<int> origenaux,std::stack<int> aux,std::stack<int> destinoaux);
	void MostrarMov(std::stack<int> origenaux,std::stack<int> aux,std::stack<int> destinoaux);
};
