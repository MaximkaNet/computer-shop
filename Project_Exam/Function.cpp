#include "Header.h"

//проверка на правильность ввода пользователем числа
void CorrectNum(int& num)
{
	while (true)
	{
		char temp[255]{};
		cin >> temp;
		if (Command(temp) == 0)
		{
			num = 123;
			return;
		}
		bool flag = true;
		for (int i = 0; i < strlen(temp) + 1; i++)
		{
			if (flag == false || temp[i] == '\0')
			{
				break;
			}
			if (temp[i] >= '0' && temp[i] <= '9')
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		if (flag == true)
		{
			num = atoi(temp);
			break;
		}
		cout << "Вы ошиблись в правописании! Введите число снова: ";
	}
}
//проверка на правильность ввода пользователем числа
void CorrectNum(double& num)
{
	while (true)
	{
		char temp[255]{};
		cin >> temp;
		bool flag = true;
		for (int i = 0; i < strlen(temp) + 1; i++)
		{
			if (flag == false || temp[i] == '\0')
			{
				break;
			}
			if (temp[i] >= '0' && temp[i] <= '9')
			{
				flag = true;
			}
			else if ((temp[i - 1] >= '0' && temp[i - 1] <= '9') && (temp[i] == '.' || temp[i] == ','))
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		if (flag == true)
		{
			num = atof(temp);
			break;
		}
		cout << "Вы ошиблись в правописании! Введите число снова: ";
	}
}
//перенос строки
void LineBreak(const char* features)
{
	int scaleStr = 40;
	int pos = 0;
	for (int i = 0; i < strlen(features) + 1; i++)
	{
		if (features[i] == '\0')
		{
			cout << endl;
			break;
		}
		if (features[i] == ' ')
		{
			int sizeWord = 0;
			for (int j = i + 1; j < strlen(features) + 1; j++)
			{
				if (features[j] != ' ')
				{
					sizeWord++;
				}
				else
				{
					break;
				}
			}
			if (sizeWord > scaleStr || scaleStr < i - pos)
			{
				pos = i;
				while (true)
				{
					if (features[i + 1] == ' ')
					{
						i++;
					}
					else
					{
						i++;
						break;
					}
				}
				cout << endl;
			}
		}
		cout << features[i];
	}
}

bool IsZero(const char* buffer)
{
	if (buffer[0] != '\0') {
		for (int i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] != '0')
				return false;
		}
	}
	return true;
}

int HitButton()
{
	int s = 0;
	while (true)
	{
		//если любая кнопка нажата
		if (_kbhit())
		{
			s = _getch();
			//cout << _getch() << endl;
			if (s == 115 || s == 19)
			{
				return 1;
			}
			else
				return -1;
		}
		Sleep(250);
	}
}

int Command(const char* buffer)
{
	if (strcmp(buffer, "/code") == 0)
		return 0;
	else
		return 1;
}

//тут так задумано что оно все в одной куче

