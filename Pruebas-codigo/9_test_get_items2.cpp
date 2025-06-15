#include <iostream>
#include "..\List.hpp"

int main() {
    Lista lista;
    lista.add('L');
    lista.add('M');
    lista.add('N');
    lista.add('R');
    lista.add('T');
    lista.add('Y');

    lista.mostrar() ;

    std::cout << "Elemento en posición 4: " << lista.get_item2(3) << std::endl;
    std::cout << "Elemento en posición 3: " << lista.get_item2(2) << std::endl;
    std::cout << "Elemento en posición 6: " << lista.get_item2(5) << std::endl;
    return 0;
}