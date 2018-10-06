#pragma once

#ifndef CATEGORY_H
#define CATEGORY_H
class Category
{

	string name;

public:

	Category();
	Category(string);
	Category(const Category&);
	~Category();

	void SetName(string);

	string GetName() const;

	void Show(ostream& os = cout);

	Category& operator= (const Category&);

	bool operator< (const Category&) const;
	bool operator> (const Category&) const;

	bool operator== (const Category&);
	bool operator!= (const Category&);

	friend ostream& operator<< (ostream& os, const Category& cat);
	friend istream& operator>> (istream& is, Category& cat);

};
#endif /* CATEGORY_H */
