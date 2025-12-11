#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <unordered_set>


// ----------------Учетки-----------------
size_t userSize = 2;
size_t staffCount = 1;
std::string userStatus[3]{ "Супер Администратор", "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "login", "login1" };
std::string* passArr = new std::string[userSize]{ "parol", "parol1" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
double* awardArr = new double[userSize] {0.0, 0.0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2};
std::string currentStatus;
int currentId = 0;

bool CheckLogin(const std::string& str);
bool CheckPass(const std::string& str);
void ChangeUsers();
void ShowUsers(int mode = 0);
void AddNewUsers();
void DeleteUser();
void ChangePass();
// ---------------------------------------



// -----------Cклад--------------
size_t storageSize = 0;
int* idArr;
std::string* nameArr;
unsigned int* countArr;
double* priceArr;

bool staticStorageCreated = false;

void CreateStorage();
void CreateNewStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();

template<typename T>
void SwapArr(T* Arr, T* Arr2, size_t SizeArr);

void ChangeStorage();
void AddNewItem();
void changeName();
void deleteItem();



//-----------Служебки------------

void Start();
bool Login();
bool Logout();
inline void Getline(std::string& str);
inline void Err();
bool IsNumber(const std::string& str);

void ShowSuperAdminMenu();
void ShowAdminMenu();
void ShowUserMenu();



// ------Продажи-------------
size_t checkSize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
double* priceArrCheck;
double* totalPriceArrCheck;

double cash = 10000 + rand() % 7000;
double cashIncome = 0.0;
double bankIncome = 0.0;

void Selling();
void CheckArrAppend();
void PrintCheck(double& totalSum);
void StorageReturner();
void ShowInCome();

double Discount(double& totalSum);
double DiscountOfItem(double& totalSum);

// ----------------------------


int main()
{
	//setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();
	delete[]loginArr;
	delete[]passArr;
	delete[]statusArr;

	if (staticStorageCreated)
	{
		delete[]idArr;
		delete[]nameArr;
		delete[]countArr;
		delete[]priceArr;
	}

	return 0;
}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::string name[staticSize]
	{
		"RTX 5060", "RTX 5070", "RTX 5080", "RTX 5090 ti",
		"Iphone 14", "Iphone 15", "Iphone 16",
		"Xiaomi UltraMegaMaxSuper 3000", "NE Xiaomi NeSuper", "Xiaomi Super 15"
	};
	unsigned int count[staticSize]{ 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	double price[staticSize]{ 30000.5, 60000.5, 100000.5, 300000.5, 50000.5, 80000.5, 90000.5, 22222.5, 500.5, 30000.5 };

	storageSize = staticSize;
	idArr = new int[storageSize];
	nameArr = new std::string[storageSize];
	countArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	staticStorageCreated = true;

	SwapArr(idArr, id, storageSize);
	SwapArr(priceArr, price, storageSize);
	SwapArr(countArr, count, storageSize);
	SwapArr(nameArr, name, storageSize);
}

void CreateNewStorage()
{
	staticStorageCreated = true;
	std::string size;
	while (true)
	{
		std::cout << "\nСоздание нового склада\nСколько позиций склада будет?\nВвод: ";
		Getline(size);
		if (IsNumber(size))
		{
			break;
		}
		else
		{
			Err();
		}
	}
	if (!IsNumber(size))
	{
		Err();
	}
	else
	{
		idArr = new int[storageSize];
		nameArr = new std::string[storageSize];
		countArr = new unsigned int[storageSize];
		priceArr = new double[storageSize];
		staticStorageCreated = true;

		for (int i = 0; i < std::stoi(size); i++)
		{
			AddNewItem();
		}
	}
}

void ShowStorage(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" <<
			"Цена\t" << "Кол-во\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i]
				<< "\t" << priceArr[i] << "\t" << countArr[i] << "\n";
		}
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Кол-во\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i]
				<< "\t" << countArr[i] << "\n";
		}

	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" <<
			"Цена\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i]
				<< "\t" << priceArr[i] << "\n";
		}

	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\n";
		}

	}
	else
	{
		std::invalid_argument("StorageMode Error");
	}
	std::cout << "\n\n";
}

