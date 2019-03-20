//
// Created by Horatiu on 19-Mar-19.
//

#ifndef LAB5_6_DYNAMICVECTOR_H
#define LAB5_6_DYNAMICVECTOR_H
#define DEFAULT_CAPACITY 10

#include "exceptions.h"

template<class TElem>
class DynamicVector
{
private:
    int size;
    int capacity;
    TElem *elements;

    void extend();

    void shrink();

    void validateIndex(int index);

public:
    DynamicVector();

    void add(TElem element);

    TElem get(int index);

    void set(TElem element, int index);

    void remove(int index);

    void removeElement(TElem element);

    int length();

    ~DynamicVector();
};

template<class TElem>
DynamicVector<TElem>::DynamicVector()
{
    size = 0;
    capacity = DEFAULT_CAPACITY;
    elements = new TElem[capacity];
}

template<class TElem>
DynamicVector<TElem>::~DynamicVector()
{
    delete[] elements;
}

template<class TElem>
void DynamicVector<TElem>::add(TElem element)
{
    extend();
    elements[size++] = element;
}

template<class TElem>
TElem DynamicVector<TElem>::get(int index)
{
    validateIndex(index);
    return elements[index];
}

template<class TElem>
void DynamicVector<TElem>::set(TElem element, int index)
{
    validateIndex(index);
    elements[index] = element;
}

template<class TElem>
void DynamicVector<TElem>::remove(int index)
{
    validateIndex(index);
    for (int i = index; i < size - 1; i++)
    {
        elements[i] = elements[i + 1];
    }
    size--;
}

template<class TElem>
void DynamicVector<TElem>::removeElement(TElem element)
{
    for (int i = 0; i < size; i++)
    {
        if (elements[i] == element)
        {
            remove(i);
            return;
        }
    }
}

template<class TElem>
int DynamicVector<TElem>::length()
{
    return size;
}

template<class TElem>
void DynamicVector<TElem>::extend()
{
    if (size == capacity)
    {
        capacity = 2 * capacity;
        TElem *newElements = new TElem[capacity];
        for (int i = 0; i < size; i++)
        {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }
}

template<class TElem>
void DynamicVector<TElem>::shrink()
{
    if (size == capacity / 4)
    {
        capacity = capacity / 2;
        TElem *newElements = new TElem[capacity];
        for (int i = 0; i < size; i++)
        {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }
}

template<class TElem>
void DynamicVector<TElem>::validateIndex(int index)
{
    if (index < 0 || index >= size)
    {
        throw IndexInvalidException();
    }
}


#endif //LAB5_6_DYNAMICVECTOR_H
