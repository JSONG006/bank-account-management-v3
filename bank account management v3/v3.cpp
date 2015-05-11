#include "v3.h"
#include <cmath>
#include <iostream>

using namespace std;

double SavingAccount:: total=0;

SavingAccount:: SavingAccount(const Date &date, const std::string &id, double rate) : id(id), balance(0), rate(rate), lastDate(date),accumulation(0){
	date.show();
	cout<<"\tID: #"<<id<<" has been created"<<endl;
}

void SavingAccount:: record(const Date &date, double amount, const std::string &info){
	accumulation = accumulate(date);
	lastDate = date;
	amount = (amount*100+0.5)/100;
	balance+=amount;
	total+= amount;
	date.show();
	cout<<"\tID: #"<<id<<"    Amount: "<<amount<<"    Balance: "<<balance<<"    Information: "<<info<<endl;
}

void SavingAccount:: error(const string &msg) const{
	cout<<"Error(#"<<id<<"): "<<msg<<endl;
}

void SavingAccount::deposit(const Date &date, double amount, const std::string &info){
	record(date, amount, info);
}

void SavingAccount:: withdraw(const Date &date, double amount, const std::string &info){
	if(amount>getBalance()){
		error("not enough money");
	}
	else{
		record(date,-amount,info);
	}
}

void SavingAccount::settle(const Date &date){
	double interest = accumulate(date)*rate/date.distance(Date(date.getYear()-1,1,1));
	if(interest!=0){
		record(date, interest, "interest");
	}
	accumulation=0;
}

void SavingAccount:: show() const{
	cout<<"ID: "<<id<<"\tBalance: "<<balance;
}