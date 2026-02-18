#include "app.hpp"

void Start()
{
	std::string choose;
	std::cout << "\n\n\n\t\t\t\n\n\n\n\n\n";
	while (true)
	{
		if (Login())
		{
			if (currentStatus == userStatus[0])
			{
				while (true)
				{
					std::cout << " : \n1. \n2.  " << "\n: ";
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
			std::cout << "       - ";
			Getline(choose);
			if (choose == passArr[0])
			{
				system("cls");
				std::cout << "    - " << cashIncome + bankIncome << " ";
				Sleep(1500);
				std::cout << "\n\n\t  \n\n";
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
		std::cout << "  - ";
		Getline(login);
		std::cout << "  - ";
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
				std::cout << " - " << loginArr[i] << "\n\n \n";
				std::cout << "  - " << statusArr[i] << "\n\n";
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
	std::cout << "       \"exit\"";
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

void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}

void Err()
{
	std::cout << " \n";
	Sleep(1500);
	system("cls");
}

bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 100)
	{
		std::cout << "\n\t ";
		std::cout << "\n\t  \n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			Err();
			std::cout << "  \n\n";
			return false;
		}
		return true;
	}
}

