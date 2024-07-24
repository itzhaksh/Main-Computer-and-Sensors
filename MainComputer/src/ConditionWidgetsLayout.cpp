#include "ConditionWidgetsLayout.h"

ConditionWidgetsLayout::ConditionWidgetsLayout(QWidget* parent)
	: QVBoxLayout(parent), _andOrButton(nullptr)
{
	_Conditionlayout = new QHBoxLayout;

	_inputSource = new QComboBox(parent);
	_inputSource->setPlaceholderText("input source");
	_inputSource->addItem("sensor 1");
	_inputSource->addItem("sensor 2");
	_inputSource->addItem("sensor 3");
	_Conditionlayout->addWidget(_inputSource);

	_conditionType = new QComboBox(parent);
	_conditionType->setPlaceholderText("condition");
	_conditionType->addItem("greater then");
	_conditionType->addItem("smaller then");
	_conditionType->addItem("equels to");
	_Conditionlayout->addWidget(_conditionType);

	_validationValue = new QLineEdit(parent);
	_validationValue->setPlaceholderText("validation value");
	_Conditionlayout->addWidget(_validationValue);

	_deleteButton = new QPushButton("-");
	int defaultHeight = _deleteButton->sizeHint().height();
	_deleteButton->setFixedSize(defaultHeight, defaultHeight);
	_Conditionlayout->addWidget(_deleteButton);
	
	_Conditionlayout->addStretch(1);

	connect(_deleteButton, &QPushButton::clicked, this, [this]() {
		emit requestDelete(this);
	});

	addLayout(_Conditionlayout);

	addStretch(1);
}

ConditionWidgetsLayout::~ConditionWidgetsLayout()
{
	if (_inputSource)
		delete _inputSource;
	if (_conditionType)
		delete _conditionType;
	if (_validationValue)
		delete _validationValue;
	if (_deleteButton)
		delete _deleteButton;
	if (_andOrButton != nullptr)
		delete _andOrButton;
}

void ConditionWidgetsLayout::setAndOrButton(bool And)
{
	if (!_andOrButton)
	{
		_andOrButton = new QPushButton(And == true ? "and" : "or");
		insertWidget(0, _andOrButton);

		connect(_andOrButton, &QPushButton::clicked, this, &ConditionWidgetsLayout::andOrButtonSwitch);
	}
	else
	{
		_andOrButton->setText(And == true ? "and" : "or");
	}
}

void ConditionWidgetsLayout::andOrButtonSwitch()
{
	QString text = _andOrButton->text();
	if (text == "or")
		_andOrButton->setText("and");
	else
		_andOrButton->setText("or");
}

void ConditionWidgetsLayout::deleteAndOrButton()
{
	//_andOrButton->deleteLater();
	delete _andOrButton;
	_andOrButton = nullptr;
}
