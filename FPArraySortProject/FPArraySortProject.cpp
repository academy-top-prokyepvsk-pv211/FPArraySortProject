#include <iostream>

using namespace std;

void ArrayPrint(int array[], int size);
void ArrayInit(int array[], int size, int begin = 0, int end = 100);

void ArraySortSelect(int array[], int size);
void ArraySortBubble(int array[], int size);
void ArraySortShacker(int array[], int size);
void ArraySortInsert(int array[], int size);

template <typename T>
void ArraySortComb(T array[], int size);

template <typename T>
void ArraySortShell(T array[], int size);

template <typename T>
void ArraySortQuick(T array[], int size);

template <typename T>
void QuickSortReq(T array[], int begin, int end);

int ArraySearchLinear(int array[], int size, int key);
int ArraySearchBinary(int array[], int size, int key);


template <typename T>
void Swap(T& a, T& b);

int main()
{
    const int size{ 20 };
    int array[size];

    ArrayInit(array, size);
    ArrayPrint(array, size);

    //ArraySortSelect(array, size);
    //ArraySortBubble(array, size);

    //ArraySortComb(array, size);
    //ArraySortShell(array, size);
    ArraySortQuick(array, size);


    ArrayPrint(array, size);

    return 0;
}

template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
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
        Swap(array[i], array[indexMin]);
        /*int temp = array[i];
        array[i] = array[indexMin];
        array[indexMin] = temp;*/
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
                Swap(array[j], array[j - 1]);
                /*int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;*/
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
                Swap(array[i], array[i - 1]);
                /*int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;*/
                isSort = false;
            }
        if (isSort) break;
        top++;

        isSort = true;
        for (int i = top; i < bottom; i++)
            if (array[i] > array[i + 1])
            {
                Swap(array[i], array[i + 1]);
                /*int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;*/
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

int ArraySearchLinear(int array[], int size, int key)
{
    int index{ -1 };
    for (int i = 0; i < size; i++)
        if (array[i] == key)
        {
            index = i;
            break;
        }
    return index;
}

int ArraySearchBinary(int array[], int size, int key)
{
    int index{ -1 };

    int left{ 0 };
    int right{ size - 1 };

    while (left <= right)
    {
        int middle{ (left + right) / 2 };
        if (array[middle] == key)
        {
            index = middle;
            break;
        }

        if (key < array[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return index;
}

template <typename T>
void ArraySortComb(T array[], int size)
{
    const double FACTOR{ 1.2473309 };
    int step = size - 1;

    while (step >= 1)
    {
        for (int i = 0; i + step < size; i++)
            if (array[i] > array[i + step])
                Swap(array[i], array[i + step]);
        step /= FACTOR;
    }
}

template <typename T>
void ArraySortShell(T array[], int size)
{
    for (int step = size / 2; step > 0; step /= 2)
        for (int i = step; i < size; i++)
            for (int j = i - step; j >= 0; j -= step)
                if (array[j] > array[j + step])
                    Swap(array[j], array[j + step]);

}

template <typename T>
void ArraySortQuick(T array[], int size)
{
    QuickSortReq(array, 0, size - 1);
}

template <typename T>
void QuickSortReq(T array[], int begin, int end)
{
    T pivot = array[(begin + end) / 2];
    int left = begin;
    int right = end;

    do
    {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;
        if (left <= right)
        {
            Swap(array[left], array[right]);
            left++;
            right--;
        }
    } while (left <= right);
    if (begin < right) QuickSortReq(array, begin, right);
    if (left < end) QuickSortReq(array, left, end);
}
