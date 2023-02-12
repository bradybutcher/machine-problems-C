/*
 * --- Machine Problem 04 - Repetition ---
 *  CPS 171-01
 *  @Brady Butcher
 *  2.9.2023
 *
 *  Write a program which finds and writes all the abundant numbers which are smaller or equal to the smallest natural number that has exactly six proper divisors.  For each of the abundant numbers that it finds, the program output should include:
	    •	that particular abundant number,
	    •	the list of its proper divisors,
	    •	the sum of those divisors,
	    •	the total number of proper divisors
	    •	the appropriate messages.
 *  Finally, print out the natural number that has exactly six proper divisors.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

/* Global Variables */
int natNum;

ofstream outputFile;


/* Functions */
int divisorSum(int num) // finds and returns the summation of the divisors of int num
{
    // Final result of summation of divisors
    int result = 0;
    if(num == 1) // there will be no proper divisor
      return result;
    // find all divisors which divides 'num'
    for (int i = 2; i <= sqrt(num); i++)
    {
        // if 'i' is divisor of 'num'
        if (num % i == 0)
        {
            // if both divisors are same then add
            // it only once else add both
            if (i == (num / i))
                result += i;
            else
                result += (i + num/i);
        }
    }
    // Add 1 to the result as 1 is also a divisor
    return (result + 1);
}

void findDivisors(int n) // finds the divisors of int n
{
    for (int i = 1; i < n; i++)
    {
      if (n % i == 0) {
         outputFile << i << " ";
      } 
  }
  outputFile << endl;
}

int numberOfDiv(int n) // returns the number of divisors that are in the input
{
  int count = 0;
  for (int i = 1; i < n; i++)
  {
    if (n % i == 0)
    {
      count++; // increment the number of divisors every time a proper divisor is reached
    }
  }
  return count;
}



int main ()
{
  int tempNum = 0; // used to find the first natural number with 6 divisors


  outputFile.open("output.txt");
  if (!outputFile) {
  std:cerr << "Error: Output file could not be opened" << endl;
    exit(1);
  }

  /* Finds the first natural number with exactly 6 divisors*/
  while (tempNum != 100) { // setting a random boundary
    if (numberOfDiv(tempNum) == 6) { 
      natNum = tempNum; // assigns the tempNum to the natNum if the number of divisors is 6
      break;
    }
    tempNum++; // increments the tempNum otherwise
  }

  /* Finds every abundant number between 0 and natNum */
  for (int i = 1; i < natNum; i++)
  {
    if (i == 1)
    {
      continue;
    }

    if (i < divisorSum(i)){ // if abundant, output the following
      outputFile << "The Number " << i << " Is An Abundant Number" << endl;
      outputFile << "The sum of the proper divisors is " << divisorSum(i) << " which is greater than " << i << endl;
      outputFile << "The proper divisors are: ";
      findDivisors(i);
      outputFile << "There are " << numberOfDiv(i) << " divisors for the number " << i << endl;
    } else {
      continue; // otherwise, ignore and continue searching
    }
    outputFile << "\n" << endl;
  }

  /* Finally prints the natural number and the divisors */
  outputFile << "The smallest natural number with 6 divisors is: " << natNum << endl;
  outputFile << "The proper divisors of " << natNum << " are: ";
  findDivisors(natNum); // finds the divisors of the natural number
  
  outputFile << "\nThe sum of the divisors is: " << divisorSum(natNum);

  return (0);
}
