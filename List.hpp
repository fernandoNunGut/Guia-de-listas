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

  void add(char e) // añadir un nuevo nodo con su elemento al final de la lista
  {
    nodoL *nuevo = new nodoL; // creamos un nuevo nodo 
    nuevo->e = e; // nuevo ingresado en valor apunta al valor e
    nuevo->back = nullptr; // nuevo nodo ingresado en back apunta a nullptr
    nuevo->next = nullptr; // nuevo nodo ingresado a next apunta a nullptr

    if (_tail == nullptr) // preguntamos si cola es igual a null // ejecuta
    {
      _head = nuevo; // cabeza apunta a nuevo 
      _tail = nuevo; // cola apunta a nuevo
    }
    else si no
    {
      _tail->next = nuevo; // the tail ingres to next and point the new(nuevo) // la cola ingresada en next y apunta a nuevo
      nuevo->back = _tail; // the new(nuevo) ingres to back(atras) and point the tail // el nuevo ingresado en back y apunta a la cola 
      _tail = nuevo;       // the tail point to new(nuevo) // la cola apunta a nuevo;
    }
    _largo++; // the long increases by 1 // largo aumenta en 1
  };

  void add_head(char e) // anade un nuevo nodo con su elemento al principio de la lista
  {
    nodoL *nuevo = new nodoL; // creamos un nuevo nodo
    nuevo->e = e; // nuevo ingresado en valor apunta al valor 
    nuevo->back = nullptr; // nuevo ingresado en back apunta a null
    nuevo->next = nullptr; // nuevo ingresado en next apunta a null

    if (_head == nullptr) // pregunta si cabeza es igual a null // ejecuta 
    {
      // Lista vacía: el nuevo nodo es el primero y el último
      _head = nuevo; // cabeza apunta a nuevo 
      _tail = nuevo; // cola apunta a nuevo 
    }
    else // si no 
    {
      // Lista no vacía: conectar el nuevo nodo al principio
      nuevo->next = _head; // El nuevo apunta al actual primero
      _head->back = nuevo; // El anterior primero apunta hacia atrás al nuevo
      _head = nuevo;       // El nuevo pasa a ser el primero
    }

    _largo++; // largo aumenta en 1 
  }

  void add_item(int k, char e) // añade un nuevo nodo en la posicion indicada
  {
    // Caso 1: agregar al inicio 
    if (k == 0)
    {
      add_head(e); // llama a ingresar al inicio funcion ya creada
      return;
    }

    // Caso 2: agregar al final
    if (k == _largo)
    {
      add(e); // llama a ingresar al final funcion ya creada
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

  char remove() // elimina un nodo al inicio de la lista
  {
    nodoL *borrar = _head; // creamos un nodo temporal borrar apuntado a cabeza de la lista
    _head = _head->next; // cabeza apuntado a cabeza ingresada en valor de next
    char eliminado = borrar->e; // // creo memoria temporal llamada eliminado la cual guarda el valor de borrar ingresado en valor 

    if (_head != nullptr) // pregunra si cabeza es distinto de nullo // si se cumple ejecuta 
    {
      _head->back = nullptr; // cabeza ingresada en valor de back apunta a null
    }  
    else // si no 
    {
      _tail = nullptr; // cola apunta a null
    }

    delete borrar; // elimina el nodo borrar
    _largo--; // largo de la lista disminuye en 1

    return eliminado; // retorna el elemento eliminado 
  };

  void remove_tail() // elimina el ultimo nodo de la lista
  {
    nodoL *borrar = _tail; // creamos un nodo temporal borrar apuntando a la cola de la lista
    _tail = _tail->back; // cola apunta a cola ingresada en valor de back

    if (_tail != nullptr) // pregunta si cola es distinta de null // si se cumple ejecuta 
    {
      _tail->next = nullptr; // cola ingresada en valor del next apunta a null
    }
    else // si no 
    {
      _tail = nullptr; // cola apunta a null
    }

    delete borrar; // elimina el nodo borrar
    _largo--; // el largo de la lista disminuye en 1
  }

  int size() { return _largo; }; // retorna el largo de la lista 
 
  bool empty() // para sabes si la lista esta vacia o no 
  {
    if (_largo == 0) // pregunta si _largo es igual a 0 // si se cumple ejecuta 
    {
      return true; // retorna verdadero la lista esta vacia 
    }
    else // si no 
    {
      return false; // retorna falso la lista tiene contenido 
    }
  };

  void mostrar() // funcion para mostar la lista
  { 
    nodoL *aux = _head; // ceramos un nodo temporal aux apuntando a la cabeza de la lista para ir recorriendo esta
    while (aux != nullptr) // preguntamos si aux es distinto de null // si se cumple ejecuta
    {
      std::cout << aux->e << " "; // imprime el valor del nodo aux
      aux = aux->next; // nodo aux apunta al aux ingresado en valor de next // aux ahora es igual al siguiente nodo
    }
    std::cout << std::endl; // imprime espacion para ordenar impresion
  }

  bool contains(char e) // funcion para encontrar valor en la lista
  {
    nodoL *aux = _head; // creamos un nodo temporal para recorrer la lista el cual apunta a la cabeza de la lista

    while (aux != nullptr) // rpeguntamos si aux es distinto de nullo // si se cumple ejecuta 
    {
      if (aux->e == e) // pregunta si aux ingresado en valor es igual al valor 
      {
        return true; // lo encontró
      } // si no 
      aux = aux->next; // aux apunta a aux ingresado en next // ahora es igual al siguiente nodo
    }

    return false; // recorrió toda la lista y no lo encontró
  }

  void set_item(int k, char e) // reemplaza valor de nodo por parametro de entrada e 
  {
    nodoL *actual = _head; // creamos un nodo temporal actual apuntado a la cabeza para recorrer lista
    for (int i = 0; i < k; i++) // recorremos lista hasta posicion indicada por k
    {
      actual = actual->next; // acutal punta a actual ingresado en next // ahora actual es igual al siguiente nodo
    }
    actual->e = e; // actual ingresado en valor apunta a parametro de entrada // ahora elemento de nodo actual es igaul a parametro de entrada 
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

  void copyTo(int pos, char array[]) // funcion para copiar lista en arreglo 
  {
    if (pos < 0 || pos > _largo) // primero preguntamos si pos es menor a cero o pos es mayor a _largo // si se cumpel  ejecuta 
    {
      return; // returna ( invalido)
    };

    nodoL *actual = _head; // creamos un nodo temporal actual apuntando a cabeza // para recorrer la lista

    for (int i = 0; i < pos; i++) // recorremos lista hasta la posicin indicada 
    {
      actual = actual->next; // nodo actual apunta a actual ingresado en valor next
    }

    int i = 0; // inicializamos i en 0 // para el arreglo 
    while (actual != nullptr) // pregunta si actual es distinto de nulo // si se cumple ejecuta 
    {
      array[i] = actual->e; // arreglo en posicion i apunta a acutal ingresado en su valor // ingresa ese valor de actual a la posicion i de arreglo 
      actual = actual->next; // nodo acutal apunta a actual ingresado en valor next // ahora actual es igual al siguiente nodo
      i++; // i aumenta en 1 //  posicion de arreglo avanza una posicion 
    }
  };

  void copyTo(int pos, char array[], int count) // copiamos lista en arreglo de una posicion hasta la cantidad de elementos indicados
  {
    if (pos < 0 || pos >= _largo || count < 0 || pos + count > _largo) // pregunta si pos es menor a 0 o pos es mayor o igual a largo o count es menor a 0 o pos mas count es mayor a largo 
    {
      return; // No hace nada si los parámetros no son válidos
    };

    nodoL *actual = _head; // creamos un nodo temporal actual apuntando a _head // para recorrer a primera posicion 

    for (int i = 0; i < pos; i++) // recorremos lista hasta pos 
    {
      actual = actual->next; // actual apunta a actual en valor next // actual ahora es igual al siguiente nodo
    };


    for (int i = 0; i < count && actual != nullptr; i++) // recorremos lista de hasta count(cantidad de elementos) y actual no sea null
    {
      array[i] = actual->e; // arreglo en posicion i apunta  a actual ingresado en su valor // guarda valor de elemnto de actual en posicion i de arreglo
      actual = actual->next; // nodo actual apunta a acutal ingresado en next // ahora actual es igual al siguente  nodo 
    };
  };

  void copyTo(int pos, char array[], int k1, int k2) // copiar lista en arreglo de una posicion k1 hasta otra k2
  {
    if (k1 < 0 || pos < 0 || pos >= _largo || k1 > k2) // pregunta por datos que son invalidos devulve codigo vaicio 
    {
      return;
    };

    nodoL *actual = _head; // creamos nodo temporal actual apuntando a cabeza de la lista para recorrerla 

    for (int i = 0; i < pos; i++) // recorremos lista hasta la pos
    {
      actual = actual->next; // actual apunta actual ingresada en next (ahora actual es igual al siguiente nodo)
    };

    for (int i = 0; i < (k2 - k1) && actual != nullptr; i++) // recorremos lista hasta posicon (k2-k1) y que cumla que actual sea distinto de nullo
    {
      array[pos + i] = actual->e; // arreglo en (posicion + i) apunta a actual ingresado en valor e // guarda valor de actual->e en arreglo 
      actual = actual->next; // nodo actual apuntando en actual ingresado en next // ahora actual es igual al siguiente nodo
    };
  };

  void add(char array[], int n) // funcion para añadir elementos del arreglo al final de la lista
  {
    for (int i = 0; i < n; i++) // recorre el arreglo hasta n 
    {
      add(array[i]); // agrelos elementos de arreglo llamando a la funcion add ingresandole el valor de arreglo 
    };
  };

  void add_head(char array[], int n) // añade los elemntod del arreglo al principio de la lista
  {
    for (int i = 0; i < n; i++) // recorre la el arreglo hasta n
    {
      add_head(array[i]); // añade los elementos del arrego llamando a la funcion add_head ingresandole como valor el arreglo en posicion 
    };
  };

  void add_at(int k, char array[], int n) // añade elementos desde la posicion indicada k de la lista,  
  {
    if (k < 0 || k > _largo || n < 0) return; // pregunta si parametro de entrada k es valido o no 

    for (int i = 0; i < n; ++i) // recorre arreglo hasta n
    {
      add_item(k + i, array[i]); // añade elementos empezando con k posion mas i posion inicial de recorrido del arreglo y elemento arreglo en misma posicion de i 
    };
  };
};
