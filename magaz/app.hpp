#pragma once

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <unordered_set>

extern size_t userSize;
extern size_t staffCount;
extern std::string userStatus[3];
extern std::string* loginArr;
extern std::string* passArr;
extern std::string* statusArr;
extern double* awardArr;
extern unsigned int* userIdArr;
extern std::string currentStatus;
extern int currentId;

extern size_t storageSize;
extern int* idArr;
extern std::string* nameArr;
extern unsigned int* countArr;
extern double* priceArr;
extern bool staticStorageCreated;

extern size_t checkSize;
extern int* idArrCheck;
extern std::string* nameArrCheck;
extern unsigned int* countArrCheck;
extern double* priceArrCheck;
extern double* totalPriceArrCheck;

extern double cash;
extern double cashIncome;
extern double bankIncome;

bool CheckLogin(const std::string& str);
bool CheckPass(const std::string& str);
void ChangeUsers();
void ShowUsers(int mode = 0);
void AddNewUsers();
void DeleteUser();
void ChangePass();

void CreateStorage();
void CreateNewStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();

void ChangeStorage();
void AddNewItem();
void changeName();
void deleteItem();

void Start();
bool Login();
bool Logout();
void Getline(std::string& str);
void Err();
bool IsNumber(const std::string& str);

void ShowSuperAdminMenu();
void ShowAdminMenu();
void ShowUserMenu();

void Selling();
void CheckArrAppend();
void PrintCheck(double& totalSum);
void StorageReturner();
void ShowInCome();

double Discount(double& totalSum);
double DiscountOfItem(double& totalSum);

template<typename T>
void SwapArr(T* Arr, T* Arr2, size_t SizeArr)
{
	for (int i = 0; i < SizeArr; i++)
	{
		Arr[i] = Arr2[i];
	}
}
