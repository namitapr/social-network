#include "user.h"

User::User(int ID, string name, int year, int zip) {
	//initializing each private variable that makes
	//up a user class to the inputted parameters
		id = ID;
		fullName = name;
		birthYear = year;
	 	zipCode = zip;
}

User::~User() {

	//destructor... empty

}
 
void User::add_friend(int friendID) {
	//accepts ID of user to add as a friend
	//if user is already a friend, does nothing

	//bool to check if user is already a friend	
	bool friendAlready = false;

	//loop checks if user is already a friend
	for (int i=0; i < friendConnections.size(); i++)
	{
		if (friendConnections[i] == friendID)
		{
			friendAlready = true;
		}
	}

	//adds user to friend vector
	if (!friendAlready)
	{
		friendConnections.push_back(friendID);
	}
}


void User::delete_friend(int friendID) {
	//removes ID and all follows friend ID's are moved up one slot
	//if friend ID is NOT in the list of friends, does nothing
	for (int i=0; i<friendConnections.size(); i++)
	{
		if (friendConnections[i] == friendID)
		{
			friendConnections.erase(friendConnections.begin()+i);
		}
	}
}
 	
//individual accessor methods
int User::get_id() {
	return id;
}

string User::get_name() {
	return fullName;
}

int User::get_year() {
	return birthYear;
}

int User::get_zipCode() {
	return zipCode;
}

vector<int> User::get_friends() {
	return friendConnections;
}