#include "Header.h" // Включаємо ваш файл заголовка
#include <iostream>

// Конструктор за замовчуванням
Abiturient::Abiturient() :
	id(0),
	name("N/A"),
	surname("N/A"),
	paternal("N/A"),
	adres("N/A"),
	phone(0),
	year_pass(0),
	number_NMT(0),
	pin_code(0)
{
}

// Конструктор з параметрами
Abiturient::Abiturient(int _id, const std::string& _name, const std::string& _surname,
	const std::string& _paternal, const std::string& _adres, int _phone,
	int _year_pass, int _number_NMT, int _pin_code) :
	id(_id),
	name(_name),
	surname(_surname),
	paternal(_paternal),
	adres(_adres),
	phone(_phone),
	year_pass(_year_pass),
	number_NMT(_number_NMT),
	pin_code(_pin_code)
{
}

// Конструктор копіювання
Abiturient::Abiturient(const Abiturient& other) :
	id(other.id),
	name(other.name),
	surname(other.surname),
	paternal(other.paternal),
	adres(other.adres),
	phone(other.phone),
	year_pass(other.year_pass),
	number_NMT(other.number_NMT),
	pin_code(other.pin_code)
{

}


Abiturient::~Abiturient()
{

}


ostream& operator<<(ostream& out, const Abiturient& p)
{
	out << "ID: " << p.id << endl;
	out << "Name: " << p.name << " " << p.paternal << " " << p.surname << endl;
	out << "Address: " << p.adres << endl;
	out << "Phone: " << p.phone << endl;
	out << "Year Passed: " << p.year_pass << endl;
	out << "NMT Number: " << p.number_NMT << endl;
	out << "PIN Code: " << p.pin_code;
	return out;
}


istream& operator>>(istream& in, Abiturient& p)
{
	cout << "Enter ID: ";
	in >> p.id;

	cout << "Enter name: ";
	in >> p.name;

	cout << "Enter surname: ";
	in >> p.surname;

	cout << "Enter paternal: ";
	in >> p.paternal;

	cout << "Enter address: ";

	in >> p.adres;

	cout << "Enter phone: ";
	in >> p.phone;

	cout << "Enter year pass: ";
	in >> p.year_pass;

	cout << "Enter NMT number: ";
	in >> p.number_NMT;

	cout << "Enter PIN code: ";
	in >> p.pin_code;

	return in;
}