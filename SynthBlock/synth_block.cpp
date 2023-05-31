#include "synth_block.h"

template<class T> inline
std::list<T> operator+(const std::list<T>& first, const std::list<T>& second)
{
	std::list<T> newList(first.cbegin(), first.cend());
	newList.insert(newList.end(), second.cbegin(), second.cend());
	return newList;
}

bool BF_grammar::EQUAL(std::shared_ptr<Symbol> A, std::shared_ptr<Symbol> B)
{
	for (auto& it : m_rules)
	{
		for (auto first = it.second.m_right_part.begin(), second = (++it.second.m_right_part.begin()); second != it.second.m_right_part.end() && first != it.second.m_right_part.end(); ++first, ++second)
		{
			if (*A == *(*first) && *B == *(*second))
				return true;
		}
	}

	return false;
}

bool BF_grammar::MORE(std::shared_ptr<Symbol> A, std::shared_ptr<Symbol> B)
{
	bool res = false;

	for (auto &it : m_rules)
		for (auto first = it.second.m_right_part.begin(), second = (++it.second.m_right_part.begin()); second != it.second.m_right_part.end() && first != it.second.m_right_part.end(); ++first, ++second)
		{
			bool B_in_FIRST1_of_second = false;                  //Флаг говорит, что В входит в FIRST1 от second
			auto FIRST1_of_second = FIRST1(* second);             
			for (auto& that : FIRST1_of_second)
			{
				if (that->m_id == B->m_id)
					B_in_FIRST1_of_second = true;
			}

			if (((dynamic_cast<Terminal*>(B.get())) && *B == *(*second)) || B_in_FIRST1_of_second && (dynamic_cast<Non_terminal*>(first->get())))
			{
				auto first_end = END1(*first);
				for (auto& that : first_end)
				{
					if (that->m_id == A->m_id)
						res = true;
				}
			}
		}

	return res;
}
