#include "accounts.h"


accounts::accounts()
{
	username = "EMPTY";
	password = "EMPTY";
}
accounts::~accounts()
{
}

accounts::accounts(std::string username, std::string password)
{
	this->username = username;
	this->password = password;
}

void accounts::writeAccountToFile()
{
	file.open(ACCOUNT_RECORD);
	file << username << password << '\n';
}

void accounts::getUser()
{
	std::cout << username;
}
void accounts::getPass()
{
	std::cout << password;
}