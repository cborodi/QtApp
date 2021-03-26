#pragma once
#include "Repository.h"
#include "domain.h"

class Action {
public:
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
	virtual ~Action() {}
};

class AddAction : public Action {
private:
	Dog addedDog;
	Repository& repo;
public:
	AddAction(Dog dog, Repository& repo) : addedDog{ dog }, repo{ repo } {}
	void executeUndo() override;
	void executeRedo() override;
	~AddAction() override {}
};

class DeleteAction : public Action {
private:
	Dog deletedDog;
	Repository& repo;
public:
	DeleteAction(Dog dog, Repository& repo) : deletedDog{ dog }, repo{ repo } {}
	void executeUndo() override;
	void executeRedo() override;
	~DeleteAction() override {}
};

class UpdateAction : public Action {
private:
	Dog updatedDog;
	Dog newDog;
	Repository& repo;
public:
	UpdateAction(Dog oldDog, Dog youngDog, Repository& repo) : updatedDog{ oldDog }, newDog{ youngDog }, repo{ repo } {}
	void executeUndo() override;
	void executeRedo() override;
	~UpdateAction() override {}
};

class SaveAction : public Action {
private:
	Dog savedDog;
	Repository& repo;
public:
	SaveAction(Dog savedDog, Repository& repo) : savedDog{ savedDog }, repo{ repo } {}
	void executeUndo() override;
	void executeRedo() override;
	~SaveAction() override {}
};