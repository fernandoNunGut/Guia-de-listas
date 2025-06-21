#include <iostream>
#include "..\List.hpp"

int main()
{
  Lista miLista;
  miLista.add('A');
  miLista.add('B');
  miLista.add('C');
  miLista.add('D');
  miLista.add('C');
  miLista.add('T');

  char array[2];
  miLista.copyTo(2, array); // Copia desde la posición 2 -> 'C', 'D'

  for (int i = 0; i < 2; ++i)
  {
    std::cout << array[i] << " "; // Imprime: C D
  }
}