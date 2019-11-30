#include <iostream>

static int comparisons = 0;
static int assignments = 0;

template <typename T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printStatistics(int n)
{
    std::cout << "--- Bubble sort informations ---" << std::endl
              << "-   Elements    : " << n << std::endl
              << "-   Assignments : " << assignments << std::endl
              << "-   Comparisons : " << comparisons << std::endl
              << "--------------------------------";
}

void fill_random(int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        tab[i] = rand() % (size * 10);
    }
}

bool operator<(std::string const &s1, std::string const &s2)
{
    return s1.compare(s2) < 0;
}

template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
void bubbleSort(T *array, int begin, int end)
{
    int n = end - begin;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            ++comparisons;
            if (array[j] > array[j + 1])
            {
                assignments += 3;
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int array[n];
    fill_random(array, n);
    printArray(array, n);
    bubbleSort(array, 0, n);
    printArray(array, n);
    printStatistics(n);

    return 0;
}