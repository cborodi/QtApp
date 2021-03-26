#include "domain.h"

Dog::Dog() : name(""), breed(""), birthDate(), vaccinationCount(0), photograph("") {}

Dog::Dog(const string& name, const string& breed, const tm& birthDate, const int vaccinationCount, const string& photograph)
{
	this->name = name;
	this->breed = breed;
	this->birthDate = birthDate;
	this->vaccinationCount = vaccinationCount;
	this->photograph = photograph;
}

bool Dog::operator==(const Dog& newDog)
{
	return this->getName() == newDog.getName();
}

string Dog::toString()
{
	return this->getName() + " is a " + this->getBreed() + " born in " + to_string(this->getBirthDate().tm_mday) + "-" + to_string(this->getBirthDate().tm_mon) + "-" + to_string(this->getBirthDate().tm_year) + ". Vaccinations count: " + to_string(this->getVaccinationCount()) + ". " + this->getPhotograph();
}

vector<string> tokenize(string inputString, char delimiter)
{
	vector <string> result;
	stringstream stream(inputString);
	string stringToken;
	while (getline(stream, stringToken, delimiter))
		result.push_back(stringToken);

	return result;
}

#define dogName 0
#define dogBreed 1
#define dogBirthDate 2
#define dogVaccinationCount 3
#define dogPhotograph 4

std::istream& operator>>(std::istream& inputStream, Dog& dog)
{
	string intputline;
	getline(inputStream, intputline);

	vector<string> extreactedTokens = tokenize(intputline, ',');
	if (extreactedTokens.size() != 5)
		return inputStream;
	dog.name = extreactedTokens[dogName];
	dog.breed = extreactedTokens[dogBreed];
	dog.birthDate = dog.splitDate(extreactedTokens[dogBirthDate]);
	dog.vaccinationCount = stoi(extreactedTokens[dogVaccinationCount]);
	dog.photograph = extreactedTokens[dogPhotograph];

	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Dog& dog)
{
	outputStream << dog.name << "," << dog.breed << "," << to_string(dog.birthDate.tm_mday) << "-" << to_string(dog.birthDate.tm_mon) << "-" << to_string(dog.birthDate.tm_year) <<"," << dog.vaccinationCount << "," << dog.photograph << "\n";
	return outputStream;
}

tm Dog::splitDate(const string& birthDate)
{
	tm returnDate;
	char duplicateString[1001];
	strcpy(duplicateString, birthDate.c_str());
	char* command_token = strtok(duplicateString, "-");
	int numberOfWords = 0;
	while (command_token != NULL)
	{
		switch (numberOfWords) {
		case 0:
			returnDate.tm_mday = atoi(command_token);
			break;
		case 1:
			returnDate.tm_mon = atoi(command_token);
			break;
		case 2:
			returnDate.tm_year = atoi(command_token);
			break;
		default:
			break;
		}
		command_token = strtok(NULL, "-");
		numberOfWords++;
	}

	return returnDate;
}