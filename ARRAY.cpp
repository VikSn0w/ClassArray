#include "ARRAY.h"
ARRAY::ARRAY(){N = 0;}

//VOID SEGMENT
void ARRAY::Print()
{
    for(int i = 0; i < N; i++)
    {
        cout << setw(15) << MainArray[i];
    }
}

void ARRAY::Help()
{
    cout << "Here is a list of all the methods that you can use within this class" << endl << endl;
    cout << "Help           ()        = Prints the all the methods on the road" << endl;
    cout << "Print          ()        = Prints the Array " << endl;
    cout << "Mirror         ()        = Mirrors the Array" << endl;
    cout << "Sort           ()        = Sorts the Array (Merge Sort)" << endl;
    cout << "Research       (int key) = Researches a number in the Array " << endl << endl;

    cout << "pushBack       (int x)   = Inserts new numbers from the last cell of the Array" << endl;
    cout << "pushFront      (int x)   = Inserts new numbers from the first cell of the Array" << endl;
    cout << "popBack        (int x)   = Deletes the last element in the last cell of the Array" << endl;
    cout << "popFront       (int x)   = Deletes the first element in the first cell of the Array" << endl<< endl;

    cout << "getMinimum     ()        = Gets the minimum number in the Array" << endl;
    cout << "getAverage     ()        = Calculates the average number of the Array" << endl;
    cout << "getSum         ()        = Calculates the sum of the numbers in the Array" << endl;
    cout << "getSize        ()        = Gets the current size of the Array" << endl << endl;

    cout << "extractMinimum ()        = Exctracts the minimum number in the array and deletes it " << endl << endl;

    cout << "setSize        (int M)   = Sets the size of the Array" << endl;
}

//BOOL SEGMENT
bool ARRAY::mergeActive(int Array[], int N)
 {
                if(N > 1)
                {
                    int Center, Sx, Dx, k;
                    int* W; //Prende lo spazio dall'heap

                    Center = N/2; //Metà del vettore
                    mergeActive(Array, Center);
                    mergeActive(Array+Center, N-Center);

                    W = new int[N];

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

bool ARRAY::pushBack(int x)
{
    MainArray[N]=x;
    N++;
}
bool ARRAY::pushFront(int x)
{
    for(int i=N; i>0; i--)
	{
		MainArray[i]=MainArray[i-1];
	}
	MainArray[0] = x;
	N++;
}

bool ARRAY::popBack(int x)
{
    if(N > 0)
    {
        for(int i = 0; i < x; i++){N--;}
        return true;
    }
    else return false;

}
bool ARRAY::popFront(int x)
{
    if(N > 0)
    {
        for (int i = 0; i < N-1; i++)MainArray[i] = MainArray[i + 1];
        N--;
        return true;
    }
    else return false;
}

bool ARRAY::getMinimum()
{
    if(N > 0)
    {
        int Minimum;
        for (int i = 1, Minimum = MainArray[0]; i < N; i++)
            if(MainArray[i] < Minimum)Minimum = MainArray[i];
        N--;
        return true;
    }
    else return false;
}

bool ARRAY::extractMinimum()
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

bool ARRAY::Sort()
{
    mergeActive(MainArray, N);
}

//INT SEGMENT
int ARRAY::getSum()
{
    int Sum = 0;
    for(int i = 0; i < N; i++) Sum = Sum + MainArray[i];
    return Sum;
}

int ARRAY::getSize()
{
    return N;
}

int ARRAY::setSize(int M)
{
    N = M;
    return N;
}

int ARRAY::Research(int key)
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

int ARRAY::Mirror()
{
    int temp = 0;
    for(int i = 0; i < N; ++i)
    {
        temp = MainArray[N-i-1];
        MainArray[N-i-1] = MainArray[i];
        MainArray[i] = temp;
    }
}

//DOUBLE SEGMENT
double ARRAY::getAverage()
{
    int Sum = 0;
    for(int i = 0; i < N; i++) Sum = Sum + MainArray[i];
    return double(Sum)/double(N);
}


