#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include "date.h"

class SavingAccount{
	private:
			std:: string id;
			double balance;
			double rate;
			Date lastDate;
			double accumulation;
			static double total;
			
			//record the date, amount of the money and information for every deal
			void record(const Date &date, double amount, const std::string &info);
			
			//report error message
			void error(const std::string &msg) const;

			//get the specific date money
			double accumulate(const Date &date) const{
					return accumulation+balance*date.distance(lastDate);
			}

	public:
			SavingAccount(const Date &date, const std::string &id, double rate);
			const std::string &getId() const{
				return id;
			};
			double getBalance(){
				return balance;
			}
			double getRate(){
				return rate;
			}
			static double getTotal(){
				return total;
			}
			void deposit(const Date &date, double amount, const std::string &info);

			void withdraw(const Date &date, double amount, const std::string &info);

			void settle(const Date &date);

			void show() const;
};
#endif 