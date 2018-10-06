#pragma once

#ifndef MEDICAMENT_H
#define MEDICAMENT_H
class Medicament
{
	string info;
	string company;
	string typeOfpackag;
	double price;

public:

	Medicament();
	Medicament(string, string, string, double);
	Medicament(const Medicament&);
	~Medicament();

	Medicament& SetInfo(string);
	Medicament& SetCompany(string);
	Medicament& SetTypeOfPackag(string);
	Medicament& SetPrice(double);

	string GetInfo() const;
	string GetCompany() const;
	string GetTypeOfPackag() const;
	double GetPrice() const;

	void Show(ostream& os = cout);
	bool operator< (const Medicament&) const;
	bool operator> (const Medicament&) const;

	Medicament& operator= (const Medicament&);
	Medicament& operator= (const string);

	bool operator== (const Medicament&);
	bool operator!= (const Medicament&);

	friend ostream& operator<< (ostream& os, Medicament& med);
	friend istream& operator>> (istream& is, Medicament& med);

};
#endif /* MEDICAMENT_H */
