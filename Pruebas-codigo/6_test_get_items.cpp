#include <iostream>
#include "..\List.hpp"

int main() {
    Lista lista;
    lista.add('L');
    lista.add('M');
    lista.add('N');

    std::cout << "Elemento en posición 0: " << lista.get_item(0) << std::endl;
    std::cout << "Elemento en posición 2: " << lista.get_item(2) << std::endl;
    return 0;
}
