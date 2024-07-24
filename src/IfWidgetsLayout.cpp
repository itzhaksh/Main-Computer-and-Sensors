#include "IfWidgetsLayout.h"

IfWidgetsLayout::IfWidgetsLayout(QWidget* parent)
	: QHBoxLayout(parent)
{
	_inputSource = new QComboBox(parent);
	_inputSource->setPlaceholderText("input source");
	_inputSource->addItem("sensor 1");
	_inputSource->addItem("sensor 2");
	_inputSource->addItem("sensor 3");
	addWidget(_inputSource);
	this->

	_conditionType = new QComboBox(parent);
	_conditionType->setPlaceholderText("condition");
	_conditionType->addItem("greater then");
	_conditionType->addItem("smaller then");
	_conditionType->addItem("equels to");
	addWidget(_conditionType);

	_validationValue = new QLineEdit(parent);
	_validationValue->setPlaceholderText("validation value");
	addWidget(_validationValue);

	_deleteButton = new QPushButton("-");
	int defaultHeight = _deleteButton->sizeHint().height();
	_deleteButton->setFixedSize(defaultHeight, defaultHeight);
	addWidget(_deleteButton);

	connect(_deleteButton, &QPushButton::clicked, this, [this]() {
		emit requestDelete(this);
	});

	addStretch(1);
}

IfWidgetsLayout::~IfWidgetsLayout()
{
	if (_inputSource)
		delete _inputSource;
	if (_conditionType)
		delete _conditionType;
	if (_validationValue)
		delete _validationValue;
	if (_deleteButton)
		delete _deleteButton;
}
