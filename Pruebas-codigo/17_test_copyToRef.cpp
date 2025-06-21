#include <iostream>
#include "..\List.hpp"

int main()
{
  Lista miLista;
  miLista.add('A');
  miLista.add('B');
  miLista.add('C');

  char *datos = miLista.copyToRef();

  for (int i = 0; i < miLista.size(); ++i)
  {
    std::cout << datos[i] << " "; // Debería imprimir: A B C
  }

  delete[] datos; // ¡NO OLVIDES LIBERAR LA MEMORIA!
}
