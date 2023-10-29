#pragma once

#include <iostream>

using namespace std;

void systemprint();
void loanprint();
void depositprint();

void systemprint() {

	printf("歡迎來到十五行營行系統\n");
	printf("請選擇您想使用的功能\n");
	printf("------------------------\n");
	printf("1. 個人資料設定\n");
	printf("2. 個人貸款\n");
	printf("3. 定期存款\n");
	printf("4. 已輸入資料查看\n");
	printf("0. 退出系統\n");
	printf("------------------------\n");

};

void loanprint() {

	printf("歡迎來到十五行營行系統--個人貸款\n");
	printf("請選擇您想使用的功能\n");
	printf("------------------------\n");
	printf("1. 貸款相關細項設定\n");
	printf("2. 貸款相關資料查看\n");
	printf("3. 已輸入資料查看\n");
	printf("0. 退出系統\n");
	printf("------------------------\n");

};

void depositprint() {

	printf("歡迎來到十五行營行系統--定期存款\n");
	printf("請選擇您想使用的功能\n");
	printf("------------------------\n");
	printf("1. 定期存款相關細項設定\n");
	printf("2. 定期存款相關資料查看\n");
	printf("3. 已輸入資料查看\n");
	printf("0. 退出系統\n");
	printf("------------------------\n");

}