struct nodoL
{
    char e;
    nodoL *next;
    nodoL *back;
};

class Lista
{
    private:
        nodoL * _head;
        nodoL * _tail;
        int _largo;
    public:

        // Contructor por defecto de las listas
        Lista(){ _head = nullptr; _tail = nullptr; _largo = 0;}; 

        // destructor
        ~Lista(){
          nodoL *aux;
          aux = _head;
          while (aux != nullptr)
          {
            nodoL *aux2 = aux;
            aux = aux-> next;
            delete aux2;
          }
          
        };
        /**
         * @brief Obtiene el elemento ubicado al principio de la lista
         * 
         * @return char Elemento ubicado al principio de la lista
         */
        char get(){return _head->e;};// retorna el primer valor de lista llamando al puntero y asignandole el elemento [e] (char)
                                     // return the first value the list call the pointer and asigned the elements e
        /**
         * @brief Agrega un elemento al final de la lista
         * 
         * @param e Elemento que se ingresará en la lista
         */
        void add(char e){
          nodoL *nuevo = new nodoL;
          nuevo->e = e;
          nuevo->back = nullptr;
          nuevo->next = nullptr;

          if (_tail == nullptr)
          {
            nuevo = _head;
            nuevo = _tail; 
          } else {                
            _tail->next = nuevo; // the tail ingres to next and point the new(nuevo)
            nuevo->back = _tail; // the new(nuevo) ingres to back(atras) and point the tail
            _tail = nuevo; // the tail point to new(nuevo)
          }
          _largo++; // the long increase in 1
          
        };

        /**
         * @brief Elimina un elemento al principio de la lista
         * 
         */
        void remove();
        /**
         * @brief Retorna la cantidad de elementos que se encuentran en la lista
         * 
         * @return int 
         */
        int size();
        /**
         * @brief Indíca si la lista contiene elementos
         * 
         * @return true La lista contiene elementos
         * @return false La lista no contiene elementos
         */
        bool empty();
};
