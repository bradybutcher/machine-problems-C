/*
 *
 * Name: Brady Butcher
 * CPS 171, Section 01
 * Due Date: 03.08.2023
 *
 * Description:
 * This program is a bank account management system. It allows the user to create up to 4 customer accounts,
 * deposit and withdraw money, and view account information. The program will continue to run until the user
 * chooses to exit.
 */

#include <iostream>
#include <iomanip>
using namespace std;

/* Global Variables */
int devCol = 60;
int balColStr1 = 28;
int balColAcc = 5;
int balColStr2 = 10;
int balColAmt = 10;
char dolSign = '$';
int custAcc1, custAcc2, custAcc3, custAcc4;   // Customer Account Numbers
float custBal1, custBal2, custBal3, custBal4; // Customer Account Balances

/* Function Prototypes */
void title(char);
void newScreen();
void initialDeposit();
int readAccountNo();
int readBalanceAmount();
float addReturnBonus(float);
float deposit(float);
float withdraw(float);
float findAccountBal(int);
bool isDuplicate(int);
void assignAccount(int, float);
int accountMenu();
void menu();
void tryMenu();
void printAllInfo(int, int, int, int, float, float, float, float);

int main()
{
  int accountNum;
  int balance;

  title('*');
  initialDeposit();
  menu();
}

void title(char c)
{
  /* Displays name, section, and due date as header */
  for (int i = 1; i < 3; i++)
  {
    if (i == 2)
    {
      cout << "Name: Brady Butcher\tSection: 01\tDue Date: 02.19.2023" << endl;
    }
    cout << setw(devCol) << setfill(c) << "" << endl;
  }
}

void newScreen()
{
  /* Clears the screen */
  for (int i = 1; i < 3; i++)
  {
    if (i == 2)
    {
      cout << "\033[2J\033[1;1H";
    }
  }
}

void initialDeposit()
{
  /* Takes input to initialize 4 customer accounts with numbers and initial balances*/
  for (int cus = 1; cus <= 4; cus++)
  {
    cout << "Enter Customer " << cus << " Information:" << endl;

    if (cus == 1)
    {
      custAcc1 = readAccountNo();           // takes input and assigns it to the 1st customer account number
      custBal1 = readBalanceAmount();       // takes input and assigns it to the 1st customer balance
      custBal1 += addReturnBonus(custBal1); // adds the bonus to the balance
    }
    else if (cus == 2)
    {
      custAcc2 = readAccountNo();           // takes input and assigns it to the 2nd customer account number
      custBal2 = readBalanceAmount();       // takes input and assigns it to the 2nd customer balance
      custBal2 += addReturnBonus(custBal2); // adds the bonus to the balance
    }
    else if (cus == 3)
    {
      custAcc3 = readAccountNo();           // takes input and assigns it to the 3rd customer account number
      custBal3 = readBalanceAmount();       // takes input and assigns it to the 3rd customer balance
      custBal3 += addReturnBonus(custBal3); // adds the bonus to the balance
    }
    else if (cus == 4)
    {
      custAcc4 = readAccountNo();           // takes input and assigns it to the 4th customer account number
      custBal4 = readBalanceAmount();       // takes input and assigns it to the 4th customer balance
      custBal4 += addReturnBonus(custBal4); // adds the bonus to the balance
    }
  }
  newScreen(); // clears the screen
}

int readAccountNo()
{
  /* Prompts the user to enter the account number and returns it */
  int accNum = 0;

  cout << "Enter Account Number: ";
  cin >> accNum;
  isDuplicate(accNum); // checks if the account number is already in use
  if (isDuplicate(accNum) == true)
  {
    while (isDuplicate(accNum) == true) // will continue to loop until a unique account number is entered
    {
      cout << "Please enter an account number that is not already in use" << endl;
      cout << "Enter Account Number: ";
      cin >> accNum;
    }
  }
  if (accNum > 10000 || accNum < 0 || (accNum % 2 != 0)) // checks if the account number is valid (even and between 0 and 10000)
  {
    while (accNum > 10000 || accNum < 0 || (accNum % 2 != 0))
    {
      cout << "Please enter an even account number between 0 and 10000" << endl;
      cout << "Enter Account Number: ";
      cin >> accNum;
    }
  }

  return accNum; // returns the account number
}

int readBalanceAmount()
{
  /* Prompts the user to enter the opening balance and returns it */
  float openBal = 0;

  cout << "Enter Opening Balance: ";
  cin >> openBal;
  if (openBal < 0 || openBal > 200000) // checks if the balance is valid (between 0 and 200000)
  {
    cout << "Please enter an opening balance between $1 and $200,000" << endl;
  }

  return openBal; // returns the balance
}

