#include<iostream>
#include<fstream>
#include"IParcer.h"
#include"IniParcer.h"





int main() {
	setlocale(LC_ALL, "ru");
	std::string m, n;
	//std::cout << "Введите операцию которую хотите выполнить\n";
	std::cout << "1. В каком заголовке лежит ключ.\n2. Существует ли заголовок X (секция)\n";
	std::cout << "3. Существует ли ключ X в файле.\n4. Существует ли значение X в файле.\n5. Какое значение у ключа X в секции Y.\n";
	std::cout << "6. Обратиться к секции X и присвоить ключу Y значение Z.\n";
	std::cout << "7. Вывести отредактированный(или оставленный как есть).ini файл в новый файл с пользовательским названием.\n";
	IniParcer a;
	int input = 0;
	while (input != 8) {
		std::cout << "Введите операцию которую хотите выполнить\n";
		std::cin >> input;
		switch (input)
		{
		case 1: std::cout << "Введите ключ: "; std::cin >> m; a.keySearchTitle(m); break;
		case 2: std::cout << "Введите заголовок: "; std::cin >> m; a.titleSearch(m); break;
		case 3: std::cout << "Введите ключ: "; std::cin >> m; a.keySearch(m); break;
		case 4: std::cout << "Введите значение: "; std::cin >> m; a.valueSearch(m); break;
		case 5: std::cout << "Введите заголовок и ключ: "; std::cin >> m >> n; a.valueSearchKeyTitle(m, n); break;
		case 6: std::cout << "Введите заголовок: "; std::cin >> m; a.titleAddKeyVal(m); break;
		case 7: std::cout << "Введите название файла: "; std::cin >> m; a.creatingFile(m); break;

		default:break;
		}
	}
	return 0;
}