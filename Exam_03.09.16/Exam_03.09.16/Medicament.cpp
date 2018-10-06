#include "stdafx.h"
#include "Medicament.h"


Medicament::Medicament()
{
	info = "���";
	company = "���";
	typeOfpackag = "���";
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
		throw Text_Exception("������ ������ ������!");

	os << "====================================" << endl;
	os << "\t��������: " << info << endl;
	os << "\t�������������: " << company << endl;
	os << "\t��� ����������: " << typeOfpackag << endl;
	os << "\t����: " << price << endl;
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
		cout << "������� ��������: ";
		getline(is, info);
		cout << "������� �������������: ";
		getline(is, company);
		cout << "������� ��� ����������: ";
		getline(is, typeOfpackag);
		do
		{
			is.sync();
			cout << "������� ����: ";
			getline(is, num_s);
		} while (!regex_match(num_s, Pattern));
	}
	else if (!is.good())
		throw Text_Exception("������ ������ �����!");

	med.SetInfo(info).SetCompany(company).SetTypeOfPackag(typeOfpackag).SetPrice(strtod(num_s.c_str(), NULL));

	return is;
}
