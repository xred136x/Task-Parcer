#pragma once
#include"IParcer.h"
class IniParcer : public IParcer
{
public:
	IniParcer(std::string& nameFile);
	void keySearchTitle(std::string& key) override;
	void titleSearch(std::string& title) override;
	void keySearch(std::string& key) override;
	void valueSearch(std::string& value) override;
	void valueSearchKeyTitle(std::string& key, std::string& title) override;
	void titleAddKeyVal(std::string& title) override;
	void creatingFile(std::string& faileName) override;

	~IniParcer(){}
private:
	std::map<std::string, std::map<std::string, std::string>> _myMap;

};

