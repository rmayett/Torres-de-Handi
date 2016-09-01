#include "Hanoi.h"

Hanoi::Hanoi(int Discos){
      this->Discos=Discos;
      this->NumMovimientos=pow(2,this->Discos)-1;
}
/*
Constructor
@params 
@result void*/

void Hanoi::Llenar(){
          for(i=Discos;i>0;i--){
          this.origen.push(i);}
}
void Hanoi::mostrar(){
std::stack<int> auxO;
std::stack<int> auxA;
std::stack<int> auxD;
int mayor;
if(this->origen.size() > this->aux.size()&&this->origen.size()>this->destino.size()){
mayor=origen.size();}
else if(this->aux.size() > this->origen.size()&&this->aux.size()>this->destino.size()){
      mayor=aux.size();}
      else{
      mayor=destino.size();
}
for(int i=mayor;i>0;--i){
}
}
void Hanoi::Resolver(){
        if(this->Discos%2==0){
        for(int i=1;i<NumMovimintos;i++){
            if(i%3==1){
                  if(!aux.empty()&&this->origen.top()>this->aux.top()){
                  this->origen.push(this->aux.top());
                  this->aux.pop();
                  }
                  else{
                  this->aux.push(this->origen.top());
                  this->origen.pop();
                  }
            }
            if(i%3==2){
                  if(this->destino.top()>this->origen.top()){
                  this->destino.push(this->origen.top());
                  this->aux.pop();
                  }
                  else{
                  this->aux.push(this->origen.top());
                  this->origen.pop();
                  }
            }
            if(i%3==0){
                  if(this->destino.top()>this->aux.top()){
                  this->destino.push(this->aux.top());
                  this->aux.pop();
                  }
                  else{
                  this->aux.push(this->destino.top());
                  this->destino.pop();
                  }
            }
          }
        }
        else{
        }
}