float addReturnBonus(float balance)
{
  /* Calculates and returns the bonus based on the balance */
  float bonus = 0;

  if (balance >= 1 && balance <= 100)
  {
    bonus = balance * 0.02;
  }
  else if (balance >= 101 && balance <= 500)
  {
    bonus = balance * 0.03;
  }
  else if (balance >= 501 && balance <= 1000)
  {
    bonus = balance * 0.04;
  }
  else if (balance >= 1001)
  {
    bonus = balance * 0.05;
  }

  return bonus;
}

float deposit(float accountBalance)
{
  /* Prompts the user to enter the deposit amount and returns the new balance */
  float deposit = 0;
  float newBalance = 0;

  cout << "Enter Deposit Amount: ";
  cin >> deposit;
  if (deposit < 0 || deposit > 200000) // checks if the deposit is valid (between 0 and 200000)
  {
    cout << "Please enter an opening balance between $1 and $200,000" << endl;
  }

  newBalance = accountBalance + deposit; // calculates the new balance by adding the deposit to the current balance

  return newBalance; // returns the new balance
}

float withdraw(float accountBalance)
{
  /* Prompts the user to enter the withdraw amount and returns the new balance */
  float withdraw = 0;
  float newBalance = 0;

  cout << "Enter Withdraw Amount: ";
  cin >> withdraw;
  if (withdraw < 0 || withdraw > 200000) // checks if the withdraw is valid (between 0 and 200000)
  {
    cout << "Please enter a withdraw amount between $1 and $200,000" << endl;
  }

  if (withdraw <= accountBalance) // checks if the withdraw is valid (less than or equal to the current balance)
  {
    newBalance = accountBalance - withdraw; // calculates the new balance by subtracting the withdraw from the current balance
  }

  return newBalance; // returns the new balance
}

float findAccountBal(int account)
{
  /* Finds the balance of the account number entered and returns it */
  int bal = 0;

  if (account == custAcc1)
  {
    bal = custBal1;
  }
  else if (account == custAcc2)
  {
    bal = custBal2;
  }
  else if (account == custAcc3)
  {
    bal = custBal3;
  }
  else if (account == custAcc4)
  {
    bal = custBal4;
  }

  return bal;
}

bool isDuplicate(int account)
{
  /* Checks if the account number is already in use and returns true or false */
  bool duplicate = false;

  if (account == custAcc1 || account == custAcc2 || account == custAcc3 || account == custAcc4)
  {
    duplicate = true;
  }

  return duplicate;
}

void assignAccount(int account, float balance)
{
  /* Finalizes the deposit into the correct account */
  if (account == custAcc1)
  {
    custBal1 = balance;
  }
  else if (account == custAcc2)
  {
    custBal2 = balance;
  }
  else if (account == custAcc3)
  {
    custBal3 = balance;
  }
  else if (account == custAcc4)
  {
    custBal4 = balance;
  }
}

int accountMenu()
{
  int accChoice;
  /* Displays the account menu and calls the appropriate functions based on the user's choice */
  cout << "1 - Account Number: " << setw(balColAcc) << setfill(' ') << custAcc1 << endl;
  cout << "2 - Account Number: " << setw(balColAcc) << setfill(' ') << custAcc2 << endl;
  cout << "3 - Account Number: " << setw(balColAcc) << setfill(' ') << custAcc3 << endl;
  cout << "4 - Account Number: " << setw(balColAcc) << setfill(' ') << custAcc4 << endl;
  cout << endl;

  cout << "Enter Account: ";
  cin >> accChoice;

  switch (accChoice)
  {
  case 1:
    accChoice = custAcc1;
    break;
  case 2:
    accChoice = custAcc2;
    break;
  case 3:
    accChoice = custAcc3;
    break;
  case 4:
    accChoice = custAcc4;
    break;
  default:
    cout << "Invalid Choice" << endl;
    break;
  }

  return accChoice;
}