void AddStorageItem()
{
	std::string chooseId, chooseCount, choose;
	int id = 0;
	unsigned int count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);

		std::cout << "\n\tВведите ID товара для его пополнения: ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "Отмена операции пополнения\n";
			Sleep(1500);
			break;
		}

		std::cout << "\n\tВведите кол-во товара для пополнения: ";
		Getline(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > 50)
			{
				std::cout << "\n\n\tНекорректный ID\n\n";
				Sleep(1500);

			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					"\t" << countArr[id] << " --> " << countArr[id] + count << "\n\n";

				std::cout << "Подтвердить?\n1. Да\n\t2. НЕТ\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] += count;
					std::cout << "Товар успешно пополнен\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена пополнения товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void RemoveStorageItem()
{
	std::string chooseId, chooseCount, choose;
	int id = 0;
	unsigned int count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);

		std::cout << "\n\tВведите ID товара для его списания: ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "Отмена операции списания\n";
			Sleep(1500);
			system("cls");
			break;
		}

		std::cout << "\n\tВведите кол-во товара для списания: ";
		Getline(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > countArr[id])
			{
				std::cout << "\n\n\tНекорректный ID\n\n";
				Sleep(1500);

			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					"\t" << countArr[id] << " --> " << countArr[id] - count << "\n\n";

				std::cout << "Подтвердить?\n1. Да\n\t2. НЕТ\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] -= count;
					std::cout << "Товар успешно списан\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена пополнения товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangePrice()
{
	std::string chooseId, newPrice, choose;
	int id = 0;
	double price = 0.0;
	while (true)
	{
		system("cls");
		ShowStorage(2);

		std::cout << "\n\tВведите ID товара для его смены цены: ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "Отмена операции смены цены\n";
			Sleep(1500);
			break;
		}

		std::cout << "\n\tВведите новую цену товара: ";
		Getline(newPrice);

		if (IsNumber(chooseId) && IsNumber(newPrice))
		{
			id = std::stoi(chooseId) - 1;
			price = std::stoi(newPrice);

			if (id < 0 || id > storageSize - 1 || price < 0.0 || price > 700000)
			{
				std::cout << "\n\n\tНекорректный ID или цена\n\n";
				Sleep(1500);

			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					"\t" << priceArr[id] << " --> " << price << "\n\n";

				std::cout << "Подтвердить?\n\t1. Да\n\t2. НЕТ\n\tВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					priceArr[id] = price;
					std::cout << "Цена товара успешно изменена\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена смены цены товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "\n\t1. Добавить новый товар\n\t2. Изменить имя товара\n\t3. Удалить товар\n\t4. Выйти из редактора\n\t";
 		std::cout << "Ввод: ";
		Getline(choose);

		if (choose == "1")
		{
			AddNewItem();
		}
		else if (choose == "2")
		{
			changeName();
		}
		else if (choose == "3")
		{
			deleteItem();
		}
		else if (choose == "4")
		{
			system("cls");
			break;
		}
		else
		{
			Err();
		}
	}
}

void AddNewItem()
{
	std::string newName, newPrice, newCount, choose;
	double price = 0.0;
	unsigned int count = 0;
	bool exit = true;
	while (exit)
	{
		while (true)
		{
			system("cls");
			std::cout << "\tДобавление нового товара\n\tВведите \"exit\" для выхода";
			std::cout << "\n\tВведите название нового товара: ";
			Getline(newName);
			if (newName == "exit")
			{
				std::cout << "Операция добавления прервана";
				Sleep(1500);
				exit = false;
				break;
			}

			if (newName.size() <= 0 || newName.size() >= 100)
			{
				std::cout << "Ошибка имени, слишком длинное название";
				Sleep(1500);
			}
			else
			{
				break;
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара\n\tВведите \"exit\" для выхода";
			std::cout << "\n\tВведите кол-во нового товара: ";
			Getline(newCount);
			if (newCount == "exit")
			{
				std::cout << "Операция добавления прервана";
				Sleep(1500);
				exit = false;
				break;
			}

			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > 100)
				{
					std::cout << "\n\tСлишком много, не более 100 ед.\n\t";
				}
				else
				{
					break;
				}
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара\n\tВведите \"exit\" для выхода";
			std::cout << "\n\tВведите цену нового товара: ";
			Getline(newPrice);
			if (newPrice == "exit")
			{
				std::cout << "Операция добавления прервана";
				Sleep(1500);
				exit = false;
				break;
			}

			if (IsNumber(newPrice))
			{
				price = std::stoi(newPrice);
				if (price > 100000000)
				{
					std::cout << "\n\tСлишком дорого, не более 1 млн.\n\t";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
		}

		while (exit)
		{
			std::cout << "\n\tНовар товар:" << newName << "\n\tЦена: " << price << "\n\tКоличество: " << count;
			std::cout << "\n\tПодтвердить???\n\t1. ДА\n\t2. НЕТ\n\tВвод: ";
			Getline(choose);
			if (choose == "1")
			{
				storageSize++;

				int* idArrTemp = new int[storageSize];
				std::string* nameArrTemp = new std::string[storageSize];
				unsigned int* countArrTemp = new unsigned int[storageSize];
				double* priceArrTemp = new double[storageSize];

				SwapArr(idArrTemp, idArr, storageSize - 1);
				SwapArr(nameArrTemp, nameArr, storageSize - 1);
				SwapArr(countArrTemp, countArr, storageSize - 1);
				SwapArr(priceArrTemp, priceArr, storageSize - 1);

				idArrTemp[storageSize - 1] = storageSize;
				nameArrTemp[storageSize - 1] = newName;
				countArrTemp[storageSize - 1] = count;
				priceArrTemp[storageSize - 1] = price;

				std::swap(idArr, idArrTemp);
				std::swap(nameArr, nameArrTemp);
				std::swap(countArr, countArrTemp);
				std::swap(priceArr, priceArrTemp);

				delete[]idArrTemp;
				delete[]nameArrTemp;
				delete[]countArrTemp;
				delete[]priceArrTemp;

				system("cls");
				std::cout << "\n\tТовар успешно добавлен!";
				system("pause");
				break;
			}
			else if (choose == "2")
			{
				std::cout << "\n\tОтмена";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}
		}

		if (exit == false)
		{
			break;
		}
		exit = false;
	}
}

void changeName()
{
	std::string newName, chooseId, choose;
	unsigned int id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\tСмена имени товара\n\tВведите \"exit\" для выхода";
		std::cout << "\n\tВведите id товара для смены имени: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Операция добавления прервана";
			Sleep(1500);
			break;
		}

		std::cout << "\n\tВведите новое название товара: ";
		Getline(newName);

		if (newName.size() <= 0 || newName.size() >= 60)
		{
			std::cout << "\n\tОшибка максимального размера имени товара\n\t";
			Sleep(1500);
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;

			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "\n\tОшибка ID\n\t";
				Sleep(1500);
				system("cls");
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					" --> " << newName << "\n\n";

				std::cout << "\nПодвердить? \n1. ДА\n2. НЕТ\nВвод - ";
				Getline(choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "\n\tСмена имени завершена\n\t";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "\n\tОтмена операции\n\t";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void deleteItem()
{
	std::string chooseId, choose;
	unsigned int id = 0;
	while (true)
	{
		ShowStorage();
		std::cout << "Введите ID товара для удаления или \"exit\" для выхода\nВвод: ";
		Getline(chooseId);	

		if (chooseId == "exit")
		{
			std::cout << "Отмена операции удаления\n";
			Sleep(1500);
			break;
		}

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "\n\tОшибка ID\n\t";
				Sleep(1500);
				system("cls");
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << " - Будет удалено";

				std::cout << "\nПодвердить? \n1. ДА\n2. НЕТ\nВвод: ";
				Getline(choose);

				if (choose == "1")
				{
					storageSize--;
					int* idArrTemp = new int[storageSize];
					std::string* nameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					double* priceArrTemp = new double[storageSize];

					for (size_t i = 0, c = 0; i < storageSize; i++, c++)
					{
						if (id == c)
						{
							c++;
						}

						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						countArrTemp[i] = countArr[c];
						priceArrTemp[i] = priceArr[c];
					}
					std::swap(idArr, idArrTemp);
					std::swap(nameArr, nameArrTemp);
					std::swap(countArr, countArrTemp);
					std::swap(priceArr, priceArrTemp);

					delete[]idArrTemp;
					delete[]nameArrTemp;
					delete[]countArrTemp;
					delete[]priceArrTemp;

					system("cls");
					std::cout << "\n\tТовар успешно удален!";
					system("pause");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "\n\tОтмена операции\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

template<typename T>
void SwapArr(T* Arr, T* Arr2, size_t SizeArr)
{
	for (int i = 0; i < SizeArr; i++)
	{
		Arr[i] = Arr2[i];
	}
}

void Start()
{
	std::string choose;
	std::cout << "\n\n\n\t\t\tТехноШоооб\n\n\n\n\n\n";
	while (true)
	{
		if (Login())
		{
			if (currentStatus == userStatus[0])
			{
				while (true)
				{
					std::cout << "Выберете склад: \n1. Готовый\n2. Создать новый" << "\nВвод: ";
					Getline(choose);
					if (choose == "1")
					{
						if (staticStorageCreated == false)
						{
							CreateStorage();
						}
						system("cls");
						//ShowStorage();
						ShowSuperAdminMenu();
						//system("pause");
						break;
					}
					else if (choose == "2")
					{
						if (staticStorageCreated == false)
						{
							CreateNewStorage();
						}
						system("cls");
						//ShowStorage();
						ShowSuperAdminMenu();
						//system("pause");
						break;
					}
					else
					{
						Err();
					}
				}

			}
			else if (currentStatus == userStatus[1])
			{
				if (staticStorageCreated == false)
				{
					CreateStorage();
				}
				system("cls");
				ShowUserMenu();
			}
			else if (currentStatus == userStatus[2])
			{
				if (staticStorageCreated == false)
				{
					CreateStorage();
				}
				system("cls");
				ShowUserMenu();
			}
		}
		else
		{
			system("cls");
			std::cout << "Введите пароль супер администратора для закрытия смены - ";
			Getline(choose);
			if (choose == passArr[0])
			{
				system("cls");
				std::cout << "Итоговая прибыль за смену - " << cashIncome + bankIncome << " рублей";
				Sleep(1500);
				std::cout << "\n\n\tЗавершение работы магазина\n\n";
				Sleep(2000);
				break;
			}
			else
			{
				Err();
			}
		}
	}
}

bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "Введите логин - ";
		Getline(login);
		std::cout << "Введите пароль - ";
		Getline(pass);
		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}

		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				system("cls");
				std::cout << "Пользователь - " << loginArr[i] << "\n\nДобро Пожаловать\n";
				std::cout << "Ваш статус - " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				system("pause");
				return true;
			}
		}
		Err();
	}
	return false;
}

bool Logout()
{
	std::string choose;
	std::cout << "Для подтверждения выхода введите свой пароль или \"exit\"";
	Getline(choose);
	if (choose == "exit")
	{
		system("cls");
		return false;
	}
	else if (choose == passArr[currentId - 1] || choose == passArr[0])
	{
		system("cls");
		return true;
	}
	else
	{
		Err();
	}
	return false;
}

inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}

inline void Err()
{
	std::cout << "Некорректный ввод\n";
	Sleep(1500);
	system("cls");
}

bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 100)
	{
		std::cout << "\n\tНекорректный ввод";
		std::cout << "\n\tНекорректная длина числа\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			Err();
			std::cout << "Не является числом\n\n";
			return false;
		}
		return true;
	}
}

