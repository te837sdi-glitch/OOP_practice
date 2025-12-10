#include "Header.h" 
#include <iostream>

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






