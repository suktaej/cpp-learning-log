#include "001_namespace.h"

void NameA::NameA_FuncA()
{
	std::cout<<"namesapceA function call"<<std::endl; //scope resolution operator
}

void NameA::NameAA::NameAA_FuncA()
{
	std::cout<<"namespaceAA in namespaceA function call"<<std::endl;
}

void NameB::NameB_FuncA()
{
	std::cout<<"namespaceB function call"<<std::endl;
}
