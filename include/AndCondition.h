#ifndef AND_CONDITION_H
#define AND_CONDITION_H

#include "CompositeCondition.h"

class AndCondition : public CompositeCondition {
public:
    using CompositeCondition::CompositeCondition;
    bool validate() override;
};

#endif 