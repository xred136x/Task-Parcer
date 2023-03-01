#pragma once
#include"IParcer.h"
class IniParcer : public IParcer
{
public:
	IniParcer(std::string& nameFile);
	void keySearchTitle(const std::string& key) override;
	void titleSearch(const std::string& title) override;
	void keySearch(const std::string& key) override;
	void valueSearch(const std::string& value) override;
	void valueSearchKeyTitle(const std::string& key, std::string& title) override;
	void titleAddKeyVal(const std::string& title) override;
	void creatingFile(const std::string& faileName) override;

	~IniParcer(){}
private:
	std::map<std::string, std::map<std::string, std::string>> _myMap;

};

