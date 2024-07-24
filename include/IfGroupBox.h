#pragma once

#include <QGroupBox>
#include <QPushButton.h>


#include "IfWidgetsLayout.h"

class IfGroupBox : public QGroupBox
{
public:
	IfGroupBox(QWidget* parent = nullptr);
	~IfGroupBox();

private slots:
	void deleteCondition(IfWidgetsLayout* layout);

private:
	QVBoxLayout* _layout;
	std::vector<IfWidgetsLayout*> _conditionLayouts;
	QPushButton* _addCondition;

	void addCondition();
	void addConditionLayout();
	void createAddButton();
};