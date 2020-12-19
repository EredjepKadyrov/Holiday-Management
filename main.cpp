#include <iostream>
#include<ctime>
#include<vector>
#include <array>
using namespace std;





class Date{
    private:
        short day;
        short month;
        int age;
        int yearOfBirth;
	public:
        void enterDate();
        void showData();
        void incrementByOneMonth();
        void showAge();

};

void Date::enterDate()
{

    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> yearOfBirth;


}

void Date::showData()
{

    cout << " |||Date Of Bith:  ";
    cout << day << "." << month << "." << yearOfBirth << endl;
    time_t timestamp; // Assign current date and time to variable
    tm *date; // Pointer object holding date and time
    timestamp = time(0); // Assignment of the number of seconds that have elapsed since 1 Jan. 1970
    date = localtime(&timestamp); // localtime returns pointer holding the current time specification
    int actYear = date->tm_year+1900; // Current year is determined and set (starting from 1900)
    age = actYear - yearOfBirth;



}
void Date::showAge()
{


    cout << " |||Age:  "  << age << endl;
    if (age == 50) {
        //age of 50 on 1 January of the current calendar year are entitled to a holiday of 32 days
        int hol = 32;
    cout << " |||Holidays:  "  << hol << endl;
    } else {
        int hol = 30;
    cout << " |||Holidays:  "  << hol << endl;
    }


}


void Date:: incrementByOneMonth()
{
    if(month == 12)
    {
        yearOfBirth =  yearOfBirth + 1;
        month=(month%12)+1;
    }
    else if(day == 28 && month == 2)
    {
        day = 31;
        month+=1;
    }
    else if(day <= 28)
    {
        month+=1;
    }
    else if(day > 28 && day <= 31 && month == 1)
    {
        day = 28;
        month+=1;
    }
    else if(day==31 && month != 7)
    {
        switch (month)
        {
            case 3:
            case 5:
            case 8:
            case 10:
                {
                    day=30;
                    month+=1;
                    break;
                }
        }
    }
    else if(day==30)
    {
        switch (month)
        {
            case 4:
            case 6:
            case 9:
            case 11:
                {
                    day=31;
                    month+=1;
                    break;
                }
        }
    }
    else
        month+=1;
}


class Employee {
private:
    // Data members
    string firstName;
    string surname;
    Date dateOfBirth;

    int id;

    unsigned int holidays;
    bool Stock;
    int countHolidays;
    int age;
public:
    //default constructor
    Employee() {}
    Employee(string f, string s,  Date d, int i ) : firstName(f), surname(s),dateOfBirth(d), id(i) {
    }
    void EnterEmployee(void);
    void DeleteEmployee(void);
    void SearchEmployee(void);
	void ShowEmployee(void);


	//getter & setter

    void set_name(string n) { firstName = n; }
	string get_name() { return firstName; }
    void set_sname(string sn) { surname = sn; }
	string get_sname() { return surname; }
	int get_holidays() { return holidays; }
	void set_id(int i) { id = i; }
	int get_id () { return id; }
	void set_dateOfbith(Date d) { dateOfBirth = d; }
	Date get_dateOfbith () {return dateOfBirth;}
	bool get_Stock() { return Stock; }

};

    //constructor with member initialization list

    void Employee :: EnterEmployee(void)
    {
    cout << "--Enter Data --" << endl;
    cout << "First name: ";
    cin >> firstName;
    cout << "Surname: ";
    cin >> surname;
    cout << "--Day of birth--" << endl;
    dateOfBirth.enterDate();
    cout << "Id number: ";
    cin >> id;
    cout << endl;
    Stock = true; //Employee is in stock
   };

    void Employee :: ShowEmployee(void)
    {
    Employee e;
    cout << " |||Employee FirstName : " << firstName << endl;
	cout << " |||Employee SurName : " << surname<< endl;
	cout << " |||ID: " << id << endl;
	dateOfBirth.showData();
    dateOfBirth.showAge();
    };

    void Employee::DeleteEmployee(void)
{
	cout<<"Which employee to delete from stock? Please give an employee ID "<<endl;
	cin>> id;
	firstName = "";
	surname = "";
	age = 0;
	holidays = 0;
	id = 0;
    Stock=false;
} ;


class HourlyEmployee : public  Employee

{
    private:

