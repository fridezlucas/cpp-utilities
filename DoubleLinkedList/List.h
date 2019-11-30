/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 10.04.2019.
 */

#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H

#include <iostream>
#include "Node.h"

template <typename T>
class List {
public:
    List();

    List(const List<T>&);

    //~List();

    bool addBegin(T value);

    void insert(T value, int index);

    bool addEnd(T value);

    int indexOf(int position);

    void removeBegin();

    void removeEnd();

    void empty();

    int getSize() const;

    T getHeadValue() const;

    T getQueueValue() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& s, const List<U>& list);

private:
    int size;
    Node<T> *head;
    Node<T> *queue;
};

#include "List.tpp"

#endif //LINKEDLIST_LIST_H
