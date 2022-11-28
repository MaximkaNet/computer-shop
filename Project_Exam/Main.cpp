#include "Header.h"

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Date CurrentDate;//������� ����
	Date prevDate;//���������� ����
	Date nextDate;//�������� ����
	Store StorageOne;
	int sizeManager = 0;
	Manager* Managers = nullptr;
	MonthlySales Sales;
	//�������� ���������, ���������� � ������� ������
	ReadItemOfFile(StorageOne, Managers, sizeManager,Sales);
	DatesFill(CurrentDate,prevDate,nextDate);
	int ch = 0;
	//�������� ���� ���������
	while (true)
	{
		//�������� ������� ����, ���� ���. ���� ������ ���������� �������� ���� � ���������� ������� �� �����
		if (DateCmp(CurrentDate, prevDate) == true)
		{
			Sales.DelAllArr();
			FILE* file;
			file = fopen("date.txt", "w");
			if (file == NULL)
			{
				cout << "Cannot open file!" << endl;
			}
			else
			{
				prevDate.day = CurrentDate.day;
				prevDate.month = CurrentDate.month;
				prevDate.year = CurrentDate.year;
				nextDate.year = 1;
				nextDate.month = 1;
				nextDate.day = 1;
				//���������� ����� �����
				FILE* file;
				file = fopen("date.txt", "w");
				if (file == NULL)
				{
					cout << "Cannot open file!" << endl;
				}
				else
				{
					fprintf(file, "%s ", "date");
					fprintf(file, "%d ", CurrentDate.year);
					fprintf(file, "%d ", CurrentDate.month);
					fprintf(file, "%d\n", CurrentDate.day);
					fprintf(file, "%s ", "prevDate");
					fprintf(file, "%d ", prevDate.year);
					fprintf(file, "%d ", prevDate.month);
					fprintf(file, "%d\n", prevDate.day);
					fprintf(file, "%s ", "nextDate");
					fprintf(file, "%d ", nextDate.year);
					fprintf(file, "%d ", nextDate.month);
					fprintf(file, "%d", nextDate.day);
					fclose(file);
					file = NULL;
				}
			}
		}
		system("cls");
		cout << "                      ������� ����" << endl << endl;
		cout << "  ������ ������: " << StorageOne.money << " ���." << "        ������� ��������� ����: " << CurrentDate.day << "." << CurrentDate.month << "." << CurrentDate.year << endl << endl;
		cout <<  "  1. ���������� �� ������" << endl;
		cout <<  "  2. ��������� � ������" << endl;
		cout <<  "  3. ����� � ������� ���������" << endl;
		//��������� ��� ����������� �������� ����
		if ((nextDate.year == 1 && nextDate.month == 1 && nextDate.day == 1) || (CurrentDate.year == nextDate.year && CurrentDate.month == nextDate.month && CurrentDate.day == nextDate.day))
		{
			cout << "  4. ������� ����� � �������� � ���������� �����-����" << endl;
		}
		cout << "  5. ������� ���� ����������" << endl;
		//cout <<  "  6. ������� ��������� ����������" << endl;
		cout <<  "  6. �������� ���" << endl;
		//cout <<  "  8. ������" << endl;
		cout << "  ";
		CorrectNum(ch);
		//����� ������������
		if (ch == 1)
		{
			AddManager(Managers, sizeManager);
			SaveItempInFile(StorageOne, Managers, sizeManager, Sales);
		}
		else if (ch == 2)
		{
			char tempN[255]{};//���
			char tempSN[255]{};//�������
			char tempP[255]{};//��������
			char tempPh[255]{};//�������
			cin.ignore();
			cout << "������� ���: ";
			cin.getline(tempN, 255);
			while (tempN[0] == '\0' || tempN[0] == ' ')
			{
				cout << "������� ���: ";
				cin.getline(tempN, 255);
			}
			cout << "������� �������: ";
			cin.getline(tempSN, 255);
			while (tempSN[0] == '\0' || tempSN[0] == ' ')
			{
				cout << "������� �������: ";
				cin.getline(tempSN, 255);
			}
			cout << "������� ��������: ";
			cin.getline(tempP, 255);
			while (tempP[0] == '\0' || tempP[0] == ' ')
			{
				cout << "������� ��������: ";
				cin.getline(tempP, 255);
			}
			cout << "������� �������: ";
			cin.getline(tempPh, 255);
			while (tempPh[0] == '\0' || tempPh[0] == ' ')
			{
				cout << "������� �������: ";
				cin.getline(tempPh, 255);
			}
			int check = 0;
			for (int i = 0; i < sizeManager; i++)
			{
				if (strcmp(tempN, Managers[i].name) == 0 && strcmp(tempSN, Managers[i].surname) == 0 && strcmp(tempP, Managers[i].patrynomic) == 0 && strcmp(tempPh, Managers[i].phone) == 0)
				{
					Managers[i].Fired_or_Not_Fired = true;
					check = 1;
				}
			}
			if (check != 0)
			{
				DelManager(Managers, sizeManager);
				SaveItempInFile(StorageOne, Managers, sizeManager, Sales);
			}
			else
			{
				cout << "�������� �� ������!" << endl;
				Sleep(400);//��������
			}
		}
		else if (ch == 3)
		{
			char tempN[255]{};//���
			char tempPh[255]{};//�������
			cout << "������� ���: ";
			cin >> tempN;
			while (tempN[0] == '\0' || tempN[0] == ' ')
			{
				cout << "������� ���: ";
				cin.getline(tempN, 255);
			}
			cout << "������� �������: ";
			cin >> tempPh;
			while (tempPh[0] == '\0' || tempPh[0] == ' ')
			{
				cout << "������� �������: ";
				cin.getline(tempPh, 255);
			}
			int check = -1;
			for (int i = 0; i < sizeManager; i++)
			{
				if (strcmp(tempN, Managers[i].name) == 0 && strcmp(tempPh, Managers[i].phone) == 0)
				{
					check = i;
					break;
				}
			}
			if (check != -1)
			{
				int ch2 = 0;
				while (true)
				{
					system("cls");
					cout << "�� ����� ���: " << Managers[check].surname << " " << Managers[check].name << " " << Managers[check].patrynomic;
					cout << "\n";
					cout << "\n";
					cout << "1. �������� ����� �����" << endl;
					cout << "2. ������� �����" << endl;
					cout << "3. ������� ������" << endl;
					cout << "4. ������� ������� ������" << endl;
					cout << "0. ����� �� �������� ���������" << endl;
					CorrectNum(ch2);
					if (ch2 == 1)
					{
						Managers[check].AddGoods(StorageOne);
						SaveItempInFile(StorageOne, Managers, sizeManager, Sales);
					}
					else if (ch2 == 2)
					{
						Managers[check].sellGoods(StorageOne, Sales);
						SaveItempInFile(StorageOne, Managers, sizeManager, Sales);
					}
					else if (ch2 == 3)
					{
						Managers[check].ShowGoods(StorageOne);
					}
					else if (ch2 == 4)
					{
						system("cls");
						cout << "<----- �������� ���������� ----->\n" << endl;
						Managers[check].ShowHistoryComp();
						cout << "<----- �������� ������������� ----->\n" << endl;
						Managers[check].ShowHistoryAcces();
						cout << endl;
						cout << endl;
						system("pause");
						system("cls");
					}
					else
					{
						break;
					}
				}
			}
			else if (check == -1)
			{
				cout << "�������� �� ������!" << endl;
				Sleep(400);//��������
			}
		}
		else if (ch == 4)
		{
			if ((nextDate.year == 1 && nextDate.month == 1 && nextDate.day == 1) || (CurrentDate.year == nextDate.year && CurrentDate.month == nextDate.month && CurrentDate.day == nextDate.day))
			{
				//��������� ���������� prevDate, nextDate
				CalculationDate(CurrentDate, nextDate);
				prevDate.day = CurrentDate.day;
				prevDate.month = CurrentDate.month;
				prevDate.year = CurrentDate.year;
				//���������� ����� �����
				FILE* file;
				file = fopen("date.txt", "w");
				if (file == NULL)
				{
					cout << "Cannot open file!" << endl;
				}
				else
				{
					fprintf(file, "%s ", "date");
					fprintf(file, "%d ", CurrentDate.year);
					fprintf(file, "%d ", CurrentDate.month);
					fprintf(file, "%d\n", CurrentDate.day);
					fprintf(file, "%s ", "prevDate");
					fprintf(file, "%d ", prevDate.year);
					fprintf(file, "%d ", prevDate.month);
					fprintf(file, "%d\n", prevDate.day);
					fprintf(file, "%s ", "nextDate");
					fprintf(file, "%d ", nextDate.year);
					fprintf(file, "%d ", nextDate.month);
					fprintf(file, "%d", nextDate.day);
					fclose(file);
					file = NULL;
				}
				//������ �����-�����
				system("cls");
				cout << "--------------> � ������� <--------------" << endl;
				cout << "--------------> ������������� <--------------" << endl;
				StorageOne.ShowAcces(StorageOne.Access, StorageOne.sizeAccess);
				cout << "--------------> � ������� <--------------" << endl;
				cout << "\n--------------> ���������� <--------------" << endl;
				StorageOne.ShowComps(StorageOne.Computers, StorageOne.sizeComputers);
				cout << "\n";
				cout << "\n";
				cout << "\n";
				//������� �� �����
				Sales.ShowMonthSeles();
				CreatePrice_List(StorageOne, CurrentDate);
				CreateMonthlySales(Sales, CurrentDate);
				Sales.DelAllArr();//������� ���� ����� ������ �� �����
				SaveItempInFile(StorageOne, Managers, sizeManager, Sales);
			}
			else
			{
				cout << "�����-���� ����������!" << endl;
				Sleep(500);
				system("cls");
			}
		}
		else if (ch == 5)
		{
			system("cls");
			int sort = 0;
			int chechHit = 0;
			while (true)
			{
				if (chechHit == 1) {
					sort++;
					if (sort > 2)
						sort = 0;
				}
				else if (chechHit == -1)
					break;
				cout << "���������" << endl;
				if (sizeManager == 0)
				{
					cout.width(3);
					cout << "��������� ��� �� �������� � ��������" << endl;
					system("pause");
					break;
				}

				if (sort == 1)
				{
					system("cls");
					SortShow(Managers, sizeManager, 1);
					cout << "���������� ���� (" << "�����������" << ")" << endl;
				}
				else if (sort == 2) 
				{
					system("cls");
					SortShow(Managers, sizeManager, 0);
					cout << "���������� ���� (" << "��������" << ")" << endl;
				}
				else if (sort == 0)
				{
					system("cls");
					for (int i = 0; i < sizeManager; i++)
					{
						cout << "---------------------" << endl;
						Managers[i].Print();
						cout << "_____________________" << endl;
					}
					cout << "���������� ���� (" << "�����������" << ")" << endl;
				}
				INFO;
				chechHit = HitButton();
			}
			system("cls");
		}
		/*else if (ch == 6)
		{
			ControlEmptyComps(StorageOne);
		}*/
		else if (ch == 6)
		{
			NullProgram(StorageOne, CurrentDate, prevDate, nextDate, Managers, sizeManager, Sales);
			SaveItempInFile(StorageOne, Managers, sizeManager, Sales);
		}
		/*else if (ch == 8)
		{
			cout << "��� � ����������" << endl;
			system("pause");
		}*/
		else if (ch == 123)
		{
			FILE* file;
			system("cd Code");
			int ch2 = 0;
			while (true)
			{
				system("cls");
				cout << "1. Header" << endl;
				cout << "2. Main" << endl;
				cout << "3. Function" << endl;
				cout << "0. Exit" << endl;
				CorrectNum(ch2);
				if (ch2 == 1)
				{
					system("cls");
					file = fopen("Code//Header.txt", "r");
					if (file != NULL)
					{
						char temp[255]{};
						while (true)
						{
							if (strcmp(temp, "//code_end") == 0)
								break;
							cout << temp;
							fgets(temp, 255, file);
						}
						fclose(file);
						file = NULL;
					}
					else
						cout << "Cannot open file" << endl;
					system("pause");
				}
				else if (ch2 == 2)
				{
					system("cls");
					file = fopen("Code//Main.txt", "r");
					if (file != NULL)
					{
						char temp[255]{};
						while (true)
						{
							if (strcmp(temp, "//code_end") == 0)
								break;
							cout << temp;
							fgets(temp, 255, file);
						}
						fclose(file);
						file = NULL;
					}
					else
						cout << "Cannot open file" << endl;
					system("pause");
				}
				else if (ch2 == 3)
				{
					system("cls");
					file = fopen("Code//Function.txt", "r");
					if (file != NULL)
					{
						char temp[255]{};
						while (true)
						{
							if (strcmp(temp, "//code_end") == 0)
								break;
							cout << temp;
							fgets(temp, 255, file);
						}
						fclose(file);
						file = NULL;
					}
					else
						cout << "Cannot open file" << endl;
					system("pause");
				}
				else
					break;
			}
		}
		else
		{
			break;
		}
	}
	SaveItempInFile(StorageOne, Managers, sizeManager, Sales);
	Clear(StorageOne, Managers, sizeManager,Sales);//������� ������
	return 0;
}