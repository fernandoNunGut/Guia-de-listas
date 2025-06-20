#include <iostream>
#include "..\List.hpp"

int main() {
    Lista lista;
    lista.add('A');
    lista.add('B');
    lista.add('C');
    std::cout << "Antes de eliminar: ";
    lista.mostrar();

    lista.remove_tail();
    std::cout << "Después de eliminar 1 elemento: ";
    lista.mostrar();

    return 0;
}
