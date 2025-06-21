#include <iostream>
#include "..\List.hpp"

int main()
{
  Lista miLista;

  miLista.add('A'); // 0
  miLista.add('B'); // 1
  miLista.add('C'); // 2
  miLista.add('D'); // 3
  miLista.add('E'); // 4

  char array[3];
  miLista.copyTo(2, array, 3);

  for (int i = 0; i < 3; ++i)
  {
    std::cout << array[i] << " ";
  }
}