void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "\n\t1. Начать продажу\n\t2. Показать склад\n\t3. Пополнить склад\n\t4. Списание товара"
			<< "\n\t5. Изменить цену\n\t6. Редакт. склад\n\t7. Редакт. персонал\n\t8. Отчет о прибыли\n\t9. Закрыть смену\n\t";
		std::cout << "Ввод: ";
		Getline(choose);

		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
			system("pause");
			system("cls");
		}
		else if (choose == "3")
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5" && storageSize > 0)
		{
			ChangePrice();
		}
		else if (choose == "6" && storageSize > 0)
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeUsers();
		}
		else if (choose == "8")
		{
			ShowInCome();
		}
		else if (choose == "9")
		{
			if (Logout())
			{
				break;
			}
		}
		else
		{
			if (storageSize)
			{
				std::cout << "Склад пустой";
			}
			Err();
		}
	}
}

void ShowAdminMenu()
{
	std::string choose;

	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - Редактировать склад\n";
		std::cout << "6 - Редактировать персонал\n";
		std::cout << "7 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод - ";
		Getline(choose);

		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
			system("pause");
			system("cls");
		}
		else if (choose == "3" && storageSize > 0)
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5")
		{
			ChangeStorage();
		}
		else if (choose == "6")
		{
			ChangeUsers();
		}
		else if (choose == "7")
		{
			ShowInCome();
		}
		else if (choose == "0")
		{
			if (Logout())
			{
				break;
			}
		}
		else
		{
			if (storageSize)
			{
				std::cout << "Склад пустой!\n";
			}
			Err();
		}
	}
}

