#include <iostream>
#include <iomanip>
using namespace std;

/* Global Variables */
int devCol = 60;

/* Function Prototypes */
int readAccountNo();
int readBalanceAmount();
void printAllInfo(int, int, int, int, float, float, float, float);


int main()
{
  int accountNum;
  int balance;

  int custAcc1, custAcc2, custAcc3, custAcc4;
  float custBal1, custBal2, custBal3, custBal4;
  

  /* Displays name, section, and due date as header */
  for (int i = 1; i < 3; i++) {
    if (i == 2) {
      cout << "Name: Brady Butcher\tSection: 01\tDue Date: 02.19.2023" << endl;
    }
    cout << setw(devCol) << setfill('*') << "" << endl;
  }

  custAcc1 = readAccountNo();
  cout << custAcc1 << endl;
  cout << readBalanceAmount() << endl;


}


int readAccountNo()
{
  int accNum = 0;

  cout << "Enter Account Number: ";
  cin >> accNum;
  if (accNum < 10000 && accNum > 0) {
      return accNum;
  }
  cout << "Please enter an account number between 0 and 10000";
  return 0;
}

int readBalanceAmount()
{
  float openBal = 0;

  cout << "Enter Opening Balance: ";
  cin >> openBal;  

  return openBal;
}

void printAllInfo(int acc1, int acc2, int acc3, int acc4, float bal1, float bal2, float bal3, float bal4)
{
  
}
