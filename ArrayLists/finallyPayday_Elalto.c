#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char fname[20];
	char lname[20];
}name;

typedef struct{
	int oneHundreds;
	int twoHundreds;
	int fiveHundreds;
	int oneThousands;
}bills;

typedef struct{
	bills bankBills;
	char bankLocation[20];
	int balance;
}bank;

typedef struct{
	name personName;
	bills personBalance;
	int onPersonBalance;
	int bankAccountBalance;
}person;

int main(){


	//Initialize bank to hold 50 one hundred bills, 50 two hundred bills, 40 five hundred bills, 20 one thousand bills.

	//Initialize their current balance to be the total of all their bills.

	//Initialize mainPerson to initially hold 0 of all bills, and 0 in onPersonBalance(cash)

}


	return 0;
}
