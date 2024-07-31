#include "ConditionsBox.h"

#include <iostream>
#include <fstream>

ConditionsBox::ConditionsBox()
	: QGroupBox("if")
{
	_layout = new QVBoxLayout;
	createAddGroupButton();
	setLayout(_layout);
}

ConditionsBox::~ConditionsBox()
{
	if (_layout)
		delete _layout;
	if (_addConditionGroup)
		delete _addConditionGroup;
}

ConditionBase* ConditionsBox::data(std::ofstream& file)
{
	file << "ConditionsBox::save" << std::endl;

	for (const auto it : _conditionsGroup)
	{
		it->data(file);
	}

	return nullptr; // temp
}

void ConditionsBox::addConditionGroup(bool operationButton)
{
	ConditionsGroup* group = new ConditionsGroup;
	if (operationButton == true && _conditionsGroup.empty() == false)
	{
		group->setAndOrButton();
	}
	_layout->addLayout(group);
	_conditionsGroup.push_back(group);

	connect(group, &ConditionsGroup::requestDelete, this, &ConditionsBox::deleteGroup);
}

void ConditionsBox::deleteGroup(ConditionLayoutBase* group)
{

	if (_conditionsGroup.size() > 1 && _conditionsGroup.at(0) == group)
	{
		_conditionsGroup.at(1)->deleteAndOrButton();
		// it becames the first one, so no need in this button anymore
	}
	_layout->removeItem(group);
	_conditionsGroup.erase(std::remove(_conditionsGroup.begin(), _conditionsGroup.end(), group), _conditionsGroup.end());
	group->deleteLater();
	_layout->update();
}

void ConditionsBox::createAddGroupButton()
{
	_addConditionGroup = new QPushButton("+");
	int defaultHeight = _addConditionGroup->sizeHint().height();
	_addConditionGroup->setFixedSize(defaultHeight, defaultHeight);
	connect(_addConditionGroup, &QPushButton::clicked, this, &ConditionsBox::addButtonClicked);
	_layout->addWidget(_addConditionGroup);
}

void ConditionsBox::addButtonClicked()
{
	if (_addConditionGroup)
		delete _addConditionGroup;

	addConditionGroup(true);
	createAddGroupButton();
}
