#include "stdafx.h"
#include "MainApp.h"


MainApp::MainApp()
{
	setCP(1251);
	setOutCP(1251);
	FirstInit();
}

MainApp::MainApp(UINT page)
{
	setCP(page);
	setOutCP(page);
	FirstInit();
}

MainApp::~MainApp()
{}

void MainApp::ShowMenu()
{
	if (!cout.good())
		throw Text_Exception("������ ������ ������!");

	cout << "�������������� ������� �������\n\n";
	cout << "����� ����������: " << pharmacy.size() << endl;
	cout << "\t1: �������� ���� ��������� ����������\n";
	cout << "\t2: �������� ����� ���������\n";
	cout << "\t3: ������� ���������\n";
	cout << "\t4: �������� ��������\n";
	cout << "\t5: ������� ��������\n";
	cout << "\t6: �������� ���������� � ���������\n";
	cout << "\t7: �������\n";
	cout << "\t8: ���������\n";
	cout << "\tESC: �����\n";
}

void MainApp::HandleKey(int key)
{
	switch (key)
	{
	case ONE:
		system("cls");
		cout << pharmacy << endl;
		_getch();
		break;
	case TWO:
		system("cls");
		AddCat();
		_getch();
		break;
	case THREE:
		system("cls");
		DelCat();
		_getch();
		break;
	case FOUR:
		system("cls");
		AddMed();
		_getch();
		break;
	case FIVE:
		system("cls");
		DelMed();
		_getch();
		break;
	case SIX:
		system("cls");
		ChangeInfo();
		_getch();
		break;
	case SEVEN:
		system("cls");
		Filters();
		_getch();
		break;
	case EIGHT:
		system("cls");
		Save();
		_getch();
		break;
	case ESC:
		exit(0);
		break;
	}
}

void MainApp::FirstInit()
{
	pharmacy.AddCategory("�����������");
	pharmacy.AddCategory("�����������");
	pharmacy.AddCategory("���������������");
	pharmacy.AddCategory("���������������");
	pharmacy.AddCategory("����������������");
	pharmacy.AddCategory("��������");
	pharmacy.AddCategory("����������");
	Medicament Penicillin("����������", "APP Pharmaceuticals, LLC", "�������", 50.50);
	pharmacy.Add(Penicillin, "�����������");
	Medicament Morphine("������", "ETHYPHARM", "������� ��� ��������", 240.05);
	pharmacy.Add(Morphine, "�����������");
	Medicament Fluoxetine("����������", "Accel Pharma Inc", "�������", 80.45);
	pharmacy.Add(Fluoxetine, "���������������");
	Medicament Aciclovir("���������", "Heritage Pharmaceuticals Inc.", "��������", 25.15);
	pharmacy.Add(Aciclovir, "���������������");
	Medicament Bifonazole("���������", "��������, ��, ���", "����", 125.85);
	pharmacy.Add(Bifonazole, "����������������");
	Medicament VitaminC("������������ �������", "Natur Produkt Europe B.V.", "��������", 12.05);
	pharmacy.Add(VitaminC, "��������");
	Medicament Nitrazepamum("����������", "���������� ����������� �����.", "��������", 65.18);
	pharmacy.Add(Nitrazepamum, "����������");
}

void MainApp::AddCat()
{
	if (!cin.good())
		throw Text_Exception("������ ������ �����!");

	cout << "2: �������� ����� ���������\n";
	string name;
	cout << "������� ��� ���������: ";
	cin.sync();
	getline(cin, name);

	if (pharmacy.AddCategory(name))
		cout << "��������� ���������.\n";
	else
		cout << "�� ������� �������� ���������.\n";
}

void MainApp::DelCat()
{
	if (!cin.good())
		throw Text_Exception("������ ������ �����!");

	cout << "3: ������� ���������\n";
	string name;
	cout << "������� ��� ���������: ";
	cin.sync();
	getline(cin, name);

	if (pharmacy.DeleteCategory(name))
		cout << "��������� �������.\n";
	else
		cout << "����� ��������� ���.\n";
}

