#include "app.hpp"

bool CheckLogin(const std::string& str)
{
	for (size_t i = 0; i < userSize; i++)
	{
		if (str == loginArr[i])
		{
			std::cout << "\n   ";
			Sleep(1500);
			return false;
		}
	}

	if (str.size() < 5 || str.size() >= 30)
	{
		std::cout << "\n ,   5,   30 ";
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
			std::cout << " \n\n";
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
		std::cout << "\n    \n";
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
			std::cout << " \n\n";
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
		std::cout << "1 -   \n";
		std::cout << "2 -  \n";
		std::cout << "3 -   \n";
		std::cout << "4 -  \n";
		std::cout << "0 -   \n";
		std::cout << " - ";
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
				std::cout << " !\n";
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
		std::cout << "\t" << std::left << std::setw(10) << "\t\t" << "\t\t\t" << "\n";
		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t"
				<< passArr[i] << "\t\t\t" << statusArr[i] << "\n";
		}
	}
	else if (mode == 1)
	{
		system("cls");
		std::cout << "\t" << std::left << std::setw(10) << "\t\t" << "\t\t\t" << "\n";
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
			std::cout << "\t  !\n\n";
			std::cout << "     \"exit\"   - ";
			Getline(newLogin);
			if (newLogin == "exit")
			{
				std::cout << "   !\n\n";
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
			std::cout << "\t    !\n\n";
			std::cout << "      \"exit\"   - ";
			Getline(newPass);
			if (newPass == "exit")
			{
				std::cout << "   !\n\n";
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
			std::cout << "\t  !\n\n";
			std::cout << "     \"exit\"   - ";
			std::cout << "1 - \n2 - \n - ";
			Getline(choose);
			if (choose == "exit")
			{
				std::cout << "   !\n\n";
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
			std::cout << " - " << newLogin << "\n";
			std::cout << " - " << newPass << "\n";
			std::cout << " - " << newRole << "\n\n";
			std::cout << "?\n1 - \n2 - \n - ";
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
				std::cout << " ... ";
				Sleep(2000);
				std::cout << "  !\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			else if (choose == "2")
			{
				std::cout << "\n";
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

		std::cout << "\n       \"exit\"  - ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "\n  !\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);
			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "\n     !\n";
				Sleep(1500);
			}
			else
			{
				while (true)
				{
					system("cls");

					if (currentStatus == userStatus[1] && statusArr[userNumber] == userStatus[1])
					{
						std::cout << "\n   !\n";
						Sleep(1500);
						break;
					}

					std::cout << "\n     " << loginArr[userNumber] << " - ";
					Getline(newPass1);
					std::cout << "\n    " << loginArr[userNumber] << " - ";
					Getline(newPass2);
					if (CheckPass(newPass1) && CheckPass(newPass2) && newPass1 == newPass2)
					{
						passArr[userNumber] = newPass1;
						std::cout << "\n";
						Sleep(1500);
						break;
					}
					else
					{
						std::cout << " \n";
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
				std::cout << "    !\n";
				Sleep(1500);
				return;
			}
		}

		else if (currentStatus == userStatus[1])
		{
			if (staffCount < 1)
			{
				std::cout << "    !\n";
				Sleep(1500);
				return;
			}
		}

		ShowUsers();
		isAdmin = 1;

		std::cout << "\n      \"exit\"  - ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "  !\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);

			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "     !\n";
				Sleep(1500);
				break;
			}

			while (true)
			{
				system("cls");

				if (currentStatus == userStatus[1] && statusArr[userNumber] != userStatus[2])
				{
					std::cout << "  \n";
					Sleep(1500);
					break;
				}

				std::cout << "  - " << loginArr[userNumber] << "\n";
				std::cout << "      \"exit\"  - ";
				Getline(checkPass);

				if (checkPass == "exit")
				{
					std::cout << "   - " << loginArr[userNumber] << "\n\n";
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
					std::cout << " ... ";
					Sleep(2000);
					std::cout << "  !\n\n";
					Sleep(1500);
					break;

				}
				else
				{
					std::cout << " \n";
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
