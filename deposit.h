//定期存款：
//只有年滿 18 歲的申請人才能擁有定期存款賬戶。
//未滿 18 歲的申請人需要父母或監護人陪同。
//符合定期存款資格的最低金額為 RM5,000.00 // 34,000(NTD)。
//利率為1-5個月=2.4%，6-12個月=2.5%，13個月及以上=2.6%。 利率按年計算。
//定期存款的最長期限為 3 年。

#pragma once

#include <iostream>
#include <windows.h>
#include "systemprint.h"

using namespace std;

void deposit(int *age,float * despositout,float * month);
int depositcount(int month,int deposit);

void deposit(int *age,float * depositout, float * month) {

	int depositin = 0,choose;
	bool leaveornot = true;

	while (leaveornot == true)
	{
		depositprint();
		cin >> choose;
		switch (choose)
		{
		case 1:
			
			if (*age >= 18)
			{
				system("cls");
				printf("請輸入您想存款的金額(最低34,000): ");
				cin >> depositin;
				if (depositin >= 34000)
				{
					system("cls");
					printf("請輸入您想存款的時間(月)(最多36個月): ");
					cin >> *month;
					if (*month <= 36)
					{
						*depositout = depositcount(*month, depositin);
						system("cls");
						printf("定期存款結束後，可拿到的錢為: %.2f 元", *depositout);
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
					printf("輸入錯誤(最低金額為34,000元)\n");
					system("pause");
				}
			}
			else if (*age == 0)
			{
				system("cls");
				printf("請先至個人資料設定，設定您的年齡，再來申請存款。\n");
				system("pause");
				leaveornot = false;
			}
			else
			{
				system("cls");
				printf("年齡不符合，無法為您申請存款(須年滿18歲)。\n");
				system("pause");
				leaveornot = false;
			}

			break;

		case 2:
			system("cls");
			printf("-------------------------\n");
			printf("1. 定期存款\n");
			printf("2. 最低金額: 34,000 (NTD)\n");
			printf("5. 最長存款時間: 3年(36個月)\n");
			printf("6. 年齡所需: 18歲(含)以上\n\n");
			printf("7. 存款利率為: \n1-5個月=2.4%\n6-12個月=2.5%\n13個月及以上=2.6% \n");
			printf("-------------------------\n");
			system("pause");
			break;

		case 3:
			system("cls");
			printf("-------------------------\n");
			cout << "1. 年齡: " << *age << " 歲" << endl;
			printf("2. 定存金額: %.2f 元\n", *depositout);
			printf("3. 存款時長: %.2f 年 (%.0f個月)\n", *month/12, *month);
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

}

int depositcount(int month, int deposit) {

	float depositout = deposit;

	if (month >= 1 && month <= 5)
	{
		for (int i = 0;i <= month; i++)
			depositout = depositout + depositout * 0.002;
	}
	else if (month >= 6 && month <= 12)
	{
		for (int i = 0;i <= month; i++)
			depositout = depositout + depositout * (0.025/12);
	}
	else if (month >= 13 && month <= 36)
	{
		for (int i = 0;i <= month; i++)
			depositout = depositout + depositout * (0.026/12);
	}

	return depositout;
}
