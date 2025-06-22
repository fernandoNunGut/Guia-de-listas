#include <iostream>

struct nodoLN
{
  int k;
  nodoLN *next;
  nodoLN *back;
};

class Lista
{
private:
  nodoLN *_head;
  nodoLN *_tail;
  int _largo;

public:
  // Contructor por defecto de las listas
  Lista()
  {
    _head = nullptr;
    _tail = nullptr;
    _largo = 0;
  };

  // destructor
  ~Lista()
  {
    nodoLN *aux;
    aux = _head;
    while (aux != nullptr)
    {
      nodoLN *aux2 = aux;
      aux = aux->next;
      delete aux2;
    }
  };

  int size() { return _largo; }; // retorna el largo de la lista

  int get() { return _head->k; }; // retorna el valor al comienzo de la lista

  // void para añadir numeros a la lista
  void addNum(int k) 
  {
    nodoLN *nuevo = new nodoLN; // cramos un nodo nuevo para añadir el nuevo valor a la lista 
    nuevo->k = k; // nodod nuevo ingresado en valor apunta al valor ingresado o lo define como este
    nuevo->back = nullptr; // nuevo nodo ingresado en el valor back apunta al nullptr
    nuevo->next = nullptr; // nueovo nodo ingresado en el valor next apunta a nullptr

    // if para ejecutar en caso de cumplirse condicion  _tail(cola) igual a nullptr
    if (_tail == nullptr) 
    {
      _head = nuevo; // _head apunta a nuevo nodo
      _tail = nuevo; // _tail apunta a nuevo nodo
    }
    else // luego ejecuta
    {
      _tail->next = nuevo; // the tail ingres to next and point the new(nuevo) // la cola ingresa a next y apunta al nuevo nodo
      nuevo->back = _tail; // the new(nuevo) ingres to back(atras) and point the tail / el nuevo nodo  ingresa a back y apunta a la cola(_tail)
      _tail = nuevo;       // the tail point to new(nuevo) // cola apunta a nuevo nodo
    }
    _largo++; // the long increases by 1 // el largo aumenta en 1 
  };

    // void para suplicar al final de la lista
  void duplicarfinal(int k)
  {
    nodoLN *nuevo = new nodoLN; // creamos un nuevo nodo
    nuevo->k = _tail->k; // nuevo nodo ingresado en valor apunta a _tail ingresado en valor 
    nuevo->back = nullptr; // nuevo nodo ingresado en back apunta a nullptr
    nuevo->next = nullptr; // nuevo nodo ingresado en next apunta a nullptr

      // if para enecutar en caso de cumplirse condicion cola es igual a nullptr
    if (_tail == nullptr) 
    {
      _head = nuevo; // cabeza apunta a nuevo nodo
      _tail = nuevo; // cola apunta a nuevo nodo
    }
    else // despues ejecuta 
    {
      _tail->next = nuevo; // the tail ingres to next and point the new(nuevo) // la cola ingresada en next apunta al nuevo nodo 
      nuevo->back = _tail; // the new(nuevo) ingres to back(atras) and point the tail // nuevo nodo ingresado en back apuntando a la  cola 
      _tail = nuevo;       // the tail point to new(nuevo) // la cola apuntando al nuevo nodo
    }
    _largo++; // the long increases by 1 // largo aumenta en 1
  };

    // void para duplicar el primer valor de la lista
  void duplicarPrimero(int k)
  {
    nodoLN *nuevo = new nodoLN; // creamos un nuevo nodo
    nuevo->k = _head->k; // nuevo nodo ingresado en valor apunta a cabeza ingresado en el valor
    nuevo->back = nullptr; // nuevo nodo ingresado en back apunta a nullptr
    nuevo->next = nullptr; // nuevo nodo ingresado en next apunta a nullptr

      // if para ejecutar en caso de cumplirse condicion cabeza sea igual a nullptr
    if (_head == nullptr)
    {
      // Lista vacía: el nuevo nodo es el primero y el último
      _head = nuevo; // cabeza apunta a nuevo nodo
      _tail = nuevo; // cola apunta a nuvo nodo
    }
    else // si no ejecutar
    {
      // Lista no vacía: conectar el nuevo nodo al principio
      nuevo->next = _head; // nuevo nodo ingresado en next apunta a cabeza
      _head->back = nuevo; // cabeza ingresado en back apunta a nuevo nodo
      _head = nuevo; // cabeza apunta a nuevo nodo
    }

    _largo++; // largo aumenta en 1
  }

