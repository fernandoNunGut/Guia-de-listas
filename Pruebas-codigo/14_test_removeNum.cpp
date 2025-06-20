#include <iostream>
#include "..\ListNum.hpp"


int main(){
  Lista miLista;

  miLista.addNum(1);
  miLista.addNum(2);
  miLista.addNum(3);
  miLista.addNum(4);
  miLista.addNum(5);
  miLista.addNum(6);
  miLista.addNum(7);
  miLista.addNum(8);
  miLista.addNum(9);
  miLista.addNum(10);

  miLista.print();

  miLista.remove(1,8);

  miLista.print();
}