#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <unordered_set>


// ----------------Учетки-----------------
size_t userSize = 2;
std::string userStatus[3]{ "Супер Администратор", "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "login", "login1" };
std::string* passArr = new std::string[userSize]{ "parol", "parol1" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string currentStatus;
// ---------------------------------------



// -----------Cклад--------------
size_t storageSize = 0;
int* idArr;
std::string* nameArr;
unsigned int* countArr;
double* priceArr;

bool staticStorageCreated = false;

void CreateStorage();
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
inline void Getline(std::string& str);
inline void Err();
bool IsNumber(const std::string& str);

void ShowSuperAdminMenu();
void ShowUsers();
bool CheckLogin(const std::string& str);
bool CheckPass(const std::string& str);
void AddNewUsers();

// ------------------------------

int main()
{
	//setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();
	delete[]loginArr, passArr, statusArr;

	if (staticStorageCreated)
	{
		delete[]idArr, nameArr, countArr, priceArr;
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
		system("pause");
		system("cls");
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
	while (true)
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
			if (newName == "exit")
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
			if (newName == "exit")
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

				delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;

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

					delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;

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
						CreateStorage();
					}
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
			CreateStorage();
		}
		else if (currentStatus == userStatus[2])
		{
			CreateStorage();
		}
	}
	else
	{
		system("cls");
		Sleep(1500);
		std::cout << "\n\tЗавершение работы магазина";
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
				return true;
			}
		}
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
	if (str.size() <= 0 || str.size() >= 10)
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

		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
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

		}
		else if (choose == "8")
		{

		}
		else if (choose == "9")
		{

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

void changeUsers()
{
	std::string choose;
	
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить нового пользователя\n";
		std::cout << "2 - Показать пользователей\n";
		std::cout << "3 - Изменить пароль пользователя\n";
		std::cout << "4 - Удалить пользователя\n";
		std::cout << "5 - Выйти из редактора\n";
		std::cout << "Ввод: ";
		Getline(choose);
		
		if (choose == "1")
		{

		}
		else if (choose == "2" && userSize > 1)
		{
			ShowUsers();
		}
		else if (choose == "3" && userSize > 1)
		{

		}
		else if (choose == "4" && userSize > 1)
		{

		}
		else if (choose == "5" && userSize > 1)
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

void ShowUsers()
{
	std::cout << "\t" << std::left << std::setw(10) << "Логин\t" << "Пароль\t" << "Роль\n";
	for (size_t i = 1; i < userSize; i++)
	{
		std::cout << i << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passArr[i] << "\t" << statusArr[i] << "\n";
	}
	system("pause");
}

bool CheckLogin(const std::string& str)
{
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
	return false;
}

bool CheckPass(const std::string& str)
{
	if (str.size() < 8 || str.size() > 60)
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

void AddNewUsers()
{
	std::string newLogin, newPass, newRole, choose;
	bool exit;

	while (true)
	{
		while (true)
		{
			exit = true;
			system("cls");
			std::cout << "\tСоздание нового пользователя\n\n";
			std::cout << "Введите логин для нового пользователя или \"exit\" для выхода";
			Getline(newLogin);

			if (newLogin == "exit")
			{
				std::cout << "Создание прервано";
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
			exit = true;
			system("cls");
			std::cout << "Введите пароль для нового пользователя или \"exit\" для выхода";
			Getline(newPass);

			if (newPass == "exit")
			{
				std::cout << "Создание прервано";
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
			std::cout << "\tСоздание нового пользователя\n\n";
			std::cout << "Введите роль для нового пользователя или \"exit\" для выхода";
			std::cout << "1 - Админстратор\n2 - Сотрудник\nВвод - ";
			Getline(choose);

			if (choose == "exit")
			{
				std::cout << "Создание прервано";
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
				newRole == userStatus[2];
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
			std::cout << "Роль - " << newRole << "\n";
			std::cout << "Подтвердить??? \n1. Да\n2. Нет\nВвод: ";
			Getline(choose);

			if (choose == "1")
			{
				userSize++;

				std::string* loginArrTemp = new std::string[userSize];
				std::string* PassArrTemp = new std::string[userSize];
				std::string* RoleArrTemp = new std::string[userSize];
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

