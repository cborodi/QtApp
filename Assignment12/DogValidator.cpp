#include "DogValidator.h"
#include "Exceptions.h"

void DogValidator::validateDog(const Dog& dog)
{
	if (dog.getBirthDate().tm_mon > 12 || dog.getBirthDate().tm_mon < 1)
		throw IncorrectDateFormat("The date format is incorrect");
	if (dog.getBirthDate().tm_mday > 31 || dog.getBirthDate().tm_mday < 1)
		throw IncorrectDateFormat("The date format is incorrect");
	if (dog.getBirthDate().tm_year > 2020 || dog.getBirthDate().tm_mon < 1)
		throw IncorrectDateFormat("The date format is incorrect");
}
