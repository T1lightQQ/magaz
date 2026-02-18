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