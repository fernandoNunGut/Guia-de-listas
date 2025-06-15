#include <iostream>
#include "..\List.hpp"

int main() {
    Lista lista;
    lista.add('X');
    lista.add('Y');
    lista.add('Z');

    std::cout << "Último elemento (get_back): " << lista.get_back() << std::endl;
    return 0;
}
