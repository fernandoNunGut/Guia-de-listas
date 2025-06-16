#include <iostream>
#include "..\List.hpp"


int main(){
  Lista lista;

  lista.add_head('A');
  lista.add_head('B');
  lista.add_head('C');
  lista.add_head('D');

  lista.mostrar();

  char mitad = lista.get_middle();

  std::cout <<"\n" << mitad;
}