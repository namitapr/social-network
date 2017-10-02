#include "network.h"
#include "user.h"
#include <iomanip>

using namespace std;

//function prototypes
//functions are menu options
void add_user(Network* network1); //option 1
void add_friend(Network* network1); //option 2
void remove_friend(Network* network1); //option 3
void display_users(Network* network1); //option 4
void display_friends(Network* network1); //option 5
void write_to_file(Network* network1); //option 6


int main(int argc, char *argv[])
{
	//creates a Network object
	Network* network1 = new Network();

	//reading User data from text file
	int success0 = network1->read_friends(argv[1]);

	//checks if read_friends ran properly
	if (success0 < 0)
	{
		delete network1;
		return 0;
	}

	//loops through menu of options
	int input;
	do {
		//menu of options
		cout << "Enter the number of the option ";
		cout << "you would like to choose and ";
		cout << "include the necessary information:\n";
		cout << "1. Add User\n";
		cout << "2. Add Friend\n";
		cout << "3. Remove Friend\n";
		cout << "4. Print Users\n";
		cout << "5. List Friends\n";
		cout << "6. Write to File\n";

		//takes in user's input
		cin >> input;

		//add user
		if (input == 1)
		{
			add_user(network1);
		}

		//add friend
		else if (input == 2)
		{
			add_friend(network1);
		}

		//remove friend
		else if (input == 3)
		{
			remove_friend(network1);
		}

		//display users
		else if (input == 4)
		{
			display_users(network1);
		}

		//display friends
		else if (input == 5)
		{
			display_friends(network1);
		}

		//write to file
		else if (input == 6)
		{
			write_to_file(network1);
		}

	}while(input > 0 && input < 7);

	delete network1;
	return 0;
}

void add_user(Network* network1) {

		string firstname;
		string lastname;
		int year;
		int zipcode;

		cin >> firstname;
		cin >> lastname;
		cin >> year;
		cin >> zipcode;

		network1->add_user(firstname + " " 
			+ lastname, year, zipcode);
}

void add_friend(Network* network1) {

			string firstname1;
			string lastname1;
			string firstname2;
			string lastname2;

			cin >> firstname1;
			cin >> lastname1;
			cin >> firstname2;
			cin >> lastname2;

			int success2 = network1->add_connection(firstname1 
				+ " " + lastname1, firstname2 + " " + lastname2);

			//checks if method ran properly
			if (success2 < 0)
			{
				return;
			}
}

void remove_friend(Network* network1) {

			string firstname1;
			string lastname1;
			string firstname2;
			string lastname2;

			cin >> firstname1;
			cin >> lastname1;
			cin >> firstname2;
			cin >> lastname2;

			int success3 = network1->remove_connection(firstname1 
				+ " " + lastname1, firstname2 + " " + lastname2);

			//checks if method ran properly
			if (success3 < 0)
			{
				return;
			}
}

void display_users(Network* network1) {

			//displays table headers
			cout << left << setw(8) << "ID";
			cout << left << setw(18) << "Name";
			cout << left << setw(10) << "Year";
			cout << left << setw(10) << "Zip";
			cout << endl;
			for (int i = 0; i < 50; i++)
			{
				cout << "=";
			}
			cout << endl;

			//displays table values
			for (int i=0; i<network1->get_UsersSize(); i++)
			{
				cout << left << setw(8) << network1->get_UsersID(i);
				cout << left << setw(18) << network1->get_UsersName(i);
				cout << left << setw(10) << network1->get_UsersYear(i);
				cout << left << setw(10) << network1->get_UsersZip(i);
				cout << endl;
			}
}

void display_friends(Network* network1) {

			string firstname, lastname;
			cin >> firstname >> lastname;

			string username = firstname + " " + lastname;
			//cout << "username:" << username << endl;

			//obtains id num of user inputted
			int idNum = network1->get_id(username);

			//checks if method ran properly
			if (idNum < 0)
			{
				return;
			}

			vector<int> tempFriendConnecs = network1->get_UsersFriends(idNum);

			//displays table headers
			cout << left << setw(8) << "ID";
			cout << left << setw(18) << "Name";
			cout << left << setw(10) << "Year";
			cout << left << setw(10) << "Zip";
			cout << endl;

			for (int i = 0; i < 50; i++)
			{
				cout << "=";
			}
			cout << endl;

			//displays table values
			for (int i=0; i<tempFriendConnecs.size(); i++)
			{
				int index = tempFriendConnecs[i];
				cout << left << setw(8) << network1->get_UsersID(index);
				cout << left << setw(18) << network1->get_UsersName(index);
				cout << left << setw(10) << network1->get_UsersYear(index);
				cout << left << setw(10) << network1->get_UsersZip(index);
				cout << endl;
			}
}

void write_to_file(Network* network1) {
				//converting from string to const char*
				string filename;
				cin >> filename;

				char* filenameInput = new char[filename.length()+1];
				filenameInput[filename.length()] = '\0';

				for (int j=0; j < filename.length(); j++)
				{
					filenameInput[j] = filename[j];
				}

			//calling write_friends to write to filenameInput file
			int success6 = network1->write_friends(filenameInput);

			//deallocation
			delete [] filenameInput;

			//checking if write_friends ran properly
			if (success6 < 0)
			{
				return;
			}

}