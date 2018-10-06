#include "stdafx.h"
#include "ChemistShop.h"


ChemistShop::ChemistShop()
{
}

ChemistShop::ChemistShop(const ChemistShop& rhs)
{
	if (this != &rhs)
	{
		this->Drugs = rhs.Drugs;
	}
}

ChemistShop::~ChemistShop()
{}

size_t ChemistShop::size()
{
	size_t count = 0;

	for (auto i = Drugs.begin(); i != Drugs.end(); i++)
		count += i->second.size();

	return count;
}

bool ChemistShop::AddCategory(Category cat)
{
	pair<map<Category, vector<Medicament>>::iterator, bool> check;
	check = Drugs.insert(pair<Category, vector<Medicament>>(cat, {}));
	return (check.second == false) ? false : true;
}

bool ChemistShop::AddCategory(string str)
{
	Category cat(str);
	pair<map<Category, vector<Medicament>>::iterator, bool> check;
	check = Drugs.insert(pair<Category, vector<Medicament>>(cat, {}));
	return (check.second == false) ? false : true;
}

bool ChemistShop::DeleteCategory(Category cat)
{
	map<Category, vector<Medicament>>::iterator it = Drugs.find(cat);
	if (it != Drugs.end())
	{
		Drugs.erase(it);
		return true;
	}
	else
		return false;
}

bool ChemistShop::DeleteCategory(string str)
{
	Category cat(str);
	map<Category, vector<Medicament>>::iterator it = Drugs.find(cat);
	if (it != Drugs.end())
	{
		Drugs.erase(it);
		return true;
	}
	else
		return false;
}

bool ChemistShop::Add(Medicament med, string str)
{
	Category cat(str);
	map<Category, vector<Medicament>>::iterator it = Drugs.find(cat);
	if (it != Drugs.end())
	{
		Drugs.at(cat).push_back(med);
		return true;
	}
	else
		return false;
}

bool ChemistShop::Add(Medicament med, Category cat)
{
	map<Category, vector<Medicament>>::iterator it = Drugs.find(cat);
	if (it != Drugs.end())
	{
		Drugs.at(cat).push_back(med);
		return true;
	}
	else
		return false;
}

bool ChemistShop::Delete(Medicament med)
{
	vector<Medicament>::iterator it;
	for (auto i = Drugs.begin(); i != Drugs.end(); i++)
	{
		it = find(i->second.begin(), i->second.end(), med);
		if (it != i->second.end())
		{
			i->second.erase(it);
			return true;
		}
	}
	return false;
}

bool ChemistShop::Delete(string name)
{
	for (auto i = Drugs.begin(); i != Drugs.end(); i++)
		for (auto j = i->second.begin(); j != i->second.end(); j++)
			if (j->GetInfo() == name)
			{
				i->second.erase(j);
				return true;
			}
	return false;
}

ChemistShop ChemistShop::FindByLetter(char ch)
{
	ChemistShop result;

	for (auto i = Drugs.begin(); i != Drugs.end(); i++)
		for (auto j = i->second.begin(); j != i->second.end(); j++)
			if (j->GetInfo()[0] == ch)
			{
				result.AddCategory(i->first);
				result.Add(*j, i->first);
			}

	return result;
}

ChemistShop ChemistShop::FindByCategory(string name)
{
	ChemistShop result;

	Category cat(name);
	map<Category, vector<Medicament>>::iterator it = Drugs.find(cat);
	if (it != Drugs.end())
	{
		result.AddCategory(cat);
		for (auto j = it->second.begin(); j != it->second.end(); j++)
			result.Add(*j, it->first);
	}

	return result;
}

ChemistShop ChemistShop::FindByCompany(string name)
{
	ChemistShop result;
	
	for (auto i = Drugs.begin(); i != Drugs.end(); i++)
		for (auto j = i->second.begin(); j != i->second.end(); j++)
			if (j->GetCompany() == name)
			{
				result.AddCategory(i->first);
				result.Add(*j, i->first);
			}

	return result;
}

ChemistShop ChemistShop::FindByPrice(double A, double B)
{
	ChemistShop result;

	for (auto i = Drugs.begin(); i != Drugs.end(); i++)
		for (auto j = i->second.begin(); j != i->second.end(); j++)
			if (j->GetPrice() >= A && j->GetPrice() <= B)
			{
				result.AddCategory(i->first);
				result.Add(*j, i->first);
			}

	return result;
}

bool ChemistShop::SaveTo(path p)
{
	if (p.empty())
		return false;

	ofstream writer;

	string str = p.string() + "\\Аптека" + "\\Категории";
	
	path tmp = str;

	if (!create_directories(tmp))
		return false;

	for (auto i = Drugs.begin(); i != Drugs.end(); i++)
	{
		string cat_s = str + "\\" + i->first.GetName(); 
		path tmp = cat_s;

		if (!create_directories(tmp))
			return false;
		
		writer.open(cat_s + "\\" + i->first.GetName() + ".txt");
		if (writer.is_open())
		{
			writer << i->second;
			writer.close();
		}
		else
			return false;
	}

	return true;
}

Medicament& ChemistShop::operator[](string name)
{
	for (auto i = Drugs.begin(); i != Drugs.end(); i++)
		for (auto j = i->second.begin(); j != i->second.end(); j++)
			if (j->GetInfo() == name)
					return *j;

	throw Text_Exception("Такого препарата нет.\n");
}

ChemistShop& ChemistShop::operator=(const ChemistShop& rhs)
{
	if (this != &rhs)
	{
		this->Drugs = rhs.Drugs;
	}
	return *this;
}

void ChemistShop::Show(ostream& os /*= cout*/)
{
	if (!os.good())
		throw Text_Exception("Ошибка потока вывода!");

	if (Drugs.empty())
	{
		os << "Категорий нет.\n";
		return;
	}

	for (auto it = Drugs.begin(); it != Drugs.end(); it++)
		os << it->first << it->second << endl;
}

ostream& operator<< (ostream& os, ChemistShop& shop)
{
	shop.Show(os);
	return os;
}

ostream& operator<< (ostream& os, vector<Medicament> vect)
{
	if (!os.good())
		throw Text_Exception("Ошибка потока вывода!");

	if (vect.empty())
	{
		os << "\tНет препаратов.\n";
		return os;
	}
	for (auto& x : vect)
		os << x;

	return os;
}