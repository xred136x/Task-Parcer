#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<string>

class IParcer
{
public:	

	virtual void keySearchTitle(std::string& key)=0;
	virtual void titleSearch(std::string& title)=0;
	virtual void keySearch(std::string& val)=0;
	virtual void valueSearch(std::string& value) =0;
	virtual void valueSearchKeyTitle(std::string& key, std::string& title) =0;
	virtual void titleAddKeyVal(std::string& title) =0;
	virtual void creatingFile(std::string& faileName) = 0;
	virtual ~IParcer(){}
};

