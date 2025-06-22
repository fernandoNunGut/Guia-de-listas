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

  char arr[2];
  miLista.copyTo(2, arr, 2);

  for (int i = 0; i < 2; ++i)
  {
    std::cout << arr[i] << " ";
  }
  // Esperado: C D
}