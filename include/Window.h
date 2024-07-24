#pragma once

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>

#include "IfGroupBox.h"
#include "ThenGroupBox.h"

class Window : public QWidget
{
public:
	Window();

private:
	QVBoxLayout* _windowLayout;
	IfGroupBox* _ifGroupBox;
	ThenGroupBox* _thenGroupBox;
};