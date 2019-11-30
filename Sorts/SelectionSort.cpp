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

template <typename T>
void selectionSort(T *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        int min = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&array[i], &array[min]);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 15;
    int array[n];
    fill_random(array, n);
    printArray(array, n);
    selectionSort(array, n);
    printArray(array, n);
    // printStatistics(n);

    return 0;
}