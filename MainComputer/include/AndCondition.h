#ifndef AND_CONDITION_H
#define AND_CONDITION_H

#include "CompositeCondition.h"
#include <../resources/json.hpp>


class AndCondition : public CompositeCondition {
public:
    using CompositeCondition::CompositeCondition;
    bool validate() override;
    nlohmann::json toJson() const override;

};

#endif 