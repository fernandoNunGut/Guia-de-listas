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
  /**
   * @brief Obtiene el elemento ubicado al principio de la lista
   *
   * @return char Elemento ubicado al principio de la lista
   */
  char get() { return _head->e; }; // return the first value the list call the pointer and asigned the elements e

  /**
   * @brief Obtiene el elemento ubicado al final de la lista
   *
   * @return  char Elemento ubicado al final de la lista
   */
  char get_back() { return _tail->e; }; // return the finish value the list call the pointer and asigned the elements e

  /**
   * @brief Agrega un elemento al final de la lista
   *
   * @param e Elemento que se ingresará en la lista
   */
  void add(char e)
  {
    nodoL *nuevo = new nodoL;
    nuevo->e = e;
    nuevo->back = nullptr;
    nuevo->next = nullptr;

    if (_tail == nullptr)
    {
      /*
      // implementacion del teacher
      nuevo = _head;
      nuevo = _tail;
      */
      // implementacion prueba
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

  /**
   * @brief Agrega un elemento al principio de la lista
   *
   * @param e Elemento que se ingresará en la lista
   */
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

  /**
   * @brief Elimina un elemento al principio de la lista
   *
   */
  /*
  void remove()
  {
    nodoL *borrar = _head;
    _head = _head->next;

    if (_head != nullptr)
    {
      _head->back = nullptr; // the _head ingres to elements back and point nullptr  (fin de lista)
    }
    else
    {
      _tail = nullptr; // else the _tail pont to nullptr (fin de la lista)
    }
    delete borrar; // delete nodo borrar
    _largo--;      // The long decreases by 1
  };
  */

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

  /**
   * @brief Retorna la cantidad de elementos que se encuentran en la lista
   *
   * @return int
   */
  int size() { return _largo; };
  /**
   * @brief Indíca si la lista contiene elementos
   *
   * @return true La lista no contiene elementos
   * @return false La lista contiene elementos
   */
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
};
