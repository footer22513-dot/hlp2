
#include "auth.h"
#include "func_module/func.h"
#include "menu/CMenu.h"
#include "menu/CMenuItem.h"
#include "models/product/product.h"
#include "models/supplier/supplier.h"
#include "models/worker/worker.h"
#include <iostream>
#include <string>

using namespace std;
using namespace GNA;

void demo_simple_polymorphism() {
  user *u =
      new worker("Anna", "Ivanova", 25, "anna_i", "securepass", "Manager");
  cout << "\n[user* u = new worker(...)]" << endl;
  u->show_info();
  u->do_work();
  delete u;
}

void demo_complex_polymorphism() {

  user *team[3];
  team[0] = new worker("Pavel", "Nava", 20, "nav", "pass1234", "Programmer");
  team[1] =
      new supplier("Ivan", "Ivanov", 35, "iva", "pass1234", "Electronics");
  team[2] = new worker("Maria", "Sokol", 28, "mar", "pass1234", "Designer");

  for (user *item : team) {
    item->show_info();
    item->do_work();
  }

  for (user *item : team)
    delete item;
}

bool run_auth(AuthSystem &auth) {
  cout << "\n================================================" << endl;
  cout << "  АВТОРИЗАЦИЯ" << endl;
  cout << "================================================" << endl;

  string login, pass, role;
  int attempts = 3;

  while (attempts > 0) {
    cout << "Логин: ";
    cin >> login;
    cout << "Пароль: ";
    cin >> pass;

    if (auth.login(login, pass, role)) {
      cout << "\n[OK] Добро пожаловать! Роль: " << role << endl;
      return true;
    }
    attempts--;
    if (attempts > 0)
      cout << "[!] Неверно. Осталось попыток: " << attempts << endl;
  }

  cout << "[X] Доступ заблокирован." << endl;
  return false;
}

int main() {

  // demo_simple_polymorphism();
  // demo_complex_polymorphism();

  AuthSystem auth("accounts.txt");
  if (!run_auth(auth)) {
    cout << "Выход из программы." << endl;
    return 1;
  }

  const int ITEMS_NUMBER = 5;
  CMenuItem items[ITEMS_NUMBER]{
      CMenuItem{"Показать всех сотрудников", menu_show_all_workers},
      CMenuItem{"Показать всех поставщиков", menu_show_all_suppliers},
      CMenuItem{"Добавить сотрудника", menu_add_worker},
      CMenuItem{"Добавить поставщика", menu_add_supplier},
      CMenuItem{"Демо товара (product)", menu_show_product}};

  CMenu menu("=== СИСТЕМА УПРАВЛЕНИЯ ===", items, ITEMS_NUMBER);
  while (menu.runCommand()) {
  }

  return 0;
}
