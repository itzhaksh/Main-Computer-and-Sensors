#pragma once

#include <QVBoxLayout>
#include "ConditionBase.h"

class ConditionLayoutBase : public QVBoxLayout
{
	Q_OBJECT

public:
	virtual ~ConditionLayoutBase() = default;

	virtual void setAndOrButton(bool And = true)	 = 0;
	virtual void deleteAndOrButton()				 = 0;
	virtual void andOrButtonSwitch()				 = 0;
	virtual ConditionBase* data(std::ofstream& file) = 0;
};