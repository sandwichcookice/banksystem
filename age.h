#pragma once

#include <iostream>

using namespace std;

void ageset(int * age );

void ageset(int * age) {

	cout << "請輸入您的年齡: ";
	cin >> *age;
	cout << "您的年齡為: " << *age << " 歲\n";
	system("pause");
};