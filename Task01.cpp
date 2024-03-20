#include <iostream>
#include <string>

using namespace std;

class BankAccount {
public:
	string name;
	int balance;
	string getInfo() {
		string s = "Name: " + name + " Balance: " + to_string(balance);
		return s;
	}
	void withdraw(int money) {
		if (!(money < 0 || money > balance)) {
			balance -= money;
		}
	}
};

string get_best_acc_name(BankAccount* accounts, int size) {
	BankAccount max = accounts[0];
	for (int i = 0; i < size; i++) {
		if (max.balance < accounts[i].balance) {
			max = accounts[i];
		}
	}
	return max.name;
}

int main() {
	const int size = 2;
	BankAccount accounts[size];
	accounts[0].name = "12345678";
	accounts[0].balance = 1000;

	accounts[1].name = "23456780";
	accounts[1].balance = 5000;
	accounts[1].withdraw(1000);
	
	for (int i = 0; i < size; i++) {
		cout << accounts[i].getInfo() << "\n";
	}
	cout << "Max:\n" << get_best_acc_name(accounts, size);

	return 0;
}