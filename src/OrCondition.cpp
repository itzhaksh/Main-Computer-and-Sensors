#include "OrCondition.h"

bool OrCondition::validate() {
    return LHS->validate() || RHS->validate();
}