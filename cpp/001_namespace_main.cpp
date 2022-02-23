#include "001_namespace.h"

int main(void)
{
	NameA::NameA_FuncA();
	NameB::NameB_FuncA();
	NameA::NameAA::NameAA_FuncA();
	AA::NameAA_FuncA();
	return 0;
}
