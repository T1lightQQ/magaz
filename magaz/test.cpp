#define BOOST_TEST_MODULE MagazTests
#include <boost/test/unit_test.hpp>

#include <sstream>

#include "app.hpp"

namespace
{
	class CinRedirect
	{
	public:
		explicit CinRedirect(const std::string& input) : stream(input), old(std::cin.rdbuf(stream.rdbuf())) {}
		~CinRedirect() { std::cin.rdbuf(old); }

	private:
		std::istringstream stream;
		std::streambuf* old;
	};
}

BOOST_AUTO_TEST_CASE(SuperAdmin_ShowStorage_Works)
{
	if (!staticStorageCreated)
	{
		CreateStorage();
	}
	BOOST_CHECK_NO_THROW(ShowStorage());
}

BOOST_AUTO_TEST_CASE(SuperAdmin_AddStorageItem_Works)
{
	if (!staticStorageCreated)
	{
		CreateStorage();
	}
	CinRedirect in("exit\n");
	BOOST_CHECK_NO_THROW(AddStorageItem());
}

BOOST_AUTO_TEST_CASE(SuperAdmin_RemoveStorageItem_Works)
{
	if (!staticStorageCreated)
	{
		CreateStorage();
	}
	CinRedirect in("exit\n");
	BOOST_CHECK_NO_THROW(RemoveStorageItem());
}

BOOST_AUTO_TEST_CASE(SuperAdmin_ChangePrice_Works)
{
	if (!staticStorageCreated)
	{
		CreateStorage();
	}
	CinRedirect in("exit\n");
	BOOST_CHECK_NO_THROW(ChangePrice());
}

BOOST_AUTO_TEST_CASE(SuperAdmin_ChangeStorage_Works)
{
	if (!staticStorageCreated)
	{
		CreateStorage();
	}
	CinRedirect in("4\n");
	BOOST_CHECK_NO_THROW(ChangeStorage());
}

BOOST_AUTO_TEST_CASE(SuperAdmin_ChangeUsers_Works)
{
	CinRedirect in("0\n");
	BOOST_CHECK_NO_THROW(ChangeUsers());
}

BOOST_AUTO_TEST_CASE(SuperAdmin_ShowIncome_Linked)
{
	BOOST_CHECK_NE(reinterpret_cast<void*>(&ShowInCome), nullptr);
}

BOOST_AUTO_TEST_CASE(SuperAdmin_Logout_Works)
{
	currentId = 1;
	CinRedirect in("exit\n");
	BOOST_CHECK(!Logout());
}

BOOST_AUTO_TEST_CASE(SuperAdmin_Selling_Works)
{
	if (!staticStorageCreated)
	{
		CreateStorage();
	}
	CinRedirect in("exit\n");
	BOOST_CHECK_NO_THROW(Selling());
}
