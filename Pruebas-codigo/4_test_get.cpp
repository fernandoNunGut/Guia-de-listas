#include <iostream>
#include "..\List.hpp"

int main() {
    Lista lista;
    lista.add('H');
    std::cout << "Primer elemento (get): " << lista.get() << std::endl;
    return 0;
}
