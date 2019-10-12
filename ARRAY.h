#define MAX 1000
/*
    Questa classe crea un oggetto di tipo Array che permette di eseguire azioni simili ad uno Stack come
    Pop(togliere l'ultimo elemento inserito) e Push(inserire un elemnto nello Stack)
*/
class ARRAY
{
    private:
            int MainArray[MAX];
            int N;

    public:
             ARRAY();

        void Print ();
        void Sort  ();//DA SCRIVERE
        void Mirror();//DA SCRIVERE

        bool pushBack      (int x);
        bool pushFront     (int x);
        bool popBack       (int x);
        bool popFront      (int x);

        bool Research      (int key, SHORT &Position);//DA SCRIVERE

        bool getMinimum    ();
        bool extractMinimum();

        int  getSum ();
        int  getSize();

        double getAverage();
};



