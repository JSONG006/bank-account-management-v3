#include<iostream>
#include "v3.h"

using namespace std;

int main(){
	Date date(2013,10,1); // set the system initial day.

	SavingAccount accounts[] = {
		SavingAccount(date, "1001", 0.015),
		SavingAccount(date, "1007", 0.015)
	};

	const int length = sizeof(accounts)/sizeof(SavingAccount);

	accounts[0].deposit(Date(2013,10,20), 100, "salary");
	accounts[1].deposit(Date(2013,10,10), 1000, "sell stock 007");
	
	accounts[0].deposit(Date(2013,11,20), 300, "salary");
	accounts[1].withdraw(Date(2013,11,28), 130, "buy a car");

	cout<<endl;
	int i;
	for(i=0; i<length; i++){
		accounts[i].settle(Date(2014, 1 ,1));
		accounts[i].show();
		cout<<endl;
	}
	cout<<"Total: "<<SavingAccount:: getTotal()<<endl;
	system("pause");
	return 0;
}