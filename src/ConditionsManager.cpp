#include "ConditionsManager.h"
#include <stdexcept>
#include <fstream>


void ConditionsManager::addCondition(ConditionBase* condition) {
    conditions.push_back(condition);
}

bool ConditionsManager::validateAll() const
{
    for (auto condition : conditions) {
        if (!condition->validate()) {
            return false;
        }
    }
    return true;
}


void ConditionsManager::exportToJson(const std::string& filename) const {
    nlohmann::json j;
    for (size_t i = 0; i < conditions.size(); ++i) {
        j["conditions"].push_back(conditions[i]->toJson());
    }
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
    file << j.dump(4);
}
ConditionsManager::~ConditionsManager() {
    for (ConditionBase* condition : conditions) {
        delete condition;
    }
}