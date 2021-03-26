#include "CSVListRepository.h"
#include <windows.h>

void CSVListRepository::adoptDog(Dog& dog)
{
	vector<Dog> dogs = this->getAdoptedDogs();
	RepositoryValidator repoValidator{ dogs };
	repoValidator.validateAdoption(dog.getName());
	dogs.push_back(dog);
	this->saveMyListFile(dogs);
}

void CSVListRepository::removeFromMyList(Dog& dog)
{
	vector<Dog> dogs = this->getAdoptedDogs();
	vector<Dog>::iterator position = find(dogs.begin(), dogs.end(), dog);
	dogs.erase(position);
	this->saveMyListFile(dogs);
}

void CSVListRepository::loadMyListFile(vector<Dog>& dogs)
{
	ifstream file(myListFileName);

	Dog dog{};
	while (file >> dog)
	{
		dogs.push_back(dog);
	}
	file.close();
}

void CSVListRepository::saveMyListFile(vector<Dog> dogs)
{
	ofstream file(myListFileName);

	Dog dog{};
	for (auto dog : dogs)
	{
		file << dog; // works the same as the main list, because they are already in a CSV format
	}
	file.close();
}

void CSVListRepository::runDisplayApp()
{
	ShellExecuteA(NULL, NULL, "notepad.exe", myListFileName.c_str(), NULL, SW_SHOWMAXIMIZED);
}
