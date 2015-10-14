#ifndef TEST_H
#define TEST_H

/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Time:13th October
@Github:www.github.com/JieTrancender
*/

//MAQ stand for My Array Queue
namespace MAQ
{
#include <iostream>

	class PC
	{
	public:
		PC() : m_user("Admin"), m_password("123456") {};
		PC(std::string user, std::string password) : m_user(user), m_password(password) {};
		PC & operator = (const PC &pc)
		{
			m_user = pc.m_user;
			m_password = pc.m_password;
			return *this;
		}
		bool operator==(const PC pc) const
		{
			return m_user == pc.m_user && m_password == pc.m_password ? true : false;
		}
		bool operator!=(const PC &pc) const
		{
			return m_user != pc.m_user && m_password != pc.m_password ? true : false;
		}

		friend std::ostream &operator << (std::ostream &os, const PC &pc);

	private:
		std::string m_user;
		std::string m_password;
	};

	std::ostream &operator << (std::ostream &os, const PC &pc)
	{
		os << pc.m_user << pc.m_password << std::endl;
		return os;
	}
}

#endif //test.hpp
