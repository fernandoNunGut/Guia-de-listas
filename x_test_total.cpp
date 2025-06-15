#include <iostream>
#include "List.hpp"

int main() {
    Lista lista;
    lista.add('A');
    lista.add('B');
    lista.add('C');
    lista.add_head('Z');

    lista.mostrar();
    std::cout << "Primer elemento: " << lista.get() << std::endl;
    std::cout << "Último elemento: " << lista.get_back() << std::endl;
    std::cout << "Tamaño: " << lista.size() << std::endl;

    std::cout << "Contiene 'B': " << (lista.contains('B') ? "Sí" : "No") << std::endl;
    std::cout << "Elemento en posición 1: " << lista.get_item(1) << std::endl;

    while (!lista.empty()) {
        std::cout << "Eliminando: " << lista.get() << std::endl;
        lista.remove();
    }

    return 0;
}
