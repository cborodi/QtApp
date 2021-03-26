#include "Service.h"

void Service::addDogService(const string& name, const string& breed, const tm& birthDate, const int& vaccinationsCount, const string& photograph)
{
	Dog puppy{ name, breed, birthDate, vaccinationsCount, photograph };
	DogValidator dogValidator;
	dogValidator.validateDog(puppy);
	this->repo.addDog(puppy);
	this->undoStack.push(new AddAction(puppy, this->repo));
}

void Service::removeDogService(const string& name)
{
	vector<Dog> dogs = this->getDogsFromRepo();
	for (auto dog : dogs)
		if (dog.getName() == name)
		{
			this->repo.removeDog(dog);
			this->undoStack.push(new DeleteAction(dog, this->repo));
			return;
		}
	throw NameNotFound("This dog is not in the list");
}

void Service::updateDogService(const string& name, const string& breed, const tm& birthDate, const int& vaccinationsCount, const string& photograph)
{
	Dog puppy{ name, breed, birthDate, vaccinationsCount, photograph };
	DogValidator dogValidator;
	dogValidator.validateDog(puppy);
	Dog oldDog;
	for (auto dog : this->repo.getDogs())
	{
		if (puppy == dog)
		{
			oldDog = dog;
			break;
		}
	}
	this->repo.updateDog(puppy);
	this->undoStack.push(new UpdateAction(oldDog, puppy, this->repo));
}

#include <cassert>

void Service::adoptDogService(string name)
{
	vector<Dog> dogs = this->getDogsFromRepo();
	for (auto dog : dogs)
	{
		if (dog.getName() == name)
		{
			this->repo.adoptDog(dog);
			this->undoStack_modeB.push(new SaveAction(dog, this->repo));
			return;
		}
	}
	throw NameNotFound("This dog is not in the list");
}

void Service::undo()
{
	if (this->undoStack.empty() == true)
		throw exception("No more undoes");
	Action* action = this->undoStack.top();
	this->redoStack.push(action);
	this->undoStack.pop();

	action->executeUndo();
}

void Service::undo_modeB()
{
	if (this->undoStack_modeB.empty() == true)
		throw exception("No more undoes");
	Action* action = this->undoStack_modeB.top();
	this->redoStack_modeB.push(action);
	this->undoStack_modeB.pop();

	action->executeUndo();
}

void Service::redo()
{
	if (this->redoStack.empty() == true)
		throw exception("No more redoes");
	Action* action = this->redoStack.top();
	this->undoStack.push(action);
	this->redoStack.pop();

	action->executeRedo();
}

void Service::redo_modeB()
{
	if (this->redoStack_modeB.empty() == true)
		throw exception("No more redoes");
	Action* action = this->redoStack_modeB.top();
	this->undoStack_modeB.push(action);
	this->redoStack_modeB.pop();

	action->executeRedo();
}

tm Service::splitDate(const string& birthDate)
{
	tm returnDate;
	char duplicateString[1001];
	strcpy(duplicateString, birthDate.c_str());
	char* command_token = strtok(duplicateString, "-");
	int numberOfWords = 0;
	while (command_token != NULL)
	{
		switch (numberOfWords) {
		case 0:
			returnDate.tm_mday = atoi(command_token);
			break;
		case 1:
			returnDate.tm_mon = atoi(command_token);
			break;
		case 2:
			returnDate.tm_year = atoi(command_token);
			break;
		default:
			break;
		}
		command_token = strtok(NULL, "-");
		numberOfWords++;
	}

	return returnDate;
}

string Service::tmToString(tm date)
{
	return to_string(date.tm_mday) + "-" + to_string(date.tm_mon) + "-" + to_string(date.tm_year);
}

void Service::runDisplayAppService()
{
	repo.runDisplayApp();
}