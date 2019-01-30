#include "accounts.h"
#include <deque>
using namespace std;

const int MAX_LENGTH_CREDENTIAL = 50;
const int SCP_MAX = 5000;
const int ENCRYPT_KEY = 4;

string stoupper(string x)
{
	for (int i = 0; i < x.length(); ++i)
		x[i] = toupper(x[i]);
	return x;
}

int decrypt(ifstream &aFile)
{
	string aLine;
	int numberOfEntries = 0;
	while (aFile.eof() == false)
	{
		getline(aFile, aLine);
		if (aLine == "")
			continue;
		for (int i = 0; i < size(aLine) - 1; i++)
		{
			aLine[i] -= ENCRYPT_KEY;
		}
		numberOfEntries++;
		cout << aLine << endl;
	}
	return numberOfEntries;
}

void encrypt(ifstream &aFile, string nameOfFile)
{
	deque<string> line;
	string aLine;
	while (aFile.eof() == false)
	{
		getline(aFile, aLine);
		if (aLine == "")
		{
			continue;
		}
		for (int i = 0; i < size(aLine) - 1; i++)
			aLine[i] += ENCRYPT_KEY;
		line.push_back(aLine);
	}
	aFile.close();
	ofstream outFile(nameOfFile);
	while (line.empty() == false)
	{
		aLine = line.front();
		outFile << aLine << endl;
		line.pop_front();
	}
}

void euclidList()
{
	ifstream euclidL("Euclid.txt");
	int euclid[SCP_MAX];
	int entryNum = decrypt(euclidL);
	cout << endl;
	cout << "EUCLID SCP'S AS OF 1/21/19" << endl;
	cout << entryNum << " ENTRIES FOUND. " << endl;
	cout << endl;
}

void safeList()
{
	ifstream safeL("Safe.txt");
	int safe[SCP_MAX];
	int entryNum = decrypt(safeL);
	cout << endl;
	cout << "SAFE SCP'S AS OF 1/21/19" << endl;
	cout << "*REMINDER TO ALL PERSONNEL, DESIGNATIONS ONLY REFER TO DIFFICULTY OF CONTAINMENT, ";
	cout << "CERTAIN OBJECTS CLASSIFIED AS SAFE ARE STILL CAPABLE OF CAUSING [REDACTED]";
	cout << "IF NOT HANDLED ACCORDING TO SPECIAL CONTAINMENT PROCEDURES." << endl;
	cout << entryNum << " ENTRIES FOUND. " << endl;
	cout << "'0' TO RETURN TO MENU." << endl;
	cout << endl;
}

void keterList()
{
	ifstream keterL("Keter.txt");
	int keter[SCP_MAX];
	int entryNum = decrypt(keterL);
	cout << endl;
	cout << "KETER SCP'S AS OF 1/16/19" << endl;
	cout << entryNum << " ENTRIES FOUND. " << endl;
	cout << endl;

}

void searchscp()
{
	int scp_Number;

	while (true)
	{
		cout << "SCP-NUMBER: ";
		
		cin >> scp_Number;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cerr << "INVALID INPUT" << endl;
		}
		else break;
	}
	if (scp_Number == 0)
		return;
	string scp = to_string(scp_Number);
	system("cls");

	string URL = "http://www.scp-wiki.net/scp-";
	URL.append(scp); // add number to URL
	ShellExecute(GetDesktopWindow(), "open", URL.c_str(), NULL, NULL, NULL); // Open Page

}

void random()
{
	srand(time(NULL)); // Random Seed

	unsigned int random = rand() % SCP_MAX; // Generate Random Number from Seed
	string s_random = to_string(random); // Convert Random Int into string equivalent

	string URL = "http://www.scp-wiki.net/scp-";
	URL.append(s_random); // add number to URL
	ShellExecute(GetDesktopWindow(), "open", URL.c_str(), NULL, NULL, NULL); // Open Page
}