void AutoFillDate(Date& CurrentDate, Date& prevDate, Date& nextDate)
{
	Date temp;
	// создаем стд объект даты и времени 
	struct tm* tim = new tm;
	// определяем текущую млисекунду 
	time_t tt = time(NULL);
	//заполняем все поля стд структуры 
	localtime_s(tim, &tt);
	//заполняем нужные поля нашей структуры 
	temp.year = 1900 + tim->tm_year;
	temp.month = 1 + tim->tm_mon;
	temp.day = tim->tm_mday;

	char temp1[50]{};
	char temp2[50]{};
	char temp3[50]{};

	FILE* file;
	file = fopen("date.txt", "r");
	if (file == NULL)
	{
		cout << "Cannot open file!" << endl;
	}
	else {
		fgets(temp1, 50, file);
		fgets(temp2, 50, file);
		fgets(temp3, 50, file);
		fclose(file);
		file = NULL;
	}
	//запись новой даты в файл
	file = fopen("date.txt", "w");
	if (file == NULL)
	{
		cout << "Cannot open file!" << endl;
		return;
	}
	fprintf(file, "%s ", "date");
	fprintf(file, "%d ", temp.year);
	fprintf(file, "%d ", temp.month);
	fprintf(file, "%d\n", temp.day);
	fprintf(file, "%s", temp2);
	fprintf(file, "%s", temp3);
	fclose(file);
	file = NULL;

	cout << "Операция успешна!" << endl;
	system("pause");
}
void ManuallFillDate(Date& CurrentDate, Date& prevDate, Date& nextDate)
{
	Date temp;
	cout << "Ведите год: ";
	CorrectNum(temp.year);
	cout << "Ведите месяц: ";
	CorrectNum(temp.month);
	cout << "Ведите день: ";
	CorrectNum(temp.day);

	char temp1[50]{};
	char temp2[50]{};
	char temp3[50]{};

	FILE* file;
	file = fopen("date.txt", "r");
	if (file == NULL)
	{
		cout << "Cannot open file!" << endl;
	}
	else
	{
		fgets(temp1, 50, file);
		fgets(temp2, 50, file);
		fgets(temp3, 50, file);
		fclose(file);
		file = NULL;
	}
	//запись новой даты в файл
	file = fopen("date.txt", "w");
	if (file == NULL)
	{
		cout << "Cannot open file!" << endl;
		return;
	}
	fprintf(file, "%s ", "date");
	fprintf(file, "%d ", temp.year);
	fprintf(file, "%d ", temp.month);
	fprintf(file, "%d\n", temp.day);
	fprintf(file, "%s", temp2);
	fprintf(file, "%s", temp3);
	fclose(file);
	file = NULL;

	cout << "Операция успешна!" << endl;
	system("pause");
}
//добавить в основную программу все изменения
void DefaultFillDate(Date& CurrentDate, Date& prevDate, Date& nextDate)
{
	FILE* file;
	file = fopen("date.txt", "r");
	if (file == NULL)
	{
		cout << "Cannot open file!" << endl;
		fclose(file);
		file = NULL;
		return;
	}
	char* temp = nullptr;
	for (int i = 0; i < 3; i++)
	{
		temp = new char[25]{};
		fgets(temp, 25, file);
		//cout << temp << endl;//debug
		if (strstr(temp, "date "))
		{
			char year[7]{};
			char month[4]{};
			char day[4]{};
			int p = 0;
			int u = 0;//счетчик для year, month, day
			for (int j = 5; j < strlen(temp); j++)
			{
				if (temp[j] >= '0' && temp[j] <= '9')
				{
					if (p == 0)
					{
						year[u] = temp[j];
						u++;
					}
					else if (p == 1)
					{
						month[u] = temp[j];
						u++;
					}
					else if (p == 2)
					{
						day[u] = temp[j];
						u++;
					}
				}
				else if (temp[j] == ' ' && temp[j + 1] != ' ')
				{
					p++;
					u = 0;
				}
			}
			CurrentDate.year = atoi(year);
			CurrentDate.month = atoi(month);
			CurrentDate.day = atoi(day);
		}
		else if (strstr(temp, "prevDate "))
		{
			char year[7]{};
			char month[4]{};
			char day[4]{};
			int p = 0;
			int u = 0;//счетчик для year, month, day
			for (int j = 9; j < strlen(temp); j++)
			{
				if (temp[j] >= '0' && temp[j] <= '9')
				{
					if (p == 0)
					{
						year[u] = temp[j];
						u++;
					}
					else if (p == 1)
					{
						month[u] = temp[j];
						u++;
					}
					else if (p == 2)
					{
						day[u] = temp[j];
						u++;
					}
				}
				else if (temp[j] == ' ' && temp[j + 1] != ' ')
				{
					p++;
					u = 0;
				}
			}
			prevDate.year = atoi(year);
			prevDate.month = atoi(month);
			prevDate.day = atoi(day);
		}
		else if (strstr(temp, "nextDate "))
		{
			char year[7]{};
			char month[4]{};
			char day[4]{};
			int p = 0;
			int u = 0;//счетчик для year, month, day
			for (int j = 9; j < strlen(temp); j++)
			{
				if (temp[j] >= '0' && temp[j] <= '9')
				{
					if (p == 0)
					{
						year[u] = temp[j];
						u++;
					}
					else if (p == 1)
					{
						month[u] = temp[j];
						u++;
					}
					else if (p == 2)
					{
						day[u] = temp[j];
						u++;
					}
				}
				else if (temp[j] == ' ' && temp[j + 1] != ' ')
				{
					p++;
					u = 0;
				}
			}
			nextDate.year = atoi(year);
			nextDate.month = atoi(month);
			nextDate.day = atoi(day);
		}
		delete[]temp;
	}
	fclose(file);
	file = NULL;
}
void ResetDate(Date& CurrentDate, Date& prevDate, Date& nextDate)
{
	Date temp;
	temp.year = 1;
	temp.month = 1;
	temp.day = 1;

	FILE* file;
	//запись новой даты в файл
	file = fopen("date.txt", "w");
	if (file == NULL)
	{
		cout << "Cannot open file!" << endl;
		return;
	}
	fprintf(file, "%s ", "date");
	fprintf(file, "%d ", temp.year);
	fprintf(file, "%d ", temp.month);
	fprintf(file, "%d\n", temp.day);
	fprintf(file, "%s ", "prevDate");
	fprintf(file, "%d ", temp.year);
	fprintf(file, "%d ", temp.month);
	fprintf(file, "%d\n", temp.day);
	fprintf(file, "%s ", "nextDate");
	fprintf(file, "%d ", temp.year);
	fprintf(file, "%d ", temp.month);
	fprintf(file, "%d", temp.day);
	fclose(file);
	file = NULL;

	cout << "Операция успешна!" << endl;
	system("pause");
}
void CorrectDate(Date& CurrentDate, Date& prevDate, Date& nextDate)
{
	FILE* file;
	file = fopen("date.txt", "w");
	if (file == NULL)
	{
		cout << "Cannot open file!" << endl;
		return;
	}
	//currentDate
	if (CurrentDate.year < 1)
	{
		CurrentDate.year = 1;
	}
	if (CurrentDate.month > 12)
	{
		CurrentDate.month = 12;
	}
	else if (CurrentDate.month < 1)
	{
		CurrentDate.month = 1;
	}
	if (CurrentDate.day > 31)
	{
		CurrentDate.day = 31;
	}
	else if (CurrentDate.day < 1)
	{
		CurrentDate.day = 1;
	}
	//prevDate
	if (prevDate.year < 1)
	{
		prevDate.year = 1;
	}
	if (prevDate.month > 12)
	{
		prevDate.month = 12;
	}
	else if (prevDate.month < 1)
	{
		prevDate.month = 1;
	}
	if (prevDate.day > 31)
	{
		prevDate.day = 31;
	}
	else if (prevDate.day < 1)
	{
		prevDate.day = 1;
	}
	//nextDate
	if (nextDate.year < 1)
	{
		nextDate.year = 1;
	}
	if (nextDate.month > 12)
	{
		nextDate.month = 12;
	}
	else if (nextDate.month < 1)
	{
		nextDate.month = 1;
	}
	if (nextDate.day > 31)
	{
		nextDate.day = 31;
	}
	else if (nextDate.day < 1)
	{
		nextDate.day = 1;
	}
	//write of file
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

void DatesFill(Date& CurrentDate, Date& prevDate, Date& nextDate)
{
	bool flag = false;
	int ch = 0;
	while (true)
	{
		system("cls");
		cout << "  <---- Настройка времени! ----->" << endl;
		cout << "  1. Заполнить дату автомитически" << endl;
		cout << "  2. Заполнить дату вручную" << endl;
		cout << "  3. Оставить дату по-умолчанию" << endl;
		cout << "  4. Сбросить дату" << endl;
		cout << "  ";
		CorrectNum(ch);
		if (ch == 1)
		{
			AutoFillDate(CurrentDate, prevDate, nextDate);
			break;
		}
		else if (ch == 2)
		{
			ManuallFillDate(CurrentDate, prevDate, nextDate);
			break;
		}
		else if (ch == 4)
		{
			ResetDate(CurrentDate, prevDate, nextDate);
		}
		else
		{
			break;
		}
	}
	DefaultFillDate(CurrentDate, prevDate, nextDate);
	//коректеровка дат
	CorrectDate(CurrentDate, prevDate, nextDate);
}

bool isLeapYear(int temp_year)//– определяет високосный год или нет
{
	if (temp_year % 4 == 0)
	{
		//cout << "Год " << year << " высокосный\n";

		return true;
	}
	else if (temp_year % 100 == 0)
	{
		//cout << "Год " << year << " НЕ высокосный\n";

		return false;
	}
	else if (temp_year % 400 == 0)
	{
		//cout << "Год " << year << " высокосный\n";

		return true;
	}
	else if (temp_year % 100 >= 1)
	{
		//cout << "Год " << year << " НЕ высокосный\n";

		return false;
	}
	else if (temp_year % 400 >= 1)
	{
		//cout << "Год " << year << " НЕ высокосный\n";

		return false;
	}
	else if (temp_year % 4 >= 1)
	{
		//cout << "Год " << year << " НЕ высокосный\n";

		return false;
	}
}

void CalculationDate(Date Temp, Date& nextDate)
{
	bool check = isLeapYear(Temp.year);
	if (check == true)
	{
		int daysInMonth[12]{ 31,29,31,30,31,30,31,31,30,31,30,31 };
		if (Temp.day > daysInMonth[Temp.month] && Temp.month != 12)
		{
			Temp.day = daysInMonth[Temp.month];
			Temp.month++;
		}
		else if (Temp.day < daysInMonth[Temp.month] && Temp.month != 12)
		{
			Temp.month++;
		}
		else if (Temp.month == 12)
		{
			Temp.month = 1;
			Temp.year++;
		}
	}
	else if (check == false)
	{
		int daysInMonth[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (Temp.day > daysInMonth[Temp.month] && Temp.month != 12)
		{
			Temp.day = daysInMonth[Temp.month];
			Temp.month++;
		}
		else if (Temp.day < daysInMonth[Temp.month] && Temp.month != 12)
		{
			Temp.month++;
		}
		else if (Temp.month == 12)
		{
			Temp.month = 1;
			Temp.year++;
		}
	}
	nextDate.day = Temp.day;
	nextDate.month = Temp.month;
	nextDate.year = Temp.year;
}

bool DateCmp(Date CurrentDate, Date prevDate)
{
	if (CurrentDate.year < prevDate.year)
	{
		return true;
	}
	else if (CurrentDate.year == prevDate.year && CurrentDate.month < prevDate.month)
	{
		return true;
	}
	else if (CurrentDate.year == prevDate.year && CurrentDate.month == prevDate.month && CurrentDate.day < prevDate.day)
	{
		return true;
	}
	else if (CurrentDate.year == prevDate.year && CurrentDate.month == prevDate.month && CurrentDate.day == prevDate.day)
	{
		return false;
	}
	return false;
}

void Accessories::Fill()
{
	cout << "<---Заполнение комплектующего--->" << endl;
	cout.width(4);
	cout << "Введите название Комплектующего: ";
	cin.ignore();
	cin.getline(nameAcces, 255);
	cout.width(4);
	cout << "Введите производителя: ";
	cin.getline(manufacturer, 255);
	cout.width(4);
	cout << "Введите особенности: ";
	cin.getline(features, 255);
	cout.width(4);
	cout << "Введите цену: ";
	CorrectNum(Price);
}

void Accessories::Print()
{
	cout << " Название: " << nameAcces << endl;
	cout << " Производитель: " << manufacturer << endl;
	cout << " Особенности:";
	//перенос строки
	LineBreak(features);
	//--------------------------
	cout << " Цена:" << Price << endl;
}

void Accessories::PrintAccesCompact()
{
	cout << nameAcces << " ; " << manufacturer << " ; " << Price;
}

void Computer::FillComp()
{
	cout.width(4);
	cout << "Название компьютера: ";
	cin.ignore();
	char temp[255]{};
	cin.getline(nameComp,50);
	cout << "<--- Конфигурация ---> (Чтобы пропустить главный пункт введите 0)" << endl;
	cout << "CPU: "; 
	cin.getline(nameCPU, 50);
	if (IsZero(nameCPU) == 0) {
		cout << "   количество ядер: ";
		CorrectNum(countCore);
		if (countCore == 0)
			nameCPU[0] = '\0';
		else
			total = true;
		cin.ignore();
	}
	else
		nameCPU[0] = '\0';
	cout << "Motherboard: "; 
	cin.getline(nameMB, 50);
	if (IsZero(nameMB) == 0)
	{
		cout << "   разъем процессора: "; 
		cin.getline(soketCPU, 50);
		if (IsZero(soketCPU) == 1) {
			soketCPU[0] = '\0';
			nameMB[0] = '\0';
		}
		else
			total = true;
	}
	else
		nameMB[0] = '\0';
	cout << "GPU: "; 
	cin.getline(nameGPU, 50);
	if (IsZero(nameGPU)==0) {
		cout << "   объем памяти (MB): ";
		CorrectNum(memoryGPU);
		if (memoryGPU == 0)
			nameGPU[0] = '\0';
		else
			total = true;
		cin.ignore();
	}
	else
		nameGPU [0]='\0';
	cout << "RAM: ";
	cin.getline(nameRAM, 50);
	if (IsZero(nameRAM) == 0) {
		cout << "   объем одного модуля (MB): ";
		CorrectNum(OneModulMemory);
		if (OneModulMemory != 0) {
			cout << "   количество планок: ";
			CorrectNum(countModule);
			if (countModule == 0) {
				nameRAM [0]='\0';
				OneModulMemory = 0;
			}
			else
				total = true;
		}
		else {
			nameGPU [0]='\0';
		}
	}
	else
		nameRAM [0]='\0';
	cout << "БП: ";
	cin.ignore();
	cin.getline(nameBP, 50);
	if (IsZero(nameBP) == 0) {
		cout << "   мощность (W): ";
		CorrectNum(power);
		cin.ignore();
		if (power == 0) {
			nameBP[0]='\0';
		}
		else
			total = true;
	}
	else
		nameBP[0]='\0';
	cout << "SSD: ";
	cin.getline(nameSSD, 50);
	if (IsZero(nameSSD) == 0) {
		cout << "   объем памяти (MB): ";
		CorrectNum(memorySSD);
		cin.ignore(); 
		if (memorySSD == 0) {
			nameSSD [0]='\0';
		}
		else
			total = true;
	}
	else
		nameSSD[0]='\0';
	cout << "HDD: ";
	cin.getline(nameHDD, 50);
	if (IsZero(nameHDD) == 0) {
		cout << "   объем памяти (MB): ";
		CorrectNum(memoryHDD);
		if (memoryHDD == 0) {
			nameHDD[0]='\0';
		}
		else
			total = true;
	}
	else
		nameHDD [0]='\0';
	cout.width(4);
	cout << "Цена компьютера (UAN): ";
	CorrectNum(Price);
}

void Computer::PrintComp()
{
	cout.width(4);
	cout << "Название компьютера: ";
	cout << nameComp << endl;
	cout << "<--- Конфигурация --->" << endl;
	if (IsZero(nameCPU) == 1 || countCore == 0)
		cout << "CPU:  -" << endl;
	else 
		cout << "CPU: " << nameCPU << "; количество ядер: " << countCore << endl;
	if (IsZero(nameMB) == 1 || IsZero(soketCPU) == 1)
		cout << "Mothrboard:  -" << endl;
	else
		cout << "Motherboard: " << nameMB << "; разъем процессора: " << soketCPU << endl;
	if (IsZero(nameGPU) ==1 || memoryGPU == 0)
		cout << "GPU:  -" << endl;
	else
		cout << "GPU: " << nameGPU << "; объем памяти: " << memoryGPU <<" MB"<< endl;
	if (IsZero(nameRAM) == 1 || OneModulMemory == 0 || countModule == 0)
		cout << "RAM:  -" << endl;
	else
		cout << "RAM: " << nameRAM << "; объем одного модуля: " << OneModulMemory<<" MB" << "; количество планок: " << countModule << endl;
	if (IsZero(nameBP) == 1 || power == 0)
		cout << "БП:  -" << endl;
	else
		cout << "БП: " << nameBP << "; мощность: " << power<<"W" << endl;
	if (IsZero(nameSSD) == 1 || memorySSD == 0)
		cout << "SSD:  -" << endl;
	else
		cout << "SSD: " << nameSSD << "; объем памяти: " << memorySSD << " MB"<< endl;
	if (IsZero(nameHDD) == 1 || memoryHDD == 0)
		cout << "HDD:  -" << endl;
	else
		cout << "HDD: " << nameHDD << "; объем памяти: " << memoryHDD << " MB" << endl;
	cout.width(4);
	cout << "Цена компьютера: " << Price <<" грн." << endl;
}

void Computer::PrintCompCompact()
{
	if (IsZero(nameComp) == 1)
		cout << " ";
	else
		cout << nameComp << " ";
	if (IsZero(nameCPU) == 1 || countCore == 0)
		cout << " CPU: -";
	else
		cout << " CPU: " << nameCPU << " " << countCore << " core";
	if (IsZero(nameMB) == 1 || IsZero(soketCPU) == 1)
		cout << "; MotherB: -" ;
	else
		cout << "; MB: " << nameMB << " soket: " << soketCPU ;
	if (IsZero(nameGPU) == 1 || memoryGPU == 0)
		cout << "; GPU: -" ;
	else
		cout << "; GPU: " << nameGPU << " " << memoryGPU <<" MB";
	if (IsZero(nameRAM) == 1 || OneModulMemory == 0 || countModule == 0)
		cout << "; RAM: -" ;
	else
		cout << "; RAM: " << nameRAM << " " << OneModulMemory<<" MB" << " X " << countModule ;
	if (IsZero(nameBP) == 1 || power == 0)
		cout << "; БП: -" ;
	else
		cout << "; БП: " << nameBP << " " << power << " W";
	if (IsZero(nameSSD) == 1 || memorySSD == 0)
		cout << "; SSD: -" ;
	else
		cout << "; SSD: " << nameSSD << " " << memorySSD << " MB";
	if (IsZero(nameHDD) == 1 || memoryHDD == 0)
		cout << "; HDD: -" ;
	else
		cout << "; HDD: " << nameHDD << " " << memoryHDD << " MB";
	cout << "; "<< Price << " грн." << endl;
}

void Manager::sellGoods(Store& StorageOne, MonthlySales& Sales)
{
	int ch = 0;
	while (true)
	{
		system("cls");
		cout << "Что продать?" << endl;
		cout << "1. ПК" << endl;
		cout << "2. Комплектующее" << endl;
		cout << "0. Выйти из меню" << endl;
		CorrectNum(ch);
		if (ch == 1)
		{
			int ch2 = 0;
			while (true)
			{
				system("cls");
				cout << "1. Выбрать компьютер вручную" << endl;
				cout << "2. Выбрать компьютер конфигуратором" << endl;
				cout << "0. Выйти из меню" << endl;
				CorrectNum(ch2);
				if (ch2 == 1)
				{
					while (true)
					{
						int sell = 0;
						system("cls");
						if (StorageOne.sizeComputers == 0)
						{
							cout << endl << "Компьютеров нет в наличии" << endl;
							system("pause");
							break;
						}
						//вывести краткий список доступных компьютеров
						for (int i = 0; i < StorageOne.sizeComputers; i++)
						{
							cout << i + 1 << ". ";
							StorageOne.Computers[i].PrintCompCompact();
						}
						cout << "Введите порядковый номер компьютера для покупки (0 чтобы выйти в меню продаж)" << endl;
						CorrectNum(sell);
						if (sell > 0 && sell < StorageOne.sizeComputers + 1) {
							int pass = 0;
							system("cls");
							StorageOne.Computers[sell - 1].PrintComp();
							cout << endl;
							cout << "1. Подтвердить покупку" << endl;
							cout << "0. Отказаться от покупки" << endl;
							CorrectNum(pass);
							if (pass == 1) {
								HistoryComp(HistoryComps, numSellComp, StorageOne.Computers[sell - 1]);
								Sales.AddMonthSellComp(StorageOne.Computers[sell - 1]);
								StorageOne.DelComp(StorageOne.Computers, StorageOne.sizeComputers, sell - 1);
								cout << "Операция успешна!\n";
								system("pause");
								break;
							}
							else
							{
								cout << "Вы отказались от покупки!" << endl;
								system("pause");
							}
						}
						else if (sell == 0)
							break;
						else
						{
							cout << "Комплектующее было продано(или не было в продаже)" << endl;
							system("pause");
						}
					}
				}
				else if (ch2 == 2)
				{
					//конфигуратор пк
					int check = 0;
					//экземпляр компьютера для поиска среди доступных
					Computer SearchComp;

					int ch2 = 0;
					char temp[255]{};
					//конфигуратор
					while (true)
					{
						system("cls");
						if (StorageOne.sizeComputers == 0)
						{
							cout << endl << "Компьютеров нет в наличии" << endl;
							system("pause");
							check = 1;
							break;
						}
						//вывести краткий список доступных компьютеров
						for (int i = 0; i < StorageOne.sizeComputers; i++)
						{
							cout << i + 1 << ". ";
							StorageOne.Computers[i].PrintCompCompact();
						}
						cout << "Собранный ПК" << endl;
						SearchComp.PrintCompCompact();
						cout << endl;
						cout << "1. CPU" << endl;
						cout << "2. MotherBoard" << endl;
						cout << "3. GPU" << endl;
						cout << "4. RAM" << endl;
						cout << "5. Блок питания" << endl;
						cout << "6. SSD" << endl;
						cout << "7. HDD" << endl;
						cout << "0. Выйти из конфигуратора и перейти к покупке" << endl;
						cout << "9. Очистить конфигуратор" << endl;
						CorrectNum(ch2);
						//элементы конфигуратора
						if (ch2 == 1) {
							cin.ignore();
							cout << "CPU: ";
							cin.getline(SearchComp.nameCPU, 50);
							if (IsZero(SearchComp.nameCPU) == 0) {
								cout << "   количество ядер: ";
								CorrectNum(SearchComp.countCore);
								cin.ignore();
							}
							else
								SearchComp.nameCPU[0] = '\0';
						}
						else if (ch2 == 2) {
							cin.ignore();
							cout << "Motherboard: ";
							cin.getline(SearchComp.nameMB, 50);
							if (IsZero(SearchComp.nameMB) == 0)
							{
								cout << "   разъем процессора: ";
								cin.getline(SearchComp.soketCPU, 50);
								if (IsZero(SearchComp.soketCPU) == 1) {
									SearchComp.soketCPU[0] = '\0';
									SearchComp.nameMB[0] = '\0';
								}
							}
							else
								SearchComp.nameMB[0] = '\0';
						}
						else if (ch2 == 3) {
							cin.ignore();
							cout << "GPU: ";
							cin.getline(SearchComp.nameGPU, 50);
							if (IsZero(SearchComp.nameGPU) == 0) {
								cout << "   объем памяти: ";
								CorrectNum(SearchComp.memoryGPU);
								if (SearchComp.memoryGPU == 0)
									SearchComp.nameGPU[0] = '\0';
								cin.ignore();
							}
							else
								SearchComp.nameGPU[0] = '\0';
						}
						else if (ch2 == 4) {
							cin.ignore();
							cout << "RAM: ";
							cin.getline(SearchComp.nameRAM, 50);
							if (IsZero(SearchComp.nameRAM) == 0) {
								cout << "   объем одного модуля: ";
								CorrectNum(SearchComp.OneModulMemory);
								if (SearchComp.OneModulMemory != 0) {
									cout << "   количество планок: ";
									CorrectNum(SearchComp.countModule);
									if (SearchComp.countModule == 0) {
										SearchComp.nameRAM[0] = '\0';
										SearchComp.OneModulMemory = 0;
									}
								}
								else {
									SearchComp.nameGPU[0] = '\0';
								}
							}
							else
								SearchComp.nameRAM[0] = '\0';
						}
						else if (ch2 == 5) {
							cin.ignore();
							cout << "БП: ";
							cin.getline(SearchComp.nameBP, 50);
							if (IsZero(SearchComp.nameBP) == 0) {
								cout << "   мощность: ";
								CorrectNum(SearchComp.power);
								cin.ignore();
								if (SearchComp.power == 0) {
									SearchComp.nameBP[0] = '\0';
								}
							}
							else
								SearchComp.nameBP[0] = '\0';
						}
						else if (ch2 == 6) {
							cin.ignore();
							cout << "SSD: ";
							cin.getline(SearchComp.nameSSD, 50);
							if (IsZero(SearchComp.nameSSD) == 0) {
								cout << "   объем памяти: ";
								CorrectNum(SearchComp.memorySSD);
								cin.ignore();
								if (SearchComp.memorySSD == 0) {
									SearchComp.nameSSD[0] = '\0';
								}
							}
							else
								SearchComp.nameSSD[0] = '\0';
						}
						else if (ch2 == 7) {
							cin.ignore();
							cout << "HDD: ";
							cin.getline(SearchComp.nameHDD, 50);
							if (IsZero(SearchComp.nameHDD) == 0) {
								cout << "   объем памяти: ";
								CorrectNum(SearchComp.memoryHDD);
								if (SearchComp.memoryHDD == 0) {
									SearchComp.nameHDD[0] = '\0';
								}
							}
							else
								SearchComp.nameHDD[0] = '\0';
						}
						else if (ch2 == 9)
						{
							Computer NewComp;
							SearchComp = NewComp;
						}
						else if (ch2 == 0) {
							break;
						}
						else {
							cout << "Вы ошиблись с выбором!" << endl;
						}
					}
					//поиск нужного компьютера
					int sizeComp = StorageOne.sizeComputers;
					
					for (int i = 0; i < sizeComp; i++)
					{
						if (strcmp(SearchComp.nameCPU, StorageOne.Computers[i].nameCPU) == 0)
						{
							if (SearchComp.countCore == StorageOne.Computers[i].countCore)
							{
								if (strcmp(SearchComp.nameMB, StorageOne.Computers[i].nameMB) == 0)
								{
									if (strcmp(SearchComp.soketCPU, StorageOne.Computers[i].soketCPU) == 0)
									{
										if (strcmp(SearchComp.nameGPU, StorageOne.Computers[i].nameGPU) == 0)
										{
											if (SearchComp.memoryGPU == StorageOne.Computers[i].memoryGPU)
											{
												if (strcmp(SearchComp.nameRAM, StorageOne.Computers[i].nameRAM) == 0)
												{
													if (SearchComp.OneModulMemory == StorageOne.Computers[i].OneModulMemory)
													{
														if (SearchComp.countModule == StorageOne.Computers[i].countModule)
														{
															if (strcmp(SearchComp.nameBP, StorageOne.Computers[i].nameBP) == 0)
															{
																if (SearchComp.power == StorageOne.Computers[i].power)
																{
																	if (strcmp(SearchComp.nameSSD, StorageOne.Computers[i].nameSSD) == 0)
																	{
																		if (SearchComp.memorySSD == StorageOne.Computers[i].memorySSD)
																		{
																			if (strcmp(SearchComp.nameHDD, StorageOne.Computers[i].nameHDD) == 0)
																			{
																				if (SearchComp.memoryHDD == StorageOne.Computers[i].memoryHDD)
																				{
																					int pass = 0;
																					system("cls");
																					StorageOne.Computers[i].PrintComp();
																					cout << endl;
																					cout << "1. Подтвердить покупку" << endl;
																					cout << "0. Отказаться от покупки" << endl;
																					CorrectNum(pass);
																					if (pass == 1) {
																						HistoryComp(HistoryComps, numSellComp, StorageOne.Computers[i]);
																						Sales.AddMonthSellComp(StorageOne.Computers[i]);
																						StorageOne.DelComp(StorageOne.Computers, StorageOne.sizeComputers, i);
																						check = 1;
																						cout << "Операция успешна!\n";
																						system("pause");
																						break;
																					}
																					else
																					{
																						check = 1;
																						cout << "Вы отказались от покупки" << endl;
																						system("pause");
																						break;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					if (check == 0)
					{
						cout << "Компьютер продан(или не было в продаже)" << endl;
						system("pause");
					}
				}
				else
					break;
				
			}
			
		}
		else if (ch == 2)
		{
			while (true)
			{
				system("cls");
				//вывод доступных комплектующих
				if (StorageOne.sizeAccess == 0)
				{
					cout << endl << "Комплектующих нет в наличии" << endl;
					system("pause");
					break;
				}
				for (int i = 0; i < StorageOne.sizeAccess; i++)
				{
					cout << i + 1 << ". ";
					StorageOne.Access[i].PrintAccesCompact();
					cout << endl;
				}
				int select = 0;
				cout << "Введите порядковый номер комплектующего (0 для выхода в меню продаж): ";
				CorrectNum(select);
				if (select > 0 && select < StorageOne.sizeAccess + 1)
				{
					system("cls");
					int ch2 = 0;
					StorageOne.Access[select - 1].Print();
					cout << endl;
					cout << "1. Подтвердить покупку" << endl;
					cout << "0. Отказаться от покупки" << endl;
					CorrectNum(ch2);
					if (ch2 == 1) {
						HistoryAcces(HistoryAccess, numSellAcces, StorageOne.Access[select - 1]);
						Sales.AddMonthSellAcces(StorageOne.Access[select - 1]);
						StorageOne.DelAcces(StorageOne.Access, StorageOne.sizeAccess, select - 1);
						cout << "Операция успешна!\n";
						system("pause");
					}
				}
				else if (select == 0)
					break;
				else
				{
					cout << "Комплектующее было продано(или не было в продаже)" << endl;
					system("pause");
				}
			}
		}
		else
		{
			break;
		}
	}
	
}

void Manager::AddGoods(Store& StorageOne)
{
	int ch = 0;
	while (true)
	{
		system("cls");
		cout << "Что добавить?" << endl;
		cout << "1. ПК" << endl;
		cout << "2. Комплектующее" << endl;
		cout << "0. Выйти из меню" << endl;
		CorrectNum(ch);
		if (ch == 1)
		{
			StorageOne.AddComp(StorageOne.Computers, StorageOne.sizeComputers);
		}
		else if (ch == 2)
		{
			StorageOne.AddAcces(StorageOne.Access, StorageOne.sizeAccess);
		}
		else
		{
			break;
		}
	}
}

void Manager::ShowGoods(Store StorageOne)
{
	int ch = 0;
	while (true)
	{
		system("cls");
		cout << "<----ВЫВОД НА ЭКРАН---->" << endl;
		cout << endl;
		cout << "1. Все товары" << endl;
		cout << "2. Только компьютеры" << endl;
		cout << "3. Только комплектующие" << endl;
		cout << "0. Выйти из меню" << endl;
		CorrectNum(ch);
		if (ch == 1)
		{
			system("cls");
			int sort = 0;
			int chechHit = 0;
			while (true)
			{
				if (StorageOne.sizeAccess == 0 && StorageOne.sizeComputers == 0)
				{
					cout << "Комплектующих нет в продаже\n" << endl;
					cout << "Компьютров нет в продаже\n" << endl;
					system("pause");
					break;
				}
				if (chechHit == 1) {
					sort++;
					if (sort == 3)
						sort = 0;
				}
				else if (chechHit == -1)
					break;
				if (sort == 1)
				{
					system("cls");
					cout << "--------------> Комплектующие <--------------" << endl;
					if (StorageOne.sizeAccess == 0)
						cout << "Комплектующих нет в продаже" << endl;
					else
						SortShow_A(StorageOne, 1);
					cout << "\n--------------> Компьютеры <--------------" << endl;
					if (StorageOne.sizeComputers == 0)
						cout << "Компьютеров нет в продаже" << endl;
					else
						SortShow_C(StorageOne, 1);
					cout << "Сортировка имен (" << "возростание" << ")" << endl;
				}
				else if (sort == 2)
				{
					system("cls");
					cout << "--------------> Комплектующие <--------------" << endl;
					if (StorageOne.sizeAccess == 0)
						cout << "Комплектующих нет в продаже" << endl;
					else
						SortShow_A(StorageOne, 0);
					cout << "\n--------------> Компьютеры <--------------" << endl;
					if (StorageOne.sizeComputers == 0)
						cout << "Компьютеров нет в продаже" << endl;
					else
						SortShow_C(StorageOne, 0);
					cout << "Сортировка имен (" << "убывание" << ")" << endl;
				}
				else if (sort == 0)
				{
					system("cls");
					cout << "--------------> Комплектующие <--------------" << endl;
					StorageOne.ShowAcces(StorageOne.Access, StorageOne.sizeAccess);
					cout << "\n--------------> Компьютеры <--------------" << endl;
					StorageOne.ShowComps(StorageOne.Computers, StorageOne.sizeComputers);
					cout << "Сортировка имен (" << "отсутствует" << ")" << endl;
				}
				INFO;
				chechHit = HitButton();
			}
			system("cls");
		}
		else if (ch == 2)
		{
			system("cls");
			int sort = 0;
			int chechHit = 0;
			while (true)
			{
				if (StorageOne.sizeComputers == 0)
					break;
				if (chechHit == 1) {
					sort++;
					if (sort > 2)
						sort = 0;
				}
				else if (chechHit == -1)
					break;
				if (sort == 1)
				{
					system("cls");
					cout << "--------------> Компьютеры <--------------" << endl;
					if (StorageOne.sizeComputers == 0)
						cout << "Компьютеров нет в продаже" << endl;
					else
						SortShow_C(StorageOne, 1);
					cout << "Сортировка имен (" << "возростание" << ")" << endl;
				}
				else if (sort == 2)
				{
					system("cls");
					cout << "--------------> Компьютеры <--------------" << endl;
					if (StorageOne.sizeComputers == 0)
						cout << "Компьютеров нет в продаже" << endl;
					else
						SortShow_C(StorageOne, 0);
					cout << "Сортировка имен (" << "убывание" << ")" << endl;
				}
				else if (sort == 0)
				{
					system("cls");
					cout << "--------------> Компьютеры <--------------" << endl;
					StorageOne.ShowComps(StorageOne.Computers, StorageOne.sizeComputers);
					cout << "Сортировка имен (" << "отсутствует" << ")" << endl;
				}
				INFO;
				chechHit = HitButton();
			}
			system("cls");
		}
		else if (ch == 3)
		{
			system("cls");
			int sort = 0;
			int chechHit = 0;
			while (true)
			{
				if (StorageOne.sizeAccess == 0)
					break;
				if (chechHit == 1) {
					sort++;
					if (sort > 2)
						sort = 0;
				}
				else if (chechHit == -1)
					break;
				if (sort == 1)
				{
					system("cls");
					cout << "--------------> Комплектующие <--------------" << endl;
					if (StorageOne.sizeAccess == 0)
						cout << "Комплектующих нет в продаже" << endl;
					else
						SortShow_A(StorageOne, 1);
					cout << "Сортировка имен (" << "возростание" << ")" << endl;
				}
				else if (sort == 2)
				{
					system("cls");
					cout << "--------------> Комплектующие <--------------" << endl;
					if (StorageOne.sizeAccess == 0)
						cout << "Комплектующих нет в продаже" << endl;
					else
						SortShow_A(StorageOne, 0);
					cout << "Сортировка имен (" << "убывание" << ")" << endl;
				}
				else if (sort == 0)
				{
					system("cls");
					cout << "--------------> Комплектующие <--------------" << endl;
					StorageOne.ShowAcces(StorageOne.Access, StorageOne.sizeAccess);
					cout << "Сортировка имен (" << "отсутствует" << ")" << endl;
				}
				INFO;
				chechHit = HitButton();
			}
			system("cls");
		}
		else
		{
			break;
		}
	}
}

void Manager::ShowHistoryAcces()
{
	if (numSellAcces != 0 && numSellAcces > -1)
	{
		for (int i = 0; i < numSellAcces; i++)
		{
			cout << "---------------------" << endl;
			HistoryAccess[i].Print();
			cout << "_____________________" << endl;
		}
	}
	else
	{
		cout << "Еще ничего не продано" << endl;
	}
}

void Manager::ShowHistoryComp()
{
	if (numSellComp != 0 && numSellComp > -1)
	{
		for (int i = 0; i < numSellComp; i++)
		{
			cout << " <-------------------------------->" << endl;
			HistoryComps[i].PrintComp();
			cout << " <________________________________>" << endl;
		}
	}
	else
	{
		cout << "Еще ничего не продано" << endl;
	}
}

void Manager::HistoryComp(Computer*& HistoryComp, int& numSellComp, Computer TempComp)
{
	Computer* temp = new Computer[numSellComp + 1];
	for (int i = 0; i < numSellComp; i++)
	{
		temp[i] = HistoryComp[i];
	}
	temp[numSellComp] = TempComp;
	if (HistoryComp != NULL && numSellAcces != 0)
	{
		delete[]HistoryComp;
	}
	numSellComp++;
	HistoryComp = temp;
}

void Manager::HistoryAcces(Accessories*& HistoryAcces, int& numSellAcces, Accessories TempAcces)
{
	Accessories* temp = new Accessories[numSellAcces + 1];
	for (int i = 0; i < numSellAcces; i++)
	{
		temp[i] = HistoryAcces[i];
	}
	temp[numSellAcces] = TempAcces;
	if (HistoryAcces != NULL && numSellAcces != 0)
	{
		delete[]HistoryAcces;
	}
	numSellAcces++;
	HistoryAcces = temp;
}

void Manager::FillManager()
{
	cout << "Введите свое имя: ";
	cin >> name;
	cout << "Введите свою фамилию: ";
	cin >> surname;
	cout << "Введите свое отчество: ";
	cin >> patrynomic;
	cin.ignore();
	cout << "Введите свою должность: ";
	cin.getline(position, 255);
	while (position[0] == '\0' || position[0] == ' ')
	{
		cout << "Введите свою должность: ";
		cin.getline(position, 255);
	}
	cout << "Введите свой номер телефона: ";
	cin.getline(phone,255);
	while (phone[0] == '\0' || phone[0] == ' ')
	{
		"Введите свой номер телефона: ";
		cin.getline(phone, 255);
	}
}

void Manager::Print()
{
	cout << "  Имя: " << name << endl;
	cout << "  Фамилия: " << surname << endl;
	cout << "  Отчество: " << patrynomic << endl;
	cout << "  Должность: " << position << endl;
	cout << "  Телефон: " << phone << endl;
}

void Store::AddComp(Computer*& Comps, int& sizeComp) 
{
	Computer* temp = new Computer[sizeComp + 1];

	temp[sizeComp].FillComp();
	if (temp[sizeComp].total == false)
	{
		delete[] temp;
	}
	else
	{
		for (int i = 0; i < sizeComp; i++)
		{
			temp[i].total = Comps[i].total;
			strcpy(temp[i].nameComp, Comps[i].nameComp);
			strcpy(temp[i].nameCPU, Comps[i].nameCPU);
			temp[i].countCore = Comps[i].countCore;
			strcpy(temp[i].nameMB, Comps[i].nameMB);
			strcpy(temp[i].soketCPU, Comps[i].soketCPU);
			strcpy(temp[i].nameGPU, Comps[i].nameGPU);
			temp[i].memoryGPU = Comps[i].memoryGPU;
			strcpy(temp[i].nameRAM, Comps[i].nameRAM);
			temp[i].OneModulMemory = Comps[i].OneModulMemory;
			temp[i].countModule = Comps[i].countModule;
			strcpy(temp[i].nameBP, Comps[i].nameBP);
			temp[i].power = Comps[i].power;
			strcpy(temp[i].nameSSD, Comps[i].nameSSD);
			temp[i].memorySSD = Comps[i].memorySSD;
			strcpy(temp[i].nameHDD, Comps[i].nameHDD);
			temp[i].memoryHDD = Comps[i].memoryHDD;
			temp[i].Price = Comps[i].Price;
			//temp[i] = Comps[i];
		}

		if (Comps != NULL && sizeComp != 0)
		{
			delete[]Comps;
		}
		sizeComp++;
		Comps = temp;
	}
}

void Store::DelComp(Computer*& Comps, int& sizeComp, int pos)
{
	money += Comps[pos].Price;
	if (sizeComp - 1 == 0)
	{
		delete[]Comps;
		sizeComp--;
		return;
	}
	Computer* temp = new Computer[sizeComp - 1];
	for (int i = 0; i < sizeComp; i++)
	{
		if (i > pos)
		{
			temp[i-1].total = Comps[i].total;
			strcpy(temp[i-1].nameComp, Comps[i].nameComp);
			strcpy(temp[i-1].nameCPU, Comps[i].nameCPU);
			temp[i-1].countCore = Comps[i].countCore;
			strcpy(temp[i-1].nameMB, Comps[i].nameMB);
			strcpy(temp[i-1].soketCPU, Comps[i].soketCPU);
			strcpy(temp[i-1].nameGPU, Comps[i].nameGPU);
			temp[i-1].memoryGPU = Comps[i].memoryGPU;
			strcpy(temp[i-1].nameRAM, Comps[i].nameRAM);
			temp[i-1].OneModulMemory = Comps[i].OneModulMemory;
			temp[i-1].countModule = Comps[i].countModule;
			strcpy(temp[i-1].nameBP, Comps[i].nameBP);
			temp[i-1].power = Comps[i].power;
			strcpy(temp[i-1].nameSSD, Comps[i].nameSSD);
			temp[i-1].memorySSD = Comps[i].memorySSD;
			strcpy(temp[i-1].nameHDD, Comps[i].nameHDD);
			temp[i-1].memoryHDD = Comps[i].memoryHDD;
			temp[i-1].Price = Comps[i].Price;
			//temp[i - 1] = Comps[i];
		}
		else if (i < pos)
		{
			temp[i].total = Comps[i].total;
			strcpy(temp[i].nameComp, Comps[i].nameComp);
			strcpy(temp[i].nameCPU, Comps[i].nameCPU);
			temp[i].countCore = Comps[i].countCore;
			strcpy(temp[i].nameMB, Comps[i].nameMB);
			strcpy(temp[i].soketCPU, Comps[i].soketCPU);
			strcpy(temp[i].nameGPU, Comps[i].nameGPU);
			temp[i].memoryGPU = Comps[i].memoryGPU;
			strcpy(temp[i].nameRAM, Comps[i].nameRAM);
			temp[i].OneModulMemory = Comps[i].OneModulMemory;
			temp[i].countModule = Comps[i].countModule;
			strcpy(temp[i].nameBP, Comps[i].nameBP);
			temp[i].power = Comps[i].power;
			strcpy(temp[i].nameSSD, Comps[i].nameSSD);
			temp[i].memorySSD = Comps[i].memorySSD;
			strcpy(temp[i].nameHDD, Comps[i].nameHDD);
			temp[i].memoryHDD = Comps[i].memoryHDD;
			temp[i].Price = Comps[i].Price;
		}
	}
	if (Comps != NULL && sizeComp != 0)
	{
		delete[]Comps;
	}
	sizeComp--;
	Comps = temp;
}

void Store::AddAcces(Accessories*& Acces, int& sizeAccess)
{
	Accessories* temp = new Accessories[sizeAccess + 1];
	for (int i = 0; i < sizeAccess; i++)
	{
		temp[i] = Acces[i];
	}
	temp[sizeAccess].Fill();
	if (Acces != NULL && sizeAccess != 0)
	{
		delete[] Acces;
	}
	sizeAccess++;
	Acces = temp;
}

void Store::DelAcces(Accessories*& Acces, int& sizeAccess, int pos)
{
	money += Acces[pos].Price;
	if (sizeAccess - 1 == 0)
	{
		delete[]Acces;
		Acces = NULL;
		sizeAccess--;
		return;
	}
	Accessories* temp = new Accessories[sizeAccess - 1];
	for (int i = 0; i < sizeAccess; i++)
	{
		if (i < pos)
		{
			temp[i] = Acces[i];
		}
		else if (i > pos)
		{
			temp[i - 1] = Acces[i];
		}
	}
	if (Acces != NULL && sizeAccess != 0)
	{
		delete[] Acces;
	}
	sizeAccess--;
	Acces = temp;
}

void Store::ShowAcces(Accessories* Acces, int sizeAccess)
{
	if (sizeAccess == 0)
	{
		cout << "Комплектующих нет в продаже" << endl;
		return;
	}
	for (int i = 0; i < sizeAccess; i++)
	{
		cout << " " << i + 1 << ". --------------------------------->" << endl;
		Acces[i].Print();
		cout << "----------------------------------->>\n" << endl;
	}
}

void Store::ShowComps(Computer* Comps, int sizeComps)
{
	if (sizeComps == 0)
	{
		cout << "Компьютеров нет в продаже" << endl;
		return;
	}
	for (int i = 0; i < sizeComps; i++)
	{
		cout << " " << i + 1 << ". --------------------------------->" << endl;
		Comps[i].PrintComp();
		cout << "------------------------------------->>\n" << endl;
	}
}

void MonthlySales::AddMonthSellAcces(Accessories Temp)
{
	Accessories* temp = new Accessories[sizeSellAcces + 1];
	for (int i = 0; i < sizeSellAcces; i++)
	{
		temp[i] = MonthSellAcces[i];
	}
	temp[sizeSellAcces] = Temp;
	if (sizeSellAcces != 0 && MonthSellAcces != NULL)
	{
		delete[]MonthSellAcces;
	}
	sizeSellAcces++;
	MonthSellAcces = temp;
}

void MonthlySales::ShowMonthSeles()
{
	cout << "<<-------------<< ПРОДАНО >>--------------->>" << endl;
	if (sizeSellAcces == 0)
	{
		cout << "      Проданые комплектующие     " << endl;
		cout << "---------------------------------" << endl;
		cout << "    Нету проданых комплектующих  \n\n" << endl;
	}
	else
	{
		cout << "      Проданые комплектующие     " << endl;
		for (int i = 0; i < sizeSellAcces; i++)
		{
			cout << "---------------------------------" << endl;
			MonthSellAcces[i].Print();
			cout << "_________________________________" << endl;
		}
	}
	cout << "<<-------------<< ПРОДАНО >>--------------->>" << endl;
	if (sizeSellComp == 0)
	{
		cout << "      Проданые компьютеры     " << endl;
		cout << "---------------------------------" << endl;
		cout << "    Нету проданых компьютеров  \n\n" << endl;
	}
	else
	{
		cout << "      Проданые компьютеры     " << endl;
		for (int i = 0; i < sizeSellComp; i++)
		{
			cout << "---------------------------------" << endl;
			MonthSellComp[i].PrintComp();
			cout << "_________________________________" << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

void MonthlySales::DelAllArr()
{
	if (sizeSellAcces != 0)
	{
		delete[]MonthSellAcces;
	}
	if (sizeSellComp != 0)
	{
		delete[]MonthSellComp;
	}
	sizeSellAcces = 0;
	sizeSellComp = 0;
}

void MonthlySales::AddMonthSellComp(Computer Temp)
{
	Computer* temp = new Computer[sizeSellComp + 1];
	for (int i = 0; i < sizeSellComp; i++)
	{
		temp[i] = MonthSellComp[i];
	}
	temp[sizeSellComp] = Temp;
	if (sizeSellComp != 0 && MonthSellComp != NULL)
	{
		delete[]MonthSellComp;
	}
	sizeSellComp++;
	MonthSellComp = temp;
}

void AddManager(Manager*& Managers, int& sizeManager)
{
	Manager CheckManager;
	CheckManager.FillManager();
	if (ControleCloneManager(Managers,sizeManager,CheckManager) == 1)
	{
		cout << "Такой менеджер уже существует!" << endl;
		system("pause");
		return;
	}
	else 
	{
		Manager* temp = new Manager[sizeManager + 1];
		for (int i = 0; i < sizeManager; i++)
		{
			temp[i] = Managers[i];
		}
		temp[sizeManager] = CheckManager;
		if (Managers != NULL && sizeManager != 0)
		{
			delete[]Managers;
		}
		sizeManager++;
		Managers = temp;
		cout << "Операция успешна!" << endl;
		system("pause");
	}
}

void DelManager(Manager*& Managers, int& sizeManager)
{
	if (sizeManager - 1 == 0)
	{
		delete[]Managers;
		Managers = NULL;
		sizeManager--;
		return;
	}
	Manager* temp = new Manager[sizeManager - 1];
	for (int i = 0; i < sizeManager; i++)
	{
		if (Managers[i].Fired_or_Not_Fired == true)
		{
			for (int j = i+1; j < sizeManager; j++)
			{
				temp[j - 1] = Managers[j];
			}
			break;
		}
		temp[i] = Managers[i];
	}
	if (Managers != NULL && sizeManager != 0)
	{
		delete[]Managers;
	}
	sizeManager--;
	Managers = temp;
	cout << "Операция успешна!" << endl;
	system("pause");
}

void SaveItempInFile(Store StorageOne, Manager* Managers, int sizeManager, MonthlySales Sales)
{
	//-----------------------------------------------------------------
	char pathFile[19]{ 'S','a','v','e','s','/','/','s','t','o','r','a','g','e','.','b','i','n','\0' };//путь к папке и файлу
	if (system("cd Saves") != 0)
	{
		system("mkdir Saves");//создание новой папки
	}
	//
	FILE* file;
	file = fopen(pathFile, "wb");
	if (file == NULL)
	{
		cout << "Error open file!" << endl;
		return;
	}
	//запись хранилищя
	fwrite(&StorageOne, sizeof(Store), 1, file);
	fwrite(&StorageOne.sizeAccess, sizeof(StorageOne.sizeAccess), 1, file);
	fwrite(&StorageOne.sizeComputers, sizeof(StorageOne.sizeComputers), 1, file);
	for (int i = 0; i < StorageOne.sizeAccess; i++)
	{
		fwrite(&StorageOne.Access[i], sizeof(StorageOne.Access[i]), 1, file);
	}
	for (int i = 0; i < StorageOne.sizeComputers; i++)
	{
		fwrite(&StorageOne.Computers[i], sizeof(StorageOne.Computers[i]), 1, file);
	}
	fclose(file);
	file = NULL;
	char pathFile2[20]{ 'S','a','v','e','s','/','/','m','a','n','a','g','e','r','s','.','b','i','n','\0' };//путь к папке и файлу
	file = fopen(pathFile2, "wb");
	if (file == NULL)
	{
		cout << "Error open file!" << endl;
		return;
	}
	//запись менеджеров
	fwrite(&sizeManager, sizeof(sizeManager),1,file);
	for (int i = 0; i < sizeManager; i++)
	{
		fwrite(&Managers[i], sizeof(Managers[i]),1,file);
		fwrite(&Managers[i].numSellComp, sizeof(Managers[i].numSellComp),1,file);
		fwrite((char*)&Managers[i].numSellAcces, sizeof(Managers[i].numSellAcces),1,file);
		for (int j = 0; j < Managers[i].numSellComp; j++)
		{
			fwrite(&Managers[i].HistoryComps[j], sizeof(Managers[i].HistoryComps[j]),1,file);
		}
		for (int j = 0; j < Managers[i].numSellAcces; j++)
		{
			fwrite(&Managers[i].HistoryAccess[j], sizeof(Managers[i].HistoryAccess[j]),1,file);
		}
	}
	fclose(file);
	file = NULL;
	char pathFile3[25]{ 'S','a','v','e','s','/','/','m','o','n','t','h','l','y',' ','s','a','l','e','s','.','b','i','n','\0' };//путь к папке и файлу
	file = fopen(pathFile3, "wb");
	if (file == NULL)
	{
		cout << "Error open file!" << endl;
		return;
	}
	//запись истории продаж
	fwrite(&Sales, sizeof(Sales),1,file);
	fwrite((char*)&Sales.sizeSellAcces, sizeof(Sales.sizeSellAcces),1,file);
	fwrite((char*)&Sales.sizeSellComp, sizeof(Sales.sizeSellComp),1,file);
	for (int i = 0; i < Sales.sizeSellAcces; i++)
	{
		fwrite(&Sales.MonthSellAcces[i], sizeof(Sales.MonthSellAcces[i]),1,file);
	}
	for (int i = 0; i < Sales.sizeSellComp; i++)
	{
		fwrite(&Sales.MonthSellComp[i], sizeof(Sales.MonthSellComp[i]), 1, file);
	}
	fclose(file);
	file = NULL;
}

void ReadItemOfFile(Store& StorageOne, Manager*& Managers, int& sizeManager, MonthlySales& Sales)
{
	//-----------------------------------------------------------------
	char pathFile[19]{ 'S','a','v','e','s','/','/','s','t','o','r','a','g','e','.','b','i','n','\0' };//путь к папке и файлу
	if (system("cd Saves") != 0)
	{
		system("mkdir Saves");//создание новой папки
	}
	//
	FILE* file;
	file = fopen(pathFile, "rb");
	if (file == NULL)
	{
		cout << "Error open file!" << endl;
		return;
	}
	//чтение хранилищя
	fread(&StorageOne, sizeof(Store), 1, file);
	fread(&StorageOne.sizeAccess, sizeof(StorageOne.sizeAccess), 1, file);
	fread(&StorageOne.sizeComputers, sizeof(StorageOne.sizeComputers), 1, file);
	if (StorageOne.sizeAccess > 0)
		StorageOne.Access = new Accessories[StorageOne.sizeAccess];
	if (StorageOne.sizeComputers > 0)
		StorageOne.Computers = new Computer[StorageOne.sizeComputers];
	for (int i = 0; i < StorageOne.sizeAccess; i++)
	{
		fread(&StorageOne.Access[i], sizeof(StorageOne.Access[i]), 1, file);
	}
	for (int i = 0; i < StorageOne.sizeComputers; i++)
	{
		fread(&StorageOne.Computers[i], sizeof(StorageOne.Computers[i]), 1, file);
	}
	fclose(file);
	file = NULL;
	char pathFile2[20]{ 'S','a','v','e','s','/','/','m','a','n','a','g','e','r','s','.','b','i','n','\0' };//путь к папке и файлу
	file = fopen(pathFile2, "rb");
	if (file == NULL)
	{
		cout << "Error open file!" << endl;
		return;
	}
	//чтение менеджеров
	fread(&sizeManager, sizeof(sizeManager), 1, file);
	if (sizeManager > 0)
		Managers = new Manager[sizeManager];
	for (int i = 0; i < sizeManager; i++)
	{
		fread(&Managers[i], sizeof(Managers[i]), 1, file);
		fread(&Managers[i].numSellComp, sizeof(Managers[i].numSellComp), 1, file);
		fread((char*)&Managers[i].numSellAcces, sizeof(Managers[i].numSellAcces), 1, file);
		if (Managers[i].numSellAcces > 0)
			Managers[i].HistoryAccess = new Accessories[Managers[i].numSellAcces];
		if (Managers[i].numSellComp > 0)
			Managers[i].HistoryComps = new Computer[Managers[i].numSellComp];
		for (int j = 0; j < Managers[i].numSellComp; j++)
		{
			fread(&Managers[i].HistoryComps[j], sizeof(Managers[i].HistoryComps[j]), 1, file);
		}
		for (int j = 0; j < Managers[i].numSellAcces; j++)
		{
			fread(&Managers[i].HistoryAccess[j], sizeof(Managers[i].HistoryAccess[j]), 1, file);
		}
	}
	char pathFile3[25]{ 'S','a','v','e','s','/','/','m','o','n','t','h','l','y',' ','s','a','l','e','s','.','b','i','n','\0' };//путь к папке и файлу
	file = fopen(pathFile3, "rb");
	if (file == NULL)
	{
		cout << "Error open file!" << endl;
		return;
	}
	//чтение истории продаж
	fread(&Sales, sizeof(Sales), 1, file);
	fread((char*)&Sales.sizeSellAcces, sizeof(Sales.sizeSellAcces), 1, file);
	fread((char*)&Sales.sizeSellComp, sizeof(Sales.sizeSellComp), 1, file);
	if (Sales.sizeSellAcces > 0)
		Sales.MonthSellAcces = new Accessories[Sales.sizeSellAcces];
	if (Sales.sizeSellComp > 0)
		Sales.MonthSellComp = new Computer[Sales.sizeSellComp];
	for (int i = 0; i < Sales.sizeSellAcces; i++)
	{
		fread(&Sales.MonthSellAcces[i], sizeof(Sales.MonthSellAcces[i]), 1, file);
	}
	for (int i = 0; i < Sales.sizeSellComp; i++)
	{
		fread(&Sales.MonthSellComp[i], sizeof(Sales.MonthSellComp[i]), 1, file);
	}
	fclose(file);
	file = NULL;
}

void CreatePrice_List(Store StorageOne, Date CurrentDate)
{
	//создание имени файла
	char nameFile[255]{ 'P','r','i','c','e','-','l','i','s','t',' ' };
	char txt[7]{ '.','t','x','t','\0' };
	char temp1[25]{};
	char temp2[25]{};
	char temp3[25]{};
	_itoa(CurrentDate.day, temp1, 10);
	_itoa(CurrentDate.month, temp2, 10);
	_itoa(CurrentDate.year, temp3, 10);
	strcat(nameFile, temp1);
	nameFile[strlen(nameFile)] = '.';
	strcat(nameFile, temp2);
	nameFile[strlen(nameFile)] = '.';
	strcat(nameFile, temp3);
	strcat(nameFile, txt);
	//-----------------------------------------------------------------
	char* pathFile = new char[strlen(nameFile)+9]{'P','r','i','c','e','s','/','/'};//путь к папке и файлу
	if (system("cd Prices") != 0)
	{
		system("mkdir Prices");//создание новой папки
		strcat(pathFile, nameFile);
	}
	else
	{
		strcat(pathFile, nameFile);
	}
	//запись прайс-листа
	FILE* fileWrite;
	fileWrite = fopen(pathFile, "w");
	if (fileWrite == NULL)
	{
		return;
	}
	fprintf(fileWrite, "%s\n", "<------------    Комплектующие    ------------->");
	if (StorageOne.sizeAccess == 0)
	{
		fprintf(fileWrite, "%s\n", "        Коплектующих нет в продаже");
		fprintf(fileWrite, "%s\n", "--------------------------------------------->");
	}
	else
	{
		for (int i = 0; i < StorageOne.sizeAccess; i++)
		{
			fprintf(fileWrite, " %d%s %s\n", i+1,".", "----------------------------->");
			fprintf(fileWrite, " %s %s\n","Название:",StorageOne.Access[i].nameAcces);
			fprintf(fileWrite, " %s %s\n","Производитель:",StorageOne.Access[i].manufacturer);
			fprintf(fileWrite, " %s %s\n","Особенности:",StorageOne.Access[i].features);
			fprintf(fileWrite, " %s %f\n","Цена:",StorageOne.Access[i].Price);
			fprintf(fileWrite, " %s\n", "_________________________________");
		}
	}
	fprintf(fileWrite, "\n%s\n", "<------------    Компьютеры    ------------->");
	if (StorageOne.sizeComputers == 0)
	{
		fprintf(fileWrite, "%s\n", "         Компьютеров нет в продаже");
		fprintf(fileWrite, "%s\n", "-------------------------------------------->");
	}
	else
	{
		for (int i = 0; i < StorageOne.sizeComputers; i++)
		{
			fprintf(fileWrite, " %d%s %s\n", i + 1, ".", "------------------------------------->");
			fprintf(fileWrite, " %s %s\n", "Название:", StorageOne.Computers[i].nameComp);
			fprintf(fileWrite, "  %s\n", "<---  Конфигурация   --->");
			if (IsZero(StorageOne.Computers[i].nameCPU) == 1 || StorageOne.Computers[i].countCore == 0)
				fprintf(fileWrite, "  %s %s\n", "CPU:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s\n", "CPU:", StorageOne.Computers[i].nameCPU, StorageOne.Computers[i].countCore, "- core");
			if (IsZero(StorageOne.Computers[i].nameMB) == 1 || IsZero(StorageOne.Computers[i].soketCPU) == 1)
				fprintf(fileWrite, "  %s %s\n", "MotherBoard:", " -");
			else
				fprintf(fileWrite, "  %s %s %s %s\n", "MotherBoard:", StorageOne.Computers[i].nameMB, "soket:", StorageOne.Computers[i].soketCPU);
			if (IsZero(StorageOne.Computers[i].nameRAM) == 1 || StorageOne.Computers[i].OneModulMemory == 0 || StorageOne.Computers[i].countModule == 0)
				fprintf(fileWrite, "  %s %s\n", "RAM:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s %s %d\n", "RAM:", StorageOne.Computers[i].nameRAM, StorageOne.Computers[i].OneModulMemory, "MB", "X", StorageOne.Computers[i].countModule);
			if (IsZero(StorageOne.Computers[i].nameGPU) == 1 || StorageOne.Computers[i].memoryGPU == 0)
				fprintf(fileWrite, "  %s %s\n", "GPU:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s\n", "GPU:", StorageOne.Computers[i].nameGPU, StorageOne.Computers[i].memoryGPU, "MB");
			if (IsZero(StorageOne.Computers[i].nameBP) == 1 || StorageOne.Computers[i].power == 0)
				fprintf(fileWrite, "  %s %s\n", "Блок питания:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s\n", "Блок питания:", StorageOne.Computers[i].nameBP, StorageOne.Computers[i].power, "W");
			if (IsZero(StorageOne.Computers[i].nameSSD) == 1 || StorageOne.Computers[i].memorySSD == 0)
				fprintf(fileWrite, "  %s %s\n", "SSD:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s\n", "SSD:", StorageOne.Computers[i].nameSSD, StorageOne.Computers[i].memorySSD, "MB");
			if (IsZero(StorageOne.Computers[i].nameHDD) == 1 || StorageOne.Computers[i].memoryHDD == 0)
				fprintf(fileWrite, "  %s %s\n", "HDD:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s\n", "HDD:", StorageOne.Computers[i].nameHDD, StorageOne.Computers[i].memoryHDD, "MB");

			fprintf(fileWrite, " %s %f\n", "Цена:", StorageOne.Computers[i].Price);
		}
	}
	fclose(fileWrite);
	fileWrite = NULL;
}

void CreateMonthlySales(MonthlySales Sales, Date CurrentDate)
{
	
	//создание имени файла
	char nameFile[255]{ 'S','a','l','e','s',' ','p','e','r',' ','m','o','n','t','h',' ' };
	char txt[7]{ '.','t','x','t','\0' };
	char temp1[25]{};
	char temp2[25]{};
	char temp3[25]{};
	_itoa(CurrentDate.day, temp1, 10);
	_itoa(CurrentDate.month, temp2, 10);
	_itoa(CurrentDate.year, temp3, 10);
	strcat(nameFile, temp1);
	nameFile[strlen(nameFile)] = '.';
	strcat(nameFile, temp2);
	nameFile[strlen(nameFile)] = '.';
	strcat(nameFile, temp3);
	strcat(nameFile, txt);
	//-----------------------------------------------------------------
	char* pathFile = new char[strlen(nameFile) + 8]{ 'S','a','l','e','s','/','/' };//путь к папке и файлу
	if (system("cd Sales") != 0)
	{
		system("mkdir Sales");//создание новой папки
		strcat(pathFile, nameFile);
	}
	else
	{
		strcat(pathFile, nameFile);
	}
	//запись прайс-листа
	FILE* fileWrite;
	fileWrite = fopen(pathFile, "w");
	if (fileWrite == NULL)
	{
		return;
	}
	fprintf(fileWrite, "%s\n", "<------------    Комплектующие    ------------->");
	if (Sales.sizeSellAcces == 0)
	{
		fprintf(fileWrite, "%s\n", "        Нету проданих комплектующих");
		fprintf(fileWrite, "%s\n", "--------------------------------------------->");
	}
	else
	{
		for (int i = 0; i < Sales.sizeSellAcces; i++)
		{
			fprintf(fileWrite, " %d%s %s\n", i + 1, ".", "----------------------------->");
			fprintf(fileWrite, " %s %s\n", "Название:", Sales.MonthSellAcces[i].nameAcces);
			fprintf(fileWrite, " %s %s\n", "Производитель:", Sales.MonthSellAcces[i].manufacturer);
			fprintf(fileWrite, " %s %s\n", "Особенности:", Sales.MonthSellAcces[i].features);
			fprintf(fileWrite, " %s %f\n", "Цена:", Sales.MonthSellAcces[i].Price);
			fprintf(fileWrite, " %s\n", "_________________________________");
		}
	}
	fprintf(fileWrite, "\n%s\n", "<------------    Компьютеры    ------------->");
	if (Sales.sizeSellComp == 0)
	{
		fprintf(fileWrite, "%s\n", "         Нету проданих компьютеров");
		fprintf(fileWrite, "%s\n", "-------------------------------------------->");
	}
	else
	{
		for (int i = 0; i < Sales.sizeSellComp; i++)
		{
			fprintf(fileWrite, " %d%s %s\n", i + 1, ".", "------------------------------------->");
			fprintf(fileWrite, " %s %s\n", "Название:", Sales.MonthSellComp[i].nameComp);
			fprintf(fileWrite, "  %s\n", "<---  Конфигурация   --->");
			if (IsZero(Sales.MonthSellComp[i].nameCPU) == 1 || Sales.MonthSellComp[i].countCore == 0)
				fprintf(fileWrite, "  %s %s\n", "CPU:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s\n", "CPU:", Sales.MonthSellComp[i].nameCPU, Sales.MonthSellComp[i].countCore, "- core");
			if (IsZero(Sales.MonthSellComp[i].nameMB) == 1 || IsZero(Sales.MonthSellComp[i].soketCPU) == 1)
				fprintf(fileWrite, "  %s %s\n", "MotherBoard:", " -");
			else
				fprintf(fileWrite, "  %s %s %s %s\n", "MotherBoard:", Sales.MonthSellComp[i].nameMB, "soket:", Sales.MonthSellComp[i].soketCPU);
			if (IsZero(Sales.MonthSellComp[i].nameRAM) == 1 || Sales.MonthSellComp[i].OneModulMemory == 0 || Sales.MonthSellComp[i].countModule == 0)
				fprintf(fileWrite, "  %s %s\n", "RAM:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s %s %d\n", "RAM:", Sales.MonthSellComp[i].nameRAM, Sales.MonthSellComp[i].OneModulMemory, "MB", "X", Sales.MonthSellComp[i].countModule);
			if (IsZero(Sales.MonthSellComp[i].nameGPU) == 1 || Sales.MonthSellComp[i].memoryGPU == 0)
				fprintf(fileWrite, "  %s %s\n", "GPU:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s\n", "GPU:", Sales.MonthSellComp[i].nameGPU, Sales.MonthSellComp[i].memoryGPU, "MB");
			if (IsZero(Sales.MonthSellComp[i].nameBP) == 1 || Sales.MonthSellComp[i].power == 0)
				fprintf(fileWrite, "  %s %s\n", "Блок питания:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s\n", "Блок питания:", Sales.MonthSellComp[i].nameBP, Sales.MonthSellComp[i].power, "W");
			if (IsZero(Sales.MonthSellComp[i].nameSSD) == 1 || Sales.MonthSellComp[i].memorySSD == 0)
				fprintf(fileWrite, "  %s %s\n", "SSD:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s\n", "SSD:", Sales.MonthSellComp[i].nameSSD, Sales.MonthSellComp[i].memorySSD, "MB");
			if (IsZero(Sales.MonthSellComp[i].nameHDD) == 1 || Sales.MonthSellComp[i].memoryHDD == 0)
				fprintf(fileWrite, "  %s %s\n", "HDD:", " -");
			else
				fprintf(fileWrite, "  %s %s %d %s\n", "HDD:", Sales.MonthSellComp[i].nameHDD, Sales.MonthSellComp[i].memoryHDD, "MB");

			fprintf(fileWrite, " %s %f\n", "Цена:", Sales.MonthSellComp[i].Price);
		}
	}
	double AllMoneyAccess = 0;
	double AllMoneyComp = 0;
	int countSales = 0;
	for (int i = 0; i < Sales.sizeSellAcces; i++)
	{
		AllMoneyAccess += Sales.MonthSellAcces[i].Price;
	}
	for (int i = 0; i < Sales.sizeSellComp; i++)
	{
		AllMoneyComp += Sales.MonthSellComp[i].Price;
	}
	fprintf(fileWrite, "  %s %f\n", "Заработанные деньги с компьютеров:", AllMoneyComp);
	fprintf(fileWrite, "  %s %f\n", "Заработанные деньги с комплектующих:", AllMoneyAccess);
	fprintf(fileWrite, "  %s %f\n", "Заработанные деньги:", AllMoneyAccess + AllMoneyComp);
	fprintf(fileWrite, "  %s %d\n", "Проданно товаров:", Sales.sizeSellAcces + Sales.sizeSellComp);
	fclose(fileWrite);
	fileWrite = NULL;
}

void SortShow(Manager* Managers, int sizeManager, bool sortFlag_bool)
{
	// 1 - возростание 0 - убывание

	char** mass = new char* [sizeManager];

	for (int i = 0; i < sizeManager; i++) {
		mass[i] = new char[200]{};
		strcpy(mass[i], Managers[i].name);
	}
	for (int i = 0; i < sizeManager; i++) {
		for (int j = 0; j < sizeManager; j++)
		{
			if (sortFlag_bool == 0) {
				if (strcmp(mass[i], mass[j]) > 0) {
					char* tmp = mass[i];
					mass[i] = mass[j];
					mass[j] = tmp;
				}
			}
			if (sortFlag_bool == 1) {
				if (strcmp(mass[i], mass[j]) < 0) {
					char* tmp = mass[i];
					mass[i] = mass[j];
					mass[j] = tmp;
				}
			}
		}
	}
	//построение позиций
	int l = 0;
	int* pos = new int[sizeManager];
	for (int i = 0; i < sizeManager; i++)
	{
		pos[i] = -1;
	}
	bool check = 0;
	for (int i = 0; i < sizeManager; i++)
	{
		for (int j = 0; j < sizeManager; j++)
		{
			if (strcmp(Managers[j].name,mass[i]) == 0)
			{
				//проверка совпадений
				for (int p = 0; p < sizeManager; p++)
				{
					if (pos[p] == j)
					{
						check = 1;
						break;
					}
					else
						check = 0;
				}
				if (check != 1)
				{
					pos[l] = j;
					l++;
				}
			}
		}
	}
	//вывод позиций
	for (int i = 0; i < sizeManager; i++)
	{
		for (int j = 0; j < sizeManager; j++)
		{
			if (pos[i] == j) {
				cout << j + 1 << ". ____________________" << endl;
				Managers[j].Print();
				cout << "----------------------" << endl;
				break;
			}
		}
	}
}

void SortShow_A(Store StorageOne,bool sortFlag_bool)
{
	// 1 - возростание 0 - убывание

	double* sort = new double [StorageOne.sizeAccess];
	for (int i = 0; i < StorageOne.sizeAccess; i++)
	{
		sort[i] = StorageOne.Access[i].Price;
	}
	//sort
	for (int repeat_counter = 0; repeat_counter < StorageOne.sizeAccess; repeat_counter++)
	{
		double temp = sort[0]; // временная переменная для хранения значения перестановки
		for (int element_counter = repeat_counter + 1; element_counter < StorageOne.sizeAccess; element_counter++)
		{
			if (sortFlag_bool == 1) {
				if (sort[repeat_counter] > sort[element_counter])
				{
					temp = sort[repeat_counter];
					sort[repeat_counter] = sort[element_counter];
					sort[element_counter] = temp;
				}
			}
			else if (sortFlag_bool == 0)
			{
				if (sort[repeat_counter] < sort[element_counter])
				{
					temp = sort[repeat_counter];
					sort[repeat_counter] = sort[element_counter];
					sort[element_counter] = temp;
				}
			}
		}
	}
	//построение позиций
	int l = 0;
	int* pos = new int[StorageOne.sizeAccess];
	for (int i = 0; i < StorageOne.sizeAccess; i++)
	{
		pos[i] = -1;
	}
	bool check = 0;
	for (int i = 0; i < StorageOne.sizeAccess; i++)
	{
		for (int j = 0; j < StorageOne.sizeAccess; j++)
		{
			if (StorageOne.Access[j].Price == sort[i])
			{
				//проверка совпадений
				for (int p = 0; p < StorageOne.sizeAccess; p++)
				{
					if (pos[p] == j)
					{
						check = 1;
						break;
					}
					else
						check = 0;
				}
				if (check != 1)
				{
					pos[l] = j;
					l++;
				}
			}
		}
	}
	//print position
	for (int i = 0; i < StorageOne.sizeAccess; i++)
	{
		for (int j = 0; j < StorageOne.sizeAccess; j++)
		{
			if (pos[i] == j)
			{
				cout << j + 1 << ". _________________________" << endl;
				StorageOne.Access[j].Print();
				cout << "--------------------------" << endl;
			}
		}
	}
	delete[]pos;
	delete[]sort;
}

void SortShow_C(Store StorageOne, bool sortFlag_bool)
{
	// 1 - возростание 0 - убывание

	double* sort = new double[StorageOne.sizeComputers]{};
	for (int i = 0; i < StorageOne.sizeComputers; i++)
	{
		sort[i] = StorageOne.Computers[i].Price;
	}
	for (int repeat_counter = 0; repeat_counter < StorageOne.sizeComputers; repeat_counter++)
	{
		double temp = sort[0]; // временная переменная для хранения значения перестановки
		for (int element_counter = repeat_counter + 1; element_counter < StorageOne.sizeComputers; element_counter++)
		{
			if (sortFlag_bool == 1) {
				if (sort[repeat_counter] > sort[element_counter])
				{
					temp = sort[repeat_counter];
					sort[repeat_counter] = sort[element_counter];
					sort[element_counter] = temp;
				}
			}
			else if (sortFlag_bool == 0)
			{
				if (sort[repeat_counter] < sort[element_counter])
				{
					temp = sort[repeat_counter];
					sort[repeat_counter] = sort[element_counter];
					sort[element_counter] = temp;
				}
			}
		}
	}
	//построение позиций
	int l = 0;
	int* pos = new int[StorageOne.sizeComputers];
	for (int i = 0; i < StorageOne.sizeComputers; i++)
	{
		pos[i] = -1;
	}
	bool check = 0;
	for (int i = 0; i < StorageOne.sizeComputers; i++)
	{
		for (int j = 0; j < StorageOne.sizeComputers; j++)
		{
			if (StorageOne.Computers[j].Price == sort[i])
			{
				//проверка совпадений
				for (int p = 0; p < StorageOne.sizeComputers; p++)
				{
					if (pos[p] == j)
					{
						check = 1;
						break;
					}
					else
						check = 0;
				}
				if (check != 1)
				{
					pos[l] = j;
					l++;
				}
			}
		}
	}
	//вывод позиций
	for (int i = 0; i < StorageOne.sizeComputers; i++)
	{
		for (int j = 0; j < StorageOne.sizeComputers; j++)
		{
			if (pos[i] == j)
			{
				cout << j+1 << ". _________________________" << endl;
				StorageOne.Computers[j].PrintComp();
				cout << "--------------------------" << endl;
				break;
			}
		}
	}
}

bool ControleCloneManager(Manager*& Managers, int& sizeManager, Manager CheckManager)
{
	for (int i = 0; i < sizeManager; i++)
	{
		if (strcmp(Managers[i].name, CheckManager.name) == 0)
		{
			if (strcmp(Managers[i].surname, CheckManager.surname) == 0) 
			{
				if (strcmp(Managers[i].patrynomic, CheckManager.patrynomic) == 0) 
				{
					if (strcmp(Managers[i].position, CheckManager.position) == 0) 
					{
						if (strcmp(Managers[i].phone, CheckManager.phone) == 0) 
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

void ControlEmptyComps(Store& StorageOne)
{
	bool type = false;
	int pos = 0;
	bool flag = true;
	int i = 0;
	do
	{
		for (; i < StorageOne.sizeComputers; i++)
		{
			if (IsZero(StorageOne.Computers[i].nameCPU) == 1 || StorageOne.Computers[i].countCore == 0) {
				type = true;
			}
			else {
				break;
			}
			if (IsZero(StorageOne.Computers[i].nameMB) == 1 || IsZero(StorageOne.Computers[i].soketCPU) == 1) {
				type = true;
			}
			else {
				break;
			}
			if (IsZero(StorageOne.Computers[i].nameGPU) == 1 || StorageOne.Computers[i].memoryGPU == 0) {
				type = true;
			}
			else {
				break;
			}
			if (IsZero(StorageOne.Computers[i].nameRAM) == 1 || StorageOne.Computers[i].OneModulMemory == 0 || StorageOne.Computers[i].countModule == 0) {
				type = true;
			}
			else {
				break;
			}
			if (IsZero(StorageOne.Computers[i].nameBP) == 1 || StorageOne.Computers[i].power == 0) {
				type = true;
			}
			else {
				break;
			}
			if (IsZero(StorageOne.Computers[i].nameSSD) == 1 || StorageOne.Computers[i].memorySSD == 0) {
				type = true;
			}
			else {
				break;
			}
			if (IsZero(StorageOne.Computers[i].nameHDD) == 1 || StorageOne.Computers[i].memoryHDD == 0) {
				type = true;
			}
			else {
				break;
			}
			if (type == true) {
				StorageOne.DelComp(StorageOne.Computers, StorageOne.sizeComputers, i);
				i--;
			}
			if (i == StorageOne.sizeComputers - 1)
				flag = false;
		}
		i++;
		if (i == StorageOne.sizeComputers || StorageOne.sizeComputers == 0)
			flag = false;
	} while (flag);
}

void NullProgram(Store& StorageOne, Date& CurrentDate, Date& prevDate, Date& nextDate,Manager*& Managers, int& sizeManager, MonthlySales& Sales)
{
	//DatesFill(CurrentDate, prevDate, nextDate);
	cout << "Обнуление даты" << endl;
	ResetDate(CurrentDate, prevDate, nextDate);
	cout << "Авто-заполнение даты" << endl;
	AutoFillDate(CurrentDate, prevDate, nextDate);
	DefaultFillDate(CurrentDate, prevDate, nextDate);
	StorageOne.money = 0;
	Clear(StorageOne, Managers, sizeManager,Sales);
}

void Clear(Store& StorageOne, Manager*& Managers, int& sizeManager, MonthlySales& Sales)
{
	//удаление масива комплектующих
	if (StorageOne.sizeAccess != 0)
		delete[]StorageOne.Access;
	StorageOne.sizeAccess = 0;
	//удаление масива компьютеров
	if (StorageOne.sizeComputers != 0)
		delete[]StorageOne.Computers;
	StorageOne.sizeComputers = 0;
	//удаление масива менеджеров
	for (int i = 0; i < sizeManager; i++)
	{
		delete[]Managers[i].HistoryAccess;
		delete[]Managers[i].HistoryComps;
		Managers[i].numSellAcces = 0;
		Managers[i].numSellComp = 0;
	}
	if (sizeManager > 0)
		delete[]Managers;
	sizeManager = 0;
	//удаление продаж за месяц
	if (Sales.sizeSellAcces != 0)
		delete[]Sales.MonthSellAcces;
	Sales.sizeSellAcces = 0;
	//удаление масива компьютеров
	if (Sales.sizeSellComp != 0)
		delete[]Sales.MonthSellComp;
	Sales.sizeSellComp = 0;
}