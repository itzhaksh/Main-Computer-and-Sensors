#pragma once

#include <QGroupBox>
#include <QPushButton.h>


#include "ConditionWidgetsLayout.h"

class ConditionsGroupBox : public QGroupBox
{
public:
	ConditionsGroupBox(QWidget* parent = nullptr);
	~ConditionsGroupBox();

private slots:
	void deleteCondition(ConditionWidgetsLayout* layout);

private:
	QVBoxLayout* _layout;
	std::vector<ConditionWidgetsLayout*> _conditionLayouts;
	QPushButton* _addCondition;

	void addCondition();
	void addConditionLayout(bool operationButton = false);
	void createAddButton();
};