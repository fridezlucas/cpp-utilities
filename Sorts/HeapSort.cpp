#include <iostream>
#include <cmath>

#include "SortTools.cpp"
#include "Struct.cpp"

static int comparisons = 0;
static int assignments = 0;

void printStatistics(int n)
{
    std::cout << "---- Heap sort informations ----" << std::endl
              << "-   Elements    : " << n << std::endl
              << "-   Assignments : " << assignments << std::endl
              << "-   Comparisons : " << comparisons << std::endl
              << "--------------------------------";
}

int leftChild(int i)
{
    return 2 * i + 1;
}

int rightChild(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return floor((i - 1) / 2);
}

int getFirstLevelElement(int level)
{
    return (1 << (level)) - 1;
}

template <typename T>
void printLevel(T *array, int size, int level)
{
    int begin = getFirstLevelElement(level);
    int end = getFirstLevelElement(level + 1);

    if (end > size)
    {
        end = size;
    }

    // print elements
    for (int i = begin; i < end; ++i)
    {
        if (i != begin)
        {
            std::cout << ", ";
        }
        std::cout << array[i];
    }

    std::cout << std::endl;
}

template <typename T>
void printHeap(T *array, int n)
{
    int level = 0;
    while (getFirstLevelElement(level) < n)
    {
        printLevel(array, n, level);
        level++;
    }
}

template <typename T>
void heapify(T *array, int parent, int size)
{
    int left = leftChild(parent);
    int right = rightChild(parent);
    int max = parent;

    if (left < size && array[left] > array[max])
    {
        max = left;
    }

    if (right < size && array[right] > array[max])
    {
        max = right;
    }

    if (parent != max)
    {
        swap(&array[parent], &array[max]);
        heapify(array, max, size);
    }
}

template <typename T>
void buildHeap(T *array, int size)
{
    for (int i = size / 2; i >= 0; --i)
    {
        heapify(array, i, size);
    }
}

template <typename T>
void heapSort(T *array, int size)
{
    buildHeap(array, size);

    for (int i = size - 1; i > 0; --i)
    {
        swap(&array[i], &array[0]);
        printHeap(array, size);
        heapify(array, 0, i);
    }
}

int main(int argc, char const *argv[])
{
    int n = 15;
    int array[15];
    fill_random(array, n);
    printArray(array, n);
    heapSort(array, n);
    printArray(array, n);
    // printStatistics(n);

    return 0;
}