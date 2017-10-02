#include "user.h"
#include <fstream>
#include <sstream>

using namespace std;

#ifndef NETWORK_H
#define NETWORK_H

class Network {
 public:
  Network();
  ~Network();
  int read_friends(const char *filename);
  int write_friends(const char *filename);
  void add_user(std::string username, int yr, int zipcode);
  int add_connection(std::string name1, std::string name2);
  int remove_connection(std::string name1, std::string name2);
  int get_id(std::string username);
  //accessor functions created for drawing out the table
  int get_UsersSize();
  int get_UsersID(int index);
  string get_UsersName(int index);
  int get_UsersYear(int index);
  int get_UsersZip(int index);
  vector<int> get_UsersFriends(int id);


 private:
 	vector<User*> Users;  
};


#endif