        float hourlyWage;
        float hoursWorked;
    public:
    HourlyEmployee () {}
    HourlyEmployee (string f, string s, Date d, int i, float hw, float hrw) : Employee(f, s, d, i), hourlyWage(hw), hoursWorked(hrw){}
       void EnterEmployee()
      {
       Employee::EnterEmployee();
       cout << "Hourly Wage: ";
       cin >> hourlyWage;
       cout << "Hours Worked: ";
       cin >> hoursWorked;
       cout << endl << "Hourly Employee has been entered." << endl;

      }
       void ShowEmployee()
      {
       Employee::ShowEmployee();
       cout << " |||Hourly Wage: " << hourlyWage << endl;
       cout << " |||Hourly Worked: " << hoursWorked << endl;
       cout << endl << "Hourly Employee." << endl;

      }

};

class SalariedEmployee : public  Employee

{
    private:

        int annualSalary;
    public:
    SalariedEmployee () {}
    SalariedEmployee (string f, string s, Date d, int i, int as) : Employee(f, s, d, i), annualSalary(as){}
       void EnterEmployee()
      {
       Employee::EnterEmployee();
       cout << "Annual salary: ";
       cin >> annualSalary;
       cout << endl << "Salaried Employee has been entered." << endl;

      }

      void ShowEmployee()
      {
       Employee::ShowEmployee();
       cout << " |||Annual salary: " << annualSalary << endl;
       cout << endl << "Salaried Employee." << endl;

      }

};


class Manager : public  Employee

{
    private:

        int profitSharing;
    public:
    Manager () {}
    Manager (string f, string s, Date d, int i, int ps) : Employee(f, s, d, i), profitSharing(ps){}
       void EnterEmployee()
      {
       Employee::EnterEmployee();
       cout << "Profit Sharing: ";
       cin >> profitSharing;
       cout << endl << "Manager has been entered." << endl;

      }
        void ShowEmployee()
      {
       Employee::ShowEmployee();
       cout << " |||Profit Sharing: " << profitSharing <<endl;
       cout << endl << "Employee has a Manager role." << endl;


      }

};


class Holiday{
private:
    string title;

public:
    Holiday() {};
    Holiday(string t) : title(t) {};
    void showData();
};

void Holiday::showData()
{
    cout << title ;
}


class Loan {
private:
    Employee borrower;
    Holiday borrowedHoliday;
    Date returnDate;
    bool has_holiday;
public:
    Loan() { has_holiday = false; };
    void enterData(Employee,Holiday,Date);
    void showData();
    void extend();
    void giveBack();
    bool get_has_holiday();
};

void Loan::enterData(Employee p, Holiday b, Date d)
{
    borrower = p;
    borrowedHoliday = b;
    returnDate = d;
    has_holiday = true;
}

void Loan::showData()
{
    borrower.ShowEmployee();
    cout << endl << "On Holiday: ";
    borrowedHoliday.showData();
    cout << endl << "Return until: ";
    returnDate.showData();
}

void Loan::extend()
{
    returnDate.incrementByOneMonth();
    cout << "Due to private(family/health) reasons the unplanned vacation was extended by 1 month." << endl;
    cout << "Please ticket in JIRA" << endl;
}

void Loan:: giveBack()
{
    cout << "Holiday ";
    borrowedHoliday.showData();
    cout << " was returned." << endl;
    has_holiday = false;
}

bool Loan::get_has_holiday()
{
    return has_holiday;
}

