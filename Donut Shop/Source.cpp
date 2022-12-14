// MP1 (donut shop) - 9/15/2022 - Jonathan Heinlein
//This program is a pos system for a donut shop that calculates total sale with tax, finds change from amount paid, and tells the user how to give the change
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	//Restart program
	int restart = 1;
	while (restart != 0) {
		//Order variables
		int fancy;
		int normal;
		int aFritters;

		//Prices and tax rate
		double fancy_price = 0.85;
		double normal_price = 0.75;
		double fdozen_price = 8.49;
		double ndozen_price = 7.99;
		double fritter_price = 1.50;
		double tax_rate = 0.075;

		//Prompts for order
		cout << "Number of regular donuts in order: "; cin >> normal;
		cout << "Number of fancy donuts in order: "; cin >> fancy;
		cout << "Number of apple fritters in order: "; cin >> aFritters;

		//Variables for sale calculation
		double sale;
		double actual_total;	//total with tax cause I want this to be on more than 1 line
		int ndozen;
		int fdozen;
		int nextra;
		int fextra;

		// Establishing dozens
		ndozen = normal / 12;
		nextra = normal % 12;
		fdozen = fancy / 12;
		fextra = fancy % 12;

		//Calculating what customer owes
		sale = (ndozen * ndozen_price) + (nextra * normal_price) + (fdozen * fdozen_price) + (fextra * fancy_price) + (aFritters * fritter_price);

		actual_total = sale + (sale * tax_rate);

		//Says amount owed by customer
		
		cout << fixed << setprecision(2) << "Customer owed: $" << actual_total;
		
		

		//Getting amount they pay
		double paid;

		cout << "\nCustomer paid: $"; cin >> paid;

		//Variables for change system
		int dollars = 0;
		int quarters = 0;
		int dimes = 0;
		int nickels = 0;
		int pennies = 0;
		double change = 0;

		//Calculating and displaying change
		change = paid - actual_total;

		//Rounding to fix issue I was having
		//Exception to fix other discrepancy
		if (change > 1 && paid < 50 || paid > 70) {
			change = ceil(change * 100.0) / 100.0;
		}
		//This variable will be used to make calculating coins easier
		int cents = change * 100;

		//For no change
		if (change < .005) {
			cout << "Exact payment recieved - no change owed.";
		}
		//For change
		else if (change > 0) {

			dollars = cents / 100;

			//Accounting for change amounts possibly causing too many digits
			cout << fixed << setprecision(2) << "Change owed is $" << change << " - ";
		

			if (dollars > 0) {
				if (dollars == 1) cout << dollars << " dollar, ";
				else cout << dollars << " dollars, ";
			}

			cents = cents % 100;
			quarters = cents / 25;
			cents = cents % 25;
			dimes = cents / 10;
			cents = cents % 10;
			nickels = cents / 5;
			cents = cents % 5;

			pennies = cents;

			//Ensuring coins won't appear in result if none are owed
			if (quarters > 0) {
				if (quarters == 1) cout << quarters << " quarter";
				else cout << quarters << " quarters";
			}
			if (dimes > 0) {
				if (dimes == 1) cout << ", " << dimes << " dime";
				else cout << ", " << dimes << " dimes";
			}
			if (nickels > 0) {
				if (nickels == 1) cout << ", " << nickels << " nickel";
				else cout << nickels << " nickels";
			}
			if (pennies > 0.00) {
				if (pennies == 1) cout << ", " << pennies << " penny";
				else cout << ", " << pennies << " pennies";
			}
			cout << ".";
		}
		cout << "\nDo another run? input 0 for no: ";
		cin >> restart;
	}
	return 0;
}
