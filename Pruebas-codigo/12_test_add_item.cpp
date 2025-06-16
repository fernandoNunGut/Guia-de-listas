#include <iostream>
#include "..\List.hpp"

int main() {
    Lista miLista;

    miLista.add('A');
    miLista.add('B');
    miLista.add('C');
    miLista.add('D'); // Lista: A B C D

    std::cout << "Lista original:\n";
    miLista.mostrar();  // A B C D

    std::cout << "Agregando 'X' en posición 2:\n";
    miLista.add_item(2, 'X');

    miLista.mostrar();  // A B X C D

    std::cout << "Agregando 'Y' en posición 0:\n";
    miLista.add_item(0, 'Y');  // Igual a add_head

    miLista.mostrar();  // Y A B X C D

    std::cout << "Agregando 'Z' al final:\n";
    miLista.add_item(miLista.size(), 'Z');  // Igual a add

    miLista.mostrar();  // Y A B X C D Z

    return 0;
}
