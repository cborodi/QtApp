#include "Assignment12.h"

Assignment12::Assignment12(Service& service, MyListWidget& mylist, QWidget *parent)
	: QMainWindow(parent), mylist{ mylist }, service{ service }
{
	ui.setupUi(this);
	this->populateList();
	this->connectSignalsAndSlots();
}
#include <cassert>

void Assignment12::populateList()
{
	this->ui.dogListWidget->clear();
	std::vector<Dog> dogs = this->service.getDogsFromRepo();
	for (auto dog : dogs)
	{
		this->ui.dogListWidget->addItem(QString::fromStdString(dog.toString()));
	}
	this->populateMyList();
	this->populateListModeB(dogs);
}

void Assignment12::populateListModeB(std::vector<Dog> dogs)
{
	this->ui.dogListWidget_modeB->clear();
	for (auto dog : dogs)
	{
		this->ui.dogListWidget_modeB->addItem(QString::fromStdString(dog.toString()));
	}
}

void Assignment12::populateMyList()
{
	this->ui.mylistWidget->clear();
	std::vector<Dog> dogs = this->service.getAdoptedDogsFromRepo();
	for (auto dog : dogs)
	{
		this->ui.mylistWidget->addItem(QString::fromStdString(dog.toString()));
	}
}

void Assignment12::connectSignalsAndSlots()
{
	QObject::connect(this->ui.dogListWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->getSelectedIndex();
		if (selectedIndex < 0)
			return;

		Dog dog = this->service.getDogsFromRepo()[selectedIndex];
		this->ui.nameLineEdit->setText(QString::fromStdString(dog.getName()));
		this->ui.breedLineEdit->setText(QString::fromStdString(dog.getBreed()));
		this->ui.dateLineEdit->setText(QString::fromStdString(this->service.tmToString(dog.getBirthDate())));
		this->ui.vaccinationLineEdit->setText(QString::number(dog.getVaccinationCount()));
		this->ui.photographLineEdit->setText(QString::fromStdString(dog.getPhotograph()));
		});
	QObject::connect(this->ui.deleteButton, &QPushButton::clicked, this, &Assignment12::removeDog);
}

int Assignment12::getSelectedIndex()
{
	QModelIndexList selectedIndexes = this->ui.dogListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->ui.nameLineEdit->clear();
		this->ui.breedLineEdit->clear();
		this->ui.dateLineEdit->clear();
		this->ui.vaccinationLineEdit->clear();
		this->ui.photographLineEdit->clear();
		return -1;
	}

	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

int Assignment12::getSelectedIndex_modeB()
{
	QModelIndexList selectedIndexes = this->ui.dogListWidget_modeB->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		return -1;
	}
	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

void Assignment12::addDog()
{
	string dogName = this->ui.nameLineEdit->text().toStdString();
	string dogBreed = this->ui.breedLineEdit->text().toStdString();
	tm dogBirthDate = this->service.splitDate(this->ui.dateLineEdit->text().toStdString());
	int dogVaccinationCount = stoi(this->ui.vaccinationLineEdit->text().toStdString());
	string dogPhotograph = this->ui.photographLineEdit->text().toStdString();

	try {
		this->service.addDogService(dogName, dogBreed, dogBirthDate, dogVaccinationCount, dogPhotograph);
	}
	catch (IncorrectDateFormat& error) {
		QMessageBox::critical(this, "Error", "Incorrect Date Format!");
		return;
	}
	catch (AlreadyExists& error) {
		QMessageBox::critical(this, "Error", "This dog is already in the list!");
		return;
	}

	this->populateList();

	int lastElement = this->service.getDogsFromRepo().size() - 1;
	this->ui.dogListWidget->setCurrentRow(lastElement);
}

void Assignment12::removeDog()
{
	string dogName = this->ui.nameLineEdit->text().toStdString();

	if (dogName.empty())
	{
		int selectedIndex = this->getSelectedIndex();
		if (selectedIndex < 0)
		{
			QMessageBox::critical(this, "Error", "No dog was selected!");
			return;
		}
		else {
			dogName = this->service.getDogsFromRepo()[selectedIndex].getName();
		}
	}

	try {
		this->service.removeDogService(dogName);
	}
	catch (NameNotFound& error) {
		QMessageBox::critical(this, "Error", "This dog is not in the list!");
		return;
	}

	this->populateList();

	int lastElement = this->service.getDogsFromRepo().size() - 1;
}

