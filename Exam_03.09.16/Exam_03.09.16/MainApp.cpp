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
		throw Text_Exception("Ошибка потока вывода!");

	cout << "Индивидуальное задание «Аптека»\n\n";
	cout << "Всего препаратов: " << pharmacy.size() << endl;
	cout << "\t1: Просмотр всех имеющихся препаратов\n";
	cout << "\t2: Добавить новую категорию\n";
	cout << "\t3: Удалить категорию\n";
	cout << "\t4: Добавить препарат\n";
	cout << "\t5: Удалить препарат\n";
	cout << "\t6: Изменить информацию о препарате\n";
	cout << "\t7: Фильтры\n";
	cout << "\t8: Сохранить\n";
	cout << "\tESC: выход\n";
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
	pharmacy.AddCategory("антибиотики");
	pharmacy.AddCategory("анальгетики");
	pharmacy.AddCategory("антидепрессанты");
	pharmacy.AddCategory("противовирусные");
	pharmacy.AddCategory("противогрибковые");
	pharmacy.AddCategory("витамины");
	pharmacy.AddCategory("снотворное");
	Medicament Penicillin("Пенициллин", "APP Pharmaceuticals, LLC", "порошок", 50.50);
	pharmacy.Add(Penicillin, "антибиотики");
	Medicament Morphine("Морфин", "ETHYPHARM", "раствор для инъекций", 240.05);
	pharmacy.Add(Morphine, "анальгетики");
	Medicament Fluoxetine("Флуоксетин", "Accel Pharma Inc", "капсулы", 80.45);
	pharmacy.Add(Fluoxetine, "антидепрессанты");
	Medicament Aciclovir("Ацикловир", "Heritage Pharmaceuticals Inc.", "таблетки", 25.15);
	pharmacy.Add(Aciclovir, "противовирусные");
	Medicament Bifonazole("Бифоназол", "Здоровье, ФК, ООО", "крем", 125.85);
	pharmacy.Add(Bifonazole, "противогрибковые");
	Medicament VitaminC("Аскорбиновая кислота", "Natur Produkt Europe B.V.", "таблетки", 12.05);
	pharmacy.Add(VitaminC, "витамины");
	Medicament Nitrazepamum("Нитразепам", "Московский эндокринный завод.", "таблетки", 65.18);
	pharmacy.Add(Nitrazepamum, "снотворное");
}

void MainApp::AddCat()
{
	if (!cin.good())
		throw Text_Exception("Ошибка потока ввода!");

	cout << "2: Добавить новую категорию\n";
	string name;
	cout << "Введите имя категории: ";
	cin.sync();
	getline(cin, name);

	if (pharmacy.AddCategory(name))
		cout << "Категория добавлена.\n";
	else
		cout << "Не удалось добавить категорию.\n";
}

void MainApp::DelCat()
{
	if (!cin.good())
		throw Text_Exception("Ошибка потока ввода!");

	cout << "3: Удалить категорию\n";
	string name;
	cout << "Введите имя категории: ";
	cin.sync();
	getline(cin, name);

	if (pharmacy.DeleteCategory(name))
		cout << "Категория удалена.\n";
	else
		cout << "Такой категории нет.\n";
}

void MainApp::AddMed()
{
	if (!cin.good())
		throw Text_Exception("Ошибка потока ввода!");

	cout << "4: Добавить препарат\n";
	Medicament med; 
	string name;
	cout << "Введите имя категории: ";
	cin.sync();
	getline(cin, name);
	cin >> med;
	if (pharmacy.Add(med, name))
		cout << "Препарат добавлен в категорию " << name << endl;
	else
		cout << "Такой категории нет.\n";
}

void MainApp::DelMed()
{
	if (!cin.good())
		throw Text_Exception("Ошибка потока ввода!");

	cout << "5: Удалить препарат\n";
	string name;
	cout << "Введите имя препарата: ";
	cin.sync();
	getline(cin, name);
	if (pharmacy.Delete(name))
		cout << "Препарат " << name << " удален.\n";
	else
		cout << "Такого препарата нет.\n";
}

void MainApp::ChangeInfo()
{
	if (!cin.good())
		throw Text_Exception("Ошибка потока ввода!");

	cout << "6: Изменить информацию о препарате\n";
	string name;
	Medicament med;
	cin.sync();
	cout << "Введите имя препарата: ";
	getline(cin, name);

	try
	{
		cout << "Препарат найден:\n" << pharmacy[name];
		cin >> med;
		pharmacy[name] = med;
		cout << "Информация изменена." << endl;
	}
	catch (const Text_Exception& err)
	{
		cout << err.what();
	}
}

void MainApp::Filters()
{
	if (!cin.good())
		throw Text_Exception("Ошибка потока ввода!");

	cout << "7: Фильтры\n";
	cout << "1: По первой букве названия препарата\n";
	cout << "2: По категории\n";
	cout << "3: По производителю\n";
	cout << "4: По ценовому диапазону\n";

	int N;
	double A, B;
	string name;

	while (!(cin >> N))
	{
		cout << "Это не число.\n";
		cin.clear();
		cin.ignore();
	}

	if (N == 1)
	{
		cout << "Введите первую букву названия препарата: ";
		cin.sync();
		getline(cin, name);

		cout << pharmacy.FindByLetter(name[0]);
	}
	else if (N == 2)
	{
		cout << "Введите имя категории: ";
		cin.sync();
		getline(cin, name);

		cout << pharmacy.FindByCategory(name);
	}
	else if (N == 3)
	{
		cout << "Введите имя производителя: ";
		cin.sync();
		getline(cin, name);

		cout << pharmacy.FindByCompany(name);
	}
	else if (N == 4)
	{
		cout << "Введите диапазон цен: ";
		cout << "От ";
		while (!(cin >> A))
		{
			cout << "Это не число.\n";
			cin.clear();
			cin.ignore();
		}
		cout << "до ";
		while (!(cin >> B))
		{
			cout << "Это не число.\n";
			cin.clear();
			cin.ignore();
		}

		cout << pharmacy.FindByPrice(A, B);
	}
}

void MainApp::Save()
{
	if (!cin.good())
		throw Text_Exception("Ошибка потока ввода!");

	string p_str; 
	char ch;
	path root;
	do 
	{
		cin.sync();
		cout << "Введите путь к папке для сохранения: ";
		getline(cin, p_str);
		root = p_str;
	} while (!root.is_complete());

	if (!exists(root))
	{
		cout << "Путь " << root << " не существует.\n"; 
		cout << "Создать путь " << root << " ? [y/n]\n";
		do
		{
			cin >> ch;
		} while (!cin.fail() && ch != 'y' && ch != 'n');
		
		if (ch == 'y')
		{
			if (!create_directories(root))
			{
				cout << "Не удалось создать путь " << root << " !\n";
				return;
			}
			else
				cout << "Путь " << root << " создан.\n";
		}
		else
			return;
	}

	if (!pharmacy.SaveTo(root))
		cout << "Не удалось сохранить в " << root << " !\n";
	else
		cout << "Сохранено в " << root << " .\n";
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