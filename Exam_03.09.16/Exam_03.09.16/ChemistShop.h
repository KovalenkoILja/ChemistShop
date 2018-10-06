#pragma once
#include "Category.h"
#include "Medicament.h"

#ifndef CHEMIST_SHOP_H
#define CHEMIST_SHOP_H
class ChemistShop
{

	map<Category, vector<Medicament>> Drugs;
	
public:
	
	ChemistShop(); 
	ChemistShop(const ChemistShop&);
	~ChemistShop();

	size_t size();

	bool AddCategory(Category);
	bool AddCategory(string);
	bool DeleteCategory(Category);
	bool DeleteCategory(string);

	bool Add(Medicament, string);
	bool Add(Medicament, Category);
	bool Delete(Medicament);
	bool Delete(string);

	ChemistShop FindByLetter(char);
	ChemistShop FindByCategory(string);
	ChemistShop FindByCompany(string);
	ChemistShop FindByPrice(double, double);

	bool SaveTo(path);

	Medicament& operator[](string);

	ChemistShop& operator= (const ChemistShop&);

	void Show(ostream& os = cout);

	friend ostream& operator<< (ostream& os, ChemistShop& shop);
	friend ostream& operator<< (ostream& os, vector<Medicament> vect);

};
#endif /* CHEMIST_SHOP_H */