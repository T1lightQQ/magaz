#include "app.hpp"

void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "\n\t1.  \n\t2.  \n\t3.  \n\t4.  "
			<< "\n\t5.  \n\t6. . \n\t7. . \n\t8.   \n\t9.  \n\t";
		std::cout << ": ";
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
				std::cout << " ";
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
		std::cout << "1 -  \n";
		std::cout << "2 -  \n";
		std::cout << "3 -  \n";
		std::cout << "4 -  \n";
		std::cout << "5 -  \n";
		std::cout << "6 -  \n";
		std::cout << "7 -   \n";
		std::cout << "0 -  \n";
		std::cout << " - ";
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
				std::cout << " !\n";
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
		std::cout << "1 -  \n";
		std::cout << "2 -  \n";
		std::cout << "3 -   \n";
		std::cout << "0 -  \n";
		std::cout << " - ";
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
				std::cout << " !\n";
			}
			Err();
		}
	}
}