void menu()
{
  /* Displays the main menu and calls the appropriate functions based on the user's choice */
  char menuChoice;
  float balance = 0;
  int accountNum = 0;

  cout << "Main Menu" << endl;
  cout << "=========" << endl;
  cout << endl;
  cout << "1 -\t Withdraw" << endl;
  cout << "2 -\t Deposit" << endl;
  cout << "3 -\t View Accounts" << endl;
  cout << "4 -\t Exit" << endl;
  cout << endl;
  cout << "Enter Choice: ";
  cin >> menuChoice;

  switch (menuChoice)
  {
  case '1': // Withdraw
    newScreen();
    cout << "Withdraw Menu" << endl;
    cout << "=============" << endl;
    cout << endl;
    accountNum = accountMenu(); // displays the account menu and returns the account number
    balance += findAccountBal(accountNum);
    cout << "Current Balance: $" << balance << endl;
    balance = withdraw(balance); // calculates the new balance
    if (balance < 0)             // checks if the withdraw can be made
    {
      newScreen();
      balance = 0; // resets the balance to 0 and does not commit the withdraw
      cout << "Withdraw Unsuccessful!" << endl;
      cout << "Withdraw amount exceeds funds in account" << endl;
    }
    else // commits the withdraw
    {
      assignAccount(accountNum, balance); // assigns the new balance to the correct account
      newScreen();
      cout << "Withdraw Successful!" << endl;
      cout << endl;
      cout << "New Balance: $" << balance << endl; // displays the new balance
    }
    break;
  case '2': // Deposit
    newScreen();
    cout << "Deposit Menu" << endl;
    cout << "============" << endl;
    cout << endl;
    accountNum = accountMenu();            // displays the account menu and returns the account number
    balance += findAccountBal(accountNum); // finds the current balance of the account
    cout << "Current Balance: $" << balance << endl;
    balance = deposit(balance);         // calculates the new balance
    assignAccount(accountNum, balance); // assigns the new balance to the correct account
    newScreen();
    cout << "Deposit Successful!" << endl;
    cout << endl;
    cout << "New Balance: $" << balance << endl; // displays the new balance
    break;
  case '3': // View Accounts
    newScreen();
    cout << "Account Balances:" << endl;
    printAllInfo(custAcc1, custAcc2, custAcc3, custAcc4, custBal1, custBal2, custBal3, custBal4); // displays all account balances
    break;
  case '4': // Exit
    cout << "Exiting..." << endl;
    exit(0);
  default: // If Invalid Choice is Entered
    cout << "Invalid Choice" << endl;
    break;
  }
  cout << endl;
  tryMenu();
}

void tryMenu()
{
  /* Asks the user if they would like to make another transaction and calls the menu function if they do */
  char choice;

  cout << "Would you like to make another transaction? (Y/N): ";
  cin >> choice;

  if (choice == 'Y' || choice == 'y')
  {
    newScreen();
    menu();
  }
  else if (choice == 'N' || choice == 'n')
  {
    cout << "Exiting..." << endl;
    exit(0);
  }
  else
  {
    cout << "Invalid Choice" << endl;
  }
}

void printAllInfo(int acc1, int acc2, int acc3, int acc4, float bal1, float bal2, float bal3, float bal4)
{
  /* Displays all account balances in a table */
  for (int i = 1; i < 3; i++)
  {
    if (i == 2)
    {
      for (int cus = 1; cus <= 4; cus++)
      {
        if (cus == 1)
        {
          cout << setw(balColStr1) << left << "Balance Amount for Customer ";
          cout << setw(balColAcc) << left << setfill(' ') << fixed << acc1;
          cout << setw(balColStr2) << right << setfill(' ') << dolSign;
          cout << setw(balColAmt) << left << setprecision(2) << bal1 << endl;
        }
        else if (cus == 2)
        {
          cout << setw(balColStr1) << left << "Balance Amount for Customer ";
          cout << setw(balColAcc) << left << setfill(' ') << fixed << acc2;
          cout << setw(balColStr2) << right << setfill(' ') << dolSign;
          cout << setw(balColAmt) << left << setprecision(2) << bal2 << endl;
        }
        else if (cus == 3)
        {
          cout << setw(balColStr1) << left << "Balance Amount for Customer ";
          cout << setw(balColAcc) << left << setfill(' ') << fixed << acc3;
          cout << setw(balColStr2) << right << setfill(' ') << dolSign;
          cout << setw(balColAmt) << left << setprecision(2) << bal3 << endl;
        }
        else if (cus == 4)
        {
          cout << setw(balColStr1) << left << "Balance Amount for Customer ";
          cout << setw(balColAcc) << left << setfill(' ') << fixed << acc4;
          cout << setw(balColStr2) << right << setfill(' ') << dolSign;
          cout << setw(balColAmt) << left << setprecision(2) << bal4 << endl;
        }
      }
    }
    cout << setw(devCol) << setfill('-') << "" << endl;
  }
}