void accountCreation()
{
	system("cls");
	string username;
	string password;
	cout << "ENTER DESIRED USERNAME: ";
	getline(cin, username);
	cout << "DESIGNATE SECURE PASSWORD: ";
	getline(cin, password);
	username = stoupper(username);
	password = stoupper(password);
	accounts O(username, password);
	O.writeAccountToFile();
}

void initialize()
{
	ifstream file(ACCOUNT_RECORD);
	if (file.fail())
	{
		file.close();
		ofstream file(ACCOUNT_RECORD);
		accounts T("GUEST", "TEMPORARY");
		T.writeAccountToFile();
		cout << "- ACCOUNT GENERATED - " << endl;

		cout << "GUEST USER: ";
		T.getUser();
		cout << endl;
		cout << "GUEST PASS: ";
		T.getPass();
		cout << endl;

		cout << "YOU WILL NEED THE USERNAME AND PASSWORD PROVIDED" << endl;
		cout << "PLEASE CREATE AN ACCOUNT AS SOON AS POSSIBLE TO AVOID INFORMATION LEAK" << endl;
		cout << "CREATION WILL RESULT IN DELETION OF GUEST PROFILE" << endl;
		cout << "UPON CREATION ONLY ORIGINAL ACCOUNT WILL BE ABLE TO ACCESS FILES." << endl;
		cout << "TYPE 'CREATE.ACCOUNT' IN USERNAME AREA TO CREATE A NEW ACCOUNT." << endl;

		cin.ignore();
		system("cls");
	}
}

int main(void)
{
	initialize();

	ifstream file(ACCOUNT_RECORD);

	cout << "FOUNDATION TERMINAL - V0.2" << endl;
	cout << "ENTER CREDENTIALS" << endl;
	cout << "USERNAME: ";
	string user;
	getline(cin, user);
	user = stoupper(user);
	if (user == "CREATE.ACCOUNT")
	{
		accountCreation();
		cout << "EXIT PROGRAM TO RE-ENTER CREDENTIALS" << endl;
		system("pause");
		return 0;
	}
	if (user == "DELETE.ACCOUNT")
	{
		ofstream file("ACCOUNTS.txt");
		file.clear();
		return 0;
	}
	cout << "PASSWORD: ";
	string pass;
	getline(cin, pass);
	pass = stoupper(pass);
	user.append(pass);

	string search;
	bool found = false;
	do
	{
		getline(file, search);
		if (user == search)
		{
			found = true;
			break;
		}
	} while (file.eof() == false);
	if (file.eof())
	{
		system("cls");
		cout << "INVALID CREDENTIALS." << endl;
		cout << "PROGRAM TERMINATION IN 5 SECONDS...";
		Sleep(5000);
		return 1;
	}
	system("cls");
	int selection;
	while (true)
	{
		cout << "MENU:" << endl;
		cout << "0. EXIT" << endl;
		cout << "1. SEARCH SCP" << endl;
		cout << "2. RANDOM SCP" << endl;
		cout << "3. KETER LIST" << endl;
		cout << "4. EUCLID LIST" << endl;
		cout << "5. SAFE LIST" << endl;
		cout << "6. APOLLYON LIST" << endl;
		cout << "7. REDACTED" << endl;
		cout << endl << "OPTION NUMBER: ";
		cin >> selection;
		system("cls");
		switch (selection)
		{
		case 0: return 0;
		case 1: searchscp(); break;
		case 2: random(); break;
		case 3: keterList(); searchscp(); break;
		case 4: euclidList(); searchscp(); break;
		case 5: safeList(); searchscp(); break;
		case 6: cout << "- APOLLYON CLASSIFIED -" << endl; break;
		case 7: cout << "REDACTED - O5 ONLY" << endl; break;
		default: cout << "INVALID SELECTION TRY AGAIN." << endl << endl; Sleep(1000);
		}
	}


	return 0;
}