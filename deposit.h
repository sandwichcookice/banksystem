//�w���s�ڡG
//�u���~�� 18 �����ӽФH�~��֦��w���s�ڽ��C
//���� 18 �����ӽФH�ݭn�����κ��@�H���P�C
//�ŦX�w���s�ڸ�檺�̧C���B�� RM5,000.00 // 34,000(NTD)�C
//�Q�v��1-5�Ӥ�=2.4%�A6-12�Ӥ�=2.5%�A13�Ӥ�ΥH�W=2.6%�C �Q�v���~�p��C
//�w���s�ڪ��̪������� 3 �~�C

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
				printf("�п�J�z�Q�s�ڪ����B(�̧C34,000): ");
				cin >> depositin;
				if (depositin >= 34000)
				{
					system("cls");
					printf("�п�J�z�Q�s�ڪ��ɶ�(��)(�̦h36�Ӥ�): ");
					cin >> *month;
					if (*month <= 36)
					{
						*depositout = depositcount(*month, depositin);
						system("cls");
						printf("�w���s�ڵ�����A�i���쪺����: %.2f ��", *depositout);
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
					printf("��J���~(�̧C���B��34,000��)\n");
					system("pause");
				}
			}
			else if (*age == 0)
			{
				system("cls");
				printf("�Х��ܭӤH��Ƴ]�w�A�]�w�z���~�֡A�A�ӥӽЦs�ڡC\n");
				system("pause");
				leaveornot = false;
			}
			else
			{
				system("cls");
				printf("�~�֤��ŦX�A�L�k���z�ӽЦs��(���~��18��)�C\n");
				system("pause");
				leaveornot = false;
			}

			break;

		case 2:
			system("cls");
			printf("-------------------------\n");
			printf("1. �w���s��\n");
			printf("2. �̧C���B: 34,000 (NTD)\n");
			printf("5. �̪��s�ڮɶ�: 3�~(36�Ӥ�)\n");
			printf("6. �~�֩һ�: 18��(�t)�H�W\n\n");
			printf("7. �s�ڧQ�v��: \n1-5�Ӥ�=2.4%\n6-12�Ӥ�=2.5%\n13�Ӥ�ΥH�W=2.6% \n");
			printf("-------------------------\n");
			system("pause");
			break;

		case 3:
			system("cls");
			printf("-------------------------\n");
			cout << "1. �~��: " << *age << " ��" << endl;
			printf("2. �w�s���B: %.2f ��\n", *depositout);
			printf("3. �s�ڮɪ�: %.2f �~ (%.0f�Ӥ�)\n", *month/12, *month);
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
