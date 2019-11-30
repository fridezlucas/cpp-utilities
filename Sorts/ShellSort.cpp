#include <iostream>
#include <cmath>

#include "SortTools.cpp"
#include "Struct.cpp"

static int comparisons = 0;
static int assignments = 0;

void printStatistics(int n)
{
    std::cout << "-- ShellSort sort informations --" << std::endl
              << "-   Elements    : " << n << std::endl
              << "-   Assignments : " << assignments << std::endl
              << "-   Comparisons : " << comparisons << std::endl
              << "---------------------------------";
}

int getNextGap(int i)
{
    return i * 3 + 1;
}

int getPrevGap(int i)
{
    return (i - 1) / 3;
}

template <typename T>
void insertionSortWithGap(T *array, int n, int gap)
{
    T key;
    int j;
    for (int i = gap; i < n; i += gap)
    {
        key = array[i];
        j = i - gap;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

template <typename T>
void shellSort(T *array, int size)
{
    int h = 1;
    do
    {
        h = getNextGap(h);
    } while (getNextGap(h) <= size);

    while (h != 0)
    {
        std::cout << h << std::endl;
        for (int i = 0; i < h; i++)
        {
            for (int p = h + i; p < size; p += h)
            {
                int i = p - h;
                T curr = array[p];
                while (i >= 0 && array[i] > curr)
                {
                    array[i + h] = array[i];
                    i -= h;
                }
                array[i + h] = curr;
            }
        }
        h = getPrevGap(h);
    }
}

int main(int argc, char const *argv[])
{
    int n = 15;
    Person array[15] = {
        {"Ken43", 43},
        {"Ken22", 22},
        {"Ken10", 10},
        {"Ken30", 30},
        {"Ken56", 56},
        {"Ken87", 87},
        {"Ken43", 43},
        {"Ken28", 28},
        {"Ken58", 58},
        {"Ken73", 73},
        {"Ken12", 12},
        {"Ken11", 11},
        {"Ken99", 99},
        {"Ken72", 72},
        {"Ken33", 33},
    };
    //fill_random(array, n);

    printArray(array, n);

    shellSort(array, n);

    printArray(array, n);
    // printStatistics(n);

    return 0;
}
