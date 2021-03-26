#include "UI.h"
#define name 1
#define breedname 2
#define birthDate 3
#define vaccinationsCount 4
#define photograph 5

tm UI::splitDate(const string& birth)
{
	tm returnDate;
	char duplicateString[1001];
	strcpy(duplicateString, birth.c_str());
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


void UI::split_command(char command[], char words_found_in_command[][50], int& numberOfWords)
{
	char* command_token = strtok(command, " ,");
	while (command_token != NULL)
	{
		strcpy(words_found_in_command[numberOfWords++], command_token);
		command_token = strtok(NULL, " ,");
	}
}

void UI::addDogUI(char command[])
{
	char words_found_in_command[20][50];
	int numberOfWords = 0;
	split_command(command, words_found_in_command, numberOfWords);
	tm birthDateFormated = splitDate(words_found_in_command[birthDate]);
	try{
		this->service.addDogService(words_found_in_command[name], words_found_in_command[breedname], birthDateFormated, stoi(words_found_in_command[vaccinationsCount]), words_found_in_command[photograph]);
	}
	catch (exception& e) {
		cout << e.what() << '\n';
	}
}


void UI::deleteDogUI(char command[])
{
	char words_found_in_command[20][50];
	int numberOfWords = 0;
	split_command(command, words_found_in_command, numberOfWords);
	try{	
		this->service.removeDogService(words_found_in_command[name]);
	}
	catch (exception& e) {
		cout << e.what() << '\n';
	}
}

void UI::updateDogUI(char command[])
{
	char words_found_in_command[20][50];
	int numberOfWords = 0;
	split_command(command, words_found_in_command, numberOfWords);
	tm birthDateFormated = splitDate(words_found_in_command[birthDate]);
	try{
		this->service.updateDogService(words_found_in_command[name], words_found_in_command[breedname], birthDateFormated, stoi(words_found_in_command[vaccinationsCount]), words_found_in_command[photograph]);
	}
	catch (exception& e) {
		cout << e.what() << '\n';
	}
}

void UI::adoptDogUI(char command[])
{
	char words_found_in_command[20][50];
	int numberOfWords = 0;
	split_command(command, words_found_in_command, numberOfWords);
	try{
		this->service.adoptDogService(words_found_in_command[name]);
	}
	catch (exception& e) {
		cout << e.what() << '\n';
	}
}

void UI::displayDogList()
{
	vector<Dog> dogs = service.getDogsFromRepo();
	for (auto dog : dogs)
	{
		cout << dog;
	}
}

void UI::displayAdoptedDogList()
{
	vector<Dog> dogs = service.getAdoptedDogsFromRepo();
	for (auto dog : dogs)
	{
		cout << dog;
	}
	service.runDisplayAppService();
}

void UI::displayDogListByVaccinationCount(int vaccinationCount)
{
	vector<Dog> dogs = service.getDogsFromRepo();
	for (auto dog : dogs)
	{
		if (dog.getVaccinationCount() < vaccinationCount)
		{
			cout << dog;
		}
	}
}

void UI::displayDogListByVaccinationCountAndBreed(char breed[], int vaccinationCount)
{
	vector<Dog> dogs = service.getDogsFromRepo();
	for (auto dog : dogs)
	{
		if (dog.getBreed() == breed && dog.getVaccinationCount() < vaccinationCount)
		{
			cout << dog;
		}
	}
}

void UI::printNextDog(Dog& currentDog)
{
	cout << currentDog;
}

void UI::start()
{
	int userType; // 0 - admin 1 - user
	while (true)
	{
		cout << "Please select mode A/B\n";
		char full_command[100];
		cin.getline(full_command, 100);
		char words_found_in_command[20][50];
		int numberOfWords = 0;
		split_command(full_command, words_found_in_command, numberOfWords);
		if (strcmp(words_found_in_command[0], "mode") == 0 && strcmp(words_found_in_command[1], "A") == 0)
		{
			userType = 0;
			break;
		}
		else if (strcmp(words_found_in_command[0], "mode") == 0 && strcmp(words_found_in_command[1], "B") == 0)
		{
			userType = 1;
			break;
		}
		else if (strcmp(words_found_in_command[0], "exit") == 0)
			return;
	}
	while (true)
	{
		if (userType == 0)
		{
			while (true)
			{
				char full_command[100], explicit_command[100];
				cin.getline(full_command, 100);
				strcpy(explicit_command, full_command);
				strtok(explicit_command, " ");
				if (strcmp(explicit_command, "add") == 0)
				{
					this->addDogUI(full_command);
				}
				else if (strcmp(explicit_command, "delete") == 0)
				{
					this->deleteDogUI(full_command);
				}
				else if (strcmp(explicit_command, "update") == 0)
				{
					this->updateDogUI(full_command);
				}
				else if (strcmp(explicit_command, "list") == 0)
				{
					this->displayDogList();
				}
				else if (strcmp(explicit_command, "mode") == 0)
				{
					char words_found_in_command[20][50];
					int numberOfWords = 0;
					split_command(full_command, words_found_in_command, numberOfWords);
					if (strcmp(words_found_in_command[1], "B") == 0)
					{
						userType = 1;
						break;
					}
				}
				else if (strcmp(explicit_command, "exit") == 0)
					return;
				else
					cout << "Bad command\n";
			}
		}
		else
		{
			vector<Dog> dogs = service.getDogsFromRepo(); // current dog to be displayed at "next"
			int currentDog = 0;
			while (true)
			{
				char full_command[100], explicit_command[100];
				cin.getline(full_command, 100);
				strcpy(explicit_command, full_command);
				strtok(explicit_command, " ");
				if (strcmp(explicit_command, "next") == 0)
				{
					if (service.getDogsFromRepo().size() > 0)
						cout << dogs[currentDog];
					currentDog++;
					if (currentDog == service.getDogsFromRepo().size())
						currentDog = 0;
				}
				else if (strcmp(explicit_command, "save") == 0)
				{
					char save_command[100];
					strcpy(save_command, full_command);
					this->adoptDogUI(full_command);
				}
				else if (strcmp(explicit_command, "list") == 0)
				{
					char words_found_in_command[20][50];
					int numberOfWords = 0;
					split_command(full_command, words_found_in_command, numberOfWords);
					if (numberOfWords == 2)
					{
						this->displayDogListByVaccinationCount(atoi(words_found_in_command[1]));
					}
					else if (numberOfWords == 3)
					{
						this->displayDogListByVaccinationCountAndBreed(words_found_in_command[1], atoi(words_found_in_command[2]));
					}
				}
				else if (strcmp(explicit_command, "mylist") == 0)
				{
					this->displayAdoptedDogList();
				}
				else if (strcmp(explicit_command, "mode") == 0)
				{
					char words_found_in_command[20][50];
					int numberOfWords = 0;
					split_command(full_command, words_found_in_command, numberOfWords);
					if (strcmp(words_found_in_command[1], "A") == 0)
					{
						userType = 0;
						break;
					}
				}
				else if (strcmp(explicit_command, "exit") == 0)
					return;
				else
					cout << "Bad command\n";
			}
		}
	}
}