#include "conditionsManager.h"

void conditionsManager::addCondition(ConditionBase* condition) {
    conditions.push_back(condition);
}

bool conditionsManager::validateAll() {
    for (auto condition : conditions) {
        if (!condition->validate()) {
            return false;
        }
    }
    return true;
}

conditionsManager::~conditionsManager() {
    for (auto condition : conditions) {
        delete condition;
    }
}