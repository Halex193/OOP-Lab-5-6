#ifndef LAB5_6_COMPARATOR_H
#define LAB5_6_COMPARATOR_H

template <class T>
class Comparator
{
public:
    virtual bool compare(const T &element1, const T &element2) = 0;
};

#endif //LAB5_6_COMPARATOR_H
