#include "Assignment12.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "CSVListRepository.h"
#include "HTMLListRepository.h"
#include "Assignment12.h"
#include "MyListWidget.h"

#include <fstream>

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);
	
	std::ifstream file;
	file.open("configuration.config");
	std::string line;

	std::string intermediaryString, fileLocation, mylistLocation;
	int currentWord = 1;
	while (std::getline(file, intermediaryString)) {
		std::stringstream stringstream(intermediaryString);
		while (std::getline(stringstream, intermediaryString, ' '))
		{
			if (currentWord == 2)
				fileLocation = intermediaryString;
			if (currentWord == 4)
				mylistLocation = intermediaryString;
			currentWord++;
		}
	}
	file.close();

	if (fileLocation == "inmemory")
	{
		if (mylistLocation == "inmemory")
		{
			Repository repo{};
			MyListTableModel* model = new MyListTableModel{ repo };
			MyListWidget mylist{ model };
			Service service(repo);
			Assignment12 gui{ service, mylist };
			gui.show();
			//mylist.show();
			return application.exec();
		}
	}
	else if (fileLocation == "file")
	{
		if (mylistLocation == "CSV")
		{
			CSVListRepository repo{"dogs.txt", "doglist.csv"};
			MyListTableModel* model = new MyListTableModel{ repo };
			MyListWidget mylist{ model };
			Service service(repo);
			Assignment12 gui{ service, mylist };
			gui.show();
			//mylist.show();
			return application.exec();
		}
		else if (mylistLocation == "HTML")
		{
			HTMLListRepository repo{ "dogs.txt", "doglist.html" };
			MyListTableModel* model = new MyListTableModel{ repo };
			MyListWidget mylist{ model };
			Service service(repo);
			Assignment12 gui{ service, mylist };
			gui.show();
			//mylist.show();
			return application.exec();
		}
	}
	else if (fileLocation == "HTML")
	{
		if (mylistLocation == "CSV")
		{
			CSVListRepository repo{ "dogs.html", "doglist.csv" };
			MyListTableModel* model = new MyListTableModel{ repo };
			MyListWidget mylist{ model };
			Service service(repo);
			Assignment12 gui{ service, mylist };
			gui.show();
			//mylist.show();
			return application.exec();
		}
		else if (mylistLocation == "HTML")
		{
			HTMLListRepository repo{ "dogs.html", "doglist.html" };
			MyListTableModel* model = new MyListTableModel{ repo };
			MyListWidget mylist{ model };
			Service service(repo);
			Assignment12 gui{ service, mylist };
			gui.show();
			//mylist.show();
			return application.exec();
		}
	}
	else if (fileLocation == "HTML")
	{
		if (mylistLocation == "CSV")
		{
			CSVListRepository repo{ "dogs.html", "doglist.csv" };
			MyListTableModel* model = new MyListTableModel{ repo };
			MyListWidget mylist{ model };
			Service service(repo);
			Assignment12 gui{ service, mylist };
			gui.show();
			//mylist.show();
			return application.exec();
		}
		else if (mylistLocation == "HTML")
		{
			HTMLListRepository repo{ "dogs.html", "doglist.html" };
			MyListTableModel* model = new MyListTableModel{ repo };
			MyListWidget mylist{ model };
			Service service(repo);
			Assignment12 gui{ service, mylist };
			gui.show();
			//mylist.show();
			return application.exec();
		}
	}
	else if (fileLocation == "CSV")
	{
		if (mylistLocation == "CSV")
		{
			CSVListRepository repo{ "dogs.csv", "doglist.csv" };
			MyListTableModel* model = new MyListTableModel{ repo };
			MyListWidget mylist{ model };
			Service service(repo);
			Assignment12 gui{ service, mylist };
			gui.show();
			//mylist.show();
			return application.exec();
		}
		else if (mylistLocation == "HTML")
		{
			HTMLListRepository repo{ "dogs.csv", "doglist.html" };
			MyListTableModel* model = new MyListTableModel{ repo };
			MyListWidget mylist{ model };
			Service service(repo);
			Assignment12 gui{ service, mylist };
			gui.show();
			//mylist.show();
			return application.exec();
		}
	}

	return application.exec();
}
