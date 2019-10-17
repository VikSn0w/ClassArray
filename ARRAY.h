#define MAX 1000000
/*
    Questa classe crea un oggetto di tipo vettore che permette di eseguire azioni simili ad uno Stack come
    Pop(togliere l'ultimo elemento inserito) e Push(inserire un elemnto nello Stack)
*/
class ARRAY
{
    private:

            int  PhysicalSize;
            int* MainArray;
            int N;

            bool mergeActive(int Array[], int N);


    public:
             ARRAY();

        void Print ();
        void Help();

        int Mirror();

        bool pushBack      (int x);
        bool pushFront     (int x);
        bool popBack       (int x);
        bool popFront      (int x);

        bool getMinimum    ();
        bool extractMinimum();

        bool Sort          ();

        int spaceControl   ();

        int getSum         ();
        int getSize        ();
        int Research       (int key);
        int setSize        (int M);

        double getAverage  ();
};




