#pragma once

// 個人貸款：
//個人貸款的最高金額為 RM100,000.00 => 680,000 NTD
//可以考慮的最低個人貸款額為 RM5,000.00 => 34000 NTD
//申請人必須年滿 21 歲才能獲得貸款。
//個人貸款利率為3.5%（月復利）。
//償還貸款的最長期限為 5 年，最短期限為 1 年。
//
//printf("歡迎來到十五行營行系統--個人貸款\n");
//printf("請選擇您想使用的功能\n");
//printf("------------------------\n");
//printf("1. 貸款相關細項設定\n");
//printf("2. 貸款相關資料查看\n");
//printf("3. 已輸入資料查看\n");
//printf("0. 退出系統\n");
//printf("------------------------\n");

#include <iostream>
#include <windows.h>
#include "systemprint.h"

using namespace std;

void loan(int * age, int  *loanout , int *loanyear);
int loancount(int year, int loan);

void loan(int * age, int *loanout , int *loanyear) {

	int loanin = 0,choose;
	bool leaveornot = true;

	while (leaveornot == true)
	{
		loanprint();
		cin >> choose;
		switch (choose)
		{
			case 1:
				if (*age >= 21)
				{
					system("cls");
					printf("請輸入您想貸款的金額(最低34,000，最高680,000): ");
					cin >> loanin;
					if (loanin >= 34000 && loanin <= 680000)
					{
						system("cls");
						printf("請輸入您想償還的期限(最短1年，最長5年): ");
						cin >> *loanyear;
						if (*loanyear <= 5 && *loanyear >= 1)
						{
							*loanout = loancount(*loanyear, loanin);
							system("cls");
							printf("您所需要償還的錢為: %d 元", *loanout);
							system("pause");
						}
						else
						{
							system("cls");
							printf("輸入錯誤\n");
							system("pause");
						}
					}
					else
					{
						system("cls");
						printf("輸入錯誤(範圍為:34,000~680,000)\n");
						system("pause");
					}
						

				}
				else if (*age == 0)
				{
					system("cls");
					printf("請先至個人資料設定，設定您的年齡，再來申請貸款。\n");
					system("pause");
					leaveornot = false;
				}
				else
				{
					system("cls");
					printf("年齡不符合，無法為您申請貸款。\n");
					system("pause");
					leaveornot = false;
				}
				break;

			case 2:
				system("cls");
				printf("-------------------------\n");
				printf("1. 個人貸款\n");
				printf("2. 最低金額: 34,000 (NTD)\n");
				printf("3. 最高金額: 680,000(NTD)\n");
				printf("4. 最短償還時間: 1年\n");
				printf("5. 最長償還時間: 5年\n");
				printf("6. 年齡所需: 21歲(含)以上\n");
				printf("7. 貸款利率為: 3.5%(月複利)\n");
				printf("-------------------------\n");
				system("pause");
				break;

			case 3:
				system("cls");
				printf("-------------------------\n");
				cout << "1. 年齡: " << *age << " 歲" << endl;
				printf("2. 須償還金額: %d 元\n", *loanout);
				cout << "3. 償還年限: " << *loanyear << " 年" << endl;
				printf("-------------------------\n");
				system("pause");
				break;

			case 0:
				system("cls");
				printf("正在退出系統");
				for (int i = 0; i <= 2; i++)
				{
					Sleep(500);
					printf(".");
				}
				leaveornot = false;

				break;
			default:
				break;
		}

		system("cls");

	}

};

int loancount(int year,int loan) {

	float loanout = loan;

	for (int i = 0;i <= year; i++)
		loanout = loanout + loanout * (0.035 / 12);
		

	return loanout;

}