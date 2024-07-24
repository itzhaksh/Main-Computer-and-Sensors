#include "ConditionsGroupBox.h"

#include <iostream>

ConditionsGroupBox::ConditionsGroupBox(QWidget* parent)
	: QGroupBox("if", parent)
{
	_layout = new QVBoxLayout;
	addConditionLayout();
	createAddButton();
	setLayout(_layout);
}

ConditionsGroupBox::~ConditionsGroupBox()
{
	if (_layout)
		delete _layout;
	if (_addCondition)
		delete _addCondition;
}

void ConditionsGroupBox::addCondition()
{
	addConditionLayout(true);

	if (_addCondition)
	{
		_addCondition->deleteLater();
		createAddButton();
	}
}

void ConditionsGroupBox::addConditionLayout(bool operationButton)
{
	ConditionWidgetsLayout* widgetsLayout = new ConditionWidgetsLayout;
	if (operationButton == true && _conditionLayouts.empty() == false)
	{
		widgetsLayout->setAndOrButton();
	}
	_layout->addLayout(widgetsLayout);
	_conditionLayouts.push_back(widgetsLayout);

	connect(widgetsLayout, &ConditionWidgetsLayout::requestDelete, this, &ConditionsGroupBox::deleteCondition);
}

void ConditionsGroupBox::createAddButton()
{
	_addCondition = new QPushButton("+");
	int defaultHeight = _addCondition->sizeHint().height();
	_addCondition->setFixedSize(defaultHeight, defaultHeight);
	connect(_addCondition, &QPushButton::clicked, this, &ConditionsGroupBox::addCondition);
	_layout->addWidget(_addCondition);
}

void ConditionsGroupBox::deleteCondition(ConditionWidgetsLayout* layout)
{
	if (_conditionLayouts.size() > 1 && _conditionLayouts.at(0) == layout)
	{
		_conditionLayouts.at(1)->deleteAndOrButton();
	}
	_layout->removeItem(layout);
	_conditionLayouts.erase(std::remove(_conditionLayouts.begin(), _conditionLayouts.end(), layout), _conditionLayouts.end());
	layout->deleteLater();
	_layout->update();
}