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

  Lista(const Lista& list); // crea una lista secundaria para otros usos

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

  char get_item(int k) // obtinene el elemento de la posicion indicada por k
  {
    if (k < 0 || k >= _largo) // pregunta por k es menor a cero o k es mayor igual a _largo // si se cumple retorna null
    {
      std::cerr << "Error: posición inválida.\n";
      return '\0'; // o lanza una excepción si prefieres
    }

    nodoL *aux = _head; // creamos un nodo aux que apunte a la cabeza de la lista
    int contador = 0; // interamos un contador que se inicializa en 0

    while (aux != nullptr && contador < k) // ejecuta si nodo temporal aux es distinto de nulo y contador es menor a k
    {
      aux = aux->next; // nodo temporal aux apunta a aux ingresado en next // aux ahora es igual al siguiente nodo
      contador++; // contador aumenta en 1
    }

    return aux->e; // retorna elemento de aux 
  }

  char get_item2(int k) // buqueda de elemento mas rapida dividiendo la busqueda de cabeza a elemento o de cola a elemento dependiendo de cual este mas cerca
  {
    if (k < 0 || k >= _largo) // pregunta si valor de entrada k es menor a 0 o k es mayor o igual a largo. si se cumple ejecuta
    {
      throw std::out_of_range("Índice fuera de rango"); 
    }

    nodoL *actual; // creamos un nodo temporal para recorrer lista
    int i; // inicializamos el entero i 

    // Si la posición está en la primera mitad
    if (k <= _largo / 2) // pregunta si k es menor o igual a largo divido en 2 ejecuta 
    {
      actual = _head; // nodo actual apunta a cabeza
      for (i = 0; i < k; i++) //recorremos hasta posicion k 
      {
        actual = actual->next; // nodoo actual apunta a actual ingresado en next
      }
    }
    else //si no 
    {
      // Está en la segunda mitad: retroceder desde el final
      actual = _tail; // actual apunta a cola
      for (i = _largo - 1; i > k; i--) // recorremos lista de cola a posicion k
      {
        actual = actual->back; // nodo actual apunta a actual ingresado en back
      }
    }

    return actual->e; // retorna elemnto de actual 
  }

  char get_back() { return _tail->e; }; // return the finish value the list call the pointer and asigned the elements e

  char get_middle() // retorna el elemento que esta a la mitad de la lista priozando el mayor en caso de lista par
  {
    int mitad = _largo / 2; // creamos espacion temporal mitad que sea igual a _largo dividido en 2 // osea la mitad de la lista
    nodoL *actual = _head; // craemos un nodo temporal para recorrer lista el cual apunta a la cabeza de la lista

    for (int i = 0; i < mitad; i++) // recorremos la lista hasta la mitad dada por mitad = _largo/2;
    {
      actual = actual->next; // nodo temporal actual apunta a actual ingresado en next // ahora actual es igual al siguiente nodo
    }
    return actual->e; // retorna elemento de actual 
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
    nodoL *actual = _head;      // el nodo actaul esta apuntando a la cabeza
    for (int i = 0; i < k; ++i) // recorre hasta la posicion
    {
      actual = actual->next; // nodo actual apunta al elemtento ingredaso de actual en next(siguiente)
    }

    nodoL *nuevo = new nodoL; // creo un nuevo nodo para mantenener las pocisiones
    nuevo->e = e;             // nuevo nodo le asigono el valor de e y lugo lo apunto a (e)

    nuevo->next = actual;       // el nodo nuevo ingresa el valor del next(sigiente) y apunta al nodo actual
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

  void remove_tail()
  {
    nodoL *borrar = _tail;
    _tail = _tail->back;

    if (_tail != nullptr)
    {
      _tail->next = nullptr;
    }
    else
    {
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

  char *copyToRef() // copia de una lista ya creada a un arrego
  {
    if (_largo == 0)  // pegunta si el largo es igual = 0 en ese caso
      return nullptr; // retorna null, proque no tiene elementos la lista

    // Reservar espacio dinámico
    char *arreglo = new char[_largo]; // se crea un espacio dinamico para guardar el arreglo

    nodoL *actual = _head;                                // creamos un nodo temporal para que recorra la lista
    for (int i = 0; i < _largo && actual != nullptr; ++i) // iniicia en el primer elemnto hasta el largo
    {
      arreglo[i] = actual->e; // el arreglo en posicion [i] apunta a nodo actual ingresado en el valor (e)
      actual = actual->next;  // nodo actual apunta al nodo actual ingredado en el siguiente valor(next)
    }

    return arreglo; // Devolver el puntero al arreglo
  }

  void copyTo(char array[])
  {                        // copia lista en arreglo
    nodoL *actual = _head; // crea nodo teporal llamado actual apuntado a _head
    int i = 0;             // inicializa i en 0;

    while (actual != nullptr && i < _largo)
    {                        // pregunta si nodo temporal actual es distinto de nulo Y i el menor al largo de la lista
      array[i] = actual->e;  // arreglo en la posicion que este apunta al nodo temporal ingresado en el valor e
      actual = actual->next; // nodo temporal actual apunta al nodo temporal actual ingresado en el valor siguiente
      ++i;                   // i aumenta en 1  ( se mueve una posicion)
    }
  }

  void copyTo(int pos, char array[])
  {
    if (pos < 0 || pos > _largo)
    {
      return;
    };

    nodoL *actual = _head;

    for (int i = 0; i < pos; i++)
    {
      actual = actual->next;
    }

    int i = 0;
    while (actual != nullptr)
    {
      array[i] = actual->e;
      actual = actual->next;
      i++;
    }
  };

  void copyTo(int pos, char array[], int count)
  {
    if (pos < 0 || pos >= _largo || count < 0 || pos + count > _largo)
    {
      return; // No hace nada si los parámetros no son válidos
    };

    nodoL *actual = _head;

    for (int i = 0; i < pos; i++)
    {
      actual = actual->next;
    };

    // nodoL *final = inicio->back;

    for (int i = 0; i < count && actual != nullptr; i++)
    {
      array[i] = actual->e;
      actual = actual->next;
    };
  };

  void copyTo(int pos, char array[], int k1, int k2)
  {
    if (k1 < 0 || pos < 0 || pos >= _largo || k1 > k2)
    {
      return;
    };

    nodoL *actual = _head;

    for (int i = 0; i < pos; i++)
    {
      actual = actual->next;
    };

    for (int i = 0; i < (k2 - k1) && actual != nullptr; i++)
    {
      array[pos + i] = actual->e;
      actual = actual->next;
    };
  };

  void add(char array[], int n)
  {
    for (int i = 0; i < n; i++)
    {
      add(array[i]);
    };
  };

  void add_head(char array[], int n)
  {
    for (int i = 0; i < n; i++)
    {
      add_head(array[i]);
    };
  };

  void add_at(int k, char array[], int n)
  {
    if (k < 0 || k > _largo || n < 0) return;

    for (int i = 0; i < n; ++i)
    {
      add_item(k + i, array[i]); // cada inserción posterior se ajusta sola
    };
  };
};
