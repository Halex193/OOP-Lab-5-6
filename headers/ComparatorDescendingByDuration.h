#ifndef LAB5_6_COMPARATORDESCENDINGBYDURATION_H
#define LAB5_6_COMPARATORDESCENDINGBYDURATION_H

#include "Comparator.h"
#include "Tutorial.h"

class ComparatorDescendingByDuration : public Comparator<Tutorial>
{
public:
    bool compare(const Tutorial &tutorial1, const Tutorial &tutorial2) override
    {
        const Duration &duration1 = tutorial1.getDuration();
        const Duration &duration2 = tutorial2.getDuration();
        if (duration1.minutes > duration2.minutes)
        {
            return true;
        }
        if (duration1.minutes == duration2.minutes)
        {
            return duration1.seconds >= duration2.seconds;
        }
        return false;
    }
};

#endif //LAB5_6_COMPARATORDESCENDINGBYDURATION_H
