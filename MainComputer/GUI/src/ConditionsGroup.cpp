#include "ConditionsGroup.h"

#include <fstream>
#include <QMenu>

ConditionsGroup::ConditionsGroup()
	: _andOrButton(nullptr)
{
	_conditionsBox = new QGroupBox;
	_conditionsLayout = new QVBoxLayout;
	_buttonsLayout = new QHBoxLayout;
	
	addLayout(_buttonsLayout);
	_conditionsBox->setLayout(_conditionsLayout);
	addWidget(_conditionsBox);

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

	_SingleConditions.clear();
}

void ConditionsGroup::addSingleCondition(bool operationButton)
{
	SingleCondition* widgetsLayout = new SingleCondition;
	if (operationButton == true && _SingleConditions.empty() == false)
	{
		widgetsLayout->setAndOrButton();
	}
	_conditionsLayout->addLayout(widgetsLayout);
	_SingleConditions.push_back(widgetsLayout);

	connect(widgetsLayout, &SingleCondition::requestDelete, this, &ConditionsGroup::deleteCondition);
}

void ConditionsGroup::addConditionGroup(bool operationButton)
{
	ConditionsGroup* widgetsLayout = new ConditionsGroup;
	if (operationButton == true && _SingleConditions.empty() == false)
	{
		widgetsLayout->setAndOrButton();
	}
	_conditionsLayout->addLayout(widgetsLayout);
	_SingleConditions.push_back(widgetsLayout);

	connect(widgetsLayout, &ConditionsGroup::requestDelete, this, &ConditionsGroup::deleteCondition);
}

void ConditionsGroup::createAddConditionButton()
{
	_addConditionButton = new QPushButton("+");
	int defaultHeight = _addConditionButton->sizeHint().height();
	_addConditionButton->setFixedSize(defaultHeight, defaultHeight);
	//connect(_addConditionButton, &QPushButton::clicked, this, &ConditionsGroup::addButtonClicked);

	QMenu* menu = new QMenu();
	QAction* addSingleConditionAction = new QAction("Add Single Condition");
	QAction* addConditionGroupAction = new QAction("Add Condition Group");

	menu->addAction(addSingleConditionAction);
	menu->addAction(addConditionGroupAction);

	connect(addSingleConditionAction, &QAction::triggered, this, &ConditionsGroup::addSingleButtonClicked);
	connect(addConditionGroupAction, &QAction::triggered, this, &ConditionsGroup::addGroupButtonClicked);

	// connect the button to show the menu
	connect(_addConditionButton, &QPushButton::clicked, [this, menu]() {
		menu->exec(QCursor::pos());
	});

	_conditionsLayout->addWidget(_addConditionButton);
	//_buttonsLayout->addStretch(1);
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

void ConditionsGroup::deleteCondition(ConditionLayoutBase* layout)
{
	if (_SingleConditions.size() > 1 && _SingleConditions.at(0) == layout)
	{
		_SingleConditions.at(1)->deleteAndOrButton();
		// it becames the first one, so no need in this button anymore
	}
	_conditionsLayout->removeItem(layout);
	_SingleConditions.erase(std::remove(_SingleConditions.begin(), _SingleConditions.end(), layout), _SingleConditions.end());
	layout->deleteLater();
	_conditionsLayout->update();
}

void ConditionsGroup::addSingleButtonClicked()
{
	if (_addConditionButton)
		delete _addConditionButton;

	addSingleCondition(true);
	createAddConditionButton();
}

void ConditionsGroup::addGroupButtonClicked()
{
	if (_addConditionButton)
		delete _addConditionButton;

	addConditionGroup(true);
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

void ConditionsGroup::save(std::ofstream& file)
{
	file << "ConditionsGroup::save" << std::endl;

	for (const auto it : _SingleConditions)
	{
		it->save(file);
	}
}
