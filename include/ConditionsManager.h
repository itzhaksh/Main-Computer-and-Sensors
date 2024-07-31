#ifndef CONDITIONS_MANAGER_H
#define CONDITIONS_MANAGER_H

#include "ConditionBase.h"
#include <vector>
#include <string>
#include <../resources/json.hpp>

class ConditionsManager {
private:
    std::vector<ConditionBase*> conditions;

public:
    void addCondition(ConditionBase* condition);
    bool validateAll() const;
    void exportToJson(const std::string& filename) const;
    ~ConditionsManager();
};

#endif