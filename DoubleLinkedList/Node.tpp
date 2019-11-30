/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 10.04.2019.
 */

#include "Node.h"

template <typename T>
int Node<T>::nbNodes = 0;

template <typename T>
Node<T>::~Node() {
    nbNodes--;
}

template <typename T>
Node<T>::Node(T value) {
    this->value = value;
    nbNodes++;
}

template <typename T>
Node<T>::Node(T value, Node<T> *next) {
    this->value = value;
    this->next = next;
    nbNodes++;
}

template <typename T>
Node<T>::Node(T value, Node<T> *next, Node<T> *previous) {
    this->value = value;
    this->next = next;
    this->previous = previous;
    nbNodes++;
}

template <typename T>
T Node<T>::getValue() const {
    return value;
}

template <typename T>
Node<T> *Node<T>::getNext() const {
    return next;
}

template <typename T>
Node<T> *Node<T>::getPrevious() const {
    return previous;
}

template <typename T>
int Node<T>::count() {
    return Node<T>::nbNodes;
}

