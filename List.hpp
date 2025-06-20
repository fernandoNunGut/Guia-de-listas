#include <iostream>


struct nodoL
{
  char e;
  nodoL *next;
  nodoL *back;
};

class Lista
{
private:
  nodoL *_head;
  nodoL *_tail;
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
    nodoL *aux;
    aux = _head;
    while (aux != nullptr)
    {
      nodoL *aux2 = aux;
      aux = aux->next;
      delete aux2;
    }
  };

  char get() { return _head->e; }; // return the first value the list call the pointer and asigned the elements e

  char get_item(int k)
  {
    if (k < 0 || k >= _largo)
    {
      std::cerr << "Error: posición inválida.\n";
      return '\0'; // o lanza una excepción si prefieres
    }

    nodoL *aux = _head;
    int contador = 0;

    while (aux != nullptr && contador < k)
    {
      aux = aux->next;
      contador++;
    }

    return aux->e;
  }

  char get_item2(int k)
  {
    if (k < 0 || k >= _largo)
    {
      throw std::out_of_range("Índice fuera de rango");
    }

    nodoL *actual;
    int i;

    // Si la posición está en la primera mitad
    if (k <= _largo / 2)
    {
      actual = _head;
      for (i = 0; i < k; i++)
      {
        actual = actual->next;
      }
    }
    else
    {
      // Está en la segunda mitad: retroceder desde el final
      actual = _tail;
      for (i = _largo - 1; i > k; i--)
      {
        actual = actual->back;
      }
    }

    return actual->e;
  }

  char get_back() { return _tail->e; }; // return the finish value the list call the pointer and asigned the elements e

  char get_middle()
  {
    int mitad = _largo / 2;
    nodoL *actual = _head;

    for (int i = 0; i < mitad; i++)
    {
      actual = actual->next;
    }
    return actual->e;
  };

  void add(char e)
  {
    nodoL *nuevo = new nodoL;
    nuevo->e = e;
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

  void add_head(char e)
  {
    nodoL *nuevo = new nodoL;
    nuevo->e = e;
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
      _head = nuevo;       // El nuevo pasa a ser el primero
    }

    _largo++;
  }

  void add_item(int k, char e)
  {
    // Caso 1: agregar al inicio
    if (k == 0)
    {
      add_head(e);
      return;
    }

    // Caso 2: agregar al final
    if (k == _largo)
    {
      add(e);
      return;
    }

    // Caso 3: agregar en el medio
    nodoL *actual = _head; // el nodo actaul esta apuntando a la cabeza 
    for (int i = 0; i < k; ++i) // recorre hasta la posicion
    {
      actual = actual->next; // nodo actual apunta al elemtento ingredaso de actual en next(siguiente)
    }

    nodoL *nuevo = new nodoL;  // creo un nuevo nodo para mantenener las pocisiones
    nuevo->e = e; // nuevo nodo le asigono el valor de e y lugo lo apunto a (e)

    nuevo->next = actual; // el nodo nuevo ingresa el valor del next(sigiente) y apunta al nodo actual
    nuevo->back = actual->back; // el nodo nuevo ingresa el valor del next(sigiente) y apunta elemnto ingresado de actual en back(atras)

    if (actual->back != nullptr) // pregunto si el elemento del nodo de back es distinto de null si es asi ejecuta
    {
      actual->back->next = nuevo; // nodo actual es igual a elemtno de back y back es igual al elemento de next y esto apunta al nodo nuevo
    }
    actual->back = nuevo; // nodo actual es igual al elemento del back y apuntal al nodo nuevo

    _largo++; // el largo de la fila aumenta en 1
  }

  char remove()
  {
    nodoL *borrar = _head;
    _head = _head->next;
    char eliminado = borrar->e;

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

    return eliminado;
  };

  void remove_tail(){
    nodoL *borrar = _tail;
    _tail = _tail->back; 
    
    if(_tail != nullptr){
      _tail->next = nullptr;
    } else{
      _tail = nullptr;
    }

    delete borrar;
    _largo--;
  }

  int size() { return _largo; };

  bool empty()
  {
    if (_largo == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  };

  void mostrar()
  {
    nodoL *aux = _head;
    while (aux != nullptr)
    {
      std::cout << aux->e << " ";
      aux = aux->next;
    }
    std::cout << std::endl;
  }

  bool contains(char e)
  {
    nodoL *aux = _head;

    while (aux != nullptr)
    {
      if (aux->e == e)
      {
        return true; // lo encontró
      }
      aux = aux->next; // avanzar al siguiente nodo
    }

    return false; // recorrió toda la lista y no lo encontró
  }

  void set_item(int k, char e)
  {
    nodoL *actual = _head;
    for (int i = 0; i < k; i++)
    {
      actual = actual->next;
    }
    actual->e = e;
  }
};
