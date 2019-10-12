#include "ARRAY.h"
ARRAY::ARRAY(){N = 0;}

//VOID SEGMENT
void ARRAY::Print()
{
    for(int i = 0; i < N; i++)
    {
        cout << "[" << MainArray[i] << "] - ";
    }
}

//BOOL SEGMENT
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
        while(){}

        return true;
    }
    else return false;
}

bool ARRAY::Research(int key, SHORT &Position)
{
    Position = 0xA113;
    if(N > 0)
    {
        if(N<=100)
            for(int i = 0; i < N; i++)
                if(MainArray[i] == key)Position = i;


        return true;
    }
    else return false;
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

//DOUBLE SEGMENT
double ARRAY::getAverage()
{
    int Sum = 0;
    for(int i = 0; i < N; i++) Sum = Sum + MainArray[i];
    return double(Sum)/double(N);
}


