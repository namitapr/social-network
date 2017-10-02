#include "user.h"
#include <iostream>

using namespace std;


int main () {

	ID = 1;
	fullName = "Namita Prakash";
	birthYear = 1998;
	zipCode = 92620;


	User nams(ID, fullName, birthYear, zipCode);

	cout << nams.ID << endl << nams.fullName << endl << nams.birthYear << endl << nams.zipCode << endl;



	return 0;
}



#include "network.h"
#include "user.h"

int main(int argc, char *argv[])
{
	//creates a Network object
	//reads User data from a text file
	//command line arg provides filename of file to be read
	//loops through progression of displaying a menu of options, accepting user input, and processing option
	Network network1;


	//menu
	//1. add user
	//2. add friend
	//3. remove friend
	//4. print users
	//5. list friends
	//6. write to file
	//ANY OTHER NUMBER, exit


  return 0;
}


#include "user.h"
#include <iostream>
#include <string>

using namespace std;


int main () {

	int ID = 1;
	string fullName = "Namita Prakash";
	int birthYear = 1998;
	int zipCode = 92620;


	User nams(ID, fullName, birthYear, zipCode);

	cout << nams.get_id() << endl;
	cout << nams.get_name() << endl;
	cout << nams.get_year() << endl;
	cout << nams.get_zipCode() << endl;


	return 0;
}