void Assignment12::updateDog()
{
	string dogName = this->ui.nameLineEdit->text().toStdString();
	string dogBreed = this->ui.breedLineEdit->text().toStdString();
	tm dogBirthDate = this->service.splitDate(this->ui.dateLineEdit->text().toStdString());
	int dogVaccinationCount = stoi(this->ui.vaccinationLineEdit->text().toStdString());
	string dogPhotograph = this->ui.photographLineEdit->text().toStdString();

	try {
		this->service.updateDogService(dogName, dogBreed, dogBirthDate, dogVaccinationCount, dogPhotograph);
	}
	catch (IncorrectDateFormat& error) {
		QMessageBox::critical(this, "Error", "Incorrect Date Format!");
		return;
	}
	catch (NameNotFound& error) {
		QMessageBox::critical(this, "Error", "This dog is not in the list!");
		return;
	}

	this->populateList();
}

void Assignment12::undo()
{
	try {
		this->service.undo();
	}
	catch (exception& error) {
		QMessageBox::critical(this, "Error", "No more undoes!");
		return;
	}

	this->populateList();
}

void Assignment12::redo()
{
	try {
		this->service.redo();
	}
	catch (exception& error) {
		QMessageBox::critical(this, "Error", "No more redoes!");
		return;
	}

	this->populateList();
}

void Assignment12::undo_modeB()
{
	try {
		this->service.undo_modeB();
	}
	catch (exception& error) {
		QMessageBox::critical(this, "Error", "No more undoes!");
		return;
	}

	this->populateList();
}

void Assignment12::redo_modeB()
{
	try {
		this->service.redo_modeB();
	}
	catch (exception& error) {
		QMessageBox::critical(this, "Error", "No more redoes!");
		return;
	}

	this->populateList();
}

void Assignment12::showNewWindow()
{
	this->mylist.show();
}

void Assignment12::saveDog()
{
	string dogNameLine, dogName;
	int selectedIndex = this->getSelectedIndex_modeB();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No dog was selected!");
		return;
	}
	else {
		dogNameLine = this->ui.dogListWidget_modeB->item(selectedIndex)->text().toStdString();
		dogName = dogNameLine.substr(0, dogNameLine.find(' '));
	}

	try {
		this->service.adoptDogService(dogName);
		this->mylist.model->update();
	}
	catch (NameNotFound& error) {
		QMessageBox::critical(this, "Error", "This dog is not in the main list!");
		return;
	}
	catch (AlreadyExists& error) {
		QMessageBox::critical(this, "Error", "This dog is already in mylist!");
		return;
	}

	this->populateMyList();
}

void Assignment12::runMyList()
{
	this->service.runDisplayAppService();
}

void Assignment12::next()
{
	int selectedIndex = this->getSelectedIndex_modeB();
	if (selectedIndex == -1)
		this->ui.dogListWidget_modeB->setCurrentRow(0);
	else
		if (selectedIndex == this->ui.dogListWidget_modeB->count() - 1)
			this->ui.dogListWidget_modeB->setCurrentRow(0);
		else
			this->ui.dogListWidget_modeB->setCurrentRow(selectedIndex + 1);
}

void Assignment12::filter()
{
	string dogBreed = this->ui.breedLineEdit_modeB->text().toStdString();
	string dogVaccinationString = this->ui.vaccinationLineEdit_modeB->text().toStdString();
	if (dogVaccinationString.empty())
		return;
	
	int dogVaccinationCount = stoi(this->ui.vaccinationLineEdit_modeB->text().toStdString());

	std::vector<Dog> dogs;
	if (dogBreed.empty())
	{
		for (auto dog : this->service.getDogsFromRepo())
			if (dog.getVaccinationCount() < dogVaccinationCount)
				dogs.push_back(dog);
	}
	else
	{
		for (auto dog : this->service.getDogsFromRepo())
			if (dog.getBreed() == dogBreed && dog.getVaccinationCount() < dogVaccinationCount)
			{
				dogs.push_back(dog);
			}
	}
	this->populateListModeB(dogs);
}

