#ifndef SIMPLE_CONDITION_H
#define SIMPLE_CONDITION_H

#include "ConditionBase.h"
#include <string>

class SimpleCondition : public ConditionBase {
private:
    std::string input;
    std::string validationType;
    std::string validationValue;

public:
    SimpleCondition(const std::string& input, const std::string& validationType, const std::string& validationValue);
    bool validate() override;
};

#endif 