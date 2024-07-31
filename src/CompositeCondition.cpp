#include "CompositeCondition.h"

CompositeCondition::CompositeCondition(ConditionBase* lhs, ConditionBase* rhs) : LHS(lhs), RHS(rhs) {}

CompositeCondition::~CompositeCondition() {
    delete LHS;
    delete RHS;
}