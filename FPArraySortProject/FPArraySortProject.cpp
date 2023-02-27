#include <iostream>

using namespace std;

void ArrayPrint(int array[], int size);
void ArrayInit(int array[], int size, int begin = 0, int end = 100);

void ArraySortSelect(int array[], int size);
void ArraySortBubble(int array[], int size);
void ArraySortShacker(int array[], int size);
void ArraySortInsert(int array[], int size);

int main()
{
    const int size{ 10 };
    int array[size];

    ArrayInit(array, size);
    ArrayPrint(array, size);

    //ArraySortSelect(array, size);
    //ArraySortBubble(array, size);

    


    ArrayPrint(array, size);

    return 0;
}

void ArrayPrint(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "\n";
}

void ArrayInit(int array[], int size, int begin, int end)
{
    srand(time(nullptr));
    for (int i = 0; i < size; i++)
        array[i] = begin + rand() % (end - begin + 1);
}

void ArraySortSelect(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int indexMin{ i };
        for (int j = i + 1; j < size; j++)
            if (array[j] < array[indexMin])
                indexMin = j;
        int temp = array[i];
        array[i] = array[indexMin];
        array[indexMin] = temp;
    }
}

void ArraySortBubble(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSort = true;
        for (int j = size - 1; j > i; j--)
            if (array[j] < array[j - 1])
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                isSort = false;
            }
        if (isSort)
            break;
    }
}

void ArraySortShacker(int array[], int size)
{
    int top{ 0 };
    int bottom{ size - 1 };
    bool isSort;

    while (top < bottom)
    {
        isSort = true;
        for (int i = bottom; i > top; i--)
            if (array[i] < array[i - 1])
            {
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                isSort = false;
            }
        if (isSort) break;
        top++;

        isSort = true;
        for (int i = top; i < bottom; i++)
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                isSort = false;
            }
        if (isSort) break;
        bottom--;
    }
}

void ArraySortInsert(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int index;
        for (index = i; index > 0; index--)
            if (array[index - 1] > temp)
                array[index] = array[index - 1];
            else
                break;
        array[index] = temp;
    }
}