#define MAX 1000000
#include <iostream> //console output
#include <fstream>  //file i/o
#include <iomanip>  //output format
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

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
            void simpleSort(T V[], int N);
            void insertionSort(T V[], int N);
            void selectionSort(T V[], int N);

    public:
             ARRAY();
            ~ARRAY();

        void help           ();
        void printOnConsole (int indexStart, int indexEnd);

        int  mirror         ();

        bool pushBack       (T x);
        bool pushFront      (T x);
        bool popBack        (int x);
        bool popFront       (int x);

        bool getMinimum     (T &Minimum);
        bool getMaximum     (T &Maximum);
        bool getIndexMinimum     (int &Minimum);
        bool getIndexMaximum     (int &Maximum);
        bool extractMinimum ();
        bool extractMaximum ();

        bool sort           (short type);

        int spaceControl    ();

        T   getSum          ();
        int getSize         ();
        T   search        (T key);
        int setSize         (int M);
        int swapElement     (int indexA, int indexB);

        double getAverage   ();
};





