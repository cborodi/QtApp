#pragma once
#include "Service.h"
#include <iostream>
#include <cstring>

using namespace std;

class UI
{
private:
	Service& service;

public:
	UI(Service& service) : service(service) {}

	void start();

private:
	void addDogUI(char command[]);
	void deleteDogUI(char command[]);
	void updateDogUI(char command[]);
	void adoptDogUI(char command[]);
	void split_command(char command[], char words_found_in_command[][50], int& numberOfWords);
	void displayDogList();
	void displayAdoptedDogList();
	void displayDogListByVaccinationCount(int vaccinationCount);
	void displayDogListByVaccinationCountAndBreed(char breed[], int vaccinationCount);
	void printNextDog(Dog& currentDog);
	tm splitDate(const string& birthDate);
};