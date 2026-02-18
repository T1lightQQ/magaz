#include "app.hpp"

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