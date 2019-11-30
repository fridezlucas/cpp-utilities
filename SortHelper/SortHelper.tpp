/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 30.09.2019.
 */

#include <iomanip>
#include <stdlib.h>
#include <sys/time.h>
#include <cmath>
#include "SortHelper.h"
//region Constants

template<typename T>
const std::string SortHelper<T>::ALPHABET = "abcdefghijklmnopqrstuvwxyz";

template<typename T>
const int SortHelper<T>::MAX_NUMBER = 150;
//endregion

//region General method for arrays
/**
 * SortHelper Instantiation
 * @tparam T type
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
template<typename T>
SortHelper<T>::SortHelper() {
    size = 0;
}

/**
 * Generate a random {int|float|double} element
 * @return {int|float|double} random element
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
template<typename T>
T SortHelper<T>::generateElement() {

    return static_cast <T> (std::rand() % MAX_NUMBER);
}

/**
 * Generate a random{string} element
 * @return {string} random element
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
template<>
std::string SortHelper<std::string>::generateElement() {

    int maxLength = rand() % 15 + 1;

    std::string str = "";
    while (str.size() < maxLength) {
        str += ALPHABET[rand() % 26];
    }
    return str;
}

/**
 * Swap 2 cells in array
 * @tparam T type
 * @param i {int} first index cell
 * @param j {int} second index cell
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
template<typename T>
void SortHelper<T>::swap(int i, int j) {
    T tmp = elements[i];
    elements[i] = elements[j];
    elements[j] = tmp;
}

/**
 * Generate a random list
 * @tparam T type
 * @param size {int} array size to generate
 * @return T[] generated random array
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
template<typename T>
T *SortHelper<T>::generateList(int size) {
    elements = new T[size];
    this->size = size;

    srand(time(0));
    for (int i = 0; i < size; ++i) {
        elements[i] = generateElement();
    }
}

/**
 * Print array on console
 * @tparam T type
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
template<typename T>
void SortHelper<T>::print() {
    // Calculate type precision
    int width = 6;
    std::string separator = ",";

    // Int specifications
    if (std::is_same<T, int>::value) {
        width = 3;
    }

    // String specification
    if (std::is_same<T, std::string>::value) {
        width = 15;
        separator = "\n";
    }

    // Print elements
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(width) << std::fixed << std::setprecision(2)
                  << elements[i] << std::setw(1) << (i + 1 != size ? separator : "");
    }
    std::cout << "]\n";
}

template<typename T>
bool SortHelper<T>::compareVariables(T x, T y, int order) {
    return (x * order) > (y * order);
}

template<>
bool SortHelper<std::string>::compareVariables(const std::string x, const std::string y, int order) {
    return (x.compare(y) * order) > 0;
}
//endregion

//region ShellSort

/**
 * Apply Shell Sort on array
 * @tparam T type
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
template<typename T>
void SortHelper<T>::sortShell() {
    int h = 0;
    do {
        h = 3 * h + 1;
    } while (h < size);


    while (h != 0) {
        for (int i = 0; i < h; i++) {
            for (int p = h + i; p < size; p += h) {
                int i = p - h;
                T curr = elements[p];
                while (i >= 0 && elements[i] > curr) {
                    elements[i + h] = elements[i];
                    i -= h;
                }
                elements[i + h] = curr;
            }
        }
        h = (h - 1) / 3;
    }
}
//endregion

//region HeapSort
/**
 * Get Left child index in heap
 * @tparam T type
 * @param idxParent parent index
 * @return left child index
 */
template<typename T>
int SortHelper<T>::getLeftChildIndex(int idxParent) {
    return idxParent * 2 + 1;
}

/**
 * Get right child index
 * @tparam T type
 * @param idxParent parent index
 * @return right child index
 */
template<typename T>
int SortHelper<T>::getRightChildIndex(int idxParent) {
    return idxParent * 2 + 2;
}

/**
 * Print a level in a Heap
 * @tparam T type
 * @param level number of level to print
 * @param countLastLevel last level count (in case)
 */
template<typename T>
void SortHelper<T>::printLevel(int level, int *countLastLevel) {
    std::cout << "Level " << level << " : ";

    if (level == 0) {
        std::cout << elements[0];
    } else {
        // Get position in array
        int levelCount = (int) pow(2, (level - 1));
        *countLastLevel += (int) pow(2, (level - 2));

        // Print level
        for (int i = 0; i < levelCount; ++i) {
            std::cout << elements[getLeftChildIndex(i + *countLastLevel)]
                      << ","
                      << elements[getRightChildIndex(i + *countLastLevel)]
                      << (((i + 1) != levelCount) ? "," : "");
        }
    }

    std::cout << "\n";
}

/**
 * Print informations about a specific element
 * @tparam T type
 * @param element element index to print informations
 */
template<typename T>
void SortHelper<T>::printElement(int element) {
    std::cout << "Element id=" << element << "\n";
    std::cout << "Parent : " << (element - 1) / 2 << "\n";

    int idxRightChild = getRightChildIndex(element);
    if (idxRightChild < size) {
        std::cout << "Childs : " << getLeftChildIndex(element) << "," << getRightChildIndex(element) << "\n";
    }
}

/**
 * Print a complete Heap
 * @tparam T type
 */
template<typename T>
void SortHelper<T>::printHeap() {
    int countLastLevel = 0;
    for (int stair = 0; stair < (int) log2(size) + 1; ++stair) {
        printLevel(stair, &countLastLevel);
    }
    std::cout << "\n";
}

/**
 * Heapify a heap
 * @tparam T type
 * @param size array size to heapify (x[0] -> x[size]
 * @param idxParent parent index to begin
 * @param order SortOrder (Ascendant | Descendant)
 */
template<typename T>
void SortHelper<T>::heapify(int size, int idxParent, int order) {

    int left = getLeftChildIndex(idxParent);
    int right = getRightChildIndex(idxParent);

    int idxMax = idxParent;

    if (left < size && compareVariables(elements[left], elements[idxMax], order)) {
        idxMax = left;
    }

    if (right < size && compareVariables(elements[right], elements[idxMax], order)) {
        idxMax = right;
    }

    if (idxMax != idxParent) {
        swap(idxMax, idxParent);
        heapify(size, idxMax, order);
    }
}

/**
 * Heap Sort
 * @tparam T type
 * @param order SortOrder (Ascendant | Descendant)
 */
template<typename T>
void SortHelper<T>::sortHeap(int order) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(size, i, order);
    }
    for (int i = size - 1; i >= 0; --i) {
        swap(i, 0);
        heapify(i, 0, order);
    }
}
//endregion

//region QuickSort

template<typename T>
int SortHelper<T>::partition(int start, int end) {
    if ((end - start) < 2) {
        return start;
    }

    int pivot = start;
    int smaller = start + 1;
    int larger = end - 1;

    while (smaller < larger) {
        while (elements[larger] >= elements[pivot] && smaller < larger) {
            larger--;
        }
        while (elements[smaller] <= elements[pivot] && smaller < larger) {
            smaller++;
        }
        if (smaller < larger) {
            swap(smaller, larger);
        }
    }

    if (elements[smaller] > elements[pivot]) {
        smaller--;
    }
    swap(smaller, pivot);

    return smaller;
}

template <typename T>
void SortHelper<T>::quickSortStep(int begin, int end){
    if (begin < end) {
        int pivot = partition(begin, end);
        quickSortStep(begin, pivot);
        quickSortStep(pivot + 1, end);
    }
}

template<typename T>
void SortHelper<T>::quickSort() {
    quickSortStep(0, size);
}

//endregion