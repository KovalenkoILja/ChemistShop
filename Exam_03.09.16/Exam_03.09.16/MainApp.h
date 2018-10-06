#pragma once
#include "ChemistShop.h"

#ifndef MAINAPP_H
#define MAINAPP_H
class MainApp
{
	ChemistShop pharmacy;

	void ShowMenu();
	void HandleKey(int);
	void FirstInit();
	void AddCat();
	void DelCat();
	void AddMed();
	void DelMed();
	void ChangeInfo(); 
	void Filters();
	void Save();

	enum Keys
	{
		ONE = 0x31,
		TWO = 0x32,
		THREE = 0x33,
		FOUR = 0x34,
		FIVE = 0x35,
		SIX = 0x36,
		SEVEN = 0x37,
		EIGHT = 0x38,
		NINE = 0x39,
		ESC = VK_ESCAPE
	};
	
public:

	MainApp(); 
	MainApp(UINT);
	~MainApp();	

	void begin();

	void setCP(UINT);
	void setOutCP(UINT);

};
#endif /* MAINAPP_H */