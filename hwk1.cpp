#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct Student
{
	int id;
	string first;
	string last;
	int exam1;
	int exam2;
	int exam3;
	float avg;
};

int main()
{
	cout <<"+----------------------------------+" << endl;
	cout <<"| Computer Science and Engineering |" << endl;
	cout <<"| CSCE 1040 - Computer Science II  |" << endl;
	cout <<"| Juveriyah Haq        jh1484      |" << endl;
	cout <<"|     juveriyahhaq@my.unt.edu      |" << endl;
	cout <<"+----------------------------------+" << endl;
	
	Student* students = new Student[25];
	int num = 0;

	int menu;

	do{
		cout << "\nMenu\n";
		cout <<"1. Display Student Info\n";
		cout <<"2. Add New Student\n";
		cout <<"3. Update existing Student\n";
		cout <<"4. Compute Exam Average\n";
		cout <<"5. Compute Minimum Average\n";
		cout <<"6. Compute Maximum Average\n";
		cout <<"7. Exit Program\n";
		cin >> menu;

		if (menu == 1)
		{
			if(num ==0)
			{
				cout << "Empty list of students.\n";
			}
			else
			{
				cout << "************************* Students Information ***********************\n";
				cout << left << setw(12) << "ID" << setw(12) << "First" << setw(12) << "Last" << setw(8) << "Exam 1" << setw(8) << "Exam 2" << setw(8) << "Exam 3" << setw(8) << "Average" << endl;
			       cout << "---------------------------------------------------------------------\n";

				for(int i = 0; i < num; i++)
				{
					cout << left << setw(12) << students[i].id << setw(12) << students[i].first << setw(12) << students[i].last << setw(8) << students[i].exam1 << setw(8) << students[i].exam2 << setw(8) << students[i].exam3 << setw(8) << fixed << setprecision(2) << students[i].avg << endl;
				}
			}
		}
		else if( menu == 2)
		{
			if (num < 25)
			{
				cout << "Enter student's information\n";
				cout <<"ID: ";
				cin >> students[num].id;
				cout <<"First name: ";
				cin >> students[num].first;
				cout <<"Last name: ";
				cin >> students[num].last;
				cout << "Exam 1 score: ";
				cin >> students[num].exam1;
				cout << "Exam 2 score: ";
				cin >> students[num].exam2;
				cout << "Exam 3 score: ";
				cin >> students[num].exam3;

				students[num].avg = (students[num].exam1 + students[num].exam2 + students[num].exam3) / 3.0;

				cout <<"New student with id " << students[num].id << " added.\n";
				num++;
			}
			else
			{
				cout <<" Array full.\n";
			}
		}
		else if(menu == 3)
		{
			int search;
			cout << "Please enter student ID: ";
			cin >> search;
			bool found = false;

			for (int i = 0; i < num; i++)
			{
				if(students[i].id == search)
				{
					cout << "Update student's information\n";
					cout <<"ID: " << search << endl;

					cout <<"First name: ";
				       	cin >> students[i].first;
					cout <<"Last name: ";
					cin >> students[i].last;
                                	cout << "Exam 1 score: ";
                                	cin >> students[i].exam1;
                                	cout << "Exam 2 score: ";
                                	cin >> students[i].exam2;
                                	cout << "Exam 3 score: ";
                                	cin >> students[i].exam3;

					students[i].avg = (students[i].exam1 + students[i].exam2 + students[i].exam3) / 3.0;

					cout <<"Student's information with id" << search <<" updated.\n";
					found = true;
					break;
				}
			}
			if(!found)
			{
				cout <<"There was no ID match." << endl;
			}
		}
		else if(menu == 4)
		{
			if( num == 0)
			{
				cout <<"No students.\n";
			}
			else
			{
				float total = 0;
				for( int i = 0; i < num; i++)
				{
					total += students[i].avg;
				}
				
				cout << "Average: " << fixed << setprecision(2) << total / num << endl;
				
			}
		}
		else if( menu == 5)
		{
			if(num == 0)
			{
				cout << "No students\n";
			}
			else
			{
				float min = students[0].avg;
				for(int i = 1; i < num; i++)
				{
					if(students[i].avg < min)
					{
						min = students[i].avg;
					}
				}	
				
				cout << "Minimum average: " << fixed << setprecision(2) << min << endl;
	
			}
		} 
		else if( menu == 6)
		{
			if( num == 0)
			{
				cout <<"No students.\n";
			}
			else
			{
				float max = students[0].avg;
				for( int i = 1; i < num; i++)
				{
					if(students[i].avg > max)
					{
						max = students[i].avg;
					}
				}
				cout << "Maximum average: " << fixed << setprecision(2) << max << endl;
				
			}
		}
		else if( menu !=7)
		{
			cout << "Invalid input. Try again.\n";
		}
	}while(menu !=7);
	
	
	cout << "Thank you for using this program. Goodbye!\n";

 	

			       	


















}
