# Class - ARRAY
A C++ **class** that permits an easy manipulation of an **Array**.

Limits: now the only limit of the Array that is going to be created is given by the OS. 

Now the class encrypts, decrypts and saves the elements on an external file, .save (the default name is "\\$\\$ARRAY\\$\\$.save").

Methods:
Here is a list of all the methods that you can use within this class


**help**          ()             = Prints the all the methods on the road

**printOnConsole**          (int indexStart, int indexEnd)             = Prints the Array by giving a start and end index (putting NULL at the start will set the index at 0 and putting NULL at the end will set the index at N-1

**mirror**       ()             = Mirrors the Array

**sort**           (short type)             = Sorts the Array with 4 types of sorting (1. Simple Sort, 2. Selection Sort, 3. Insertion Sort, 4. Merge Sort)

**search**   (int key) = Researches a number in the Array



**pushBack**  (int x)   = Inserts new numbers from the last cell of the Array

**pushFront** (int x)   = Inserts new numbers from the first cell of the Array

**popBack**    (int x)   = Deletes the last element in the last cell of the Array

**popFront**   (int x)   = Deletes the first element in the first cell of the Array



**getMinimum**     ()        = Gets the minimum number in the Array

**getMaximum**     ()        = Gets the maximum number in the Array

**getIndexMinimum (int &Minimum)** = Gets the index of the minimum number in the Array

**getIndexMaximum (int &Minimum)** = Gets the index of the maximum number in the Array

**getAverage**       ()        = Calculates the average number of the Array

**getSum**              ()        = Calculates the sum of the numbers in the Array

**getSize**               ()        = Gets the current size of the Array


**spaceControl()** = Verifies if the Array has been resized;


**extractMinimum** ()  = Exctracts the minimum number in the array and deletes it

**extractMaximum** ()  = Exctracts the maximum number in the array and deletes it


**setSize** (int M)   = Sets the size of the Array


**swapElement**     (int indexA, int indexB) = Swaps the elements at the position specified by indexA and indexB 
