#pragma once
#include "Repository.h"
#include "DogValidator.h"
#include "Action.h"
#include "MyListWidget.h"

#include <stack>

class Service {
private:
	Repository& repo;
	stack<Action*> undoStack;
	stack<Action*> redoStack;
	stack<Action*> undoStack_modeB;
	stack<Action*> redoStack_modeB;
	//MyListWidget& mylist;

public:
	Service(Repository& repository) : repo{ repository } {}

	vector<Dog> getDogsFromRepo() { return repo.getDogs(); }
	vector<Dog> getAdoptedDogsFromRepo() { return repo.getAdoptedDogs(); }

	void addDogService(const string& name, const string& breed, const tm& birthDate, const int& vaccinationsCount, const string& photograph);
	void removeDogService(const string& name);
	void updateDogService(const string& name, const string& breed, const tm& birthDate, const int& vaccinationsCount, const string& photograph);
	void adoptDogService(string name);
	tm splitDate(const string& birthDate);
	string tmToString(tm date);
	
	void undo();
	void undo_modeB();
	void redo();
	void redo_modeB();

	void runDisplayAppService();

};