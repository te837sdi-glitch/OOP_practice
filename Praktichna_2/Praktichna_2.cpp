#include "Header.h" 
#include <iostream>

void testComparison() {
	using std::cout;
	using std::endl;


	cout << "--- Тест 1: ---" << endl;
	Abiturient a1(1, "Ivan", "Ivanov", "Ivanovich", "Kyiv", 123, 2024, 777, 1111);
	Abiturient a2(1, "Ivan", "Ivanov", "Ivanovich", "Kyiv", 123, 2024, 777, 1111);

	if (a1 == a2) {
		cout << "Результат: a1 та a2 рівні." << endl;
	}
	else {
		cout << "Результат: a1 та a2 НЕ рівні." << endl;
	}
	cout << "-----------------------------------------------------" << endl << endl;


	cout << "--- Тест 2: ---" << endl;
	Abiturient b1(2, "Petro", "Petrov", "Petrovich", "Lviv", 456, 2023, 888, 2222);
	Abiturient b2(2, "Petro", "Sidorov", "Petrovich", "Lviv", 456, 2023, 888, 2222);

	if (b1 == b2) {
		cout << "Результат: b1 та b2 рівні." << endl;
	}
	else {
		cout << "Результат: b1 та b2 НЕ рівні." << endl;
	}
	cout << "-----------------------------------------------------" << endl << endl;


	cout << "--- Тест 3: ---" << endl;
	Abiturient c1(3, "Olia", "Olhova", "Oleksiivna", "Odesa", 789, 2024, 999, 3333);
	Abiturient c2 = c1;

	if (c1 == c2) {
		cout << "Результат: c1 та c2 рівні." << endl;
	}
	else {
		cout << "Результат: c1 та c2 НЕ рівні." << endl;
	}
	cout << "-----------------------------------------------------" << endl;
}

int main() {
	setlocale(LC_CTYPE, "ukr");
	testComparison();
	return 0;
}