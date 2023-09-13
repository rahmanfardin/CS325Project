#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
bool isAvailable(vector<int> array, int key)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == key)
            return true;
    }
    return false;
}
void makeArray(vector<int> array, int pageSize)
{
    for (int i = 0; i < pageSize; i++)
        array.at(i) = -1;
}
void printArray(vector<int> array, int pageSize)
{
    for (int i = 0; i < pageSize; i++)
    {
        cout << "\t\t f " << i << " : " << array[i];
    }
}

int findMIN(vector<int> givenArray, int Size)
{
    int min = givenArray[0], index = 0;
    for (int i = 0; i < Size; i++)
    {
        if (min > givenArray[i])
        {
            min = givenArray[i];
            index = i;
        }
    }
    return index;
}

int findIndex(vector<int> givenArray, int Size, int key)
{
    for (int i = Size; i >= 0; i--)
    {
        if (givenArray[i] == key)
            return i;
    }
    return INT_MAX;
}
int findIndex(vector<int> givenArray, int Size, int till, int key)
{
    for (int i = Size; i >= till; i--)
    {
        if (givenArray[i] == key)
            return i;
    }
    return INT_MAX;
}

vector<int> leastIdx(vector<int> array, int pageSize, vector<int> givenArray, int Size)
{
    vector<int> index(pageSize, -1);
    for (int i = 0; i < pageSize; i++)
    {
        int j = findIndex(givenArray, Size, array[i]);
        index[i] = j;
    }
    return index;
}

int lru(vector<int> array, int pageSize, vector<int> givenArray, int Size)
{
    int fault = 0, count = 0;
    makeArray(array, pageSize);

    int index = 0;
    for (int i = 0; i < Size; i++)
    {
        if (count >= pageSize)
        {
            vector<int> lindex = leastIdx(array, pageSize, givenArray, i + 1);
            index = findMIN(lindex, pageSize);
        }

        int value = givenArray[i];
        if (!isAvailable(array, value))
        {
            array[index] = value;
            //if (count >= pageSize)
                fault++;
            count++;
            index++;
        }

        cout << "value-->" << value;
        printArray(array, pageSize);
        cout << endl;
    }

    return fault;
}

int fifo(vector<int> array, int pageSize, vector<int> givenArray, int Size)
{
    int fault = 0, top = 0, count = 0;
    makeArray(array, pageSize);

    for (int i = 0; i < Size; i++)
    {
        if (top == pageSize)
        {
            count = 1;
            top = 0;
        }
        int value = givenArray[i];
        if (!isAvailable(array, value))
        {
            array[top] = value;
            //if (count != 0)
                fault++;
            top++;
        }
        cout << "value-->" << value;
        printArray(array, pageSize);
        cout << endl;
    }
    return fault;
}

vector<int> opIdx(vector<int> array, int pageSize, vector<int> givenArray, int Size, int till)
{
    vector<int> index(pageSize, -1);
    for (int i = 0; i < pageSize; i++)
    {
        int j = findIndex(givenArray, Size, till, array[i]);
        index[i] = j;
    }
    return index;
}
int findMAX(vector<int> givenArray, int Size)
{
    int max = givenArray[0], index = 0;
    for (int i = 0; i < Size; i++)
    {
        if (max < givenArray[i])
        {
            max = givenArray[i];
            index = i;
        }
    }
    return index;
}

int optimal(vector<int> array, int pageSize, vector<int> givenArray, int Size)
{
    int fault = 0, count = 0;
    makeArray(array, pageSize);
    int index = 0;
    for (int i = 0; i < Size; i++)
    {
        if (count >= pageSize)
        {
            vector<int> lindex = opIdx(array, pageSize, givenArray, Size, i);
            index = findMAX(lindex, pageSize);
        }

        int value = givenArray[i];
        if (!isAvailable(array, value))
        {
            array[index] = value;
            //if (count >= pageSize)
                fault++;
            count++;
            index++;
        }

        cout << "value-->" << value;
        printArray(array, pageSize);
        cout << endl;
    }

    return fault;
}