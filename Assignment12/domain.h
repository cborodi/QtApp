#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Dog {
private:
	string name;
	string breed;
	tm birthDate;
	int vaccinationCount;
	string photograph;
public:
	Dog();

	Dog(const string& name, const string& breed, const tm& birthDate, const int vaccinationCount, const string& photograph);

	bool operator==(const Dog& newDog);

	string getName() const { return this->name; }
	string getBreed() const { return this->breed; }
	tm getBirthDate() const { return this->birthDate; }
	int getVaccinationCount() const { return this->vaccinationCount; }
	string getPhotograph() const { return this->photograph; }

	string toString();

	friend std::istream& operator>>(std::istream& inputStream, Dog& dog);
	friend std::ostream& operator<<(std::ostream& outputStream, const Dog& dog);

	tm splitDate(const string& birthDate);
};