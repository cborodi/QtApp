#pragma once

#include <QtWidgets/QMainWindow>
#include "qmessagebox.h"
#include "ui_Assignment12.h"
#include "Service.h"
#include "MyListWidget.h"

class Assignment12 : public QMainWindow
{
	Q_OBJECT

public:
	Assignment12(Service& service, MyListWidget& mylist, QWidget *parent = Q_NULLPTR);

private:
	Ui::Assignment12Class ui;
	Service& service;
	MyListWidget& mylist;

	void populateList();
	void populateMyList();
	void populateListModeB(std::vector<Dog> dogs);

	void connectSignalsAndSlots();

	void removeDog();
	int getSelectedIndex();
	int getSelectedIndex_modeB();

public slots:
	void addDog();
	void updateDog();
	void saveDog();
	void runMyList();
	void next();
	void filter();
	void undo();
	void undo_modeB();
	void redo();
	void redo_modeB();
	void showNewWindow();
};
