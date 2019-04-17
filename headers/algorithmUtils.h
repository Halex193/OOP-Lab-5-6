#ifndef LAB5_6_ALGORITHMUTILS_H
#define LAB5_6_ALGORITHMUTILS_H

#include <vector>
#include <algorithm>
#include "Comparator.h"

template<class T>
void templatedSort(std::vector<T> &initialVector, Comparator<T> &comparator)
{
    std::sort(initialVector.begin(), initialVector.end(), [&comparator](T element1, T element2)
    { return comparator.compare(element1, element2); });
}

#endif //LAB5_6_ALGORITHMUTILS_H
