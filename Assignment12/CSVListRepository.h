#pragma once
#include "TextFileRepository.h"

class CSVListRepository : public TextFileRepository
{
private:
	string myListFileName;
public:
	CSVListRepository(string fileName, string myListFileName) : TextFileRepository{ fileName }, myListFileName{ myListFileName } {}

	void adoptDog(Dog& dog) override;
	void removeFromMyList(Dog& dog) override;

	vector<Dog> getAdoptedDogs() override { vector<Dog> dogs; this->loadMyListFile(dogs);  return dogs; };

	void loadMyListFile(vector<Dog>& dogs);

	void saveMyListFile(vector<Dog> dogs);

	void runDisplayApp() override;
};