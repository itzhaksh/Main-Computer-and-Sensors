#pragma once

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>

#include "ConditionsGroupBox.h"
#include "ThenGroupBox.h"

class Window : public QWidget
{
public:
	Window();

private:
	QVBoxLayout* _windowLayout;
	ConditionsGroupBox* _ConditionsGroupBox;
	ThenGroupBox* _thenGroupBox;
};