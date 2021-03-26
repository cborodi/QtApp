#pragma once
#include "domain.h"
#include "RepositoryValidator.h"
#include <vector>

class Repository {
private:
	vector<Dog> dogList;
	vector<Dog> adoptedDogs;

public:
	Repository() {};

	virtual void addDog(const Dog& dog);
	virtual void removeDog(const Dog& dog);
	virtual void updateDog(const Dog& dog);
	virtual void adoptDog(Dog& dog);
	virtual void removeFromMyList(Dog& dog);

	virtual void runDisplayApp() {};

	virtual vector<Dog> getDogs() { return this->dogList; }
	virtual vector<Dog> getAdoptedDogs() { return this->adoptedDogs; }
};