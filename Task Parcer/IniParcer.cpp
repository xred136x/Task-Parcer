#include "IniParcer.h"

IniParcer::IniParcer(std::string& nameFile)
{
	std::ifstream in;
	in.open(nameFile);
	if (in.is_open()) {
		int cnt = 0;
		int cnt2 = 0;
		std::string str, heading, key, value;
		std::map<std::string, std::map<std::string, std::string>> myMap;
		while (!in.eof()) {
			std::getline(in, str);
			if (str[0] == '[') {
				if (cnt == 0 && cnt2 != 0) {
					myMap[heading];
					cnt2 = 0;
				}
				heading = str.substr(1, str.find(']') - 1);
				cnt2++;
			}
			else if (str[0] != ';' && str[0] != '#') {
				key = str.substr(0, str.find('='));
				std::string value1;
				value1 = str.substr(str.find('=') + 1, str.find(';') - str.find('=') - 1);
				value = value1.substr(0, value1.find('#'));
				cnt++;
			}
			if (cnt > 0) {
				myMap[heading][key] = value;
				cnt = 0;
			}
		}
		_myMap = myMap;
	}
	
	else
		std::cout << "File opening error\n";

	in.close();
}

void IniParcer::keySearchTitle(std::string& key)
{
	int cnt = 0;
	for (auto it = _myMap.begin(); it != _myMap.end(); it++) {
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			if (it2->first == key) {
				std::cout << it->first << '\n';
				cnt++;
			}
		}
	}
	if (cnt == 0)
		std::cout << "Заголовка с таким ключом нет\n";
}

void IniParcer::titleSearch(std::string& title)
{
	int cnt = 0;
	for (auto it = _myMap.begin(); it != _myMap.end(); it++) {
		if (it->first == title) {
			std::cout << "Такой заголовок существует" << '\n';
			cnt++;
			break;
		}
	}
	if (cnt == 0)
		std::cout << "Такого заголовка нет\n";
}
		
void IniParcer::keySearch(std::string& key)
{
	int cnt = 0;
	for (auto it = _myMap.begin(); it != _myMap.end(); it++) {
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			if (it2->first == key) {
				cnt++;
				break;
			}			
		}
	}
	if (cnt == 0)
		std::cout << "Такого ключа нет\n";
	else
		std::cout << "Такой ключ существует" << '\n';
}

void IniParcer::valueSearch(std::string& value)
{
	int cnt = 0;
	for (auto it = _myMap.begin(); it != _myMap.end(); it++) {
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			if (it2->second == value) {
				cnt++;
				break;
			}
		}
	}
	if (cnt > 0)
		std::cout << "Значение существует в файле\n";
	else
		std::cout << "Значение отсутствует в файле\n";
}

void IniParcer::valueSearchKeyTitle(std::string& title, std::string& key)
{
	int cnt2 = 0;
	int cnt = 0;
	for (auto it = _myMap.begin(); it != _myMap.end(); it++) {
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			if (it->first == title && it2->first == key) {
				std::cout << it2->second << '\n';
				cnt++;
			}			
		}
		if (it->first == title && cnt == 0) {
			std::cout << "В заголовке такого ключа нет " << '\n';
			cnt2++;
		}
	}
	if(cnt == 0 && cnt2 == 0)
		std::cout << "Нет такого заголовка и ключа " << '\n';
}

void IniParcer::titleAddKeyVal(std::string& title)
{
	std::cout << "Введите ключ и значение которые хотите присвоить\n";
	std::string a, b;
	std::cin >> a >> b;
	for (auto it = _myMap.begin(); it != _myMap.end(); it++) {
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			if (it->first == title) {
				_myMap[title][a] = b;				
			}
		}
	}
}

void IniParcer::creatingFile(std::string& faileName)
{
	std::ofstream out;
	out.open(faileName,std:: ios::out);
	if (out.is_open()) {
		for (auto it = _myMap.begin(); it != _myMap.end();it++) {
			out << '[' << it->first << ']' << '\n';

			for (auto it2 = it->second.begin(); it2 != it->second.end();it2++) {
				if (it2->first != "")
				out << it2->first << " = " << it2->second << '\n';	
			}
		}
	}
	out.close();
}
