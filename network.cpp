#include "network.h"

Network::Network() {
	//no arguments
}

Network::~Network() {
	//memory deallocation
	for (int i=0; i<Users.size(); i++)
	{
		delete Users[i];
	}
}


int Network::read_friends(const char *filename) {
	//initializes all of the network's info from file
	//return 0 on success, -1 on failure
	
	//creates ifstream object using inputted filename
	ifstream infile;
	infile.open(filename);

	//checks if file opens
	if(!infile.is_open()) {
		cout << "Invalid file" << endl;
		return -1;
	}

	//checks if file opens properly
	if (infile.fail()) {
	  cout << "Could not open file" << endl;
	  return -1;
	}

	//temp variables store information to be added to User class
	  	int tempID;
	  	string tempFirstName;
	  	string tempLastName;
	  	int tempYear;
	  	int tempZip;
	  	int tempFriendsID;
	  	vector<int> tempFriends;

	//stringstream used to parse file
		string temp;
	  	getline(infile, temp);
		stringstream user(temp);	
		int numUsers;
		user >> numUsers;

	//loops parse file
	for (int i=0; i<numUsers; i++)
	  {	
	  	for (int k=0; k<5; k++)
		{  	
			getline(infile, temp);
			stringstream ss(temp);

			//clears tempFriends vector after
			//each iteration
			tempFriends.clear();
		  	
		  	if(k==0)
		  	{
		  		ss >> tempID;
		  		//cout << endl << "tempID:" << tempID << endl;
		  	}

		  	if(k==1)
		  	{
		  		ss >> tempFirstName >> tempLastName;
		  		//cout << "tempName:" << tempFirstName 
		  			//<< " " << tempLastName << endl;
		  	}

		  	if(k==2)
		 	{
		 		ss >> tempYear;
		 		//cout << "tempYear:" << tempYear << endl;
		 	}

		 	if(k==3)
		 	{
		  		ss >> tempZip;
		  		//cout << "tempZip:" << tempZip << endl;
		  	}

		  	if (k==4)
		  	{
		  		//cout << "tempFriends:";
		  		while (ss >> tempFriendsID)
			  		{
				  		tempFriends.push_back(tempFriendsID);
				  		//cout << tempFriendsID << " ";
				  	}
				//cout << endl;
		  	}
		}

		//create a user object pointer with all the parsed info
		User* u = new User(tempID, tempFirstName + 
			" " + tempLastName, tempYear, tempZip);

		//adds friend info to new user object
		//cout << "tempFriends in loop:";
		for (int j=0; j<tempFriends.size(); j++)
		{
			//cout << tempFriends[j] << " ";
			u->add_friend(tempFriends[j]);
		}
		//cout << endl;

		//adds user pointer to network vector
		Users.push_back(u);

		//checks if function ran properly
		if (i == numUsers - 1)
		{
			infile.close();
			return 0;
		}

	  }

	  infile.close();
	  cout << "Error reading file" << endl;
	  return -1;
}


int Network::write_friends(const char *filename) {
	//writes all network info to a file
	//return 0 on success, -1 on failure
	
	//cout << "filename:" << filename;

	//creates ofstream object
	ofstream outfile;

	//opens file
	outfile.open(filename);

	//writes numUsers to file
	outfile << Users.size() << endl;

	//writes info for all users to file
	for (int i=0; i<Users.size(); i++)
	{
		//writes each info piece for user to file
		outfile << Users[i]->get_id() << endl;
		outfile << '\t' << Users[i]->get_name() << endl;
		outfile << '\t' << Users[i]->get_year() << endl;
		outfile << '\t' << Users[i]->get_zipCode() << endl;

		//stores user friends in temp vector
		vector<int> tempFriends = Users[i]->get_friends();

		//writes friend info for user to file
		outfile << '\t';
		for (int j=0; j<tempFriends.size(); j++)
		{
			outfile << tempFriends[j];
			if (j < tempFriends.size() - 1)
			{
				outfile << " ";
			}
		}
		outfile << endl;

		//returns 0 if method runs successfully
		if (i == Users.size() - 1)
		{
			outfile.close();
			return 0;
		}
	}

	outfile.close();
	cout << "Error writing to file" << endl;
	return -1;

}

void Network::add_user(std::string username, int yr, 
	int zipcode) {
	//add user to network database
	//create user object with inputted info
	int newID = Users.size();

	User* u= new User(newID, username, yr, zipcode);
	Users.push_back(u);
}

int Network::add_connection(std::string name1, 
	std::string name2) {

	//bools check if both users exist
	bool user1valid = false;
	bool user2valid = false;

	//ints store indexes of users in network
	int user1index;
	int user2index;

	//loops check if both users exist
	for (int i=0; i<Users.size(); i++)
	{
		if (Users[i]->get_name() == name1)
		{
			user1valid = true;
			user1index = i;
		}	
	}

	for (int i=0; i<Users.size(); i++)
	{
		if (Users[i]->get_name() == name2)
		{
			user2valid = true;
			user2index = i;
		}
	}

	//adds ids to each other's friend vectors
	if (user1valid == true && user2valid == true)
	{
		int tempid1 = Users[user1index]->get_id();
		int tempid2 = Users[user2index]->get_id();

		Users[user1index]->add_friend(tempid2);
		Users[user2index]->add_friend(tempid1);

		return 0;
	}

	else
	{
		cout << "Error adding friend" << endl;
		return -1;
	}

}


int Network::remove_connection(std::string name1, 
	std::string name2) {
	
	//bools check if both users exist
	bool user1valid = false;
	bool user2valid = false;

	//ints store indexes of both users in network
	int user1index;
	int user2index;

	//loops check if users exist
	for (int i=0; i<Users.size(); i++)
	{
		User u1 = *Users[i];
		if (u1.get_name() == name1)
		{
			user1valid = true;
			user1index = i;
		}	
	}

	for (int i=0; i<Users.size(); i++)
	{
		User u2 = *Users[i];
		if (u2.get_name() == name2)
		{
			user2valid = true;
			user2index = i;
		}
	}

	//deletes ids from each other's friend vectors
	if(user1valid == true && user2valid == true)
	{
		
		User user1 = *Users[user1index];
		User user2 = *Users[user2index];

		int tempid1 = user1.get_id();
		int tempid2 = user2.get_id();

		Users[user1index]->delete_friend(tempid2);
		Users[user2index]->delete_friend(tempid1);

		return 0;
	}

	else
	{
		cout << "Error deleting friend" << endl;
		return -1;
	}

}

int Network::get_id(std::string username) {
	//return corresponding ID for inputted username
	int id;
	
	for (int i=0; i < Users.size(); i++)
	{
		User u = *Users[i];

		if (u.get_name() == username)
		{
			id = u.get_id();
			return id;
		}

	}

	cout << "Error finding user" << endl;
	return -1;
}

int Network::get_UsersSize() {
	return Users.size();
}

int Network::get_UsersID(int index) {
	return Users[index]->get_id();
}

string Network::get_UsersName(int index) {
	return Users[index]->get_name();
}

int Network::get_UsersYear(int index) {
	return Users[index]->get_year();
}

int Network::get_UsersZip(int index) {
	return Users[index]->get_zipCode();
}

vector<int> Network::get_UsersFriends(int id) {
	User u = *Users[id];
	vector<int> userFriends;
	userFriends.clear();
	userFriends = u.get_friends();
	return userFriends;
}