void ShowUserMenu()
{
	std::string choose;

	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод - ";
		Getline(choose);

		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
			system("pause");
			system("cls");
		}
		else if (choose == "3" && storageSize > 0)
		{
			ShowInCome();
		}
		else if (choose == "0")
		{
			if (Logout())
			{
				break;
			}
		}
		else
		{
			if (storageSize)
			{
				std::cout << "Склад пустой!\n";
			}
			Err();
		}
	}
}

bool CheckLogin(const std::string& str)
{
	for (size_t i = 0; i < userSize; i++)
	{
		if (str == loginArr[i])
		{
			std::cout << "\nТакой пользователь уже существует";
			Sleep(1500);
			return false;
		}
	}

	if (str.size() < 5 || str.size() >= 30)
	{
		std::cout << "\nНедопустимая длина, не меньше 5, не больше 30 символов";
		Sleep(1500);
		return false;
	}

	std::unordered_set<char> specialSymbols;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char symb : str)
	{
		if (!specialSymbols.count(symb))
		{
			std::cout << "Некорректные символы\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}

bool CheckPass(const std::string& str)
{
	if (str.size() <= 5 || str.size() > 60)
	{
		std::cout << "\nСлишком длинный или короткий пароль\n";
		Sleep(1500);
		return false;
	}
	std::unordered_set<char> specialSymbols;
	std::unordered_set<char> passSymbols {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=',
		'+', '/', ';', '\'', '\\', '.', ',', '{', '}', '[', ']', '|', '`', '~' };
	int symbolCount = 0, maxSymbolCount = 3;

	for (char i = '!'; i <= '~'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char symb : str)
	{
		if (!specialSymbols.count(symb))
		{
			std::cout << "Некорректные символы\n\n";
			Sleep(1500);
			return false;
		}
	}
	
	for (char symb : str)
	{
		if (passSymbols.count(symb))
		{
			symbolCount++;
			if (passSymbols.count(symb));
			{
				return true;
			}
		}
	}
	return false;
}

void ChangeUsers()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить нового пользователя\n";
		std::cout << "2 - Показать пользователей\n";
		std::cout << "3 - Изменить пароль пользователя\n";
		std::cout << "4 - Удалить пользователя\n";
		std::cout << "0 - Выйти из редактора\n";
		std::cout << "Ввод - ";
		Getline(choose);

		if (choose == "1")
		{
			AddNewUsers();
		}
		else if (choose == "2" && userSize > 1)
		{
			ShowUsers();
			system("pause");
		}
		else if (choose == "3" && userSize > 1)
		{
			ChangePass();
		}
		else if (choose == "4" && userSize > 1)
		{
			DeleteUser();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (userSize <= 1)
			{
				std::cout << "Пользователей нет!\n";
			}
			Err();
		}
	}
}

