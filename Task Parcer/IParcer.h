#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<string>

class IParcer
{
public:	

	virtual void keySearchTitle(const std::string& key)=0;
	virtual void titleSearch(const std::string& title)=0;
	virtual void keySearch(const std::string& val)=0;
	virtual void valueSearch(const std::string& value) =0;
	virtual void valueSearchKeyTitle(const std::string& key, std::string& title) =0;
	virtual void titleAddKeyVal(const std::string& title) =0;
	virtual void creatingFile(const std::string& faileName) = 0;
	virtual ~IParcer(){}
};

