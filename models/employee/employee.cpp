#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

employee::employee(string fName, string lName, int a, string log, string pass,
                   string emp_role)
    : user(fName, lName, a, log, pass), role(emp_role) {
  if (fName != "") {
    cout << "Сотрудник " << fName << " " << lName
         << " нанят на должность: " << emp_role << endl;
  }
}

employee::~employee() {
  if (Get_first_name() != "") {
    cout << "Сотрудник " << Get_first_name() << " уволен" << endl;
  }
}

string employee::get_role() const { return role; }

void employee::set_role(string emp_role) {
  // Валидация роли
  if (emp_role != "worker" && emp_role != "administrator") {
    cout
        << "Ошибка: некорректная роль. Используйте 'worker' или 'administrator'"
        << endl;
    return;
  }
  role = emp_role;
}

void employee::show_info() {
  cout << "\n=== КАРТОЧКА СОТРУДНИКА ===" << endl;
  cout << "Имя: " << Get_first_name() << " " << Get_last_name() << endl;
  cout << "Возраст: " << Get_age() << endl;
  cout << "Логин: " << get_login() << endl;
  cout << "РОЛЬ: " << role << endl;
  cout << "===========================\n" << endl;
}

void employee::do_work() {
  cout << "🔨 " << Get_first_name() << " работает как \"" << role << "\"..."
       << endl;
}

ostream &operator<<(ostream &os, const employee &sup) {
  os << sup.Get_first_name() << "\n"
     << sup.Get_last_name() << "\n"
     << sup.Get_age() << "\n"
     << sup.get_login() << "\n"
     << sup.get_password() << "\n";
  return os;
}

istream &operator>>(istream &is, employee &sup) {
  string fName, lName, log, pass;
  int age;

  cout << "Имя: ";
  is >> fName;
  cout << "Фамилия: ";
  is >> lName;
  cout << "Возраст: ";
  is >> age;
  cout << "Логин: ";
  is >> log;
  cout << "Пароль: ";
  is >> pass;

  sup.set_first_name(fName);
  sup.set_last_name(lName);
  sup.set_Age(age);
  sup.set_login(log);
  sup.set_pass(pass);

  return is;
}
