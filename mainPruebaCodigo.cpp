#include <iostream>
#include "List.hpp" // opcional si luego separas el .hpp

int main() {
    Lista miLista;

    std::cout << "¿Lista vacía? " << (miLista.empty() ? "Sí" : "No") << std::endl;

    std::cout << "Agregando elementos: A, B, C" << std::endl;
    miLista.add('A');
    miLista.add('B');
    miLista.add('C');

    std::cout << "Contenido de la lista: ";
    miLista.mostrar();

    std::cout << "¿Lista vacía? " << (miLista.empty() ? "Sí" : "No") << std::endl;
    std::cout << "Tamaño de la lista: " << miLista.size() << std::endl;

    std::cout << "Primer elemento (get): " << miLista.get() << std::endl;

    std::cout << "Eliminando un elemento (remove)..." << std::endl;
    miLista.remove();

    std::cout << "Nuevo primer elemento: " << miLista.get() << std::endl;
    std::cout << "Tamaño actual: " << miLista.size() << std::endl;

    std::cout << "Eliminando todos los elementos..." << std::endl;
    while (!miLista.empty()) {
        std::cout << "Eliminado: " << miLista.get() << std::endl;
        miLista.remove();
    }

    std::cout << "¿Lista vacía? " << (miLista.empty() ? "Sí" : "No") << std::endl;
    std::cout << "Tamaño final: " << miLista.size() << std::endl;

    std::cout << "Contenido de la lista: ";
    miLista.mostrar();

    return 0;
}
