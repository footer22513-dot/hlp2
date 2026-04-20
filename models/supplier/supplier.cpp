

#include "supplier.h"
#include <iostream>
#include <string>
using namespace std;

supplier::supplier(string fName, string lName, int a, string log, string pass,
                   string p_type)
    : user(fName, lName, a, log, pass), product_type(p_type) {}
supplier::~supplier() {};

// Геттер и сеттер
string supplier::get_product_type() const { return product_type; }

void supplier::set_product_type(string pType) { product_type = pType; }

void supplier::show_info() {
  cout << "\n=== КАРТОЧКА ПОСТАВЩИКА ===" << endl;
  cout << "Имя: " << Get_first_name() << " " << Get_last_name() << endl;
  cout << "Возраст: " << Get_age() << endl;
  cout << "Логин: " << get_login() << endl;
  cout << "ТИП ПРОДУКЦИИ: " << product_type << endl;
  cout << "===========================\n" << endl;
}

void supplier::do_work() { cout << "Supplier is working..." << endl; }


ostream& operator<<(ostream& os, const supplier& sup) {
    os << sup.Get_first_name() << "\n"
       << sup.Get_last_name() << "\n"
       << sup.Get_age() << "\n"
       << sup.get_login() << "\n"
       << sup.get_password() << "\n"
       << sup.product_type << "\n";
    return os;
}



istream& operator>>(istream& is, supplier& sup) {
    string fName, lName, log, pass, pType;
    int age;

    cout << "Имя: ";           is >> fName;
    cout << "Фамилия: ";       is >> lName;
    cout << "Возраст: ";       is >> age;
    cout << "Логин: ";         is >> log;
    cout << "Пароль: ";        is >> pass;
    cout << "Тип продукции: "; is >> pType;

    sup.set_first_name(fName);  // было Set_first_name
    sup.set_last_name(lName);   // было Set_last_name
    sup.set_Age(age);           // было Set_age
    sup.set_login(log);
    sup.set_pass(pass);         // было set_password
    sup.product_type = pType;

    return is;
}