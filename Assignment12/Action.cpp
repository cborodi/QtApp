#include "Action.h"

void AddAction::executeUndo()
{
	this->repo.removeDog(this->addedDog);
}

void AddAction::executeRedo()
{
	this->repo.addDog(this->addedDog);
}

void DeleteAction::executeUndo()
{
	this->repo.addDog(this->deletedDog);
}

void DeleteAction::executeRedo()
{
	this->repo.removeDog(this->deletedDog);
}

void UpdateAction::executeUndo()
{
	this->repo.updateDog(this->updatedDog);
}

void UpdateAction::executeRedo()
{
	this->repo.updateDog(this->newDog);
}

void SaveAction::executeUndo()
{
	this->repo.removeFromMyList(this->savedDog);
}

void SaveAction::executeRedo()
{
	this->repo.adoptDog(this->savedDog);
}
