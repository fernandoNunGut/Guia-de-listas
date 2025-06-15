#include <iostream>
#include "..\List.hpp"

int main() {
    Lista lista;
    lista.add('A');
    lista.add('B');
    lista.add('C');

    std::cout << "Lista tras agregar A, B y C:\n";
    lista.mostrar(); // Asume que tienes una función mostrar()
    return 0;
}
