#include <iostream>
using namespace std;

class Abiturient
{
protected:
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

    virtual void fill_data() = 0;
    virtual void display_info() = 0;
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

    void fill_data() override
    {
        
        cout << "  Введіть рік: ";
        cin >> rik;
        cout << "  Введіть номер: ";
        cin >> nomer;
        cout << "  Введіть PIN: ";
        cin >> pin;

       
        cout << "  Введіть ID студента: ";
        cin >> id;
        cout << "  Введіть ім'я: ";
        cin >> name;
        cout << "  Введіть прізвище: ";
        cin >> surname;
        cout << "  Введіть по-батькові: ";
        cin >> paternal;
        cout << "  Введіть телефон (ціле число): ";
        cin >> phone;
    }

    void display_info() override
    {
        cout << "  Тип: Student" << endl;
        cout << "  Рік/Номер/PIN (Абітурієнт): " << rik << "/" << nomer << "/" << pin << endl;
        cout << "  ID: " << id << endl;
        cout << "  ПІБ: " << surname << " " << name << " " << paternal << endl;
        cout << "  Телефон: " << phone << endl;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

