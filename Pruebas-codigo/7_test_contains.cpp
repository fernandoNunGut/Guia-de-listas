#include <iostream>
#include "..\List.hpp"

int main() {
    Lista lista;
    lista.add('P');
    lista.add('Q');

    std::cout << "¿Contiene 'P'? " << (lista.contains('P') ? "Sí" : "No") << std::endl;
    std::cout << "¿Contiene 'Z'? " << (lista.contains('Z') ? "Sí" : "No") << std::endl;
    return 0;
}
