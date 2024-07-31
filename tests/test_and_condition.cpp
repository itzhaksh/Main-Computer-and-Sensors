#include "doctest.h"
#include "../include/AndCondition.h"


class TrueCondition : public ConditionBase {
public:
    bool validate() override {
        return true;
    }
    nlohmann::json toJson() const override {
        return { {"type", "true"} };
    }
};

class FalseCondition : public ConditionBase {
public:
    bool validate() override {
        return false;
    }
    nlohmann::json toJson() const override {
        return { {"type", "false"} };
    }
};

TEST_CASE("AndCondition Tests") {
    SUBCASE("Both Conditions True") {
        TrueCondition trueCond;
        AndCondition andCond(&trueCond, &trueCond);
        CHECK(andCond.validate());
        CHECK(andCond.toJson() == nlohmann::json({
            {"type", "and"},
            {"left", nlohmann::json({{"type", "true"}})},
            {"right", nlohmann::json({{"type", "true"}})}
            }));
    }

    SUBCASE("One Condition False") {
        TrueCondition trueCond;
        FalseCondition falseCond;
        AndCondition andCond(&trueCond, &falseCond);
        CHECK_FALSE(andCond.validate());
        CHECK(andCond.toJson() == nlohmann::json({
            {"type", "and"},
            {"left", nlohmann::json({{"type", "true"}})},
            {"right", nlohmann::json({{"type", "false"}})}
            }));
    }
}
