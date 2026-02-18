#include "app.hpp"

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

		std::cout << "\n ID     \"exit\"    - ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			if (isFirst == false)
			{
				std::cout << "  \n";
				Sleep(1500);
				break;
			}
			system("cls");
			PrintCheck(totalSum);
			std::cout << "\n ?\n1 - \n2 -   \n3 - \n - ";
			Getline(choose);
			totalSum = Discount(totalSum);
			totalSum = DiscountOfItem(totalSum);
			if (choose == "1")
			{
				while (true)
				{
					system("cls");
					std::cout << "  \n1 - \n2 - \n - ";
					Getline(choose);
					if (choose == "1")
					{
						std::cout << "\n  : " << totalSum << "\n";
						std::cout << " -  - ";
						Getline(chooseCash);
						if (IsNumber(chooseCash))
						{
							money = std::stod(chooseCash);
							if (money < totalSum)
							{
								std::cout << " !\n";
								Sleep(1500);
								continue;

							}
							else if (money - totalSum > cash)
							{
								std::cout << "   .  \n";
								Sleep(1500);
								continue;
							}
							else
							{
								std::cout << " " << money << "\n";
								Sleep(400);
								std::cout << "  .  " << money - totalSum << " \n";
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
						std::cout << " \n\n";
						Sleep(1000);
						if (rand() % 10 <= 2)
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Sleep(800);
							}
							std::cout << "\n  .  \n";
							Sleep(1500);
						}
						else
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Sleep(800);
							}
							std::cout << "\n  \n\n  !\n\n";
							Sleep(2500);
							bankIncome += totalSum;
							awardArr[currentId] += totalSum;
							system("cls");
							break;
						}
					}
					else if (choose == "rA9" || choose == "ra9")
					{
						std::cout << "\n .  \n";
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
				std::cout << " !\n";
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
				std::cout << " ID!\n";
				Sleep(1500);
				continue;
			}
		}

		std::cout << "\n -  \"exit\"     - ";
		Getline(chooseCount);
		if (chooseCount == "exit")
		{
			std::cout << "   - " << nameArr[id] << "\n";
			Sleep(1500);
			continue;
		}

		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount);

			if (count < 1 || count > countArr[id])
			{
				std::cout << " -!  - " << countArr[id] << "\n";
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


		std::cout << "\n   \n\n";
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
	std::cout << "\t" << "ID\t" << std::left << std::setw(25) << " \t\t" <<
		"  \t" << "-\t" << "\n";

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
	std::cout << "   \n\n";
	std::cout << " : " << cashIncome << "\n\n";
	std::cout << " : " << bankIncome << "\n\n";
	std::cout << " " << cashIncome + bankIncome << "\n\n";
	std::cout << "  : " << awardArr[currentId] << "\n";
	system("pause");
	system("cls");
}

double Discount(double& totalSum)
{
	if (totalSum >= 100000.0)
	{
		std::cout << "\n.      100000,      20%!\n";
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
		std::cout << "\n.    3  ,      30%   !\n";
		system("pause");
		return totalSum - (totalSum / 100 * 30);
	}
	else
	{
		return totalSum;
	}
}
