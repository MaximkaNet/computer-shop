#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>//для проверки нажатий клавиш
//#include <fstream>//для бинарного файла

using namespace std;

#define INFO cout << "\nДля изменения сортировка нажмите s(ENG) или S(ENG). Для выхода нажмите любую клавишу"

//команда
int Command(const char* buffer);
//проверка на правильность ввода пользователем числа 
void CorrectNum(int&);
//проверка на правильность ввода пользователем числа 
void CorrectNum(double&);
//перенос строки 
void LineBreak(const char* features);
//проверка на нули 
bool IsZero(const char* buffer);
//проверка нажатия кнопок
int HitButton();

//структура даты 
struct Date
{
	int year = 0;
	int month = 0;
	int day = 0;
};
//комплектующие 
struct Accessories
{
	char nameAcces[255]{};//название комплектующего
	char manufacturer[255]{};//производитель
	char features[255]{};//особенности комплектующего
	double Price = 0;
	//заполнение экземпляра комплектующего
	void Fill();
	//вывод на экран комплектующего
	void Print();
	//компактный вывод комплектующего
	void PrintAccesCompact();
};
//экземпляр компьютера 
struct Computer
{
	//fill or not fill
	bool total = false;

	char nameComp[100]{};
	//
	char nameCPU[100]{};
	int countCore = 0;//

	char nameMB[100]{};//
	char soketCPU[100]{};//

	char nameGPU[100]{};//
	int memoryGPU = 0;//

	char nameRAM[100]{};//
	int OneModulMemory = 0;//
	int countModule = 0;//

	char nameBP[100]{};//
	int power = 0;//

	char nameSSD[100]{};//
	int memorySSD = 0;//

	char nameHDD[100]{};//
	int memoryHDD = 0;//
	
	double Price = 0;
	//добавление нового компьютера
	void FillComp();
	//вывод компьютера на экран
	void PrintComp();
	//вывод компьютера на экран(компактно)
	void PrintCompCompact();
};
//продажи за месяц 
struct MonthlySales
{
	int sizeSellAcces = 0;
	int sizeSellComp = 0;
	Accessories* MonthSellAcces = nullptr;
	Computer* MonthSellComp = nullptr;
	//заполнение истории продаж компьютеров
	void AddMonthSellComp(Computer temp);
	//заполнение истории продаж комплектующих
	void AddMonthSellAcces(Accessories temp);
	//вывод продаж за месяц
	void ShowMonthSeles();
	//удаление всех масивов даных
	void DelAllArr();
};
//Storage 
struct Store
{
	//зароботаные деньги 
	double money = 0;

	int sizeAccess = 0;
	int sizeComputers = 0;

	Accessories* Access = nullptr;
	Computer* Computers = nullptr;

	//добавление нового экземпляра компьютера
	void AddComp(Computer*& Comps, int& sizeComp);
	//Удаление компьютера
	void DelComp(Computer*& Comps, int& sizeComp, int pos);
	//добавление нового комплектующего на продажу
	void AddAcces(Accessories*& Acces, int& sizeAccess);
	//удаляет комплектующие
	void DelAcces(Accessories*& Acces, int& sizeAccess, int pos);
	//вывод всех комплектующих
	void ShowAcces(Accessories* Acces, int sizeAccess);
	//вывод всех компьютеров
	void ShowComps(Computer* Comps, int sizeComps);
};
//менеджер
struct Manager
{
	bool Fired_or_Not_Fired = false;// Уволен/не уволен

	//---------- История продаж менеджера--------------
	int numSellComp = 0;
	int numSellAcces = 0;

	Computer* HistoryComps = nullptr;
	Accessories* HistoryAccess = nullptr;
	//------------------------------------------------------

	char name[255]{};
	char surname[255]{};
	char patrynomic[255]{};
	char position[255]{};//должность
	char phone[255]{};
	//добавление в историю проданого компьютера
	void HistoryComp(Computer*& HistoryComp, int& numSellComp, Computer TempComp);
	//добавление в историю проданого комплектующего
	void HistoryAcces(Accessories*& HistoryAcces, int& numSellAcces, Accessories TempAcces);
	//заполняет менеджера
	void FillManager();
	//продажа товара
	void sellGoods(Store& StorageOne, MonthlySales& Sales);
	//добавление товара на продажу
	void AddGoods(Store& StorageOne);
	//вывод товаров на экран
	void ShowGoods(Store StorageOne);
	//вывод продаж компьютеров
	void ShowHistoryAcces();
	//вывод продаж комплектующих
	void ShowHistoryComp();
	//вывод информации о менеджере
	void Print();
};

//сортировка
//сортировка символьных значений
void SortShow(Manager* arr_struct, int s_int, bool sortFlag_bool);
//сортировка цифровых значений коплектующих
void SortShow_A(Store StorageOne, bool sortFlag_bool);
//сортировка цифровых значений компьютеров
void SortShow_C(Store StorageOne, bool sortFlag_bool);

//авто-заполнение даты
void AutoFillDate(Date& CurrentDate, Date& prevDate, Date& nextDate);
//заполнение даты вручную
void ManuallFillDate(Date& CurrentDate, Date& prevDate, Date& nextDate);
//оставить дату по-умолчанию
void DefaultFillDate(Date& CurrentDate, Date& prevDate, Date& nextDate);
//сбросить дату
void ResetDate(Date& CurrentDate, Date& prevDate, Date& nextDate);
//корректеровка даты
void CorrectDate(Date& CurrentDate, Date& prevDate, Date& nextDate);

//Сохранение элементов программы
void SaveItempInFile(Store StorageOne, Manager* Managers, int sizeManager, MonthlySales Sales);
//Загрузка элементов программы
void ReadItemOfFile(Store& StorageOne, Manager*& Managers, int& sizeManager, MonthlySales& Sales);
//добавляет менеджера
void AddManager(Manager*& Managers, int& sizeManager);
//Удаляет менеджера
void DelManager(Manager*& Managers, int& sizeManager);
//заполнение файла с датами
void DatesFill(Date& CurrentDate, Date& prevDate, Date& nextDate);
//высчитывание следующей даты
void CalculationDate(Date Temp, Date& nextDate);
//определяет высокосный год
bool isLeapYear(int temp_year);
//сравнение дат
//возвращяет true если дата меньше предидущей
bool DateCmp(Date CurrentDate, Date prevDate);
//Очистка памяти 
void Clear(Store& StorageOne, Manager*& Managers, int& sizeManager, MonthlySales& Sales);
//проверка на одинаковых менеджеров при создании нового аккаунта
bool ControleCloneManager(Manager*& Managers, int& sizeManager, Manager CheckManager);
//удаляет "пустые" компьютеры
void ControlEmptyComps(Store& StorageOne);
//обнуление всех данных
void NullProgram(Store& StorageOne, Date& CurrentDate, Date& prevDate, Date& nextDate, Manager*& Managers, int& sizeManager, MonthlySales& Sales);
//Создание файла и запись прайс-листа в файл
void CreatePrice_List(Store StorageOne, Date CurrentDate);
//Создание файла и запись продаж за месяц в файл
void CreateMonthlySales(MonthlySales Sales, Date CurrentDate);
//печать кода
void PrintCode();