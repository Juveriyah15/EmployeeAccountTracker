
// CSCE 1040.312 - Lab 1 assignment
//Juveriyah Haq, 8/25/25, This program keeps track of employee name, id, and their withdrawls/deposits from accounts.
#include <iostream> // cin, cout
#include <iomanip> // setw, fixed, setprecision
#include <string> // string
#include <stdio.h> // printf, scanf

using namespace std;
// Employee structure
struct Employee
{
	string name;
	int id;
};
// Customer structure
struct Customer 
{
	string name;
	int id;
	float balance;
};

int main() 
{
	Employee emp[50]; // array of employee
	Customer cus[50]; // array of customer
	int empCount = 0; // empployee index counter
	int cusCount = 0; // customer index counter
	char type;
	
	//print out table headings

        cout << "*************** Transaction Information ***************" << endl;
        cout << left << setw(15) <<"Customer" << left << setw(15) <<" Employee" << left << setw(15) << "Transaction" << "Balance" << endl;
        cout << "--------------------------------------------------------" << endl;

	while( cin >> type ) 
	{
		if(type == 'e') 
		{
			cin >> emp[empCount].id >> emp[empCount].name;
			empCount++;
		}	
		else if (type == 'c') 
		{
			cin>> cus[cusCount].id >> cus[cusCount].name >> cus[cusCount].balance;
			cusCount++;;
		}
		else if (type == 't') 
		{
			int cusID;
			int empID;
			char trans;
			double money;

			cin >> cusID >> empID >> trans >> money;

			//search for the customer using their ID
			int cusSearch = -1;
			for(int i = 0; i < cusCount; i++)
			{
				if(cus[i].id == cusID)
				{
					cusSearch = i;
				}
			}
			
			//search for employee using their ID
			int empSearch = -1;
			for(int i = 0; i < empCount; i++)
			{
				if( emp[i].id == empID)
				{
					empSearch= i;
				}
			}

			//update the account balance with the transaction
			if (trans == 'w')
			{
				cus[cusSearch].balance -= money;
			}
			else if (trans == 'd')
			{
				cus[cusSearch].balance += money;
			}
	
			//print out the transaction results
			cout << fixed << setprecision(2);	
			cout << left << setw(15) << cus[cusSearch].name << left << setw(15)<<  emp[empSearch].name;
			
			if(trans == 'w')
			{
				cout << "-$" << money << "\t" << "\t";
			}
			else
			{
				cout << "+$" << money << "\t" << "\t";
			}
		
			cout << "$" << cus[cusSearch].balance << endl;


		}
		else {
		
			cout << "invalid data type " << type << "entered.";
		}
	}
	return 0;
}

