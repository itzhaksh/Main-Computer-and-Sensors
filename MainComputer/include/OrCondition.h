#ifndef OR_CONDITION_H
#define OR_CONDITION_H

#include "CompositeCondition.h"
#include <../resources/json.hpp>


class OrCondition : public CompositeCondition {
public:
    using CompositeCondition::CompositeCondition;
    bool validate() override;
    nlohmann::json toJson() const override;
};

#endif 