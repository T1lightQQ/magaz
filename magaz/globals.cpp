#include "app.hpp"

size_t userSize = 2;
size_t staffCount = 1;
std::string userStatus[3]{ "Главный Администратор", "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "login", "login1" };
std::string* passArr = new std::string[userSize]{ "parol", "parol1" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
double* awardArr = new double[userSize] {0.0, 0.0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2};
std::string currentStatus;
int currentId = 0;

size_t storageSize = 0;
int* idArr;
std::string* nameArr;
unsigned int* countArr;
double* priceArr;

bool staticStorageCreated = false;

size_t checkSize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
double* priceArrCheck;
double* totalPriceArrCheck;

double cash = 10000 + rand() % 7000;
double cashIncome = 0.0;
double bankIncome = 0.0;