void ShowUsers(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::cout << "\t" << std::left << std::setw(10) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t"
				<< passArr[i] << "\t\t\t" << statusArr[i] << "\n";
		}
	}
	else if (mode == 1)
	{
		system("cls");
		std::cout << "\t" << std::left << std::setw(10) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
		for (size_t i = 0; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t"
				<< passArr[i] << "\t\t\t" << statusArr[i] << "\n";
		}
	}

}

void AddNewUsers()
{
	std::string newLogin, newPass, newRole, choose;
	bool exit;
	while (true)
	{
		exit = true;
		while (true)
		{
			system("cls");
			std::cout << "\tСоздание нового пользователя!\n\n";
			std::cout << "Введите логин нового пользователя или \"exit\" для выхода - ";
			Getline(newLogin);
			if (newLogin == "exit")
			{
				std::cout << "Создание нового пользователя прервано!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckLogin(newLogin))
			{
				break;
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "\tСоздание пароля для нового пользователя!\n\n";
			std::cout << "Введите пароль для нового пользователя или \"exit\" для выхода - ";
			Getline(newPass);
			if (newPass == "exit")
			{
				std::cout << "Создание нового пользователя прервано!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckPass(newPass))
			{
				break;
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "\tСоздание нового пользователя!\n\n";
			std::cout << "Введите роль нового пользователя или \"exit\" для выхода - ";
			std::cout << "1 - Администратор\n2 - Сотрудник\nВвод - ";
			Getline(choose);
			if (choose == "exit")
			{
				std::cout << "Создание нового пользователя прервано!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (choose == "1")
			{
				newRole = userStatus[1];
			}
			else if (choose == "2")
			{
				newRole = userStatus[2];
				break;
			}
			else
			{
				Err();
			}
		}

		while (exit)
		{
			std::cout << "Пользователь - " << newLogin << "\n";
			std::cout << "Пароль - " << newPass << "\n";
			std::cout << "Роль - " << newRole << "\n\n";
			std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
			Getline(choose);

			if (choose == "1")
			{
				if (newRole == userStatus[2])
				{
					staffCount++;
				}

				userSize++;
				std::string* loginArrTemp = new std::string[userSize];
				std::string* passArrTemp = new std::string[userSize];
				std::string* statusArrTemp = new std::string[userSize];
				double* awardArrTemp = new double[userSize];
				unsigned int* userIdArrTemp = new unsigned int[userSize];

				SwapArr(loginArrTemp, loginArr, userSize - 1);
				SwapArr(passArrTemp, passArr, userSize - 1);
				SwapArr(statusArrTemp, statusArr, userSize - 1);
				SwapArr(awardArrTemp, awardArr, userSize - 1);
				SwapArr(userIdArrTemp, userIdArr, userSize - 1);

				loginArrTemp[userSize - 1] = newLogin;
				passArrTemp[userSize - 1] = newPass;
				statusArrTemp[userSize - 1] = newRole;
				awardArrTemp[userSize - 1] = 0.0;
				userIdArrTemp[userSize - 1] = userSize;

				std::swap(loginArr, loginArrTemp);
				std::swap(passArr, passArrTemp);
				std::swap(statusArr, statusArrTemp);
				std::swap(awardArrTemp, awardArr);
				std::swap(userIdArrTemp, userIdArr);

				delete[] loginArrTemp, passArrTemp, statusArrTemp, awardArrTemp, userIdArrTemp;
				std::cout << "Идет подготовка... ";
				Sleep(2000);
				std::cout << "Пользователь успешно добавлен!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена\n";
				Sleep(1500);
			}
			else
			{
				Err();
			}
		}

		if (exit == false)
		{
			break;
		}
	}
}

void ChangePass()
{
	std::string newPass1, newPass2, choose;
	int userNumber = 0;
	int isAdmin = 0;

	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			ShowUsers(1);
			isAdmin = 0;
		}
		else
		{
			ShowUsers();
			isAdmin = 1;
		}

		std::cout << "\nВыберите номер пользователя для смены пароля или \"exit\"для выхода - ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "\nОтмена изменения пароля!\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);
			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "\nПользователь с таким номером не существует!\n";
				Sleep(1500);
			}
			else
			{
				while (true)
				{
					system("cls");

					if (currentStatus == userStatus[1] && statusArr[userNumber] == userStatus[1])
					{
						std::cout << "\nНельзя менять пароли Администраторам!\n";
						Sleep(1500);
						break;
					}

					std::cout << "\nВведите новый пароль для пользователя " << loginArr[userNumber] << " - ";
					Getline(newPass1);
					std::cout << "\nПодтвердите пароль для пользователя " << loginArr[userNumber] << " - ";
					Getline(newPass2);
					if (CheckPass(newPass1) && CheckPass(newPass2) && newPass1 == newPass2)
					{
						passArr[userNumber] = newPass1;
						std::cout << "Успешно\n";
						Sleep(1500);
						break;
					}
					else
					{
						std::cout << "Повторите попытку\n";
						Sleep(1500);
					}
				}
			}
		}
		else
		{
			Err();
		}

	}
}

