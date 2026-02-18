#include "app.hpp"

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
		std::cout << "\n  \n   ?\n: ";
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
		std::cout << "ID\t" << std::left << std::setw(25) << " \t\t" <<
			"\t" << "-\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i]
				<< "\t" << priceArr[i] << "\t" << countArr[i] << "\n";
		}
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << " \t\t" << "-\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i]
				<< "\t" << countArr[i] << "\n";
		}

	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << " \t\t" <<
			"\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i]
				<< "\t" << priceArr[i] << "\n";
		}

	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << " \t\t" << "\n";

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

		std::cout << "\n\t ID    : ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "  \n";
			Sleep(1500);
			break;
		}

		std::cout << "\n\t -   : ";
		Getline(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > 50)
			{
				std::cout << "\n\n\t ID\n\n";
				Sleep(1500);

			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					"\t" << countArr[id] << " --> " << countArr[id] + count << "\n\n";

				std::cout << "?\n1. \n\t2. \n: ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] += count;
					std::cout << "  \n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "  \n";
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

		std::cout << "\n\t ID    : ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "  \n";
			Sleep(1500);
			system("cls");
			break;
		}

		std::cout << "\n\t -   : ";
		Getline(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > countArr[id])
			{
				std::cout << "\n\n\t ID\n\n";
				Sleep(1500);

			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					"\t" << countArr[id] << " --> " << countArr[id] - count << "\n\n";

				std::cout << "?\n1. \n\t2. \n: ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] -= count;
					std::cout << "  \n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "  \n";
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

		std::cout << "\n\t ID     : ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "   \n";
			Sleep(1500);
			break;
		}

		std::cout << "\n\t   : ";
		Getline(newPrice);

		if (IsNumber(chooseId) && IsNumber(newPrice))
		{
			id = std::stoi(chooseId) - 1;
			price = std::stoi(newPrice);

			if (id < 0 || id > storageSize - 1 || price < 0.0 || price > 700000)
			{
				std::cout << "\n\n\t ID  \n\n";
				Sleep(1500);

			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					"\t" << priceArr[id] << " --> " << price << "\n\n";

				std::cout << "?\n\t1. \n\t2. \n\t: ";
				Getline(choose);
				if (choose == "1")
				{
					priceArr[id] = price;
					std::cout << "   \n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "   \n";
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
		std::cout << "\n\t1.   \n\t2.   \n\t3.  \n\t4.   \n\t";
 		std::cout << ": ";
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
			std::cout << "\t  \n\t \"exit\"  ";
			std::cout << "\n\t   : ";
			Getline(newName);
			if (newName == "exit")
			{
				std::cout << "  ";
				Sleep(1500);
				exit = false;
				break;
			}

			if (newName.size() <= 0 || newName.size() >= 100)
			{
				std::cout << " ,   ";
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
			std::cout << "\t  \n\t \"exit\"  ";
			std::cout << "\n\t -  : ";
			Getline(newCount);
			if (newCount == "exit")
			{
				std::cout << "  ";
				Sleep(1500);
				exit = false;
				break;
			}

			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > 100)
				{
					std::cout << "\n\t ,   100 .\n\t";
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
			std::cout << "\t  \n\t \"exit\"  ";
			std::cout << "\n\t   : ";
			Getline(newPrice);
			if (newPrice == "exit")
			{
				std::cout << "  ";
				Sleep(1500);
				exit = false;
				break;
			}

			if (IsNumber(newPrice))
			{
				price = std::stoi(newPrice);
				if (price > 100000000)
				{
					std::cout << "\n\t ,   1 .\n\t";
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
			std::cout << "\n\t :" << newName << "\n\t: " << price << "\n\t: " << count;
			std::cout << "\n\t???\n\t1. \n\t2. \n\t: ";
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
				std::cout << "\n\t  !";
				system("pause");
				break;
			}
			else if (choose == "2")
			{
				std::cout << "\n\t";
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
		std::cout << "\t  \n\t \"exit\"  ";
		std::cout << "\n\t id    : ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "  ";
			Sleep(1500);
			break;
		}

		std::cout << "\n\t   : ";
		Getline(newName);

		if (newName.size() <= 0 || newName.size() >= 60)
		{
			std::cout << "\n\t    \n\t";
			Sleep(1500);
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;

			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "\n\t ID\n\t";
				Sleep(1500);
				system("cls");
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					" --> " << newName << "\n\n";

				std::cout << "\n? \n1. \n2. \n - ";
				Getline(choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "\n\t  \n\t";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "\n\t \n\t";
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
		std::cout << " ID     \"exit\"  \n: ";
		Getline(chooseId);	

		if (chooseId == "exit")
		{
			std::cout << "  \n";
			Sleep(1500);
			break;
		}

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "\n\t ID\n\t";
				Sleep(1500);
				system("cls");
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << " -  ";

				std::cout << "\n? \n1. \n2. \n: ";
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
					std::cout << "\n\t  !";
					system("pause");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "\n\t \n";
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
