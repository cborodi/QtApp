#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "domain.h"
#include "Repository.h"

using namespace std;

class TextFileRepository : public Repository
{
private:
	string fileName;
public:
	TextFileRepository(string fileName) : fileName{ fileName } {}

	void addDog(const Dog& dog) override;
	void removeDog(const Dog& dog) override;
	void updateDog(const Dog& dog) override;

	vector<Dog> getDogs() override { vector<Dog> dogs;  this->loadFile(dogs);  return dogs; };
	//vector<Dog>& getAdoptedDogs() { return this->getAdoptedDogs(); }

	void loadFile(vector<Dog>& dogs);

	void saveFile(vector<Dog> dogArray);

	void clearFile();
};