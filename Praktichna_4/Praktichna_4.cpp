#include <iostream>
using namespace std;

class Abiturient
{
private:
    int rik;
    int nomer;
    int pin;
public:
    Abiturient() 
    {
        this->rik = 0;
        this->nomer = 0;
        this->pin = 0;
    }
    Abiturient(int rik, int nomer, int pin)
    {
        this->rik = rik;
        this->nomer = nomer;
        this->pin = pin;
    }
};

class Student : public Abiturient
{
private:
    int id;
    string name;
    string surname;
    string paternal;
    int phone;
public:
    Student() : Abiturient()
    {
        id = 0;
        name = "";
        surname = "";
        paternal = "";
        phone = 0;
    }
    Student(int id, string name, string surname, string paternal, int phone, int rik, int nomer, int pin) : Abiturient(rik, nomer, pin)
    {
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->paternal = paternal;
        this->phone = phone;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

