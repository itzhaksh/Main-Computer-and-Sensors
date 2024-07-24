#ifndef CONDITION_BASE_H
#define CONDITION_BASE_H

class ConditionBase {
public:
    virtual bool validate() = 0;
    virtual ~ConditionBase() = default;
};

#endif 