void DeleteUser()
{
	std::string chooseNumber, checkPass, choose;
	int userNumber = 0, isAdmin = 0;

	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			if (userSize < 2)
			{
				std::cout << "Нет доступных пользователей для удаления!\n";
				Sleep(1500);
				return;
			}
		}

		else if (currentStatus == userStatus[1])
		{
			if (staffCount < 1)
			{
				std::cout << "Нет доступных пользователей для удаления!\n";
				Sleep(1500);
				return;
			}
		}

		ShowUsers();
		isAdmin = 1;

		std::cout << "\nВыберите номер пользователя для удаления или \"exit\"для выхода - ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "Отмена удаления пароля!\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);

			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "Пользователя с таким номером не существует!\n";
				Sleep(1500);
				break;
			}

			while (true)
			{
				system("cls");

				if (currentStatus == userStatus[1] && statusArr[userNumber] != userStatus[2])
				{
					std::cout << "Нельзя удалять администратора\n";
					Sleep(1500);
					break;
				}

				std::cout << "Удаление пользователя - " << loginArr[userNumber] << "\n";
				std::cout << "Для подтверждения введите пароль супер администратора или\"exit\"для выхода - ";
				Getline(checkPass);

				if (checkPass == "exit")
				{
					std::cout << "Отмена удаления пользователя - " << loginArr[userNumber] << "\n\n";
					Sleep(1500);
					break;
				}

				else if (checkPass == passArr[0])
				{
					if (statusArr[userNumber] == userStatus[2])
					{
						staffCount--;
					}

					userSize--;
					std::string* loginArrTemp = new std::string[userSize];
					std::string* passArrTemp = new std::string[userSize];
					std::string* statusArrTemp = new std::string[userSize];
					double* awardArrTemp = new double[userSize];
					unsigned int* userIdArrTemp = new unsigned int[userSize];

					for (size_t i = 0, c = 0; i < userSize; i++, c++)
					{
						if (userNumber == c)
						{
							c++;
						}
						loginArrTemp[i] = loginArr[c];
						passArrTemp[i] = passArr[c];
						statusArrTemp[i] = statusArr[c];
						awardArrTemp[i] = awardArr[c];
						userIdArrTemp[i] = userIdArr[c];
					}
					std::swap(loginArrTemp, loginArr);
					std::swap(passArrTemp, passArr);
					std::swap(statusArrTemp, statusArr);
					std::swap(awardArrTemp, awardArr);
					std::swap(userIdArrTemp, userIdArr);

					delete[]loginArrTemp, passArrTemp, statusArrTemp, awardArrTemp, userIdArrTemp;
					std::cout << "Идет подготовка... ";
					Sleep(2000);
					std::cout << "Пользователь успешно удалён!\n\n";
					Sleep(1500);
					break;

				}
				else
				{
					std::cout << "Некорректный пароль\n";
					Sleep(1500);
				}
			}
		}
		else
		{
			Err();
		}
	}



}

