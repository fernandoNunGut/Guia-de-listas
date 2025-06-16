#include <iostream>
#include "..\List.hpp"

int main() {
    Lista miLista;

    miLista.add('A');
    miLista.add('B');
    miLista.add('C');
    miLista.add('D');

    std::cout << "Antes de reemplazar:" << std::endl;
    miLista.mostrar();  // A B C D

    // Reemplazar el segundo elemento (índice 1, es 'B') con 'X'
    miLista.set_item(1, 'X');

    std::cout << "Después de reemplazar posición 1 por 'X':" << std::endl;
    miLista.mostrar();  // A X C D

    return 0;
}
