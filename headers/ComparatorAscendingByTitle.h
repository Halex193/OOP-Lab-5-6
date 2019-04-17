#ifndef LAB5_6_COMPARATORASCENDINGBYTITLE_H
#define LAB5_6_COMPARATORASCENDINGBYTITLE_H

#include "Comparator.h"
#include "Tutorial.h"

class ComparatorAscendingByTitle : public Comparator<Tutorial>
{
public:
    bool compare(const Tutorial &tutorial1, const Tutorial &tutorial2) override
    {
        return tutorial1.getTitle() <= tutorial2.getTitle();
    }
};

#endif //LAB5_6_COMPARATORASCENDINGBYTITLE_H
