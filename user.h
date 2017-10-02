#include <string>
#include <vector>
#include <iostream>

using namespace std;


#ifndef USER_H
#define USER_H

class User {
 public:
 	User(int ID, string name, int year, int zip); //constructor
 	~User(); //destructor
 	void add_friend(int friendID);
 	void delete_friend(int friendID);
 	//individual accessor methods
 	int get_id();
 	string get_name();
 	int get_year();
 	int get_zipCode();
 	vector<int> get_friends();

 private:
 	int id;
 	string fullName;
 	int birthYear;
 	int zipCode;
 	vector<int> friendConnections; //each entry is integer ID of friend

};


#endif
