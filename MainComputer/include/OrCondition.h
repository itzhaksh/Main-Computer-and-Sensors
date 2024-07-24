#ifndef OR_CONDITION_H
#define OR_CONDITION_H

#include "CompositeCondition.h"

class OrCondition : public CompositeCondition {
public:
    using CompositeCondition::CompositeCondition;
    bool validate() override;
};

#endif 