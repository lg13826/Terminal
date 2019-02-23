// TODO:
// Create a parent class for file reads (ex: keter, euclid, etc...).
// Make individual classes for each list type. 
// Make a more realistic and secure login.

#include "accounts.h"
#include <deque>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

const int MAX_LENGTH_CREDENTIAL = 50;
const int SCP_MAX = 5000;
const int ENCRYPT_KEY = 4;
const int VERY_SLOW = 1000;
const int SLOW = 60;
const int STANDARD = 30;
const int FAST = 10;

void scp_number_conditions(int scp_Number, string &URL)
{
	if (scp_Number == 0)
	{
		system("cls");
		return;
	}
	if (scp_Number < 10) 
		URL = "http://www.scp-wiki.net/scp-00";
	else if (scp_Number < 100)
		URL = "http://www.scp-wiki.net/scp-0";
	else URL = "http://www.scp-wiki.net/scp-";
}

void slow_type(const string &message, unsigned int time_in_milliseconds)
{
	int count = 0;
	for (const char c : message)
	{
		if (c == '\n')
			count = 0;
		if (count == 76) // limits output to 76 characters
		{
			cout << endl;
			if (c != ' ')
				cout << '-';
			count = 0;
		}
		cout << c << flush;
		this_thread::sleep_for(chrono::milliseconds(time_in_milliseconds));
		count++;
	}
}

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
/*
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
	cout << "ENCRYPTION SUCCESSFUL, PLEASE EXIT THE PROGRAM";
	cin.ignore(9999, '\n');
}
*/
void thaumielList()
{
	ifstream thaumielL("Thaumiel.txt");
	int thaumiel[SCP_MAX];
	int entryNum = decrypt(thaumielL);
	slow_type("\nTHAUMIEL SCPS AS OF 1/31/19\n\n", FAST);
	slow_type("Description: [REDACTED]\n\n", FAST);
	slow_type(to_string(entryNum), STANDARD);
	slow_type(" ENTRIES FOUND.\n\n", STANDARD);
}

void euclidList()
{
	ifstream euclidL("Euclid.txt");
	int euclid[SCP_MAX];
	int entryNum = decrypt(euclidL);
	slow_type("\nEUCLID SCPS AS OF 1/21/19\n\n", FAST);
	slow_type("Description: Euclid-class SCPs are anomalies that require more resources to contain completely or where containment isn't always reliable. Usually this is because the SCP is insufficiently understood or inherently unpredictable. \n\n", FAST);
	slow_type(to_string(entryNum), STANDARD);
	slow_type(" ENTRIES FOUND.\n\n", STANDARD);
}

void safeList()
{
	ifstream safeL("Safe.txt");
	int safe[SCP_MAX];
	int entryNum = decrypt(safeL);
	cout << endl;
	slow_type("SAFE SCPS AS OF 1/21/19\n", STANDARD);
	slow_type("Description: Safe-class SCPs are anomalies that are easily and safely contained. This is often due to the fact that the Foundation has researched the SCP well enough that containment does not require significant resources or that the anomalies require a specific and conscious activation or trigger. Classifying an SCP as Safe, however, does not mean that handling or activating it does not pose a threat.\n\n", FAST);
	slow_type(to_string(entryNum), STANDARD);
	slow_type(" ENTRIES FOUND.\n", STANDARD);
	cout << endl;
}

void keterList()
{
	ifstream keterL("Keter.txt");
	int keter[SCP_MAX];
	int entryNum = decrypt(keterL);
	cout << endl;
	slow_type("KETER SCPS AS OF 1/16/19\n", STANDARD);
	slow_type("Description: Keter-class SCPs are anomalies that are exceedingly difficult to contain consistently or reliably, with containment procedures often being extensive and complex.\n\n", FAST);
	slow_type(to_string(entryNum), STANDARD);
	slow_type(" ENTRIES FOUND.\n", STANDARD);
	cout << endl;
}

void searchscp()
{
	int scp_Number;
	while (true)
	{
		slow_type("'0' TO RETURN TO MENU.\n", STANDARD);
		slow_type("SCP NUMBER: ", STANDARD);		
		cin >> scp_Number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			scp_Number = NULL;
			cerr << "INVALID INPUT" << endl;
			continue;
		}
		if (scp_Number > SCP_MAX || scp_Number < 0)
		{
			cerr << "OUT OF BOUND NUMBER. RANGE: 0 - 5000." << endl;
			continue;
		}
		break;
	}
	string Url;
	scp_number_conditions(scp_Number, Url);
	string scp = to_string(scp_Number);
	Url.append(scp); // add number to URL
	ShellExecute(GetDesktopWindow(), "open", Url.c_str(), NULL, NULL, NULL); // Open Page
	system("cls");
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
	slow_type("ENTER DESIRED USERNAME: ", STANDARD);
	getline(cin, username);
	slow_type("DESIGNATE SECURE PASSWORD: ", STANDARD);
	getline(cin, password);
	username = stoupper(username);
	password = stoupper(password);
	accounts O(username, password);
	O.writeAccountToFile();
}

int login()
{
	ifstream file(ACCOUNT_RECORD);		
	bool found = false;
	while (found == false)
	{
		slow_type("FOUNDATION TERMINAL - V0.2\nENTER CREDENTIALS\nUSERNAME: ", FAST);
		string user;
		getline(cin, user);
		user = stoupper(user);
		if (user == "CREATE.ACCOUNT")
		{
			accountCreation();
			continue;
		}
		if (user == "DELETE.ACCOUNT")
		{
			ofstream file("ACCOUNTS.txt");
			file.clear();
			slow_type("ACCOUNTS FILE CLEARED\n", FAST);
			continue;
		}
		cout << "PASSWORD: ";
		string pass;
		getline(cin, pass);
		pass = stoupper(pass);
		user.append(pass);

		string search;
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
			return 0;
		}
	}
	system("cls");
}

void menu()
{
	int selection;
	do
	{
		slow_type("MENU:\n0. EXIT\n1. SEARCH SCP\n2. RANDOM SCP\n3. KETER LIST\n4. EUCLID LIST\n5. SAFE LIST\n6. THAUMIEL LIST\n7. REDACTED", FAST);
		cout << endl << "OPTION NUMBER: ";	
		cin >> selection;
		system("cls");
		switch (selection)
		{
		case 0: break;
		case 1: searchscp(); break;
		case 2: random(); break;
		case 3: keterList(); searchscp(); break;
		case 4: euclidList(); searchscp(); break;
		case 5: safeList(); searchscp(); break;
		case 6: thaumielList(); searchscp(); break;
		case 7: cout << "REDACTED - O5 ONLY" << endl; break;
		default: cout << "INVALID SELECTION TRY AGAIN." << endl << endl; Sleep(1000);
		}
	} while (selection != 0);
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
	int ret_val = login();
	if (ret_val == 0)
		return ret_val;
	menu();
	return 0;
}
