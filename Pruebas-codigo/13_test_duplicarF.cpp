#include <iostream>
#include "..\ListNum.hpp"



int main(){
  Lista miLista;


  miLista.addNum(1);
  miLista.addNum(2);
  miLista.addNum(3);
  miLista.addNum(4);
  miLista.addNum(5);
  
  miLista.print();
  std::cout << "================= duplica posicion 0 ==================="<< std::endl;
  miLista.duplicar(0); // duplica la posicion 0
  miLista.print();
  std::cout << "================= elimina el elemento 1 ================"<< std::endl;
  miLista.remove(1);
  miLista.print();
  std::cout << "================= duplica posicion 4 ==================="<< std::endl;
  miLista.duplicar(4); // duplica la posicion 4 
  miLista.print();
  std::cout << "================= elimina el elemento 4 ================"<< std::endl;
  miLista.remove(4);
  miLista.print();
  std::cout << "================= duplica posicion 3 ==================="<< std::endl;
  miLista.duplicar(3); // duplica la posicion 3
  miLista.print();
  std::cout << "========================================================" << std::endl;
}