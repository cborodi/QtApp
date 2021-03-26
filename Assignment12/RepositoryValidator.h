#pragma once
#include <vector>
#include "domain.h"
#include "Exceptions.h"

class RepositoryValidator
{
private:
	vector<Dog> dogs;
public:
	RepositoryValidator(vector<Dog> dogs) : dogs{ dogs } {}

	void validateAddition(Dog dog);
	void validateDeletion(string dogName);
	void validateUpdate(Dog dog);
	void validateAdoption(string dogName);
};