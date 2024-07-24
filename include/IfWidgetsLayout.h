#pragma once

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>

class IfWidgetsLayout : public QHBoxLayout
{
	Q_OBJECT

public:
	IfWidgetsLayout(QWidget* parent = nullptr);
	~IfWidgetsLayout();

signals:
	void requestDelete(IfWidgetsLayout* layout);

private:
	QComboBox* _inputSource;
	QComboBox* _conditionType;
	QLineEdit* _validationValue;
	QPushButton* _deleteButton;
};