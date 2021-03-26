#include "MyListTableModel.h"

int MyListTableModel::rowCount(const QModelIndex& parent) const
{
	return this->repo.getAdoptedDogs().size();
}

int MyListTableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

string tmToString(tm date)
{
	return to_string(date.tm_mday) + "-" + to_string(date.tm_mon) + "-" + to_string(date.tm_year);
}

QVariant MyListTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	Dog currentDog = this->repo.getAdoptedDogs()[row];

	if (role == Qt::DisplayRole)
	{
		switch (column) {
		case 0:
			return QString::fromStdString(currentDog.getName());
		case 1:
			return QString::fromStdString(currentDog.getBreed());
		case 2:
			return QString::fromStdString(tmToString(currentDog.getBirthDate()));
		case 3:
			return QString::fromStdString(to_string(currentDog.getVaccinationCount()));
		case 4:
			return QString::fromStdString(currentDog.getPhotograph());
		}
	}

	return QVariant();
}

QVariant MyListTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section) {
			case 0:
				return QString("Name");
			case 1:
				return QString("Breed");
			case 2:
				return QString("Birth Date");
			case 3:
				return QString("Vaccination Count");
			case 4:
				return QString("Photograph");
			}
		}
	}
	return QVariant();
}

bool MyListTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	return false;
}

Qt::ItemFlags MyListTableModel::flags(const QModelIndex& index) const
{
	return Qt::ItemFlags();
}

void MyListTableModel::update()
{
	emit layoutAboutToBeChanged();
	emit layoutChanged();
}
