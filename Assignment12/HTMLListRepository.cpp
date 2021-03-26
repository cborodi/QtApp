#include "HTMLListRepository.h"
#include <regex>
#include <windows.h>
#include <tchar.h>

void HTMLListRepository::adoptDog(Dog& dog)
{
	vector<Dog> dogs = this->getAdoptedDogs();
	RepositoryValidator repoValidator{ dogs };
	repoValidator.validateAdoption(dog.getName());
	dogs.push_back(dog);
	this->saveMyListFile(dogs);
}

void HTMLListRepository::removeFromMyList(Dog& dog)
{
	vector<Dog> dogs = this->getAdoptedDogs();
	vector<Dog>::iterator position = find(dogs.begin(), dogs.end(), dog);
	dogs.erase(position);
	this->saveMyListFile(dogs);
}

string HTMLListRepository::splitHTMLLine(string HTMLText)
{
	int stringParseIndex = 3, currentNewStringIndex = 0;
	int stringLength = HTMLText.length();
	stringParseIndex += 4; // 4 characters = <td>
	string resultedString;
	while (stringParseIndex < stringLength - 5) // 5 characters = </td>
	{
		resultedString.append(1, HTMLText[stringParseIndex]);
		stringParseIndex++;
	}
	return resultedString;
}

void HTMLListRepository::loadMyListFile(vector<Dog>& dogs)
{
	ifstream file(myListFileName);
	string HTMLtext;
	int countInitialLines = 14;
	int countFinalLines = 3;
	int currentReadLine = 0;
	string dogName, dogBreed, dogPhotograph;
	tm dogBirthDate;
	int dogVaccinationCount;
	while (getline(file, HTMLtext))
	{
		regex patternSTOP("(.*)(</table>)");
		if (regex_match(HTMLtext, patternSTOP))
			break;
		if (countInitialLines-- > 0)
			continue;
		if (currentReadLine >= 1 && currentReadLine <= 5)
		{
			string lineExtracted = splitHTMLLine(HTMLtext);
			switch (currentReadLine) {
			case 1:
				dogName = lineExtracted;
				break;
			case 2:
				dogBreed = lineExtracted;
				break;
			case 3:
				dogBirthDate = splitDate(lineExtracted);
				break;
			case 4:
				dogVaccinationCount = stoi(lineExtracted);
				break;
			case 5:
				dogPhotograph = lineExtracted;
				break;
			}
		}
		currentReadLine++;
		if (currentReadLine == 7)
		{
			Dog dog{ dogName, dogBreed, dogBirthDate, dogVaccinationCount, dogPhotograph };
			dogs.push_back(dog);
			currentReadLine = 0;
		}
	}
	file.close();
}

void HTMLListRepository::saveMyListFile(vector<Dog> dogs)
{
	ofstream file(myListFileName);

	file << "<!DOCTYPE HTML>\n";
	file << "<html>\n";
	file << "	<head>\n";
	file << "		<title>Adoption List</title>\n";
	file << "	</head>\n";
	file << "	<body>\n";
	file << "		<table border=\"1\">\n";
	file << "       <tr>\n";
	file << "			<td>Name</td>\n";
	file << "			<td>Breed</td>\n";
	file << "			<td>Birth Date</td>\n";
	file << "			<td>Vaccination Count</td>\n";
	file << "			<td>Photograph</td>\n";
	file << "		</tr>\n";

	for (auto dog : dogs)
	{
		file << "		<tr>\n";
		file << "			<td>" << dog.getName() << "</td>\n";
		file << "			<td>" << dog.getBreed() << "</td>\n";
		file << "			<td>" << to_string(dog.getBirthDate().tm_mday) << "-" << to_string(dog.getBirthDate().tm_mon) << "-" << to_string(dog.getBirthDate().tm_year) << "</td>\n";
		file << "			<td>" << dog.getVaccinationCount() << "</td>\n";
		file << "			<td>" << dog.getPhotograph() << "</td>\n";
		file << "		</tr>\n";
	}

	file << "		</table>\n";
	file << "	</body>\n";
	file << "</html>\n";



	file.close();
}

void HTMLListRepository::runDisplayApp()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", myListFileName.c_str(), NULL, SW_SHOWMAXIMIZED);
}

tm HTMLListRepository::splitDate(const string& birthDate)
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