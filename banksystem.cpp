// banksystem.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
// 個人貸款：
//個人貸款的最高金額為 RM100,000.00。
//可以考慮的最低個人貸款額為 RM5,000.00
//申請人必須年滿 21 歲才能獲得貸款。
//個人貸款利率為3.5%（月復利）。
//償還貸款的最長期限為 5 年，最短期限為 1 年。
//
//main : 營行系統 !!!
// 
//定期存款：
//只有年滿 18 歲的申請人才能擁有定期存款賬戶。
//未滿 18 歲的申請人需要父母或監護人陪同。
//符合定期存款資格的最低金額為 RM5,000.00。
//利率為1-5個月=2.4%，6-12個月=2.5%，13個月及以上=2.6%。 利率按年計算。
//定期存款的最長期限為 3 年。


#include <iostream>
#include <windows.h>
#include "systemprint.h"
#include "age.h"
#include "loan.h"
#include "deposit.h"

using namespace std;


int main()
{
	bool leaveornot=true;

	int * age = new int;
	*age = NULL;

	int * loanyear = new int;
	int* loanout = new int; //貸款用

	float * depositout = new float,* month = new float; //定存用

	*loanyear = NULL;
	*loanout = NULL;
	*depositout = NULL;
	*month = NULL;

	while (leaveornot == true)
	{
		int choose;
		systemprint();
		
		cin >> choose;
		switch (choose)
		{
			case 1:  //個人資料設定
				system("cls");
				ageset(age);
				break;
			case 2: //貸款
				system("cls");
				loan(age,loanout,loanyear);
				break;
			case 3: //定存
				system("cls");
				deposit(age,depositout,month);
				break;
			case 4:
				system("cls");
				printf("個人資料:\n");
				printf("-------------------------\n");
				cout << "1. 年齡: " << *age << " 歲" << endl;
				printf("-------------------------\n\n");
				printf("個人貸款:\n");
				printf("-------------------------\n");
				printf("1. 須償還金額: %d 元\n", *loanout);
				cout << "2. 償還年限: " << *loanyear << " 年" << endl;
				printf("-------------------------\n\n");
				printf("定期存款:\n");
				printf("-------------------------\n");
				printf("1. 定存金額: %.2f 元\n", *depositout);
				printf("2. 存款時長: %.2f 年 (%.0f個月)\n", *month / 12, *month);
				printf("-------------------------\n");
				system("pause");
				break;
			case 0: //退出系統
				system("cls");
				printf("正在退出系統");
				for (int i = 0; i <= 3; i++)
				{
					Sleep(500);
					printf(".");
				}
				leaveornot = false;
				break;
			default:
				printf("錯誤*error\n");
				break;
		}

		system("cls");
	}
}


// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
