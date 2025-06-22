#include <iostream>
#include "..\List.hpp"

int main()
{
  char datos[] = {'H', 'o', 'l', 'a'};
  int n = sizeof(datos) / sizeof(char); // n = 4

  Lista miLista;
  miLista.add(datos, n);

  // Resultado esperado en la lista: H <-> o <-> l <-> a
  miLista.mostrar();
}