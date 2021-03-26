#pragma once
#include "TextFileRepository.h"

class HTMLListRepository : public TextFileRepository
{
private:
	string myListFileName;
public:
	HTMLListRepository(string fileName, string myListFileName) : TextFileRepository{ fileName }, myListFileName{ myListFileName } {}
	//this->saveMyListFile(vector<Dog>());
	void adoptDog(Dog& dog) override;
	void removeFromMyList(Dog& dog) override;

	vector<Dog> getAdoptedDogs() override { vector<Dog> dogs; this->loadMyListFile(dogs);  return dogs; };

	void loadMyListFile(vector<Dog>& dogs);

	void saveMyListFile(vector<Dog> dogs);

	void runDisplayApp() override;

	string splitHTMLLine(string HTMLText);
	tm splitDate(const string& birthDate);
};