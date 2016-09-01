/* Rodrigo Mayett Guzmán 
Descripción: que hace como trabaja */
#include <stack>
#include <iostream>
#include <cmath>

class Hanoi{
private:
  int Discos;
  std::stack<int> origen;
  std::stack<int> aux;
  std::stack<int> destino;
public:
  Hanoi(int Discos);
  void Resolver();
  void Llenar();
  void mostrar();
    }