#pragma once

// �ӤH�U�ڡG
//�ӤH�U�ڪ��̰����B�� RM100,000.00 => 680,000 NTD
//�i�H�Ҽ{���̧C�ӤH�U���B�� RM5,000.00 => 34000 NTD
//�ӽФH�����~�� 21 ���~����o�U�ڡC
//�ӤH�U�ڧQ�v��3.5%�]��_�Q�^�C
//�v�ٶU�ڪ��̪������� 5 �~�A�̵u������ 1 �~�C
//
//printf("�w��Ө�Q�������t��--�ӤH�U��\n");
//printf("�п�ܱz�Q�ϥΪ��\��\n");
//printf("------------------------\n");
//printf("1. �U�ڬ����Ӷ��]�w\n");
//printf("2. �U�ڬ�����Ƭd��\n");
//printf("3. �w��J��Ƭd��\n");
//printf("0. �h�X�t��\n");
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
					printf("�п�J�z�Q�U�ڪ����B(�̧C34,000�A�̰�680,000): ");
					cin >> loanin;
					if (loanin >= 34000 && loanin <= 680000)
					{
						system("cls");
						printf("�п�J�z�Q�v�٪�����(�̵u1�~�A�̪�5�~): ");
						cin >> *loanyear;
						if (*loanyear <= 5 && *loanyear >= 1)
						{
							*loanout = loancount(*loanyear, loanin);
							system("cls");
							printf("�z�һݭn�v�٪�����: %d ��", *loanout);
							system("pause");
						}
						else
						{
							system("cls");
							printf("��J���~\n");
							system("pause");
						}
					}
					else
					{
						system("cls");
						printf("��J���~(�d��:34,000~680,000)\n");
						system("pause");
					}
						

				}
				else if (*age == 0)
				{
					system("cls");
					printf("�Х��ܭӤH��Ƴ]�w�A�]�w�z���~�֡A�A�ӥӽжU�ڡC\n");
					system("pause");
					leaveornot = false;
				}
				else
				{
					system("cls");
					printf("�~�֤��ŦX�A�L�k���z�ӽжU�ڡC\n");
					system("pause");
					leaveornot = false;
				}
				break;

			case 2:
				system("cls");
				printf("-------------------------\n");
				printf("1. �ӤH�U��\n");
				printf("2. �̧C���B: 34,000 (NTD)\n");
				printf("3. �̰����B: 680,000(NTD)\n");
				printf("4. �̵u�v�ٮɶ�: 1�~\n");
				printf("5. �̪��v�ٮɶ�: 5�~\n");
				printf("6. �~�֩һ�: 21��(�t)�H�W\n");
				printf("7. �U�ڧQ�v��: 3.5%(��ƧQ)\n");
				printf("-------------------------\n");
				system("pause");
				break;

			case 3:
				system("cls");
				printf("-------------------------\n");
				cout << "1. �~��: " << *age << " ��" << endl;
				printf("2. ���v�٪��B: %d ��\n", *loanout);
				cout << "3. �v�٦~��: " << *loanyear << " �~" << endl;
				printf("-------------------------\n");
				system("pause");
				break;

			case 0:
				system("cls");
				printf("���b�h�X�t��");
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