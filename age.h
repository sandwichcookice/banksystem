#pragma once

#include <iostream>

using namespace std;

void ageset(int * age );

void ageset(int * age) {

	cout << "�п�J�z���~��: ";
	cin >> *age;
	cout << "�z���~�֬�: " << *age << " ��\n";
	system("pause");
};