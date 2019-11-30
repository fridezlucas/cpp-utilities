/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 10.04.2019.
 */

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

template <typename T>
class Node {
public:
    virtual ~Node();

    T getValue() const;

    Node *getNext() const;

    Node *getPrevious() const;

    static int count();

private:
    T value;
    Node *next;
    Node *previous;
    static int nbNodes;

    Node(T value);

    Node(T value, Node<T> *next);

    Node(T value, Node<T> *next, Node<T> *previous);

    template <typename TList> friend class List;
};

#include "Node.tpp"

#endif //LINKEDLIST_NODE_H
