#include<iostream>

namespace NameA
{
	void NameA_FuncA();
	
	namespace NameAA
	{
		void NameAA_FuncA();
	}
}

namespace NameB
{
	void NameB_FuncA();
}

namespace AA=NameA::NameAA;
