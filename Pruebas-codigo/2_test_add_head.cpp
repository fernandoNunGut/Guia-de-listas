#include <iostream>
#include "..\List.hpp"

int main() {
    Lista lista;
    lista.add_head('X');
    lista.add_head('Y');
    lista.add_head('Z');

    std::cout << "Lista tras agregar Z, Y, X al principio:\n";
    lista.mostrar();
    return 0;
}
