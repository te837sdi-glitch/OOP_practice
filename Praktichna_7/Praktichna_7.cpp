#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
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
};

class Abiturient_Entrant : public Abiturient
{
protected:
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
    }
};


int main()
{
    setlocale(LC_CTYPE, "ukr");
    srand(time(nullptr));

    vector<int> odd(10), even;
    vector<int> merged;

    for (int i = 0; i < 10; i++)
    {
        odd[i] = rand() % 50 * 2 + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        even.push_back((rand() % 50) * 2);
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    merged.resize(odd.size() + even.size());
    merge(odd.begin(), odd.end(), even.begin(), even.end(), merged.begin());

    cout << "Вектор непарних" << endl;
    for (int i = 0; i < odd.size(); i++)
        cout << odd[i] << " ";

    cout << "\nВектор парних" << endl;
    for (int i = 0; i < even.size(); i++)
        cout << even[i] << " ";

    cout << "\nОб'єднаний вектор" << endl;
    for (int i = 0; i < merged.size(); i++)
        cout << merged[i] << " ";

    vector<Abiturient*> vec;

    int choice;
    do {
        cout << "\n1 - Додати Student";
        cout << "\n2 - Додати Abiturient_Entrant";
        cout << "\n0 - Завершити\nВибір: ";
        cin >> choice;

        if (choice == 1)
        {
            Abiturient* s = new Student();
            s->fill_data();
            vec.push_back(s);
        }
        else if (choice == 2)
        {
            Abiturient* e = new Abiturient_Entrant();
            e->fill_data();
            vec.push_back(e);
        }
    } while (choice != 0);

    cout << "Вектор об'єктів\n";
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i]->display_info();
    }

    vector<Abiturient*> vec2 = vec;

    vec.erase(remove_if(vec.begin(), vec.end(),
        [](Abiturient* p) { return dynamic_cast<Student*>(p) != nullptr; }),
        vec.end());

    vec2.erase(remove_if(vec2.begin(), vec2.end(),
        [](Abiturient* p) { return dynamic_cast<Abiturient_Entrant*>(p) != nullptr; }),
        vec2.end());

    cout << "\nВектор 1 (без Student)\n";
    for (int i = 0; i < vec.size(); i++) 
    {
        vec[i]->display_info();
    }
        

    cout << "\nВектор 2 (без Entrant)\n";
    for (int i = 0; i < vec2.size(); i++) 
    {
        vec2[i]->display_info();
    }
        

    for (int i = 0; i < vec.size(); i++) 
    {
        delete vec[i];
    }
    for (int i = 0; i < vec2.size(); i++) 
    {
        delete vec2[i];
    } 

    return 0;
}
