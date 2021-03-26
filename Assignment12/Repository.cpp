#include "Repository.h"
#include <algorithm>

void Repository::addDog(const Dog& dog)
{
	RepositoryValidator repoValidator{ this->dogList };
	repoValidator.validateAddition(dog);
	this->dogList.push_back(dog);
}

void Repository::removeDog(const Dog& dog)
{
	RepositoryValidator repoValidator{ this->dogList };
	repoValidator.validateDeletion(dog.getName());
	vector<Dog>::iterator position = find(this->dogList.begin(), this->dogList.end(), dog);
	this->dogList.erase(position);
}

void Repository::updateDog(const Dog& dog)
{
	RepositoryValidator repoValidator{ this->dogList };
	repoValidator.validateUpdate(dog);
	replace(this->dogList.begin(), this->dogList.end(), dog, dog);
}

void Repository::adoptDog(Dog& dog)
{
	RepositoryValidator repoValidator{ this->adoptedDogs };
	repoValidator.validateAdoption(dog.getName());
	this->adoptedDogs.push_back(dog);
}

void Repository::removeFromMyList(Dog& dog)
{
	vector<Dog>::iterator position = find(this->adoptedDogs.begin(), this->adoptedDogs.end(), dog);
	this->adoptedDogs.erase(position);
}