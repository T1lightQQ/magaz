#include "app.hpp"

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