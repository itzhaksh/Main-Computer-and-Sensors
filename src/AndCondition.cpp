#include "AndCondition.h"

bool AndCondition::validate() {
    return LHS->validate() && RHS->validate();
}

nlohmann::json AndCondition::toJson() const {
    return {
        {"type", "and"},
        {"left", LHS->toJson()},
        {"right", RHS->toJson()}
    };
}