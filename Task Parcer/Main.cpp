#include<iostream>
#include<fstream>
#include"IParcer.h"
#include"IniParcer.h"





int main(int argc, char** argv) {
	setlocale(LC_ALL, "ru");
	/*if (argc > 1) {
		std::string fileName(argv[1]);
		std::ifstream in(fileName);*/

		std::string m, n, fileName ;

		std::cout << "1. � ����� ��������� ����� ����.\n2. ���������� �� ��������� X (������)\n";
		std::cout << "3. ���������� �� ���� X � �����.\n4. ���������� �� �������� X � �����.\n5. ����� �������� � ����� X � ������ Y.\n";
		std::cout << "6. ���������� � ������ X � ��������� ����� Y �������� Z.\n";
		std::cout << "7. ������� �����������������(��� ����������� ��� ����).ini ���� � ����� ���� � ���������������� ���������.\n";

		std::cout << "������� ��� ����� ��� ����������: ";
		std::cin >> fileName;

		std::shared_ptr<IParcer> a = std::make_shared<IniParcer>(fileName);

		int input = 0;
		while (input != 8) {
			std::cout << "������� �������� ������� ������ ���������\n";
			std::cin >> input;
			switch (input)
			{
			case 1: std::cout << "������� ����: "; std::cin >> m; a->keySearchTitle(m); break;
			case 2: std::cout << "������� ���������: "; std::cin >> m; a->titleSearch(m); break;
			case 3: std::cout << "������� ����: "; std::cin >> m; a->keySearch(m); break;
			case 4: std::cout << "������� ��������: "; std::cin >> m; a->valueSearch(m); break;
			case 5: std::cout << "������� ��������� � ����: "; std::cin >> m >> n; a->valueSearchKeyTitle(m, n); break;
			case 6: std::cout << "������� ���������: "; std::cin >> m; a->titleAddKeyVal(m); break;
			case 7: std::cout << "������� �������� ����� � ������� (File.txt): "; std::cin >> m; a->creatingFile(m); break;

			default:break;
			}
		}
	
	return 0;
}