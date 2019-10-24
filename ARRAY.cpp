#include "ARRAY.h"

#define EXPRESSION (10/3 * 4)

//CONSTRUCTOR
template <typename T>
ARRAY<T>::ARRAY()
{
    T x,
      y;

    PhysicalSize = 100;
    MainArray = new (std::nothrow) T [PhysicalSize];
    N = 0;
    ifstream F;

    F.open("$$ARRAY$$.save");
    if(F.is_open())
    {
        F >> x;
        while(!F.eof())
        {
            pushBack(decryptoFunc(x));
            F >>x;
        }
        F.close();
    }
}
template <typename T>
ARRAY<T>::~ARRAY()
{
    ofstream F;
    F.open("$$ARRAY$$.save");
    if(F.is_open())
    {
        for(int i = 0; i < N; i++) F << cryptoFunc(MainArray[i]) << endl;
        F.close();
    }
    delete []MainArray;
}

template <typename T>
T ARRAY<T>::cryptoFunc(T x)
{
    x = x + EXPRESSION;
    return x;
}

template <typename T>
T ARRAY<T>::decryptoFunc(T x)
{
    x = x - EXPRESSION;
    return x;
}

//VOID SEGMENT
template <typename T>
void ARRAY<T>::Print()
{
    for(int i = 0; i < N; i++)
    {
        std::cout << setw(15) << MainArray[i];
    }
}

template <typename T>
void ARRAY<T>::Help()
{
    std::cout << "Here is a list of all the methods that you can use within this class" << endl << endl;
    std::cout << "Help           ()        = Prints the all the methods on the road" << endl;
    std::cout << "Print          ()        = Prints the Array " << endl;
    std::cout << "Mirror         ()        = Mirrors the Array" << endl;
    std::cout << "Sort           ()        = Sorts the Array (Merge Sort)" << endl;
    std::cout << "Research       (int key) = Researches a number in the Array " << endl << endl;

    std::cout << "pushBack       (int x)   = Inserts new numbers from the last cell of the Array" << endl;
    std::cout << "pushFront      (int x)   = Inserts new numbers from the first cell of the Array" << endl;
    std::cout << "popBack        (int x)   = Deletes the last element in the last cell of the Array" << endl;
    std::cout << "popFront       (int x)   = Deletes the first element in the first cell of the Array" << endl<< endl;

    std::cout << "spaceControl   ()        =  Verifies if the Array has been resized" << endl<< endl;

    std::cout << "getMinimum     ()        = Gets the minimum number in the Array" << endl;
    std::cout << "getAverage     ()        = Calculates the average number of the Array" << endl;
    std::cout << "getSum         ()        = Calculates the sum of the numbers in the Array" << endl;
    std::cout << "getSize        ()        = Gets the current size of the Array" << endl << endl;

    std::cout << "extractMinimum ()        = Exctracts the minimum number in the array and deletes it " << endl << endl;

    std::cout << "setSize        (int M)   = Sets the size of the Array" << endl;
}

//BOOL SEGMENT
template <typename T>
bool ARRAY<T>::mergeActive(T Array[], int N)
{
    if(N > 1)
    {
        int Center, Sx, Dx, k;
        T* W; //Prende lo spazio dall'heap

        Center = N/2; //Metà del vettore
        mergeActive(Array, Center);
        mergeActive(Array+Center, N-Center);

        W = new (std::nothrow) int[N];

        for(Sx = 0, Dx = Center, k = 0; k < N; k++)
        {
                 if(Sx == Center)   W[k] =  Array[Dx++];                              //Se la parte sinistra è finita allora prendi dalla parte destra
            else if(Dx == N)        W[k] =  Array[Sx++];                              //Se la parte destra è finita allora prendi dalla parte sinistra
            else                    W[k] = (Array[Sx] <= Array[Dx]) ? Array[Sx++] : Array[Dx++]; //Prendi ìl più piccolo
        }

        for(k = 0; k < N; Array[k] = W[k], k++);//Ricopia vettore

        delete[]W; //Cedi lo spazio nuovamente

            return true;
        }
        else return false;
}

template <typename T>
bool ARRAY<T>::pushBack(T x)
{
    if(N == PhysicalSize)
    {
        T* SecondaryArray;
        SecondaryArray =  new (nothrow) T [PhysicalSize + 100];

        for(int i = 0; i < N; i++) SecondaryArray[i] = MainArray[i];

        delete[]MainArray;
        MainArray = SecondaryArray;
        PhysicalSize += 100;
    }
    MainArray[N]=x;
    N++;
}

template <typename T>
 bool ARRAY<T>::pushFront(T x)
{
    if(N == PhysicalSize)
    {
        T* SecondaryArray;
        SecondaryArray =  new (nothrow) T [PhysicalSize + 100];

        for(int i = 0; i < N; i++) SecondaryArray[i] = MainArray[i];

        delete[]MainArray;
        MainArray = SecondaryArray;
        PhysicalSize += 100;

    }
    for(int i=N; i>0; i--)
	{
		MainArray[i]=MainArray[i-1];
	}
	MainArray[0] = x;
	N++;
}

template <typename T>
 bool ARRAY<T>::popBack(int x)
{
    if(N > 0)
    {
        for(int i = 0; i < x; i++){N--;}
        return true;
    }
    else return false;

}
template <typename T>
bool ARRAY<T>::popFront(int x)
{
    if(N > 0)
    {
        for (int i = 0; i < N-1; i++)MainArray[i] = MainArray[i + 1];
        N--;
        return true;
    }
    else return false;
}

template <typename T>
bool ARRAY<T>::getMinimum(T &Minimum)
{
    if(N > 0)
    {
        for (int i = 1, Minimum = MainArray[0]; i < N; i++)
            if(MainArray[i] < Minimum)Minimum = MainArray[i];
        N--;
        return true;
    }
    else return false;
}

template <typename T>
bool ARRAY<T>::extractMinimum()
{
    if(N > 0)
    {
        int m, Risp;
        for(int i = 1, m = 0;i < N; i++)
            if(MainArray[i] < MainArray[m]) m = i;
        Risp = MainArray[m];
        while(m < N-1){MainArray[m] = MainArray[m+1]; m++;}

        return true;
    }
    else return false;
}

template <typename T>
bool ARRAY<T>::Sort()
{
    mergeActive(MainArray, N);
}

//INT SEGMENT

template <typename T>
int ARRAY<T>::spaceControl()
{
    if(!MainArray) return 0x0;
    else           return 0xA113;
}


template <typename T>
T ARRAY<T>::getSum()
{
    T Sum = 0;
    for(int i = 0; i < N; i++) Sum = Sum + MainArray[i];
    return Sum;
}

template <typename T>
int ARRAY<T>::getSize()
{
    return N;
}

template <typename T>
int ARRAY<T>::setSize(int M)
{
    N = M;
    return N;
}

template <typename T>
T ARRAY<T>::Research(T key)
{
    int Error = 0xA113;
    if(N > 0)
    {
        for(int i = 0; i < N; i++)
            if(MainArray[i] == key)return i;
        Error = 0;
    }
    else return Error;
}

template <typename T>
int ARRAY<T>::Mirror()
{
    T temp = 0;
    for(int i = 0; i < N; ++i)
    {
        temp = MainArray[N-i-1];
        MainArray[N-i-1] = MainArray[i];
        MainArray[i] = temp;
    }
}

//DOUBLE SEGMENT
template <typename T>
double ARRAY<T>::getAverage()
{
    T Sum = 0;
    for(int i = 0; i < N; i++) Sum = Sum + MainArray[i];
    return double(Sum)/double(N);
}


