# Holiday Management(Project created by Eredjep Kadyrov)
##  - Holiday Management


I created a program for the staff holiday management at a college.
Each employee is entitled to 30 days off per year(was not used counter to counter used and remaining days).
Employees who have reached the age of 50 on 1 January of the current calendar year are entitled to a holiday of 32 days.
The following data of each employee is stored in the system:

#### Surname
#### First name
#### Date of birth
#### Days of holiday 
In addition, there are following three subclasses, which inherit the properties from the Employee class:

#### HourlyEmployee, from whom the following additional information is stored in the system:

Hourly wage
Hours worked

#### SalariedEmployee

Annual salary

#### Manager

Profit sharing

When the program starts, the "database" of the holiday management is empty, the data must first be entered.

The data only available during runtime (no permanent storage!).

##  - Process Description
Program that covers the following situation:

• Staff holiday management for a maximum of 500 employees of each kind/group (In the programm 500 HourlyEmployee(ho), 500 SalariedEmployee(sa), 500 Manager(ma))

• Creating and deleting an employee by ID (on stack)

• Entering the days on which the employee wants to take a holiday (must be possible more than once). In this case I used annual holiday and 

occasional holiday(such as Family/ Health issues and so on)

• Extend the holidays on special case which the employee wants family issues/health and so on 

• Search for an employee by ID and output of his/her data and how many total days of holiday he/she has 

(for the future development  we can add counter to the code to count remaining days of holiday he/she has)

• Listing of all stored employee data





##  - For the submission task a maximum of 30 points can be achieved:
#### • 60% Syntax and semantics (correctness)

       20% Documentation (comprehensibility)

       10% Structuring (readability of the source code, OO principles)

       10% Creativity and your own ideas!


