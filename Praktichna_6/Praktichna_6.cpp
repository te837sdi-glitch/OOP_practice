#include <iostream>
using namespace std;

template<class T, int N>
class Vector
{
private:
    T** arr;
    int size;
    int capacity;

public:
    Vector()
    {
        size = 0;
        capacity = N;
        arr = new T * [capacity];

        for (int i = 0; i < capacity; i++) 
        {
            arr[i] = nullptr;
        }
            
    }

    ~Vector()
    {
        for (int i = 0; i < size; i++) 
        {
            delete arr[i];
        }
            

        delete[] arr;
    }

    int getSize() 
    { 
        return size; 
    }
    int getCapacity() 
    { 
        return capacity; 
    }

    void push_back(T element)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T** temp_arr = new T * [capacity];

            for (int i = 0; i < size; i++) 
            {
                temp_arr[i] = arr[i];
            }
             
            for (int i = size; i < capacity; i++) 
            {
                temp_arr[i] = nullptr;
            }
            
            delete[] arr;
            arr = temp_arr;
        }

        arr[size] = new T(element);
        size++;
    }

    void pop_back()
    {
        if (size == 0)
            return;

        size--;
        delete arr[size];
        arr[size] = nullptr;
    }

    T at(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Невірний індекс\n";
            exit(1);
        }
        return *arr[index];
    }

    T operator[](int index) 
    {
        if (index < 0 || index >= size)
        {
            cout << "Невірний індекс\n";
            exit(1);
        }
        return *arr[index];
    }
};

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
        cout << "  *** Тип: Abiturient_Entrant (Вступник) ***" << endl;
        cout << "  Рік/Номер/PIN (Абітурієнт): " << rik << "/" << nomer << "/" << pin << endl;
        cout << "  Номер сертифіката ЗНО: " << sertificat_nomer << endl;
        cout << "  Середній бал ЗНО: " << zno_average << endl;
        cout << "  Бажана спеціальність: " << desired_specialty << endl;
    }

    virtual ~Abiturient_Entrant() {}
};

int main() 
{
    setlocale(LC_CTYPE, "ukr");

    Vector<int, 5> v;
    for (int i = 0; i < v.getCapacity(); i++) 
    {
        int var;
        cin >> var;

        v.push_back(var);
    }
    for (int i = 0; i < v.getSize(); i++)
    {
        cout << v.at(i)<< " ";
    }

    Vector<Abiturient*, 4> v2;
    for (int i = 0; i < v2.getCapacity(); i++) 
    {
        cout << "Оберіть обєкт: Студент(1) | Вступник(2)" << endl;
        int vubir;
        cin >> vubir;

        if (vubir == 1)
        {
            Student *s = new Student();
            s->fill_data();

            v2.push_back(s);
        }
        else if (vubir == 2) 
        {
            Abiturient_Entrant* ae = new Abiturient_Entrant();
            ae->fill_data();

            v2.push_back(ae);
        }
    }
    for (int i = 0; i < v2.getSize(); i++) 
    {
        v2[i]->display_info();
    }
}