//�������������� ������� ������� 
//� ������ ������������ ������� ������������� ����������.
//������������ �������� ���� ����� ������������� ���������� � ������������ � ����������(������ ��������� � ��������� �����).
//����������: 
//�������� ���� ��������� ����������  
//�������� ����� ��������� 
//������� ��������� 
//�������� ��������
//������� ��������  
//�������� ���������� � ��������� 
//������� : 
//�� ������ ����� �������� ��������� 
//�� ��������� 
//�� ������������� 
//�� �������� ���������


#include "stdafx.h"
#include "MainApp.h"

int main(int argc, char* argv[]) try
{
	MainApp app;

	app.begin();
	
	return EXIT_SUCCESS;
}
catch (const out_of_range& oor)
{
	cerr << "����� �� ������� ���������: " << oor.what() << endl;
}
catch (const filesystem_error& code)
{
	cerr << "������ �������� �������: " << code.what() << endl;
}
catch (const Text_Exception& err)
{
	cerr << "������! " << err.what() << endl;
}
catch (...)
{
	cerr << "������!\n";
}