void Selling()
{
	std::string chooseId, chooseCount, choose, chooseCash;
	unsigned int id = 0, count = 0, index = -1;
	double totalSum = 0.0, money = 0.0;
	bool isFirst = false;
	checkSize = 0;
	while (true)
	{
		ShowStorage();

		std::cout << "\nВведите ID товара для покупки или \"exit\" для завершения покупок - ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			if (isFirst == false)
			{
				std::cout << "Выход без покупок\n";
				Sleep(1500);
				break;
			}
			system("cls");
			PrintCheck(totalSum);
			std::cout << "\nПодтвердите покупку?\n1 - Да\n2 - Добавить ещё товар\n3 - Отмена\nВвод - ";
			Getline(choose);
			totalSum = Discount(totalSum);
			totalSum = DiscountOfItem(totalSum);
			if (choose == "1")
			{
				while (true)
				{
					system("cls");
					std::cout << "Выберите способ оплаты\n1 - Наличными\n2 - Безнал\nВвод - ";
					Getline(choose);
					if (choose == "1")
					{
						std::cout << "\nСумма к оплате: " << totalSum << "\n";
						std::cout << "Введите кол-во наличных - ";
						Getline(chooseCash);
						if (IsNumber(chooseCash))
						{
							money = std::stod(chooseCash);
							if (money < totalSum)
							{
								std::cout << "Недостаточно средств!\n";
								Sleep(1500);
								continue;

							}
							else if (money - totalSum > cash)
							{
								std::cout << "Нет возможности дать сдачи. Повторите попытку\n";
								Sleep(1500);
								continue;
							}
							else
							{
								std::cout << "Ваши " << money << "\n";
								Sleep(400);
								std::cout << "Оплата прошла успешно. Сдача " << money - totalSum << " рублей\n";
								Sleep(1800);
								cash -= money - totalSum;
								cashIncome += totalSum;
								awardArr[currentId] += totalSum;
								system("cls");
								break;
							}
						}
					}
					else if (choose == "2")
					{
						system("cls");
						std::cout << "Приложите карту\n\n";
						Sleep(1000);
						if (rand() % 10 <= 2)
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Sleep(800);
							}
							std::cout << "\nСоединение не установлено. Повторите попытку\n";
							Sleep(1500);
						}
						else
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Sleep(800);
							}
							std::cout << "\nОплата прошла успешно\n\nСпасибо за покупку!\n\n";
							Sleep(2500);
							bankIncome += totalSum;
							awardArr[currentId] += totalSum;
							system("cls");
							break;
						}
					}
					else if (choose == "rA9" || choose == "ra9")
					{
						std::cout << "\nИерихон рядом. Всего хорошего\n";
						Sleep(1500);
						system("cls");
						break;
					}
					else
					{
						Err();
					}
				}
			}
			else if (choose == "2")
			{
				continue;
			}
			else if (choose == "3")
			{
				std::cout << "Отмена покупки!\n";
				StorageReturner();
				Sleep(1500);
				system("cls");
				return;
			}
			else
			{
				Err();
				continue;
			}

			delete[]idArrCheck;
			delete[]nameArrCheck;
			delete[]countArrCheck;
			delete[]priceArrCheck;
			delete[]totalPriceArrCheck;

			idArrCheck = nullptr;
			nameArrCheck = nullptr;
			countArrCheck = nullptr;
			priceArrCheck = nullptr;
			totalPriceArrCheck = nullptr;
			system("cls");
			break;
		}

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;

			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
				continue;
			}
		}

		std::cout << "\nВведите кол-во товара \"exit\" для выбора другого товара - ";
		Getline(chooseCount);
		if (chooseCount == "exit")
		{
			std::cout << "Отмена покупки товара - " << nameArr[id] << "\n";
			Sleep(1500);
			continue;
		}

		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount);

			if (count < 1 || count > countArr[id])
			{
				std::cout << "Ошибка кол-ва! Максимум - " << countArr[id] << "\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}

		CheckArrAppend();
		index++;
		idArrCheck[index] = idArr[id];
		nameArrCheck[index] = nameArr[id];
		priceArrCheck[index] = priceArr[id];
		countArrCheck[index] = count;
		totalPriceArrCheck[index] = count * priceArr[id];
		countArr[id] -= count;
		totalSum += totalPriceArrCheck[index];


		std::cout << "\nТовар добавлен в чек\n\n";
		isFirst = true;
		Sleep(1000);
	}
}

