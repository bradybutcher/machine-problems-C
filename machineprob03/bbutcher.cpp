/*
 * --- Machine Problem 03 - Selection ---
 *  @ Brady Butcher
 *  2.2.2023
 *  CPS 171 - 01
 *
 * Calculate the monthly bill for a cell phone user given the following rate structure:
 *  1. All evening and night calls that begin from 6pm (exactly) up to and including 5:59am are free and there is no limit on these minutes used. As long as the call starts before 6am (even if it lasts until after 6am) it is counted as a night time call.
 *  2. The basic monthly rate is $39.99 which includes the first 200 minutes of daytime calls (from 6am up to and including 5:59pm).  These can be within the calling area or long distance. If a call begins before 6pm and lasts until after 6pm, the entire call is treated as a daytime call.
 *  3. As soon as the 200 minutes have been used, there is a charge for daytime calls at the rate of $0.29 per minute if the call is within the area, or $0.69 per minute for long distance. For the one call that begins before the 200 minutes have been used but lasts until over the 200 minutes, only the portion over the 200 minutes is charged.  All subsequent daytime calls are charged for the entire duration of the call.  Again, if a call begins in the daytime period and is subject to charge, the entire duration is chargeable (as above).
 */

#include <cstddef>
#include <cstdio>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  int time; // 24h clock
  int duration; // duration of call in minutes
  int dayCall = 600; // 6:00am
  int nightCall = 1800; // 6:00pm
  int limit = 200;
  int minUsed = 0;
  int col0, col1, col2, col3, col4, col5;

  char callType; // local (A) or long distance (L)
  float monthlyRate = 39.99;
  float additionalRate;
  float totalCost = 0;
  float callCost = 0;

  string name = "Brady Butcher";
  string cell0 = " ";
  string cell1 = "Time";
  string cell2 = "Duration";
  string cell3 = "Call Type";
  string cell4 = "Minutes Used";
  string cell5 = "Cost";

  string ifile_path("input.txt");
  string ofile_path("output.txt");

  ifstream inputFile;
  ofstream outputFile;

  
  inputFile.open(ifile_path);
  if( !inputFile ) { // file couldn't be opened
    std::cerr << "Error: Input file could not be opened" << endl;
      exit(1);
  }
  outputFile.open(ofile_path);
  if( !outputFile ) { // file couldn't be opened
    std::cerr << "Error: Output file could not be opened" << endl;
      exit(1);
  }


  col0 = 4, col1 = 15, col2 = 15, col3 = 15, col4 = 15, col5 = 15; // sets column widths

  outputFile << "Cell Provider Bill - " << name << "\n" << endl; // title
  outputFile << "Standard Base Rate: $" << monthlyRate << "\n" << endl; // base rate
  outputFile << setw(col1) << left << cell1 << setw(col2) << left << cell2 << setw(col3) << left << cell3 << setw(col4) << left << cell4 << setw(col5) << left << cell5 << "\n"; // prints column titles
  outputFile << setw(col0 + col1 + col2 + col3 + col4 + col5) << setfill('-') << "" << endl;


  while (inputFile >> time >> duration >> callType) // stays in the loop until the pointer reaches the end of the file
  {
    if (inputFile.eof()) break;
    
    // read file here
    outputFile << setw(col0) << right << setfill('0') << time << setfill(' '); // fills leading zeros in 'time' output (if any needed)
    outputFile << setw(col1 - col0) << right << setfill(' ') << " "; // makes the column in between time and duration even with the rest
    outputFile << setw(col2) << left << duration;
    outputFile << setw(col3) << left << callType;

    if (time >= dayCall && time <= nightCall) // if it is a day call, increase the minutes used, otherwise do nothing
    {
      minUsed += duration;
    }
    outputFile << setw(col4) << left << minUsed;

    
    if (minUsed <= limit) // runs if the calls have not exceeded the 200 minute limit
    {
      additionalRate = 0;
      if (time <= dayCall || time >= nightCall) // all night calls are free
        {
          outputFile << setw(col5) << left << "Free" << endl;
            callCost = 0;
        } else {
          outputFile << setw(col5) << left << setprecision(4) << callCost << endl; // displays call cost if it is a day call
        }
    } else if (minUsed >= limit) { // runs if the calls have exceeded the 200 minute limit
        if (time >= dayCall && time <= nightCall) // checks if the call is placed during the day, if so enters the loop to determine extra charge rate
        {
          if (callType == 'A') // if the call type is local (A)
          {
            additionalRate = 0.29;
            callCost = additionalRate * (minUsed - limit); // only charges for the minutes used after the 200 minute limit
          } else if (callType == 'L') { // if the call type is long-distance (L)
              additionalRate = 0.69;
              callCost = additionalRate * (minUsed - limit); // only charges for the minutes used after the 200 minute limit
            } else {
                cout << "Error: Call Type not defined" << endl; // checks for human error in input (restrains call types to only A or L)
                return 1; // exits if there is an error detected
            }
          outputFile << setw(col5) << left << setprecision(4) << callCost << endl; // displays call cost after determining whether the call was local (A) or long-distance (L)
        } else if (time <= dayCall || time >= nightCall) { // checks if the call was placed at night, if so then there was no charge
            outputFile << setw(col5) << left << "Free" << endl;
            callCost = 0;
          }
      }
    
    totalCost += callCost; // adding the total cost during iteration
  } 

  outputFile << fixed << setprecision(2) << "\nTotal Month Cost: $" << totalCost + monthlyRate << endl;


  inputFile.close();
  outputFile.close();

  return 0;
}
