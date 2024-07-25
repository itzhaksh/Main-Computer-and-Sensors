#include "ConditionsGroup.h"

ConditionsGroup::ConditionsGroup()
	: _andOrButton(nullptr)
{
	_conditionsBox = new QGroupBox;
	_conditionsLayout = new QVBoxLayout;
	_buttonsLayout = new QHBoxLayout;
	
	addLayout(_buttonsLayout);
	_conditionsBox->setLayout(_conditionsLayout);
	addWidget(_conditionsBox);

	addConditionLayout();
	createAddConditionButton();
	createDeleteButton();
}

ConditionsGroup::~ConditionsGroup()
{
	if (_conditionsBox)
		delete _conditionsBox;
	
	if (_andOrButton)
		delete _andOrButton;

	if (_deleteButton)
		delete _deleteButton;

	_conditionLayouts.clear();
}

void ConditionsGroup::addConditionLayout(bool operationButton)
{
	ConditionWidgetsLayout* widgetsLayout = new ConditionWidgetsLayout;
	if (operationButton == true && _conditionLayouts.empty() == false)
	{
		widgetsLayout->setAndOrButton();
	}
	_conditionsLayout->addLayout(widgetsLayout);
	_conditionLayouts.push_back(widgetsLayout);

	connect(widgetsLayout, &ConditionWidgetsLayout::requestDelete, this, &ConditionsGroup::deleteCondition);
}

void ConditionsGroup::createAddConditionButton()
{
	_addConditionButton = new QPushButton("+");
	int defaultHeight = _addConditionButton->sizeHint().height();
	_addConditionButton->setFixedSize(defaultHeight, defaultHeight);
	connect(_addConditionButton, &QPushButton::clicked, this, &ConditionsGroup::addButtonClicked);
	_conditionsLayout->addWidget(_addConditionButton);
}

void ConditionsGroup::createDeleteButton()
{
	_deleteButton = new QPushButton("-");
	int defaultHeight = _deleteButton->sizeHint().height();
	_deleteButton->setFixedSize(defaultHeight, defaultHeight);
	_buttonsLayout->addWidget(_deleteButton);
	_buttonsLayout->addStretch(1);

	connect(_deleteButton, &QPushButton::clicked, this, [this]() {
		emit requestDelete(this);
	});
}

void ConditionsGroup::deleteCondition(ConditionWidgetsLayout* layout)
{
	if (_conditionLayouts.size() > 1 && _conditionLayouts.at(0) == layout)
	{
		_conditionLayouts.at(1)->deleteAndOrButton();
		// it becames the first one, so no need in this button anymore
	}
	_conditionsLayout->removeItem(layout);
	_conditionLayouts.erase(std::remove(_conditionLayouts.begin(), _conditionLayouts.end(), layout), _conditionLayouts.end());
	layout->deleteLater();
	_conditionsLayout->update();
}

void ConditionsGroup::addButtonClicked()
{
	if (_addConditionButton)
		delete _addConditionButton;

	addConditionLayout(true);
	createAddConditionButton();
}

void ConditionsGroup::setAndOrButton(bool And)
{
	if (!_andOrButton)
	{
		_andOrButton = new QPushButton(And == true ? "and group" : "or group");
		int defaultHeight = _andOrButton->sizeHint().height();
		_andOrButton->setFixedSize(defaultHeight * 3, defaultHeight);
		_buttonsLayout->insertWidget(0, _andOrButton);

		connect(_andOrButton, &QPushButton::clicked, this, &ConditionsGroup::andOrButtonSwitch);
	}
	else
	{
		_andOrButton->setText(And == true ? "and group" : "or group");
	}
}

void ConditionsGroup::deleteAndOrButton()
{
	_andOrButton->deleteLater();
	delete _andOrButton;
	_andOrButton = nullptr;
}

void ConditionsGroup::andOrButtonSwitch()
{
	QString text = _andOrButton->text();
	if (text == "or group")
		_andOrButton->setText("and group");
	else
		_andOrButton->setText("or group");
}