int main(void)
{
   int s=0, eing, nr; // declared integer s to zero is used for the menu
   int i = 0;
   int input;
   Loan a;
   Date d;
   Holiday b[2] = {{"Annual Holiday"},{"National holiday"}};
   string input_empl;

   HourlyEmployee hmployees[500];
   SalariedEmployee smployees[500];
   Manager mmployees[500];

   vector<Employee> Emp; //one way was to use vector but need more time for c++ development

   time_t timetoday;
   time (&timetoday);

   cout << " Welcome to the STAFF HOLIDAY MANAGEMENT" << endl << endl;
   cout << " -- Todays is : "<< asctime(localtime(&timetoday));
   cout << " Please select from the menu..." << endl << endl << endl;


   // While-loop that contains menu and submenu

   do
   {
    s = 0;
	//The menu
	cout << "--------MENU----------" << endl;
	cout << " [1] Create employee" << endl;
	cout << " [2] Show all employees " << endl;
	cout << " [3] Search employee " << endl;
    cout << " [4] Delete employee " << endl;
    cout << " [5] Take holiday " << endl;
    cout << " [6] Extend holiday " << endl;
    cout << " [7] Return holiday " << endl;
	cout << " [0] Exit " << endl<<endl;
	cout << "Please select: ";
	cin >> input;
   //switch query loads into the individual menu items

	switch(input)
	{
    //: Hourly/Salaried/Manager
		case 1 : {   //Function to create employee

			system("cls");
			cout << " Please write ho/sa/ma (Hourly/Salaried/Manager) " << endl;
			cin >> input_empl;
			//hmployees[i].EnterEmployee();
			if(input_empl == "ho"){
                cout << "The employee has been entered: " << endl;
                hmployees[i].EnterEmployee(); // Function to enter an employee
			} else if (input_empl == "sa"){
                smployees[i].EnterEmployee(); // Function to enter an employee
			} else if (input_empl == "ma"){
                mmployees[i].EnterEmployee(); // Function to enter an employee
			} else {
			  cout << " Error, employee was not created, please try again indicate right group: ho/sa/ma ! " << endl;

			}
			cout << "The employee has been entered: " << endl;
			i++;
			break;
		}
		case 2 : { //Function to show all the employees
			system("cls");
            cout << " Please write to show: Hourly/Salaried/Manager (ho/sa/ma) " << endl;
			cin >> input_empl;

			if(input_empl == "ho"){
                cout << "Show Hourly employee: " << endl;
                for(int j = 0; j < i; j++)
			{
			    hmployees[j].ShowEmployee();
                cout << endl;
			}
			} else if (input_empl == "sa"){
			     cout << "Show Salary employee: " << endl;
			     for(int j = 0; j < i; j++)
			{
			    smployees[j].ShowEmployee();
                cout << endl;
			}

			} else if (input_empl == "ma"){
			     cout << "Show Manager employee: " << endl;
                 for(int j = 0; j < i; j++)
			{
                 mmployees[j].ShowEmployee();
                cout << endl;
			}

			} else {

			  cout << " Error! Please try again! " << endl;
			  cout << endl;

			}

			break;
		}
        case 3 : { //Function to search an employee
			system("cls");
			cout << " Please write group where to search Hourly/Salaried/Manager (ho/sa/ma) " << endl;
			cin >> input_empl;
			if(input_empl == "ho"){
			cout << "Please enter the Hourly employee ID to search: " << endl;
			cin >> nr;
			bool tmp = false;
			for(int j = 0; j < i; j++)
			{
				if(hmployees[j].get_id() == nr && hmployees[j].get_Stock() == 1)
				{
					hmployees[j].ShowEmployee();
					tmp = true;
					break;
				}
				else if (hmployees[j].get_id() == nr && hmployees[j].get_Stock() == 0)
				{
					cout << "Hourly Employees with ID " << hmployees[j].get_id() << " is not in stock." << endl;
					tmp = true;
					break;
				}
			}
			if(!tmp) //if no employee was found
				cout << "Hourly Employee with number " << nr << " was not found." << endl;

			break;
			} else if(input_empl == "sa"){
			   	cout << "Please enter the Salaried employee ID to search: " << endl;
			cin >> nr;
			bool tmp = false;
			for(int j = 0; j < i; j++)
			{
				if(smployees[j].get_id() == nr && smployees[j].get_Stock() == 1)
				{
					smployees[j].ShowEmployee();
					tmp = true;
					break;
				}
				else if (smployees[j].get_id() == nr && smployees[j].get_Stock() == 0)
				{
					cout << "Salaried Employees with ID " << smployees[j].get_id() << " is not in stock." << endl;
					tmp = true;
					break;
				}
			}
			if(!tmp) //if no employee was found
				cout << "Hourly Employee with number " << nr << " was not found." << endl;

			break;
			}
			else if(input_empl == "ma"){
			   	cout << "Please enter the Manager Employee ID to search: " << endl;
			cin >> nr;
			bool tmp = false;
			for(int j = 0; j < i; j++)
			{
				if(mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 1)
				{
					mmployees[j].ShowEmployee();
					tmp = true;
					break;
				}
				else if (mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 0)
				{
					cout << "Manager Employees with ID " << mmployees[j].get_id() << " is not in stock." << endl;
					tmp = true;
					break;
				}
			}
			if(!tmp) //if no employee was found
				cout << "Manager Employee with number " << nr << " was not found." << endl;

			break;
			}
		}
        case 4 : { //Function to delete employee
			system("cls");
			cout << " Please write group where to delete Hourly/Salaried/Manager (ho/sa/ma) " << endl;
			cin >> input_empl;
			if(input_empl == "ho"){
			cout << "Please enter the Hourly employee ID to delete: " << endl;
			cin >> nr;
			bool tmp = false;
			for(int j = 0; j < i; j++)
			{
				if(hmployees[j].get_id() == nr && hmployees[j].get_Stock() == 1)
				{
					hmployees[j].DeleteEmployee();
					tmp = true;
					break;
				}
				else if (hmployees[j].get_id() == nr && hmployees[j].get_Stock() == 0)
				{
					cout << "Hourly Employees with ID " << hmployees[j].get_id() << " is not in stock." << endl;
					tmp = true;
					break;
				}
			}
			if(!tmp) //if no employee was found
				cout << "Hourly Employee with number " << nr << " was not found." << endl;

			break;
			} else if(input_empl == "sa"){
			   	cout << "Please enter the Salaried employee ID to delete: " << endl;
			cin >> nr;
			bool tmp = false;
			for(int j = 0; j < i; j++)
			{
				if(smployees[j].get_id() == nr && smployees[j].get_Stock() == 1)
				{
					smployees[j].DeleteEmployee();
					tmp = true;
					break;
				}
				else if (smployees[j].get_id() == nr && smployees[j].get_Stock() == 0)
				{
					cout << "Salaried Employees with ID " << smployees[j].get_id() << " is not in stock." << endl;
					tmp = true;
					break;
				}
			}
			if(!tmp) //if no employee was found
				cout << "Hourly Employee with number " << nr << " was not found." << endl;

			break;
			}
			else if(input_empl == "ma"){
			   	cout << "Please enter the Manager Employee ID to delete: " << endl;
			cin >> nr;
			bool tmp = false;
			for(int j = 0; j < i; j++)
			{
				if(mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 1)
				{
					mmployees[j].DeleteEmployee();
					tmp = true;
					break;
				}
				else if (mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 0)
				{
					cout << "Manager Employees with ID " << mmployees[j].get_id() << " is not in stock." << endl;
					tmp = true;
					break;
				}
			}
			if(!tmp) //if no employee was found
				cout << "Manager Employee with number " << nr << " was not found." << endl;

			break;
			}
		}

        case 5:  //Function  to take holiday

            {
                system("cls");
                cout << " Please choose group of users: Hourly/Salaried/Manager (ho/sa/ma) " << endl;
                cin >> input_empl;
                if(input_empl == "ho"){
                cout << "Hourly employee: " << endl;
				cout << "Please enter the Hourly employee ID to search: " << endl;
			    cin >> nr;
			    bool tmp = false;
			    for(int j = 0; j < i; j++)
			    {
				    if(hmployees[j].get_id() == nr && hmployees[j].get_Stock() == 1)
				    {
                       if(a.get_has_holiday() == true)
                       {
                       cout << "Vacation is not possible. Person has already has vacation" << endl;
                       }
                       else
                       {
                       cout << "Which kind of holiday should be used?" << endl;
                       for(int i=0;i<2;i++)
                       {
                          cout << "[" << i+1 << "] ";
                          b[i].showData();
                          cout << endl;
                        }
                        cout << endl << "Please select: ";
                        cin >> input;

                        system("cls");
                        cout << "Until when are you planning to return?" << endl;
                        d.enterDate();

                        for(int j = 0; j < i; j++)
			            {
			            a.enterData(hmployees[j],b[input-1],d);
                        cout << endl;
                        }

                        }

                        system("pause");
                        system("cls");
                        break;
                     }
				     else if (hmployees[j].get_id() == nr && hmployees[j].get_Stock() == 0)
				         {
					     cout << "Hourly Employees with ID " << hmployees[j].get_id() << " is not in stock." << endl;
					     tmp = true;
					     break;
				         }
                }
                } else if(input_empl == "sa"){
                cout << "Salary employee: " << endl;
				cout << "Please enter the Hourly employee ID to search: " << endl;
			    cin >> nr;
			    bool tmp = false;
			    for(int j = 0; j < i; j++)
			    {
				    if(smployees[j].get_id() == nr && smployees[j].get_Stock() == 1)
				    {
                       if(a.get_has_holiday() == true)
                       {
                       cout << "Vacation is not possible. Person has already has vacation" << endl;
                       }
                       else
                       {
                       cout << "Which kind of holiday should be used?" << endl;
                       for(int i=0;i<2;i++)
                       {
                          cout << "[" << i+1 << "] ";
                          b[i].showData();
                          cout << endl;
                        }
                        cout << endl << "Please select: ";
                        cin >> input;

                        system("cls");
                        cout << "Until when are you planning to return?" << endl;
                        d.enterDate();

                        for(int j = 0; j < i; j++)
			            {
			            a.enterData(smployees[j],b[input-1],d);
                        cout << endl;
                        }

                        }

                        system("pause");
                        system("cls");
                        break;
                     }
				     else if (smployees[j].get_id() == nr && smployees[j].get_Stock() == 0)
				         {
					     cout << "Salary Employees with ID " << smployees[j].get_id() << " is not in stock." << endl;
					     tmp = true;
					     break;
				         }
                }
                }
                else if(input_empl == "ma"){
                cout << "Manager employee: " << endl;
				cout << "Please enter the Manager employee ID to search: " << endl;
			    cin >> nr;
			    bool tmp = false;
			    for(int j = 0; j < i; j++)
			    {
				    if(mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 1)
				    {
                       if(a.get_has_holiday() == true)
                       {
                       cout << "Vacation is not possible. Person has already has vacation" << endl;
                       }
                       else
                       {
                       cout << "Which kind of holiday should be used?" << endl;
                       for(int i=0;i<2;i++)
                       {
                          cout << "[" << i+1 << "] ";
                          b[i].showData();
                          cout << endl;
                        }
                        cout << endl << "Please select: ";
                        cin >> input;

                        system("cls");
                        cout << "Until when are you planning to return?" << endl;
                        d.enterDate();

                        for(int j = 0; j < i; j++)
			            {
			            a.enterData(mmployees[j],b[input-1],d);
                        cout << endl;
                        }
                    //a.enterData(hmployees[j],b[input-1],d);
                        }

                        system("pause");
                        system("cls");
                        break;
                     }
				     else if (mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 0)
				         {
					     cout << "Manager Employees with ID " << mmployees[j].get_id() << " is not in stock." << endl;
					     tmp = true;
					     break;
                         }
                    }
                } else {

			        cout << " Error! Please try again! " << endl;
			        cout << endl;

			    }
			    break;

            }
        case 6:  //Function  to take extend holiday
            {
                system("cls");
                cout << " Please choose group of users: Hourly/Salaried/Manager (ho/sa/ma) " << endl;
                cin >> input_empl;
                if(input_empl == "ho"){
                cout << "Hourly employee: " << endl;
				cout << "Please enter the Hourly employee ID to search: " << endl;
			    cin >> nr;
			    bool tmp = false;
			    for(int j = 0; j < i; j++)
			    {
				    if(hmployees[j].get_id() == nr && hmployees[j].get_Stock() == 1)
				    {
                         if(a.get_has_holiday() == true)
                         a.extend();
                         else
                         cout << "Person has not used vacation yet." << endl;
                         system("pause");
                         system("cls");
                         break;
                    }
                    else if (hmployees[j].get_id() == nr && hmployees[j].get_Stock() == 0)
				         {
					     cout << "Hourly Employees with ID " << hmployees[j].get_id() << " is not in stock." << endl;
					     tmp = true;
					     break;
				         }
                    }
                }
                else if(input_empl == "sa"){
                cout << "Salary employee: " << endl;
				cout << "Please enter the Salary employee ID to search: " << endl;
			    cin >> nr;
			    bool tmp = false;
			    for(int j = 0; j < i; j++)
			    {
				    if(smployees[j].get_id() == nr && smployees[j].get_Stock() == 1)
				    {      if(smployees[j].get_id() == nr && smployees[j].get_Stock() == 1)
				         {
                         if(a.get_has_holiday() == true)
                         a.extend();
                         else
                         cout << "Person has not used vacation yet." << endl;
                         system("pause");
                         system("cls");
                         break;
                         }
                         else if (smployees[j].get_id() == nr && smployees[j].get_Stock() == 0)
				         {
					     cout << "Salary Employees with ID " << smployees[j].get_id() << " is not in stock." << endl;
					     tmp = true;
					     break;
				         }
                    }
                }
                }
                else if(input_empl == "ma"){
                cout << "Manager employee: " << endl;
				cout << "Please enter the Manager employee ID to search: " << endl;
			    cin >> nr;
			    bool tmp = false;
			    for(int j = 0; j < i; j++)
			    {
				    if(mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 1)
				    {
				         if(mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 1)
				         {
                         if(a.get_has_holiday() == true)
                         a.extend();
                         else
                         cout << "Person has not used vacation yet." << endl;
                         system("pause");
                         system("cls");
                         break;
                         }
                        else if (mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 0)
				         {
					     cout << "Manager Employees with ID " << mmployees[j].get_id() << " is not in stock." << endl;
					     tmp = true;
					     break;
				         }
                    }
                }
                }
                else {

			        cout << " Error! Please try again! " << endl;
			        cout << endl;

			    }
			    break;
			    }
        case 7: //Function  to take return holiday
            {
                system("cls");
                cout << " Please choose group of users: Hourly/Salaried/Manager (ho/sa/ma) " << endl;
                cin >> input_empl;
                if(input_empl == "ho"){
                cout << "Hourly employee: " << endl;
				cout << "Please enter the Hourly employee ID to search: " << endl;
			    cin >> nr;
			    bool tmp = false;
			    for(int j = 0; j < i; j++)
			    {
				    if(hmployees[j].get_id() == nr && hmployees[j].get_Stock() == 1)
				    {
                       if(a.get_has_holiday() == true)
                       a.giveBack();
                       else
                       cout << "Person has not used vacation yet." << endl;
                       system("pause");
                       system("cls");
                       break;
                     }

				     else if (hmployees[j].get_id() == nr && hmployees[j].get_Stock() == 0)
				         {
					     cout << "Hourly Employees with ID " << hmployees[j].get_id() << " is not in stock." << endl;
					     tmp = true;
					     break;
				         }
                }
                } else if(input_empl == "sa"){
                 cout << "Salary employee: " << endl;
				cout << "Please enter the Salary employee ID to search: " << endl;
			    cin >> nr;
			    bool tmp = false;
			    for(int j = 0; j < i; j++)
			    {
				    if(smployees[j].get_id() == nr && smployees[j].get_Stock() == 1)
				    {
                       if(a.get_has_holiday() == true)
                       a.giveBack();
                       else
                       cout << "Person has not used vacation yet." << endl;
                       system("pause");
                       system("cls");
                       break;
                     }

				     else if (smployees[j].get_id() == nr && smployees[j].get_Stock() == 0)
				         {
					     cout << "Salary Employees with ID " << smployees[j].get_id() << " is not in stock." << endl;
					     tmp = true;
					     break;
				         }
                }
                } else if(input_empl == "ma"){
                 cout << "Manager employee: " << endl;
				cout << "Please enter the Manager employee ID to search: " << endl;
			    cin >> nr;
			    bool tmp = false;
			    for(int j = 0; j < i; j++)
			    {
				    if(mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 1)
				    {
                       if(a.get_has_holiday() == true)
                       a.giveBack();
                       else
                       cout << "Person has not used vacation yet." << endl;
                       system("pause");
                       system("cls");
                       break;
                     }

				     else if (mmployees[j].get_id() == nr && mmployees[j].get_Stock() == 0)
				         {
					     cout << "Manager Employees with ID " << mmployees[j].get_id() << " is not in stock." << endl;
					     tmp = true;
					     break;
				         }
                }
                }
                else {

			        cout << " Error! Please try again! " << endl;
			        cout << endl;

			    }
			    break;

            }
		/* case 0 terminates program
	because s is set to 1*/

       case 0:
            {
                cout << endl << "Goodbye" << endl;
                return 0;
            }
        default:
            {
                cout << endl << "Incorrect input!" << endl;
                system("pause");
            }
        }
    }while(input!=0);

    return 0;
}
