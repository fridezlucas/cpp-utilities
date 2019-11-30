/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 10.04.2019.
 */

#include "List.h"
#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
List<T>::List() {
    this->size = 0;
    this->head = nullptr;
    this->queue = nullptr;
}

template<typename T>
bool List<T>::addBegin(T value) {
    Node<T> *ptrNewNode = new Node<T>(value, head);

    if (size == 0) {
        queue = ptrNewNode;
    } else if (size == 1) {
        queue->previous = ptrNewNode;
    } else {
        head->previous = ptrNewNode;
    }

    head = ptrNewNode;
    size++;

    return true;
}

template<typename T>
bool List<T>::addEnd(T value) {
    Node<T> *ptrNewNode = new Node<T>(value, nullptr, queue);

    if (size == 0) {
        head = ptrNewNode;
    } else if (size == 1) {
        head->next = ptrNewNode;
    } else {
        queue->next = ptrNewNode;
    }

    queue = ptrNewNode;
    size++;

    return true;
}

template<typename T>
void List<T>::empty() {
    Node<T> *actual = queue;
    while (queue != nullptr) {
        actual = queue->previous;
        delete queue;
        queue = actual;
        size--;
    }
    head = nullptr;
}

template<typename T>
void List<T>::removeEnd() {
    Node<T> *tempNode = queue;
    queue = queue->getPrevious();
    queue->next = nullptr;
    delete tempNode;

    size--;
}

template<typename T>
void List<T>::removeBegin() {
    Node<T> *tempNode = head;
    head = head->getNext();
    head->previous = nullptr;
    delete tempNode;

    size--;
}

template<typename T>
T List<T>::getHeadValue() const {
    return head->value;
}

template<typename T>
T List<T>::getQueueValue() const {
    return queue->value;
}

template<typename T>
int List<T>::getSize() const {
    return size;
}

template<typename T>
void List<T>::insert(T value, int index) {
    if (index <= 0) {
        addBegin(value);
    } else if (index >= size) {
        addEnd(value);
    } else {
        Node<T> *ptrTempNode = head;
        for (int i = 0; i <= index - 1; ++i) {
            ptrTempNode = ptrTempNode->getNext();
        }

        Node<T> *nodeToAppend = new Node<T>(value);
        nodeToAppend->previous = ptrTempNode->previous;
        nodeToAppend->next = ptrTempNode;

        ptrTempNode->previous->next = nodeToAppend;
        ptrTempNode->previous = nodeToAppend;

        size++;
    }
}

template<typename T>
int List<T>::indexOf(int position) {
    if (position <= 0) {
        return getHeadValue();
    } else if (position >= size) {
        return getQueueValue();
    } else {
        Node<T> *ptrTempNode = head;
        for (int i = 0; i <= position - 1; ++i) {
            ptrTempNode = ptrTempNode->getNext();
        }
        return ptrTempNode->value;
    }
}

string getTypeOf(const char* typeidName) {
    switch (*typeidName) {
        case 'b':
            return "bool";
        case 'c':
            return "char";
        case 'h':
            return "unsigned char";
        case 's':
            return "short";
        case 't':
            return "unsigned short";
        case 'i':
            return "int";
        case'j':
            return "unsigned int";
        case 'l':
            return "long";
        case 'm':
            return "unsigned long";
        case'x':
            return "long long";
        case 'y':
            return "unsigned long long";
        case 'f':
            return "float";
        case 'd':
            return "double";
        case 'e':
            return "long double";
        default:
            return std::string(typeidName,1);
    }
}

template<typename T>
std::ostream &operator<<(std::ostream &s, const List<T> &list) {
    Node<T> *actualNode = list.head;
    s << "\n----------\nList<" << getTypeOf(typeid(T).name()) << ">\n----------\n";
    s << "size : " << list.size << endl
      << "elements : " << endl;

    while (actualNode != nullptr) {
        s << " - " << actualNode->getValue() << endl;
        actualNode = actualNode->getNext();
    }
}

