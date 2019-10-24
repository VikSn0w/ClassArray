#define MAX 1000000
/*
    Questa classe crea un oggetto di tipo vettore che permette di eseguire azioni simili ad uno Stack come
    Pop(togliere l'ultimo elemento inserito) e Push(inserire un elemnto nello Stack)
*/
template <class T>
class ARRAY
{
    private:
            int  PhysicalSize;
            T* MainArray;
            int N;

            T  cryptoFunc  (T x);
            T  decryptoFunc(T x);
            bool mergeActive(T Array[], int N);


    public:
             ARRAY();
            ~ARRAY();

        void Print ();
        void Help();

        int Mirror();

        bool pushBack      (T x);
        bool pushFront     (T x);
        bool popBack       (int x);
        bool popFront      (int x);

        bool getMinimum    (T &Minimum);
        bool extractMinimum();

        bool Sort          ();

        int spaceControl   ();

        T   getSum         ();
        int getSize        ();
        T   Research       (T key);
        int setSize        (int M);

        double getAverage  ();
};




