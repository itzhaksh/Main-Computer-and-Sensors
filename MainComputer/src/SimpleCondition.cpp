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
    else if (validationType == "greater_than") {
        return std::stoi(input) > std::stoi(validationValue);
    }
    return false; 
}

nlohmann::json SimpleCondition::toJson() const {
    return {
        {"input", input},
        {"validationType", validationType},
        {"validationValue", validationValue}
    };
}