void CheckArrAppend()
{
	checkSize++;
	int* idArrCheckTemp = new int[checkSize];
	std::string* nameArrCheckTemp = new std::string[checkSize];
	unsigned int* countArrCheckTemp = new unsigned int[checkSize];
	double* priceArrCheckTemp = new double[checkSize];
	double* totalPriceArrCheckTemp = new double[checkSize];

	SwapArr(idArrCheckTemp, idArrCheck, checkSize - 1);
	SwapArr(nameArrCheckTemp, nameArrCheck, checkSize - 1);
	SwapArr(countArrCheckTemp, countArrCheck, checkSize - 1);
	SwapArr(priceArrCheckTemp, priceArrCheck, checkSize - 1);
	SwapArr(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);

	std::swap(idArrCheckTemp, idArrCheck);
	std::swap(nameArrCheckTemp, nameArrCheck);
	std::swap(countArrCheckTemp, countArrCheck);
	std::swap(priceArrCheckTemp, priceArrCheck);
	std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);

	delete[]idArrCheckTemp;
	delete[]nameArrCheckTemp;
	delete[]countArrCheckTemp;
	delete[]priceArrCheckTemp;
	delete[]totalPriceArrCheckTemp;


}

void PrintCheck(double& totalSum)
{
	std::cout << "№\t" << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" <<
		"Цена за ед\t" << "Кол-во\t" << "Итого\n";

	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i + 1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i]
			<< "\t" << priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\n";
	}
}

void StorageReturner()
{
	for (size_t i = 0; i < checkSize; i++)
	{
		countArr[idArrCheck[i] - 1] += countArrCheck[i];
	}

	delete[] idArrCheck;
	delete[] nameArrCheck;
	delete[] countArrCheck;
	delete[] priceArrCheck;
	delete[] totalPriceArrCheck;

	idArrCheck = nullptr;
	nameArrCheck = nullptr;
	countArrCheck = nullptr;
	priceArrCheck = nullptr;
	totalPriceArrCheck = nullptr;

	checkSize = 0;

}

void ShowInCome()
{
	system("cls");
	std::cout << "Текущая прибыль за смену\n\n";
	std::cout << "Наличный расчет: " << cashIncome << "\n\n";
	std::cout << "Безналичный расчет: " << bankIncome << "\n\n";
	std::cout << "Итого " << cashIncome + bankIncome << "\n\n";
	std::cout << "Сумма ваших продаж: " << awardArr[currentId] << "\n";
	system("pause");
	system("cls");
}

double Discount(double& totalSum)
{
	if (totalSum >= 100000.0)
	{
		std::cout << "\nТ.к ваши покупки в сумме более 100000, вам позволена скидка в размере 20%!\n";
		system("pause");
		return totalSum - (totalSum / 100 * 20);
	}
	else
	{
		return totalSum;
	}
}

double DiscountOfItem(double& totalSum)
{
	if (checkSize >= 2)
	{
		std::cout << "\nТ.к вы взяли более 3х разных позиций, вам позволена скидка в размере 30% на сумму покупок!\n";
		system("pause");
		return totalSum - (totalSum / 100 * 30);
	}
	else
	{
		return totalSum;
	}
}
