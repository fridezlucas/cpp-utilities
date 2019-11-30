/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 30.09.2019.
 */

#ifndef INC_02_SORTS_SORTHELPER_H
#define INC_02_SORTS_SORTHELPER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * SortHelper
 * Random generator (int, float, double, string)
 * Can apply sort on arrays
 * @tparam T type of elements
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
template<typename T>
class SortHelper {
public:
    static const std::string ALPHABET;
    static const int MAX_NUMBER;

    SortHelper();

    T *generateList(int size);

    void print();

    void sortShell();

    //region HeapSort

    void sortHeap(int order);

    void printHeap();
    //endregion

    void quickSort();

private:
    T *elements;
    int size;

    void swap(int i, int j);

    T generateElement();

    bool compareVariables(T x, T y, int order);

    //region Heap sort

    int getLeftChildIndex(int idxParent);

    int getRightChildIndex(int idxParent);

    void printLevel(int level, int *countLastLevel);

    void printElement(int element);

    void heapify(int size, int idxParentP, int order);
    //endregion

    //region QuickSort

    int partition(int start, int end);

    void quickSortStep(int begin, int end);
    //endregion
};

#include "SortHelper.tpp"

#endif //INC_02_SORTS_SORTHELPER_H
