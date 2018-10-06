#include "stdafx.h"
#include "Medicament.h"


Medicament::Medicament()
{
	info = "нет";
	company = "нет";
	typeOfpackag = "нет";
	price = 0;
}

Medicament::Medicament(string i, string comp, string type, double p)
{
	info = i;
	company = comp;
	typeOfpackag = type;
	price = p;
}

Medicament::Medicament(const Medicament& rhs)
{
	if (this != &rhs)
	{
		info = rhs.info;
		company = rhs.company;
		typeOfpackag = rhs.typeOfpackag;
		price = rhs.price;
	}
}

Medicament::~Medicament()
{}

Medicament& Medicament::SetInfo(string i)
{
	info = i; 
	return *this;
}

Medicament& Medicament::SetCompany(string comp)
{
	company = comp; 
	return *this;
}

Medicament& Medicament::SetTypeOfPackag(string type)
{
	typeOfpackag = type; 
	return *this;
}

Medicament& Medicament::SetPrice(double p)
{
	price = p; 
	return *this;
}

std::string Medicament::GetInfo() const
{
	return info;
}

std::string Medicament::GetCompany() const
{
	return company;
}

std::string Medicament::GetTypeOfPackag() const
{
	return typeOfpackag;
}

double Medicament::GetPrice() const
{
	return price;
}

void Medicament::Show(ostream& os /*= cout*/)
{
	if (!os.good())
		throw Text_Exception("Ошибка потока вывода!");

	os << "====================================" << endl;
	os << "\tНазвание: " << info << endl;
	os << "\tПроизводитель: " << company << endl;
	os << "\tВид расфасовки: " << typeOfpackag << endl;
	os << "\tЦена: " << price << endl;
}

bool Medicament::operator<(const Medicament& rhs) const
{
	return price < rhs.price;
}

bool Medicament::operator>(const Medicament& rhs) const
{
	return price > rhs.price;
}

Medicament& Medicament::operator=(const string rhs)
{
	info = rhs;
	return *this;
}

bool Medicament::operator==(const Medicament& rhs)
{
	return (info == rhs.info && company == rhs.company && typeOfpackag == rhs.typeOfpackag && price == rhs.price);
}

bool Medicament::operator!=(const Medicament& rhs)
{
	return (info != rhs.info && company != rhs.company && typeOfpackag != rhs.typeOfpackag && price != rhs.price);
}

Medicament& Medicament::operator=(const Medicament& rhs)
{
	if (this != &rhs)
	{
		info = rhs.info;
		company = rhs.company;
		typeOfpackag = rhs.typeOfpackag;
		price = rhs.price;
	}
	return *this;
}

ostream& operator<< (ostream& os, Medicament& med)
{
	med.Show(os);
	return os;
}

istream& operator>> (istream& is, Medicament& med)
{
	string info, company, typeOfpackag, num_s;	
	regex Pattern("[[:digit:]]+.[[:digit:]]+");
	if (is.good())
	{
		is.sync();
		cout << "Введите название: ";
		getline(is, info);
		cout << "Введите производителя: ";
		getline(is, company);
		cout << "Введите вид расфасовки: ";
		getline(is, typeOfpackag);
		do
		{
			is.sync();
			cout << "Введите цену: ";
			getline(is, num_s);
		} while (!regex_match(num_s, Pattern));
	}
	else if (!is.good())
		throw Text_Exception("Ошибка потока ввода!");

	med.SetInfo(info).SetCompany(company).SetTypeOfPackag(typeOfpackag).SetPrice(strtod(num_s.c_str(), NULL));

	return is;
}
