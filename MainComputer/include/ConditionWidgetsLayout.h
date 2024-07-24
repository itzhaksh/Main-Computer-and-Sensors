#pragma once

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>

class ConditionWidgetsLayout : public QVBoxLayout
{
	Q_OBJECT

public:
	ConditionWidgetsLayout(QWidget* parent = nullptr);
	~ConditionWidgetsLayout();

	void setAndOrButton(bool And = true);
	void andOrButtonSwitch();
	void deleteAndOrButton();

signals:
	void requestDelete(ConditionWidgetsLayout* layout);

private:
	QHBoxLayout* _Conditionlayout;
	QComboBox* _inputSource;
	QComboBox* _conditionType;
	QLineEdit* _validationValue;
	QPushButton* _andOrButton;
	QPushButton* _deleteButton;
};