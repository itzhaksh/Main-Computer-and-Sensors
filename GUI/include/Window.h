#pragma once

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>

#include "ConditionsBox.h"
#include "ThenGroupBox.h"

class Window : public QWidget
{
public:
	Window();
	
	void save();

private:
	QVBoxLayout* _windowLayout;
	ConditionsBox* _ConditionsBox;
	ThenGroupBox* _thenGroupBox;
	QPushButton* _saveButton;

};