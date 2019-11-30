template <typename T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void fill_random(int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        tab[i] = rand() % (size * 10);
    }
}

template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}