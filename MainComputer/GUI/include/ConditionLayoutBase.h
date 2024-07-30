#pragma once

#include <QVBoxLayout>

class ConditionLayoutBase : public QVBoxLayout
{
	Q_OBJECT

public:
	virtual ~ConditionLayoutBase() = default;

	virtual void setAndOrButton(bool And = true) = 0;
	virtual void deleteAndOrButton()			 = 0;
	virtual void andOrButtonSwitch()			 = 0;
	virtual void save(std::ofstream& file)		 = 0;
};