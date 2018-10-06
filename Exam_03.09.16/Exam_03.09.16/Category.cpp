#include "stdafx.h"
#include "Category.h"


Category::Category()
{
	name = "нет";
}

Category::Category(string n)
{
	name = n;
}

Category::Category(const Category& rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
	}
}

Category::~Category()
{}

void Category::SetName(string n)
{
	name = n;
}


std::string Category::GetName() const
{
	return name;
}


void Category::Show(ostream& os /*= cout*/)
{
	if (!os.good())
		throw Text_Exception("Ошибка потока вывода!");

	os << "Категория: " << name << endl;
}

bool Category::operator<(const Category& rhs) const
{
	return name < rhs.name;
}

bool Category::operator>(const Category& rhs) const
{
	return name > rhs.name;
}

bool Category::operator==(const Category& rhs)
{
	return (name == rhs.name);
}

bool Category::operator!=(const Category& rhs)
{
	return (name != rhs.name);
}

Category& Category::operator=(const Category& rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
	}
	return *this;
}

ostream& operator<< (ostream& os, const Category& cat)
{
	if (!os.good())
		throw Text_Exception("Ошибка потока вывода!");

	os << "Категория: " << cat.GetName() << endl;
	return os;
}

istream& operator>> (istream& is, Category& cat)
{
	string name;
	if (is.good())
	{
		is.sync();
		cout << "Введите название категории: ";
		getline(is, name);
	}
	else if (!is.good())
		throw Text_Exception("Ошибка потока ввода!");

	cat.SetName(name);

	return is;
}