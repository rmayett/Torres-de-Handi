/**
	Nombre(s):Jaime Alan Marquez Montes
	Descripcion:______
	____________________
	____________
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
	std::stack<int> destino;
public:
	Hanoi(int Discos);
	void Resolver();
	void LlenarTorre();
	void MostrarTorres();
};
