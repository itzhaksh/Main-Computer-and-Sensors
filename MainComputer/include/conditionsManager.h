#ifndef CONDITIONS_MANAGER_H
#define CONDITIONS_MANAGER_H

#include "ConditionBase.h"
#include <vector>

class conditionsManager {
private:
    std::vector<ConditionBase*> conditions;

public:
    void addCondition(ConditionBase* condition);
    bool validateAll();
    ~conditionsManager();
};

#endif 