    // void para duplicar a lo largo de la lista
  void duplicar(int k)
  {
    // Caso 1: agregar al inicio
    if (k == 0) // en caso de cumplirse que la posicion a duplicar se la primera
    {
      duplicarPrimero(k); // llama a duplicarPrimero y ejecuta 
      return; retorna
    }

    // Caso 2: agregar al final
    if (k == _largo) // en caso de cumplirse que posicion a cambiar sea la ultima 
    {
      duplicarfinal(k); // llama a duplicarfinal para duplicar el ultimo nodo
      return; // retorna 
    }

    // Caso 3: agregar en el medio
    nodoLN *actual = _head;     // el nodo actaul esta apuntando a la cabeza
    for (int i = 0; i < k; ++i) // recorre hasta la posicion
    {
      actual = actual->next; // nodo actual apunta al elemtento ingredaso de afctual en next(siguiente)
    }

    nodoLN *nuevo = new nodoLN; // creo un nuevo nodo para mantenener las pocisiones
    nuevo->k = k;               // nuevo nodo le asigono el valor de e y lugo lo apunto a (e)

    nuevo->next = actual;        // el nodo nuevo ingresa el valor del next(sigiente) y apunta al nodo actual
    nuevo->back = actual->back;  // el nodo nuevo ingresa el valor del next(sigiente) y apunta elemnto ingresado de actual en back(atras)
    if (actual->back != nullptr) // pregunto si el elemento del nodo de back es distinto de null si es asi ejecuta
    {
      actual->back->next = nuevo; // nodo actual es igual a elemtno de back y back es igual al elemento de next y esto apunta al nodo nuevo
    }
    actual->back = nuevo; // nodo actual es igual al elemento del back y apuntal al nodo nuevo
    nuevo->k = actual->k;
    _largo++; // el largo de la fila aumenta en 1
  }

    // void para imprimir la lista
  void print()
  {
    nodoLN *aux = _head; // creamos un nodo auxiliar que apunte a la cabeza de la lista para que recorra este desde el principio
    while (aux != nullptr) // pregunta si aux es distindo de nulo para que ejecute 
    {
      std::cout << aux->k << " "; // imprimer en pantalla el valor de aux y un espacio para el sigiente nodo(valor)
      aux = aux->next; // aux apunta a aux ingresado en next // aux ahora toma el valor de next de aux osea el siguiente nodo
    }
    std::cout << std::endl; // imprime un espacio para el orden de al lista
  }

    // void para remover nodo al princiopio de la lista
  void remove()
  {
    nodoLN *borrar = _head; // creamos un nodo auxiliar que apunte al inicio de la lista para que la recorra
    _head = _head->next; // la cabeza de lista apunta a la cabeza ingresada en el next

    if (_head != nullptr) // if apra ejecutar si se cumple condicion cabeza sea distindo de null
    {
      _head->back = nullptr; // cabeza ingresado en valor back apuntando a nullptr
    }
    else // si no 
    {
      _tail = nullptr; // cola apunta a nullptr
    }

    delete borrar; // elimina el nodo borrar o nodo auxiliar
    _largo--; // el largo de la lista disminuye en 1
  };

    // void para remover en posicion especifica de la lista defina como k
  void remove(int k)
  {
    if (k < 0 || k >= _largo) // pregunta si valor k es menor a cero o k es mayor o igual al largo de la lista ejecuta
    {
      throw std::out_of_range("Posición fuera de rango"); // retorna que valor de k ingresado es invalido
    }

    nodoLN *borrar; // creamos un nodo auxiliar llamado borrar para definir cual es el nodo a borrar

    // Caso especial: eliminar el primero
    if (k == 0)  
    {
      return remove(); // Llama al método remove() que ya tienes
    }

    // Caso especial: eliminar el último
    if (k == _largo - 1) // en caso de que k sea igual al _largo -1 ejecuta
    {
      borrar = _tail; // nodo borrar apunta a la cola
      _tail = _tail->back; // la cola apunta a la cola ingresada en back
      _tail->next = nullptr; // la cola ingresada en next apunta a nullptr
    }
    else //si no
    {
      // Caso general: eliminar del medio
      borrar = _head; // nodo borrar apunta a la cabeza de la lista
      for (int i = 0; i < k; ++i) // for para recorrer la lita hasta la posicion ingresada
      {
        borrar = borrar->next;  // nodo borrar apunta a nodo borrar ingresado en next // osea que borrar ahora es igual al siguiente nodo
      }

      nodoLN *anterior = borrar->back; // creamos un nodo anterior que apunte a nodo borrar ingresado en back
      nodoLN *siguiente = borrar->next; // creamos un nodod siguiente que apunte a nodo borrar ingresado en next

      anterior->next = siguiente; // nodo anteriror ingresado en next apunta a nodo (siguiente)
      siguiente->back = anterior; // nodo siguiente ingresado en back apunta a nodo (anteriror)
    }

    char eliminado = borrar->k; // creo espacio temporal char eliminado el cual apunta a nodo borrar ingresado en valor 
    delete borrar; // elimina el nodo borrar
    _largo--; // largo disminuye en 1
  };

