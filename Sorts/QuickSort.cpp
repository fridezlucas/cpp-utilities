#include <iostream>
#include <cmath>

#include "SortTools.cpp"
#include "Struct.cpp"

static int comparisons = 0;
static int assignments = 0;

void printStatistics(int n)
{
    std::cout << "-- QuickSort sort informations --" << std::endl
              << "-   Elements    : " << n << std::endl
              << "-   Assignments : " << assignments << std::endl
              << "-   Comparisons : " << comparisons << std::endl
              << "---------------------------------";
}

template <typename T>
int partition(T *array, int begin, int end)
{
    if (end - begin < 2)
    {
        return begin;
    }
    int pivot = begin;
    int small = begin + 1;
    int large = end - 1;

    while (small < large)
    {
        while (array[small] <= array[pivot] && small < large)
        {
            small++;
        }
        while (array[large] >= array[pivot] && small < large)
        {
            large--;
        }
        if (small < large)
        {
            swap(&array[small], &array[large]);
        }
    }
    if (array[small] > array[pivot])
    {
        small--;
    }

    swap(&array[small], &array[pivot]);

    return small;
}

template <typename T>
void quickSort(T *array, int begin, int end)
{
    int pivot = partition(array, begin, end);
    if (pivot > begin)
    {
        quickSort(array, begin, pivot);
    }
    if (end > pivot + 1)
    {
        quickSort(array, pivot + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    int n = 14;
    int array[n] = {8, 4, 5, 1, 12, 19, 31, 2, 15, 7, 11, 20, 22, 6};
    // fill_random(array, n);
    // printArray(array, n);

    quickSort(array, 0, n);
    printArray(array, n);
    // printStatistics(n);

    return 0;
}
