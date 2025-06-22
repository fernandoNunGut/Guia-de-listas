#include <iostream>
#include "..\List.hpp"


Lista::Lista(const Lista& list) {
  _head = nullptr;
  _tail = nullptr;
  _largo = 0;

  nodoL* actual = list._head;
  while (actual != nullptr) {
    this->add(actual->e); // Copiar elemento por elemento
    actual = actual->next;
  }
}


int main(){
Lista original;
original.add('A');
original.add('B');
original.add('C');
original.mostrar();
Lista copia(original);  // Usa el constructor por copia
copia.mostrar();

// Si ahora modificás original o copia, son listas diferentes

}