    // void remove que elimina todo los nodos de una posicion k1 a otra posicion k2
  void remove(int k1, int k2)
  {
    nodoLN *actual = _head; // creo un nodo temporal actual apuntado a cabeza de la lista para recorrer la lista

    for (int i = 0; i < k1; i++) // for para recorrer la lista hasta primera posicion k1
    {
      actual = actual->next; // acutal apunta a acutual ingresado en next // actual ahora el igual al nodo que esta adelante de el 
    }

    nodoLN *anterior = actual->back; //creo un nodo temporal apuntando a nodo actual ingresado en back

    for (int i = k1; i <= k2; i++) // for para recorrer lista de posicion k1 hasta la posicion k2 
    {
      nodoLN *borrar = actual; // creamos un nodoo borrar que apunte a nodo actual 
      actual = actual->next; // nodo acutal apunta a actual ingresado en next
      delete borrar; // eliminamos el nodo borrar
      _largo--; // largo de lista disminuye en 1
    } 

    nodoLN *siguiente = actual; // creamos un nodo temporal siguiente que apunte a nodo actual

    // reconexion
    if (anterior != nullptr) // ejecuta si nodo anterior es distinto de nullptr
    {
      anterior->next = siguiente; // nodo anterior ingresado en next apunte a nodo( siguiente)
    }
    else // si no 
    {
      _head = siguiente; // cabeza apunta a nodo(siguiente)
    }

    if (siguiente != nullptr) // ejecuta si se cumple que nodo(siguiente es distinto de nullptr)
    {
      siguiente->back = anterior; // nodo siguiente ingresado en back apunta a nodo(anterior)
    }
    else // sino 
    {
      _tail = anterior; // cola apunta a nodo(anterior)
    }
  };

  // void swap para  intercambiar valores de nodos en posicon k1 a k2 y viceverza 
  void swap(int k1, int k2)
  {
    nodoLN *primero = _head; // creamos nodo temporal que apunte a la cabeza de la lista

    for (int i = 0; i < k1; i++) // recorremos la lista hasta la posicion k1
    {
      primero = primero->next; // nodo primero apunta a primero ingresado en next // primero ahora es igual al siguiente nodo
    }

    nodoLN *segundo = _head; // creamos nodo temporal segundo apuntando a cabeza de la lista

    for (int i = 0; i < k2; i++) // recorremos la lista hasta la posicin k2
    {
      segundo = segundo->next; // nodo segundo apunta a segundo ingresado en next // segundo ahroa es igual el siguinete valor 
    }

    char aux = primero->k; // creamos espacion temporal char que sea igual a nodo primero ingresado en valor de este
    primero->k = segundo->k; // nodo primero ingresado en valor es igual a segundo ingresado en valor 
    segundo->k = aux; // nodo segundo es igual a aux ( el cual almecenaba el valor del nodo primero ingresado en valor )
  };

    // void clear para limpiar lista pero que siga funcionando 
  void clear()
  {
    nodoLN *actual = _head; // creamos un nodo temporal actual que apunte a la cabeza de la lista
    while (actual != nullptr) // ejecuta si se cumple que nodo actual es distinto de nullptr
    {
      nodoLN *siguiente = actual->next; // cremos un nodo temporal siguiente que apunte a nodo actual ingresado en next
      delete actual; // elimina el nodo actual
      actual = siguiente; // nodo actual ahora apunta al nodo siguiente
    }

    _head = nullptr; // cabeza de alista apunta a nullptr
    _tail = nullptr; // cola de la lista ahora apunta a nullptr
    _largo = 0; // define el largo de la lista en 0
  };

    // copiar la lista en un arrego defiendo el valor de cada nodo como un nuevo elemento del arreglo
  int *copyToRef()  
  {
    if (_largo == 0) // pregunta si el largo de la lista es igual a 0 retorna nulo
      return nullptr;

    // Reservar espacio dinámico
    int *arreglo = new int[_largo]; // crea un arreglo de enteros y define que sea igual al largo de la lista ( cantidad de nodos de esta)

    nodoLN *actual = _head; // crea un nuodo temporal que apunte a la cabeza de la lista
    for (int i = 0; i < _largo && actual != nullptr; ++i) // recorre al lista hasta el largo de esta y que es ta no sea nula 
    {
      arreglo[i] = actual->k; //ingresa al arrego y define de valor al nodo ingresado en valor osea que le asigna su valor
      actual = actual->next; // nodo actual apunta a nodo actual ingresado en next // actual ahora es igual al siguiente nodo
    }

    return arreglo; // Devolver el puntero al arreglo
  }

  void forEach((void *f)(char e)){

  };
};