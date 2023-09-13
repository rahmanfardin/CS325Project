#include "global.hpp"

int main()
{
    int Size, pageSize = 0;
    bool run = true;

    cout << "enter the number of elements: ";
    cin >> Size;

    vector<int> givenArray;

    cout << "start entering the values: " << endl;
    for (int i = 0; i < Size; i++)
    {
        int value = -1;
        cin >> value;
        givenArray.push_back(value);
    }

    while (run)
    {

        int choice = -1;
        cout << "=========================================================================================" << endl
             << "1. FIFO" << endl
             << "2. LRU" << endl
             << "3. OPTIMAL" << endl
             << "9. EXIT" << endl;

        cout << "make your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "enter the page count: ";
            cin >> pageSize;
            vector<int> array(pageSize, -1);
            cout << "FIFO: " << endl;
            int fifoFault = fifo(array, pageSize, givenArray, Size);
            cout << "Fault: " << fifoFault << endl
                 << "=========================================================================================" << endl;
            break;
        }
        case 2:
        {
            cout << "enter the page count: ";
            cin >> pageSize;
            vector<int> array(pageSize, -1);
            cout << "LRU: " << endl;
            int lruFault = lru(array, pageSize, givenArray, Size);
            cout << "Fault: " << lruFault << endl
                 << "=========================================================================================" << endl;
            break;
        }
        case 3:
        {
            cout << "enter the page count: ";
            cin >> pageSize;
            vector<int> array(pageSize, -1);
            cout << "OPTIMAL: " << endl;
            int optFault = optimal(array, pageSize, givenArray, Size);
            cout << "Fault: " << optFault << endl
                 << "=========================================================================================" << endl;
            break;
        }
        case 9:
            run = false;
            break;
        default:
            break;
        }
    }
}