#ifndef __STRING_H__
#define __STRING_H__

#include<iostream>
#include<string>

class Printer{

	private:
		std::string str;
	public:
		void SetString(std::string s);
		void ShowString(void);
};

#endif
