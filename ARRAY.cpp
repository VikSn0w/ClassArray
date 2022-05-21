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
    std::ifstream F;

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
    std::ofstream F;
    F.open("$$ARRAY$$.save");
    if(F.is_open())
    {
        for(int i = 0; i < N; i++) F << cryptoFunc(MainArray[i]) << std::endl;
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
void ARRAY<T>::printOnConsole(int indexStart, int indexEnd)
{
    int indS = indexStart, indE = indexEnd;
    if(N == 0){
        std::cout << "\nERROR - The array is empty!\n";
        return;
    }else{
        if(indexStart == NULL){
            indS = 0;
        }else if(indexEnd == NULL){
            indE = N-1;
        }else if(indS > indE){
            std::cout << "\nERROR - the end index is bigger then the start index!\n";
            return;
        }

        std::cout << std::endl << "Printing array from " << indS << " to " << indE << " (" << indE+1 << " elements)" << std::endl << std::endl;
        for (int i = indS; i < indE+1; i++) {
            std::cout << MainArray[i] << " ";
        }
    }

}

template <typename T>
void ARRAY<T>::help()
{
    std::cout << "Here is a list of all the methods that you can use within this class" << std::endl << std::endl;
    std::cout << "help           ()           = Prints the all the methods on the road" << std::endl;
    std::cout << "printOnConsole ()           = Prints the Array by giving a start and end index "
                 "\n                              (putting NULL at the start will set the index at 0"
                 "\n                               and putting NULL at the end will set the index at N-1" << std::endl;
    std::cout << "mirror         ()           = Mirrors the Array" << std::endl;
    std::cout << "sort           (short type) = Sorts the Array with 4 types of sorting (1. Simple Sort, 2. Selection Sort,"
                 "\n                              3. Insertion Sort, 4. Merge Sort)" << std::endl;
    std::cout << "search       (int key)    = Searches a number in the Array " << std::endl << std::endl;

    std::cout << "pushBack       (int x)      = Inserts new numbers from the last cell of the Array" << std::endl;
    std::cout << "pushFront      (int x)      = Inserts new numbers from the first cell of the Array" << std::endl;
    std::cout << "popBack        (int x)      = Deletes the last element in the last cell of the Array" << std::endl;
    std::cout << "popFront       (int x)      = Deletes the first element in the first cell of the Array" << std::endl<< std::endl;

    std::cout << "spaceControl   ()           =  Verifies if the Array has been resized" << std::endl<< std::endl;

    std::cout << "getMinimum     ()           = Gets the minimum number in the Array" << std::endl;
    std::cout << "getMaximum     ()           = Gets the maximum number in the Array" << std::endl;
    std::cout << "getAverage     ()           = Calculates the average number of the Array" << std::endl;
    std::cout << "getSum         ()           = Calculates the sum of the numbers in the Array" << std::endl;
    std::cout << "getSize        ()           = Gets the current size of the Array" << std::endl << std::endl;

    std::cout << "extractMinimum ()           = Exctracts the minimum number in the array and deletes it " << std::endl << std::endl;
    std::cout << "extractMaximum ()           = Exctracts the maximum number in the array and deletes it " << std::endl << std::endl;
    std::cout << "swapElement    (int indexA, int indexB) = Swaps the elements at the position specified by indexA and indexB" << std::endl << std::endl;

    std::cout << "setSize        (int M)   = Sets the size of the Array" << std::endl;
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
void ARRAY<T>::simpleSort(T V[], int N)
{
    int i, s;
    T App;

    for(i = 0; i < N - 1; i++)
    {
        for(s = i + 1; s < N; s++)
        {
            if(V[i] > V[s])
            {
                App  = V[i];
                V[i] = V[s];
                V[s] = App;
            }
        }
    }
}

template <typename T>
void ARRAY<T>::selectionSort(T V[], int N)
{
    int i, m, j;
    T app;
    for(i = 0; i < N - 1; i++)
    {
        m = i;
        for(j = i + 1; j < N; j++) if(V[j] < V[m])  m = j;
        swapElement(i,m);
    }
}

template <typename T>
void ARRAY<T>::insertionSort(T V[], int N)
{
    int i, m;
    T Prec, App;
    for(i = 1; i < N; i++)
    {
        App = V[i];
        for(Prec = i-1; Prec >= 0 and V[Prec] > App; V[Prec + 1] = V[Prec], Prec--);
        V[Prec + 1] = App;
    }
}

template <typename T>
bool ARRAY<T>::pushBack(T x)
{
    if(N == PhysicalSize)
    {
        T* SecondaryArray;
        SecondaryArray =  new (std::nothrow) T [PhysicalSize + 100];

        for(int i = 0; i < N; i++) SecondaryArray[i] = MainArray[i];

        delete[]MainArray;
        MainArray = SecondaryArray;
        PhysicalSize += 100;
    }
    MainArray[N]=x;
    N++;

    return true;
}

template <typename T>
bool ARRAY<T>::pushFront(T x)
{
    if(N == PhysicalSize)
    {
        T* SecondaryArray;
        SecondaryArray =  new (std::nothrow) T [PhysicalSize + 100];

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

    return true;
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
bool ARRAY<T>::getMaximum(T &Maximum)
{
    if(N > 0)
    {
        for (int i = 1, Maximum = MainArray[0]; i < N; i++)
            if(MainArray[i] > Maximum)Maximum = MainArray[i];
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
bool ARRAY<T>::extractMaximum()
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
bool ARRAY<T>::sort(short type)
{
    switch (type) {
        default:
            mergeActive(MainArray, N);
        break;
        case 1:
            simpleSort(MainArray, N);
        break;
        case 2:
            selectionSort(MainArray, N);
        break;
        case 3:
            insertionSort(MainArray, N);
        break;
        case 4:
            mergeActive(MainArray, N);
        break;
    }
    return 0;
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
T ARRAY<T>::search(T key)
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
int ARRAY<T>::mirror()
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

template <typename T>
int ARRAY<T>::swapElement(int indexA, int indexB){
    T app = MainArray[indexA];
    MainArray[indexA] = MainArray[indexB];
    MainArray[indexB] = app;
    return 0;
}

