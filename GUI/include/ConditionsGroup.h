#pragma once

#include <QVBoxLayout>
#include <QGroupBox>

#include "SingleCondition.h"
#include "ConditionLayoutBase.h"

class ConditionsGroup : public ConditionLayoutBase
{
	Q_OBJECT

public:
	ConditionsGroup();
	~ConditionsGroup();

	void setAndOrButton(bool And = true);
	void deleteAndOrButton();
	void andOrButtonSwitch();
	ConditionBase* data(std::ofstream& file);

private:
	std::vector<ConditionLayoutBase*> _SingleConditions;
	QGroupBox* _conditionsBox;
	QVBoxLayout* _conditionsLayout;
	QHBoxLayout* _buttonsLayout;
	QPushButton* _andOrButton;
	QPushButton* _addConditionButton;
	QPushButton* _deleteButton;
	
	void addSingleCondition(bool operationButton = false);
	void addConditionGroup(bool operationButton = false);
	void createAddConditionButton();
	void createDeleteButton();
	void deleteCondition(ConditionLayoutBase* layout);
	void addSingleButtonClicked();
	void addGroupButtonClicked();
	
signals:
	void requestDelete(ConditionLayoutBase* group);
};