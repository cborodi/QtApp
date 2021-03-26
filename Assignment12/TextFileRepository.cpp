#include "TextFileRepository.h"
#include <algorithm>
#include <iostream>

void TextFileRepository::addDog(const Dog& dog)
{
	vector<Dog> dogList = this->getDogs();
	RepositoryValidator repoValidator{ dogList };
	repoValidator.validateAddition(dog);
	dogList.push_back(dog);
	this->saveFile(dogList);
}

void TextFileRepository::removeDog(const Dog& dog)
{
	vector<Dog> dogList = this->getDogs();
	vector<Dog>::iterator position = find(dogList.begin(), dogList.end(), dog);
	dogList.erase(position);
	this->saveFile(dogList);
}

void TextFileRepository::updateDog(const Dog& dog)
{
	vector<Dog> dogList = this->getDogs();
	RepositoryValidator repoValidator{ dogList };
	repoValidator.validateUpdate(dog);
	replace(dogList.begin(), dogList.end(), dog, dog);
	this->saveFile(dogList);
}


void TextFileRepository::loadFile(vector<Dog>& dogs)
{
	ifstream file(fileName);

	Dog dog{};
	while (file >> dog)
	{
		dogs.push_back(dog);
	}

	file.close();
}

void TextFileRepository::saveFile(vector<Dog> dogArray)
{
	ofstream file(fileName);

	for (auto dog : dogArray)
	{
		file << dog;
	}

	file.close();
}

void TextFileRepository::clearFile()
{
	ofstream file(fileName);
	file.close();
}