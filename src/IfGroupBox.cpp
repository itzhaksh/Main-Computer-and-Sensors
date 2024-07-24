#include "IfGroupBox.h"

#include <iostream>

IfGroupBox::IfGroupBox(QWidget* parent)
	: QGroupBox("if", parent)
{
	_layout = new QVBoxLayout;
	addConditionLayout();
	createAddButton();
	setLayout(_layout);
}

IfGroupBox::~IfGroupBox()
{
	if (_layout)
		delete _layout;
	if (_addCondition)
		delete _addCondition;
}

void IfGroupBox::addCondition()
{
	addConditionLayout();

	if (_addCondition)
	{
		_addCondition->deleteLater();
		createAddButton();
	}
}

void IfGroupBox::addConditionLayout()
{
	IfWidgetsLayout* widgetsLayout = new IfWidgetsLayout;
	_layout->addLayout(widgetsLayout);
	_conditionLayouts.push_back(widgetsLayout);

	connect(widgetsLayout, &IfWidgetsLayout::requestDelete, this, &IfGroupBox::deleteCondition);
}

void IfGroupBox::createAddButton()
{
	_addCondition = new QPushButton("+");
	int defaultHeight = _addCondition->sizeHint().height();
	_addCondition->setFixedSize(defaultHeight, defaultHeight);
	connect(_addCondition, &QPushButton::clicked, this, &IfGroupBox::addCondition);
	_layout->addWidget(_addCondition);
}

void IfGroupBox::deleteCondition(IfWidgetsLayout* layout)
{
	_layout->removeItem(layout);
	_conditionLayouts.erase(std::remove(_conditionLayouts.begin(), _conditionLayouts.end(), layout), _conditionLayouts.end());
	layout->deleteLater();
	_layout->update();
}