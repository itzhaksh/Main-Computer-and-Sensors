#include "SimpleCondition.h"

SimpleCondition::SimpleCondition(const std::string& input, const std::string& validationType, const std::string& validationValue)
    : input(input), validationType(validationType), validationValue(validationValue) {}

bool SimpleCondition::validate() {
    if (validationType == "equals") {
        return input == validationValue;
    }
    else if (validationType == "not_equals") {
        return input != validationValue;
    }
    else if (validationType == "contains") {
        return input.find(validationValue) != std::string::npos;
    }
    return false; 
}