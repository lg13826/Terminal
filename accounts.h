#pragma once
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <queue>

const std::string ACCOUNT_RECORD = "ACCOUNTS.txt";

class accounts
{
private:
	std::string username;
	std::string password;
	std::ofstream file;
public:
	accounts();
	~accounts();
	accounts(std::string username,std::string password);
	void writeAccountToFile();
	void getUser();
	void getPass();
}; 