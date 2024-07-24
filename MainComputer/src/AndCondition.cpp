#include "AndCondition.h"

bool AndCondition::validate() {
    return LHS->validate() && RHS->validate();
}