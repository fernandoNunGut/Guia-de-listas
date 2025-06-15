#include <iostream>
#include "..\List.hpp"

int main() {
    Lista lista;

    std::cout << "¿Lista vacía? " << (lista.empty() ? "Sí" : "No") << std::endl;
    lista.add('1');
    std::cout << "¿Lista vacía tras agregar? " << (lista.empty() ? "Sí" : "No") << std::endl;
    std::cout << "Tamaño: " << lista.size() << std::endl;

    return 0;
}
