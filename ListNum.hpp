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

  int size() { return _largo; };

  int get() { return _head->k; };

  void addNum(int k)
  {
    nodoLN *nuevo = new nodoLN;
    nuevo->k = k;
    nuevo->back = nullptr;
    nuevo->next = nullptr;

    if (_tail == nullptr)
    {
      _head = nuevo;
      _tail = nuevo;
    }
    else
    {
      _tail->next = nuevo; // the tail ingres to next and point the new(nuevo)
      nuevo->back = _tail; // the new(nuevo) ingres to back(atras) and point the tail
      _tail = nuevo;       // the tail point to new(nuevo)
    }
    _largo++; // the long increases by 1
  };

  void duplicarfinal(int k)
  {
    nodoLN *nuevo = new nodoLN;
    nuevo->k = _tail->k;
    nuevo->back = nullptr;
    nuevo->next = nullptr;

    if (_tail == nullptr)
    {
      _head = nuevo;
      _tail = nuevo;
    }
    else
    {
      _tail->next = nuevo; // the tail ingres to next and point the new(nuevo)
      nuevo->back = _tail; // the new(nuevo) ingres to back(atras) and point the tail
      _tail = nuevo;       // the tail point to new(nuevo)
    }
    _largo++; // the long increases by 1
  };

  void duplicarPrimero(int k)
  {
    nodoLN *nuevo = new nodoLN;
    nuevo->k = _head->k;
    nuevo->back = nullptr;
    nuevo->next = nullptr;

    if (_head == nullptr)
    {
      // Lista vacía: el nuevo nodo es el primero y el último
      _head = nuevo;
      _tail = nuevo;
    }
    else
    {
      // Lista no vacía: conectar el nuevo nodo al principio
      nuevo->next = _head; // El nuevo apunta al actual primero
      _head->back = nuevo; // El anterior primero apunta hacia atrás al nuevo
      _head = nuevo;
    }

    _largo++;
  }

  void duplicar(int k)
  {
    // Caso 1: agregar al inicio
    if (k == 0)
    {
      duplicarPrimero(k);
      return;
    }

    // Caso 2: agregar al final
    if (k == _largo)
    {
      duplicarfinal(k);
      return;
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

  void print()
  {
    nodoLN *aux = _head;
    while (aux != nullptr)
    {
      std::cout << aux->k << " ";
      aux = aux->next;
    }
    std::cout << std::endl;
  }

  void remove()
  {
    nodoLN *borrar = _head;
    _head = _head->next;

    if (_head != nullptr)
    {
      _head->back = nullptr;
    }
    else
    {
      _tail = nullptr;
    }

    delete borrar;
    _largo--;
  };

  void remove(int k)
  {
    if (k < 0 || k >= _largo)
    {
      throw std::out_of_range("Posición fuera de rango");
    }

    nodoLN *borrar;

    // Caso especial: eliminar el primero
    if (k == 0)
    {
      return remove(); // Llama al método remove() que ya tienes
    }

    // Caso especial: eliminar el último
    if (k == _largo - 1)
    {
      borrar = _tail;
      _tail = _tail->back;
      _tail->next = nullptr;
    }
    else
    {
      // Caso general: eliminar del medio
      borrar = _head;
      for (int i = 0; i < k; ++i)
      {
        borrar = borrar->next;
      }

      nodoLN *anterior = borrar->back;
      nodoLN *siguiente = borrar->next;

      anterior->next = siguiente;
      siguiente->back = anterior;
    }

    char eliminado = borrar->k;
    delete borrar;
    _largo--;
  };

  void remove(int k1, int k2)
  {
    nodoLN *actual = _head;

    for (int i = 0; i < k1; i++)
    {
      actual = actual->next;
    }

    nodoLN *anterior = actual->back;

    for (int i = k1; i <= k2; i++)
    {
      nodoLN *borrar = actual;
      actual = actual->next;
      delete borrar;
      _largo--;
    }

    nodoLN *siguiente = actual;

    // reconexion
    if (anterior != nullptr)
    {
      anterior->next = siguiente;
    }
    else
    {
      _head = siguiente;
    }

    if (siguiente != nullptr)
    {
      siguiente->back = anterior;
    }
    else
    {
      _tail = anterior;
    }
  };

  void swap(int k1, int k2)
  {
    nodoLN *primero = _head;

    for (int i = 0; i < k1; i++)
    {
      primero = primero->next;
    }

    nodoLN *segundo = _head;

    for (int i = 0; i < k2; i++)
    {
      segundo = segundo->next;
    }

    char aux = primero->k;
    primero->k = segundo->k;
    segundo->k = aux;
  };

  void clear()
  {
    nodoLN *actual = _head;
    while (actual != nullptr)
    {
      nodoLN *siguiente = actual->next;
      delete actual;
      actual = siguiente;
    }

    _head = nullptr;
    _tail = nullptr;
    _largo = 0;
  };

  int *copyToRef()
  {
    if (_largo == 0)
      return nullptr;

    // Reservar espacio dinámico
    int *arreglo = new int[_largo];

    nodoLN *actual = _head;
    for (int i = 0; i < _largo && actual != nullptr; ++i)
    {
      arreglo[i] = actual->k;
      actual = actual->next;
    }

    return arreglo; // Devolver el puntero al arreglo
  }
};