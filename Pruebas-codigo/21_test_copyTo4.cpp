#include <iostream>
#include "..\List.hpp"

int main()
{
  Lista miLista;
  miLista.add('A');
  miLista.add('B');
  miLista.add('C');
  miLista.add('D');
  miLista.add('E');
  miLista.add('F');
  miLista.add('G');

  char arr[10] = {};

  miLista.copyTo(1, arr, 2, 4); // Copia de la lista desde posiciones 2 a 4 al arreglo comenzando en la posición 1

  for (int i = 0; i < 10; ++i)
  {
    std::cout << arr[i] << " ";
  }
  // Salida esperada (posiciones útiles): _ C D E _
}