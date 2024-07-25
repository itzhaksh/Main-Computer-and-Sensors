#pragma once

#include <QGroupBox>
#include <QPushButton.h>


#include "SingleCondition.h"
#include "ConditionsGroup.h"

class ConditionsBox : public QGroupBox
{
	Q_OBJECT

public:
	ConditionsBox();
	~ConditionsBox();

private:
	QVBoxLayout* _layout;
	std::vector<ConditionLayoutBase*> _conditionsGroup;
	QPushButton* _addConditionGroup;

	void addConditionGroup(bool operationButton = false);
	void deleteGroup(ConditionLayoutBase* group);
	void createAddGroupButton();
	void addButtonClicked();
};