#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

#define ACC_LEN 256

class AccountHandler
{
	private:
		//Account* Accarr[ACC_LEN];
		BoundCheckAccountPtrArray Accarr;
		int Accnum;
	protected:
		void MakeNormalAccount(void);
		void MakeCreditAccount(void);
	public:
		AccountHandler();
		void ShowMenu(void) const;
		void MakeAccount(void);
		void DepositMoney(void);
		void WithdrawMoney(void);
		void ShowAll(void) const;
		~AccountHandler();
};

#endif
