#pragma once

#include <QWidget>
#include "ui_MyListWidget.h"
#include "MyListTableModel.h"

class MyListWidget : public QWidget
{
	Q_OBJECT

public:
	MyListWidget(MyListTableModel* model, QWidget *parent = Q_NULLPTR);
	void update();
	~MyListWidget();
	MyListTableModel* model;

private:
	Ui::MyListWidget ui; 
};
