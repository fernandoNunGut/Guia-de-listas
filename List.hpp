struct nodoL
{
    char e;
    nodoL *next;
    nodoL *back;
};

class List
{
    private:
        nodoL * _head;
        nodoL * _tail;
        int _largo;
    public:
        List();
        ~List();
        /**
         * @brief Obtiene el elemento ubicado al principio de la lista
         * 
         * @return char Elemento ubicado al principio de la lista
         */
        char get();
        /**
         * @brief Agrega un elemento al final de la lista
         * 
         * @param e Elemento que se ingresará en la lista
         */
        void add(char e);
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
