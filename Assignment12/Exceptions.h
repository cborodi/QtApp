#pragma once
#include <exception>
#include <string>

class AlreadyExists : public std::exception
{
private:
	std::string message;

public:
	AlreadyExists(std::string message) : message{ message } {}
	const char* what() const throw() override {
		return this->message.c_str();
	}
};

class NameNotFound : public std::exception
{
private:
	std::string message;

public:
	NameNotFound(std::string message) : message{ message } {}
	const char* what() const throw() override {
		return this->message.c_str();
	}
};

class IncorrectDateFormat : public std::exception
{
private:
	std::string message;

public:
	IncorrectDateFormat(std::string message) : message{ message } {}
	const char* what() const throw() override {
		return this->message.c_str();
	}
};

class NotAnInteger : public std::exception
{
private:
	std::string message;

public:
	NotAnInteger(std::string message) : message{ message } {}
	const char* what() const throw() override {
		return this->message.c_str();
	}
};