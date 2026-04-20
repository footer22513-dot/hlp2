#pragma once
#include <string>
#include <vector>
using namespace std;

namespace GNA {

class AuthSystem {
private:
  struct Account {
    string login;
    string password;
    string role;
  };
  vector<Account> accounts;

  void load_from_file(const string &filename);

public:
  AuthSystem(const string &filename = "accounts.txt");
  bool login(const string &log, const string &pass, string &role_out);
  void add_account(const string &log, const string &pass, const string &role);
};

} // namespace GNA
