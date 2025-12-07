#include <iostream>
#include <string>

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

    virtual ~Abiturient() {}
};

class Student : public Abiturient
{
protected:
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
      
        cout << "  [База] Введіть рік вступу: ";
        cin >> rik;
        cout << "  [База] Введіть номер справи: ";
        cin >> nomer;
        cout << "  [База] Введіть PIN: ";
        cin >> pin;

        
        cout << "  [Student] Введіть ID студента: ";
        cin >> id;
        cout << "  [Student] Введіть ім'я: ";
        cin >> name;
        cout << "  [Student] Введіть прізвище: ";
        cin >> surname;
        cout << "  [Student] Введіть по-батькові: ";
        cin >> paternal;
        cout << "  [Student] Введіть телефон: ";
        cin >> phone;
    }

    void display_info() override
    {
        cout << "  *** Тип: Student (Студент) ***" << endl;
        cout << "  Рік/Номер/PIN (Абітурієнт): " << rik << "/" << nomer << "/" << pin << endl;
        cout << "  ID: " << id << endl;
        cout << "  ПІБ: " << surname << " " << name << " " << paternal << endl;
        cout << "  Телефон: " << phone << endl;
    }

    virtual ~Student() {}
};

class Abiturient_Entrant : public Abiturient
{
protected:
    int sertificat_nomer;
    double zno_average;
    string desired_specialty;
public:
    Abiturient_Entrant() : Abiturient()
    {
        sertificat_nomer = 0;
        zno_average = 0.0;
        desired_specialty = "";
    }

    
    void fill_data() override
    {
        
        cout << "  [База] Введіть рік подачі: ";
        cin >> rik;
        cout << "  [База] Введіть номер заяви: ";
        cin >> nomer;
        cout << "  [База] Введіть PIN: ";
        cin >> pin;

       
        cout << "  [Entrant] Введіть номер сертифіката ЗНО: ";
        cin >> sertificat_nomer;
        cout << "  [Entrant] Введіть середній бал ЗНО: ";
        cin >> zno_average;
        cout << "  [Entrant] Введіть бажану спеціальність: ";
        cin >> desired_specialty;
    }

    void display_info() override
    {
        cout << "  *** Тип: Abiturient_Entrant (Вступник) ***" << endl;
        cout << "  Рік/Номер/PIN (Абітурієнт): " << rik << "/" << nomer << "/" << pin << endl;
        cout << "  Номер сертифіката ЗНО: " << sertificat_nomer << endl;
        cout << "  Середній бал ЗНО: " << zno_average << endl;
        cout << "  Бажана спеціальність: " << desired_specialty << endl;
    }

    virtual ~Abiturient_Entrant() {}
};


void show_menu()
{
    cout << "\nОберіть клас для створення об'єкта (введіть номер):" << endl;
    cout << "1. Student (Студент)" << endl;
    cout << "2. Abiturient_Entrant (Вступник)" << endl;
    cout << "Ваш вибір: ";
}

int main()
{
    
    const int ARRAY_SIZE = 5;
    Abiturient* abiturients[ARRAY_SIZE];
    int choice;

   
    cout << "--- Заповнення масиву об'єктами похідних класів (розмір: " << ARRAY_SIZE << ") ---" << endl;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << "\nСтворення об'єкта #" << i + 1 << ":";
        show_menu(); 

        cin >> choice;

        switch (choice)
        {
        case 1:
            abiturients[i] = new Student();
            cout << "Введіть дані для Student #" << i + 1 << endl;
            abiturients[i]->fill_data();
            break;
        case 2:
            abiturients[i] = new Abiturient_Entrant();
            cout << "Введіть дані для Abiturient_Entrant #" << i + 1 << endl;
            abiturients[i]->fill_data();
            break;
        default:
            cout << "Невірний вибір. Створено Student за замовчуванням." << endl;
            abiturients[i] = new Student();
            cout << "Введіть дані для Student #" << i + 1 << endl;
            abiturients[i]->fill_data();
            break;
        }
    }

    cout << "\n--- Вивід даних та виклик віртуального методу (display_info) ---" << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << "\nДані об'єкта #" << i + 1 << ":" << endl;
        abiturients[i]->display_info();
    }

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        delete abiturients[i];
    }

    return 0;
}