#include <iostream>
using namespace std;

class Student
{
private:
    int id;
    string name;
    string surname;
    string paternal;
    int phone;
public:
    Student()
    {
        id = 0;
        name = "";
        surname = "";
        paternal = "";
        phone = 0;
    }
    Student(int id, string name, string surname, string paternal, int phone)
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

