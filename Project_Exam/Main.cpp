#include "Header.h"

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Date CurrentDate;//текущая дата
	Date prevDate;//предидущая дата
	Date nextDate;//следущая дата
	Store StorageOne;
	int sizeManager = 0;
	Manager* Managers = nullptr;
	MonthlySales Sales;
	//загрузка хранилищя, менеджеров и истории продаж
	ReadItemOfFile(StorageOne, Managers, sizeManager,Sales);
	DatesFill(CurrentDate,prevDate,nextDate);
	int ch = 0;
	//основной цикл программы
	while (true)
	{
		//проверка текущей даты, если тек. дата меньше предидущей обнуляем дату и сбрасываем продажи за месяц
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
				//заполнение полей файла
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
		cout << "                      Главное меню" << endl << endl;
		cout << "  Баланс склада: " << StorageOne.money << " грн." << "        Текущая системная дата: " << CurrentDate.day << "." << CurrentDate.month << "." << CurrentDate.year << endl << endl;
		cout <<  "  1. Устроиться на роботу" << endl;
		cout <<  "  2. Уволиться с роботы" << endl;
		cout <<  "  3. Войти в кабинет менеджера" << endl;
		//активация или деактивация элемента меню
		if ((nextDate.year == 1 && nextDate.month == 1 && nextDate.day == 1) || (CurrentDate.year == nextDate.year && CurrentDate.month == nextDate.month && CurrentDate.day == nextDate.day))
		{
			cout << "  4. Сделать отчет о продажах и напечатать прайс-лист" << endl;
		}
		cout << "  5. Вывести всех менеждеров" << endl;
		//cout <<  "  6. Удалить ошибочные компьютеры" << endl;
		cout <<  "  6. Обнулить все" << endl;
		//cout <<  "  8. Помощь" << endl;
		cout << "  ";
		CorrectNum(ch);
		//выбор пользователя
		if (ch == 1)
		{
			AddManager(Managers, sizeManager);
			SaveItempInFile(StorageOne, Managers, sizeManager, Sales);
		}
		else if (ch == 2)
		{
			char tempN[255]{};//имя
			char tempSN[255]{};//фамилия
			char tempP[255]{};//отчество
			char tempPh[255]{};//телефон
			cin.ignore();
			cout << "Введите имя: ";
			cin.getline(tempN, 255);
			while (tempN[0] == '\0' || tempN[0] == ' ')
			{
				cout << "Введите имя: ";
				cin.getline(tempN, 255);
			}
			cout << "Введите фамилию: ";
			cin.getline(tempSN, 255);
			while (tempSN[0] == '\0' || tempSN[0] == ' ')
			{
				cout << "Введите фамилию: ";
				cin.getline(tempSN, 255);
			}
			cout << "Введите отчество: ";
			cin.getline(tempP, 255);
			while (tempP[0] == '\0' || tempP[0] == ' ')
			{
				cout << "Введите отчество: ";
				cin.getline(tempP, 255);
			}
			cout << "Введите телефон: ";
			cin.getline(tempPh, 255);
			while (tempPh[0] == '\0' || tempPh[0] == ' ')
			{
				cout << "Введите телефон: ";
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
				cout << "Менеджер не найден!" << endl;
				Sleep(400);//ожидание
			}
		}
		else if (ch == 3)
		{
			char tempN[255]{};//имя
			char tempPh[255]{};//телефон
			cout << "Введите имя: ";
			cin >> tempN;
			while (tempN[0] == '\0' || tempN[0] == ' ')
			{
				cout << "Введите имя: ";
				cin.getline(tempN, 255);
			}
			cout << "Введите телефон: ";
			cin >> tempPh;
			while (tempPh[0] == '\0' || tempPh[0] == ' ')
			{
				cout << "Введите телефон: ";
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
					cout << "Вы вошли как: " << Managers[check].surname << " " << Managers[check].name << " " << Managers[check].patrynomic;
					cout << "\n";
					cout << "\n";
					cout << "1. Добавить новый товар" << endl;
					cout << "2. Продать товар" << endl;
					cout << "3. Вывести товары" << endl;
					cout << "4. Вывести историю продаж" << endl;
					cout << "0. Выйти из кабинета менеджера" << endl;
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
						cout << "<----- Проданые компьютеры ----->\n" << endl;
						Managers[check].ShowHistoryComp();
						cout << "<----- Проданые комплектующие ----->\n" << endl;
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
				cout << "Менеджер не найден!" << endl;
				Sleep(400);//ожидание
			}
		}
		else if (ch == 4)
		{
			if ((nextDate.year == 1 && nextDate.month == 1 && nextDate.day == 1) || (CurrentDate.year == nextDate.year && CurrentDate.month == nextDate.month && CurrentDate.day == nextDate.day))
			{
				//изменение параметров prevDate, nextDate
				CalculationDate(CurrentDate, nextDate);
				prevDate.day = CurrentDate.day;
				prevDate.month = CurrentDate.month;
				prevDate.year = CurrentDate.year;
				//заполнение полей файла
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
				//печать прайс-листа
				system("cls");
				cout << "--------------> В наличии <--------------" << endl;
				cout << "--------------> Комплектующие <--------------" << endl;
				StorageOne.ShowAcces(StorageOne.Access, StorageOne.sizeAccess);
				cout << "--------------> В наличии <--------------" << endl;
				cout << "\n--------------> Компьютеры <--------------" << endl;
				StorageOne.ShowComps(StorageOne.Computers, StorageOne.sizeComputers);
				cout << "\n";
				cout << "\n";
				cout << "\n";
				//Продажи за месяц
				Sales.ShowMonthSeles();
				CreatePrice_List(StorageOne, CurrentDate);
				CreateMonthlySales(Sales, CurrentDate);
				Sales.DelAllArr();//очистка всех полей продаж за месяц
				SaveItempInFile(StorageOne, Managers, sizeManager, Sales);
			}
			else
			{
				cout << "Прайс-лист недоступен!" << endl;
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
				cout << "Менеджеры" << endl;
				if (sizeManager == 0)
				{
					cout.width(3);
					cout << "Менеджеры еще не работают в компании" << endl;
					system("pause");
					break;
				}

				if (sort == 1)
				{
					system("cls");
					SortShow(Managers, sizeManager, 1);
					cout << "Сортировка имен (" << "возростание" << ")" << endl;
				}
				else if (sort == 2) 
				{
					system("cls");
					SortShow(Managers, sizeManager, 0);
					cout << "Сортировка имен (" << "убывание" << ")" << endl;
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
					cout << "Сортировка имен (" << "отсутствует" << ")" << endl;
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
			cout << "Ещё в разработке" << endl;
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
	Clear(StorageOne, Managers, sizeManager,Sales);//очистка памяти
	return 0;
}