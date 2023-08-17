#include <iostream>
using namespace std;

const int SIZE = 1000;

string names[SIZE];
double salaries[SIZE];
int ages[SIZE];
string genders[SIZE];

void employeeProgram();
int menu();
void addEmployee();
void viewEmployee();
void deleteEmployeeByAge();

int added = 0;

int menu()
{
  int choice = -1;
  while (choice == -1)
  {
    cout << "\nEnter your choice\n";
    cout << "1) Add new employee\n";
    cout << "2) Print all empolyees\n";
    cout << "3) Delete by age\n";
    cout << "4) Update salary by name\n";

    cin >> choice;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore();
      cout << "Enter valid number\n";
      continue;
    }
    else if (!(choice >= 1 && choice <= 4))
    {
      cout << "Invalid choice. Try again\n";
      choice = -1;
    }
    else
    {
      return choice;
    }
  }
}

void addEmployee()
{
  string name, gender;
  int age;
  double salary;

  cout << "Enter name: ";
  cin >> name;
  names[added] = name;

  cout << "Enter age: ";
  cin >> age;
  ages[added] = age;

  cout << "Enter salary: ";
  cin >> salary;
  salaries[added] = salary;

  cout << "Enter gender: ";
  cin >> gender;
  genders[added] = gender;

  added++;
}

void viewEmployee()
{
  for (int i = 0; i < added; i++)
  {
    if (ages[i] != -1)
    {
      cout << endl;
      cout << names[i] << ", "
           << ", " << genders[i] << ", " << ages[i] << ", " << salaries[i] << endl;
    }
  }
}

void deleteEmployeeByAge()
{
  int start, end;
  cout << "Enter start age you want to delete from: ";
  cin >> start;
  cout << "\n";
  cout << "Enter end age you want to delete to: ";
  cin >> end;

  for (int i = 0; i < added; i++)
  {
    if (ages[i] >= start && ages[i] <= end)
    {
      ages[i] = -1;
    }
  }
}

void updateEmployee()
{
  string name;
  double salary;
  cout << "Enter employee name: ";
  cin >> name;
  cout << "\n";
  cout << "Enter employee salary: ";
  cin >> salary;

  bool isFound = false;

  for (int i = 0; i < added; i++)
  {
    if (ages[i] != -1 && names[i] == name)
    {
      isFound = true;
      salaries[i] = salary;
      break;
    }
  }

  if (!isFound)
  {
    cout << "Employee not found\n";
  }
}

void employeeProgram()
{
  while (true)
  {
    int choice = menu();

    if (choice == 1)
    {
      addEmployee();
    }
    else if (choice == 2)
    {
      viewEmployee();
    }
    else if (choice == 3)
    {
      deleteEmployeeByAge();
    }
    else if (choice == 4)
    {
      updateEmployee();
    }
    else
    {
      break;
    }
  }
}

int main()
{
  employeeProgram();

  return 0;
}