void MainApp::AddMed()
{
	if (!cin.good())
		throw Text_Exception("������ ������ �����!");

	cout << "4: �������� ��������\n";
	Medicament med; 
	string name;
	cout << "������� ��� ���������: ";
	cin.sync();
	getline(cin, name);
	cin >> med;
	if (pharmacy.Add(med, name))
		cout << "�������� �������� � ��������� " << name << endl;
	else
		cout << "����� ��������� ���.\n";
}

void MainApp::DelMed()
{
	if (!cin.good())
		throw Text_Exception("������ ������ �����!");

	cout << "5: ������� ��������\n";
	string name;
	cout << "������� ��� ���������: ";
	cin.sync();
	getline(cin, name);
	if (pharmacy.Delete(name))
		cout << "�������� " << name << " ������.\n";
	else
		cout << "������ ��������� ���.\n";
}

void MainApp::ChangeInfo()
{
	if (!cin.good())
		throw Text_Exception("������ ������ �����!");

	cout << "6: �������� ���������� � ���������\n";
	string name;
	Medicament med;
	cin.sync();
	cout << "������� ��� ���������: ";
	getline(cin, name);

	try
	{
		cout << "�������� ������:\n" << pharmacy[name];
		cin >> med;
		pharmacy[name] = med;
		cout << "���������� ��������." << endl;
	}
	catch (const Text_Exception& err)
	{
		cout << err.what();
	}
}

void MainApp::Filters()
{
	if (!cin.good())
		throw Text_Exception("������ ������ �����!");

	cout << "7: �������\n";
	cout << "1: �� ������ ����� �������� ���������\n";
	cout << "2: �� ���������\n";
	cout << "3: �� �������������\n";
	cout << "4: �� �������� ���������\n";

	int N;
	double A, B;
	string name;

	while (!(cin >> N))
	{
		cout << "��� �� �����.\n";
		cin.clear();
		cin.ignore();
	}

	if (N == 1)
	{
		cout << "������� ������ ����� �������� ���������: ";
		cin.sync();
		getline(cin, name);

		cout << pharmacy.FindByLetter(name[0]);
	}
	else if (N == 2)
	{
		cout << "������� ��� ���������: ";
		cin.sync();
		getline(cin, name);

		cout << pharmacy.FindByCategory(name);
	}
	else if (N == 3)
	{
		cout << "������� ��� �������������: ";
		cin.sync();
		getline(cin, name);

		cout << pharmacy.FindByCompany(name);
	}
	else if (N == 4)
	{
		cout << "������� �������� ���: ";
		cout << "�� ";
		while (!(cin >> A))
		{
			cout << "��� �� �����.\n";
			cin.clear();
			cin.ignore();
		}
		cout << "�� ";
		while (!(cin >> B))
		{
			cout << "��� �� �����.\n";
			cin.clear();
			cin.ignore();
		}

		cout << pharmacy.FindByPrice(A, B);
	}
}

void MainApp::Save()
{
	if (!cin.good())
		throw Text_Exception("������ ������ �����!");

	string p_str; 
	char ch;
	path root;
	do 
	{
		cin.sync();
		cout << "������� ���� � ����� ��� ����������: ";
		getline(cin, p_str);
		root = p_str;
	} while (!root.is_complete());

	if (!exists(root))
	{
		cout << "���� " << root << " �� ����������.\n"; 
		cout << "������� ���� " << root << " ? [y/n]\n";
		do
		{
			cin >> ch;
		} while (!cin.fail() && ch != 'y' && ch != 'n');
		
		if (ch == 'y')
		{
			if (!create_directories(root))
			{
				cout << "�� ������� ������� ���� " << root << " !\n";
				return;
			}
			else
				cout << "���� " << root << " ������.\n";
		}
		else
			return;
	}

	if (!pharmacy.SaveTo(root))
		cout << "�� ������� ��������� � " << root << " !\n";
	else
		cout << "��������� � " << root << " .\n";
}

void MainApp::begin()
{
	while (true)
	{
		system("cls");
		this->ShowMenu();

		int ch = _getch();

		if (ch == 0 || ch == 224)
			ch = _getch();

		this->HandleKey(ch);
	}
}

void MainApp::setCP(UINT page)
{
	SetConsoleCP(page);
}

void MainApp::setOutCP(UINT page)
{
	SetConsoleOutputCP(page);
}