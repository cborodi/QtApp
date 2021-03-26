#include "RepositoryValidator.h"

void RepositoryValidator::validateAddition(Dog dog)
{
	for (auto dogInList : this->dogs)
	{
		if (dogInList == dog)
			throw AlreadyExists("This dog is already in the list");
	}
}

void RepositoryValidator::validateDeletion(string dogName)
{
	for (auto dogInList : this->dogs)
	{
		if (dogInList.getName() == dogName)
		{
			return;
		}
	}
	throw NameNotFound("This dog is not in the list");
}

void RepositoryValidator::validateUpdate(Dog dog)
{
	for (auto dogInList : this->dogs)
	{
		if (dogInList == dog)
			return;
	}
	throw NameNotFound("This dog is not in the list");
}

void RepositoryValidator::validateAdoption(string dogName)
{
	for (auto dogInList : this->dogs)
	{
		if (dogInList.getName() == dogName)
			throw AlreadyExists("This dog is already in the list");
	}
}
