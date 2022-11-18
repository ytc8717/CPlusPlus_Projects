#include "JollyBanker.h"

// driver for jollybanker
int main()
{
	JollyBanker bank;
	bank.ReadFile();
	bank.ProcessTransaction();
	bank.PrintResults();

	system("pause");
	return 0;
}