#pragma once

#include <QGroupBox>
#include <QPushButton.h>


#include "ConditionWidgetsLayout.h"
#include "ConditionsGroup.h"

class ConditionsBox : public QGroupBox
{
	Q_OBJECT

public:
	ConditionsBox();
	~ConditionsBox();

private:
	QVBoxLayout* _layout;
	std::vector<ConditionsGroup*> _conditionsGroup;
	QPushButton* _addConditionGroup;

	void addConditionGroup(bool operationButton = false);
	void deleteGroup(ConditionsGroup* group);
	void createAddGroupButton();
	void addButtonClicked();
};