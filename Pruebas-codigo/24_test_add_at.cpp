#include <iostream>
#include "..\List.hpp"

int main()
{
  Lista miLista;

  miLista.add('A');
  miLista.add('B');
  miLista.add('F');
  miLista.add('G');
  miLista.add('H');

  miLista.mostrar();

  char array[] = {'C', 'D', 'E'};
  miLista.add_at(2, array, 3);

  miLista.mostrar();
}