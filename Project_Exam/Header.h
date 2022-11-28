#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>//��� �������� ������� ������
//#include <fstream>//��� ��������� �����

using namespace std;

#define INFO cout << "\n��� ��������� ���������� ������� s(ENG) ��� S(ENG). ��� ������ ������� ����� �������"

//�������
int Command(const char* buffer);
//�������� �� ������������ ����� ������������� ����� 
void CorrectNum(int&);
//�������� �� ������������ ����� ������������� ����� 
void CorrectNum(double&);
//������� ������ 
void LineBreak(const char* features);
//�������� �� ���� 
bool IsZero(const char* buffer);
//�������� ������� ������
int HitButton();

//��������� ���� 
struct Date
{
	int year = 0;
	int month = 0;
	int day = 0;
};
//������������� 
struct Accessories
{
	char nameAcces[255]{};//�������� ��������������
	char manufacturer[255]{};//�������������
	char features[255]{};//����������� ��������������
	double Price = 0;
	//���������� ���������� ��������������
	void Fill();
	//����� �� ����� ��������������
	void Print();
	//���������� ����� ��������������
	void PrintAccesCompact();
};
//��������� ���������� 
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
	//���������� ������ ����������
	void FillComp();
	//����� ���������� �� �����
	void PrintComp();
	//����� ���������� �� �����(���������)
	void PrintCompCompact();
};
//������� �� ����� 
struct MonthlySales
{
	int sizeSellAcces = 0;
	int sizeSellComp = 0;
	Accessories* MonthSellAcces = nullptr;
	Computer* MonthSellComp = nullptr;
	//���������� ������� ������ �����������
	void AddMonthSellComp(Computer temp);
	//���������� ������� ������ �������������
	void AddMonthSellAcces(Accessories temp);
	//����� ������ �� �����
	void ShowMonthSeles();
	//�������� ���� ������� �����
	void DelAllArr();
};
//Storage 
struct Store
{
	//����������� ������ 
	double money = 0;

	int sizeAccess = 0;
	int sizeComputers = 0;

	Accessories* Access = nullptr;
	Computer* Computers = nullptr;

	//���������� ������ ���������� ����������
	void AddComp(Computer*& Comps, int& sizeComp);
	//�������� ����������
	void DelComp(Computer*& Comps, int& sizeComp, int pos);
	//���������� ������ �������������� �� �������
	void AddAcces(Accessories*& Acces, int& sizeAccess);
	//������� �������������
	void DelAcces(Accessories*& Acces, int& sizeAccess, int pos);
	//����� ���� �������������
	void ShowAcces(Accessories* Acces, int sizeAccess);
	//����� ���� �����������
	void ShowComps(Computer* Comps, int sizeComps);
};
//��������
struct Manager
{
	bool Fired_or_Not_Fired = false;// ������/�� ������

	//---------- ������� ������ ���������--------------
	int numSellComp = 0;
	int numSellAcces = 0;

	Computer* HistoryComps = nullptr;
	Accessories* HistoryAccess = nullptr;
	//------------------------------------------------------

	char name[255]{};
	char surname[255]{};
	char patrynomic[255]{};
	char position[255]{};//���������
	char phone[255]{};
	//���������� � ������� ��������� ����������
	void HistoryComp(Computer*& HistoryComp, int& numSellComp, Computer TempComp);
	//���������� � ������� ��������� ��������������
	void HistoryAcces(Accessories*& HistoryAcces, int& numSellAcces, Accessories TempAcces);
	//��������� ���������
	void FillManager();
	//������� ������
	void sellGoods(Store& StorageOne, MonthlySales& Sales);
	//���������� ������ �� �������
	void AddGoods(Store& StorageOne);
	//����� ������� �� �����
	void ShowGoods(Store StorageOne);
	//����� ������ �����������
	void ShowHistoryAcces();
	//����� ������ �������������
	void ShowHistoryComp();
	//����� ���������� � ���������
	void Print();
};

//����������
//���������� ���������� ��������
void SortShow(Manager* arr_struct, int s_int, bool sortFlag_bool);
//���������� �������� �������� ������������
void SortShow_A(Store StorageOne, bool sortFlag_bool);
//���������� �������� �������� �����������
void SortShow_C(Store StorageOne, bool sortFlag_bool);

//����-���������� ����
void AutoFillDate(Date& CurrentDate, Date& prevDate, Date& nextDate);
//���������� ���� �������
void ManuallFillDate(Date& CurrentDate, Date& prevDate, Date& nextDate);
//�������� ���� ��-���������
void DefaultFillDate(Date& CurrentDate, Date& prevDate, Date& nextDate);
//�������� ����
void ResetDate(Date& CurrentDate, Date& prevDate, Date& nextDate);
//������������� ����
void CorrectDate(Date& CurrentDate, Date& prevDate, Date& nextDate);

//���������� ��������� ���������
void SaveItempInFile(Store StorageOne, Manager* Managers, int sizeManager, MonthlySales Sales);
//�������� ��������� ���������
void ReadItemOfFile(Store& StorageOne, Manager*& Managers, int& sizeManager, MonthlySales& Sales);
//��������� ���������
void AddManager(Manager*& Managers, int& sizeManager);
//������� ���������
void DelManager(Manager*& Managers, int& sizeManager);
//���������� ����� � ������
void DatesFill(Date& CurrentDate, Date& prevDate, Date& nextDate);
//������������ ��������� ����
void CalculationDate(Date Temp, Date& nextDate);
//���������� ���������� ���
bool isLeapYear(int temp_year);
//��������� ���
//���������� true ���� ���� ������ ����������
bool DateCmp(Date CurrentDate, Date prevDate);
//������� ������ 
void Clear(Store& StorageOne, Manager*& Managers, int& sizeManager, MonthlySales& Sales);
//�������� �� ���������� ���������� ��� �������� ������ ��������
bool ControleCloneManager(Manager*& Managers, int& sizeManager, Manager CheckManager);
//������� "������" ����������
void ControlEmptyComps(Store& StorageOne);
//��������� ���� ������
void NullProgram(Store& StorageOne, Date& CurrentDate, Date& prevDate, Date& nextDate, Manager*& Managers, int& sizeManager, MonthlySales& Sales);
//�������� ����� � ������ �����-����� � ����
void CreatePrice_List(Store StorageOne, Date CurrentDate);
//�������� ����� � ������ ������ �� ����� � ����
void CreateMonthlySales(MonthlySales Sales, Date CurrentDate);
//������ ����
void PrintCode();