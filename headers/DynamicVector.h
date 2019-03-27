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
    int size{};
    int capacity{};
    TElem *elements;

    /**
     * Extends the dynamic vector if needed
     */
    void extend();

    /**
     * Shrinks the dynamic vector if needed
     */
    void shrink();

    /**
     * Validates an index within the vector
     */
    void validateIndex(int index) const;

public:
    /**
     * Creates a vector with the given capacity
     * @param capacity Defaults to DEFAULT_CAPACITY
     */
    explicit DynamicVector(int capacity = DEFAULT_CAPACITY);

    DynamicVector(const DynamicVector<TElem> &dynamicVector);

    DynamicVector<TElem> &operator=(const DynamicVector<TElem> &dynamicVector);

    /**
     * Adds an element at the end of the dynamic vector
     */
    void add(TElem element);

    /**
     * Retrieves the element stored at the specified position
     */
    TElem get(int index) const;

    /**
     * Sets the element at the specified index
     */
    void set(TElem element, int index);

    /**
     * Removes the element stored at the specified index
     */
    void remove(int index);

    /**
     * Gets the number of elements stored in the vector
     */
    int length() const;

    template<class T>
    friend DynamicVector<T> &operator+(DynamicVector<T> &dynamicVector, T element);

    template<class T>
    friend DynamicVector<T> &operator+(T element, DynamicVector<T> &dynamicVector);

    ~DynamicVector();
};

template<class TElem>
DynamicVector<TElem>::DynamicVector(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->elements = new TElem[capacity];
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
TElem DynamicVector<TElem>::get(int index) const
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
    shrink();
}

template<class TElem>
int DynamicVector<TElem>::length() const
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
void DynamicVector<TElem>::validateIndex(int index) const
{
    if (index < 0 || index >= size)
    {
        throw IndexInvalidException();
    }
}

template<class TElem>
DynamicVector<TElem>::DynamicVector(const DynamicVector<TElem> &dynamicVector)
{
    this->size = dynamicVector.size;
    this->capacity = dynamicVector.capacity;
    this->elements = new TElem[capacity];

    for (int i = 0; i < size; i++)
    {
        elements[i] = dynamicVector.elements[i];
    }
}

template<class TElem>
DynamicVector<TElem> &DynamicVector<TElem>::operator=(const DynamicVector<TElem> &dynamicVector)
{
    if (this == &dynamicVector)
    {
        return *this;
    }

    delete[] elements;
    this->size = dynamicVector.size;
    this->capacity = dynamicVector.capacity;
    this->elements = new TElem[capacity];

    for (int i = 0; i < size; i++)
    {
        elements[i] = dynamicVector.elements[i];
    }
    return *this;
}

template<class TElem>
DynamicVector<TElem> &operator+(DynamicVector<TElem> &dynamicVector, TElem element)
{
    dynamicVector.add(element);
    return dynamicVector;
}

template<class TElem>
DynamicVector<TElem> &operator+(TElem element, DynamicVector<TElem> &dynamicVector)
{
    dynamicVector.add(element);
    return dynamicVector;
}


#endif //LAB5_6_DYNAMICVECTOR_H
