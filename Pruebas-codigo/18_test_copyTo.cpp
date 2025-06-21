#include <iostream>
#include "..\List.hpp"

int main()
{
  Lista miLista;
  miLista.add('A');
  miLista.add('B');
  miLista.add('C');

  char arreglo[3]; // ¡Debe ser del mismo tamaño que la lista!
  miLista.copyTo(arreglo);

  // Imprimir contenido copiado
  for (int i = 0; i < 3; ++i)
  {
    std::cout << arreglo[i] << " "; // A B C
  }
}