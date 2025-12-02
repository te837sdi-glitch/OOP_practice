#pragma once
#include <string>
#include <iostream>
using namespace std;
class Abiturient
{
private:
	int id;
	string name;
	string surname;
	string paternal;
	string adres;
	int phone;
	int year_pass;
	int number_NMT;
	int pin_code;
public:
	Abiturient();
	Abiturient(int _id, const std::string& _name, const std::string& _surname,
		const std::string& _paternal, const std::string& _adres, int _phone,
		int _year_pass, int _number_NMT, int _pin_code);

	Abiturient(const Abiturient& other);

	~Abiturient();

	friend ostream& operator<<(ostream& out, const Abiturient& p);

	friend istream& operator>>(istream& in, Abiturient& p);
};