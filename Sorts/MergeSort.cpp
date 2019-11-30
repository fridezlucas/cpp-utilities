#include <iostream>
#include <cmath>

#include "SortTools.cpp"
#include "Struct.cpp"

static int comparisons = 0;
static int assignments = 0;

void printStatistics(int n)
{
    std::cout << "-- MergeSort sort informations --" << std::endl
              << "-   Elements    : " << n << std::endl
              << "-   Assignments : " << assignments << std::endl
              << "-   Comparisons : " << comparisons << std::endl
              << "---------------------------------";
}

template <typename T>
void merge2ArraysInOrder(T *arrayA, int sizeA, T *arrayB, int sizeB, T *arrayOrdered)
{
    int iArrayA, iArrayB, iArrayOrdered;
    iArrayA = iArrayB = iArrayOrdered = 0;

    while (iArrayA < sizeA && iArrayB < sizeB)
    {
        if (arrayA[iArrayA] <= arrayB[iArrayB])
        {
            arrayOrdered[iArrayOrdered++] = arrayA[iArrayA++];
        }
        else
        {
            arrayOrdered[iArrayOrdered++] = arrayB[iArrayB++];
        }
    }
    while (iArrayA < sizeA)
    {
        arrayOrdered[iArrayOrdered++] = arrayA[iArrayA++];
    }
    while (iArrayB < sizeB)
    {
        arrayOrdered[iArrayOrdered++] = arrayB[iArrayB++];
    }
}

template <typename T>
void mergeOrderedArray(T *array, int middle, int size)
{
    int *tmpArray = new int[size];

    merge2ArraysInOrder(array, middle, array + middle, size - middle, tmpArray);
    for (int i = 0; i < size; i++)
    {
        array[i] = tmpArray[i];
    }

    delete[] tmpArray;
}

template <typename T>
void mergeSort(T *array, int size)
{
    if (size < 2)
        return;

    int h = size / 2;
    // Cut in 2 arrays
    mergeSort(array, h);
    mergeSort(array + h, size - h);

    // Assemble 2 arrays in ordered
    mergeOrderedArray(array, h, size);
}

int main(int argc, char const *argv[])
{
    int n = 14;
    int array[n];
    fill_random(array, n);
    printArray(array, n);

    mergeSort(array, n);
    printArray(array, n);
    // printStatistics(n);

    return 0;
}
