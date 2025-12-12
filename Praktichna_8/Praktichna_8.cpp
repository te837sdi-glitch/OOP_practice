#include <iostream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

class Abiturient
{
protected:
    int rik;
    int nomer;
    int pin;
public:
    Abiturient() : rik(0), nomer(0), pin(0) {}
    Abiturient(int rik, int nomer, int pin) : rik(rik), nomer(nomer), pin(pin) {}

    virtual void fill_data() = 0;
    virtual void display_info() = 0;
    virtual ~Abiturient() {}
};

class Student : public Abiturient
{
protected:
    int id;
    string name, surname, paternal;
    int phone;
public:
    Student() : Abiturient(), id(0), phone(0) {}

    void fill_data() override
    {
        cout << "Введіть рік вступу: ";
        cin >> rik;
        cout << "Введіть номер справи: ";
        cin >> nomer;
        cout << "Введіть PIN: ";
        cin >> pin;

        cout << "Введіть ID студента: ";
        cin >> id;
        cout << "Введіть ім'я: ";
        cin >> name;
        cout << "Введіть прізвище: ";
        cin >> surname;
        cout << "Введіть по-батькові: ";
        cin >> paternal;
        cout << "Введіть телефон: ";
        cin >> phone;
    }

    void display_info() override
    {
        cout << "Student\n";
        cout << "Рік/Номер/PIN: " << rik << "/" << nomer << "/" << pin << endl;
        cout << "ID: " << id << endl;
        cout << "ПІБ: " << surname << " " << name << " " << paternal << endl;
        cout << "Телефон: " << phone << endl;
    }
    int getId()
    {
        return this->id;
    }
};

class Abiturient_Entrant : public Abiturient
{
protected:
    int id;
    int sertificat_nomer;
    double zno_average;
    string desired_specialty;
public:
    Abiturient_Entrant() : Abiturient(), sertificat_nomer(0), zno_average(0) {}

    void fill_data() override
    {
        cout << "Введіть рік подачі: ";
        cin >> rik;
        cout << "Введіть номер заяви: ";
        cin >> nomer;
        cout << "Введіть PIN: ";
        cin >> pin;
        cout << "Введіть ID: ";
        cin >> id;

        cout << "Введіть номер сертифіката ЗНО: ";
        cin >> sertificat_nomer;
        cout << "Введіть середній бал ЗНО: ";
        cin >> zno_average;
        cout << "Введіть бажану спеціальність: ";
        cin >> desired_specialty;
    }

    void display_info() override
    {
        cout << "Abiturient_Entrant\n";
        cout << "Рік/Номер/PIN: " << rik << "/" << nomer << "/" << pin << endl;
        cout << "Сертифікат ЗНО: " << sertificat_nomer << endl;
        cout << "Середній бал: " << zno_average << endl;
        cout << "Бажана спеціальність: " << desired_specialty << endl;
        cout << "ID: " << id << endl;
    }
    int getId() 
    {
        return this->id;
    }
};

int main()
{
    setlocale(LC_CTYPE, "ukr");

    list<int> list1 { 3,9,1,7,5 };
    list<int> list2 { 8,0,10,2,4 };
    list<int> merged_list (list1.size() + list2.size());

    list1.sort();
    list2.sort();

    merge(list1.begin(), list1.end(), list2.begin(), list2.end(), merged_list.begin());

    for (auto it = list1.begin(); it != list1.end(); it++)
    {
        cout << *it << " ";
    }cout << endl;
    for (auto it = list2.begin(); it != list2.end(); it++)
    {
        cout << *it << " ";
    }cout << endl;
    for (auto it = merged_list.begin(); it != merged_list.end(); it++)
    {
        cout << *it << " ";
    }cout << endl;

    map<int, Abiturient*> myMap;


    int m = 0;
    while (m != 3)
    {
        cout << "[1]-Вивести елемент по ID\n[2]-Додати елемент\n";
        cin >> m;

        if (m == 1) 
        {
            cout << "Введіть ID: " << endl;
            int ID;
            cin >> ID;

            myMap[ID]->display_info();
        }
        else if (m == 2) 
        {
            cout << "Введіть кількість: " << endl;
            int kilkist;
            cin >> kilkist;

            for (int i = 0; i < kilkist; i++)
            {
                cout << "Оберіть: Student(1) | Abiturient_Entrant(2)";
                int vubir;
                cin >> vubir;

                if (vubir == 1)
                {
                    Student* s = new Student();
                    s->fill_data();

                    myMap[s->getId()] = s;
                }
                else if (vubir == 2)
                {
                    Abiturient_Entrant* ae = new Abiturient_Entrant();
                    ae->fill_data();

                    myMap[ae->getId()] = ae;
                }
            }
        }
    }

    
}

