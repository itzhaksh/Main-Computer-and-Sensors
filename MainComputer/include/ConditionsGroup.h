#pragma once

#include <QVBoxLayout>
#include <QGroupBox>

#include "ConditionWidgetsLayout.h"

class ConditionsGroup : public QVBoxLayout
{
	Q_OBJECT

public:
	ConditionsGroup();
	~ConditionsGroup();

	void setAndOrButton(bool And = true);
	void deleteAndOrButton();
	void andOrButtonSwitch();

private:
	QGroupBox* _conditionsBox;
	QVBoxLayout* _conditionsLayout;
	QHBoxLayout* _buttonsLayout;
	std::vector<ConditionWidgetsLayout*> _conditionLayouts;
	QPushButton* _addConditionButton;
	QPushButton* _andOrButton;
	QPushButton* _deleteButton;
	
	void addConditionLayout(bool operationButton = false);
	void createAddConditionButton();
	void createDeleteButton();
	void deleteCondition(ConditionWidgetsLayout* layout);
	void addButtonClicked();
	
signals:
	void requestDelete(ConditionsGroup* group);
};