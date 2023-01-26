#include <ios>
#include <iostream> // I/O (cin and cout)
#include <iomanip>  // manipulators
#include <fstream>  // file streams
#include <string>
using namespace std;

int main()
{
  /*
   * File Format
   *
   * KERBAA & M COAL TRAIN REPORT - <str::username>
   *
   * Railroad Name: <str::railroad_name> //from inputFile
   * Destination: <str::destination> //from inputFile
   *
   * Number of Ore Cars: <int::numberOfCars> //from inputFile
   * Total Weight of Coal: <float::weightOfCoal> //calculated
   * Current Cost per Short Ton: <float::current_price> //from inputFile
   * Total Value of Shipment: <double::valueOfShipment> //calculated
   * Current Surcharge: <float::current_surcharge> //calculated
   *
   * Total Surcharge (Est): <float::total_surcharge> //calculated
   */

  /* Variable Declarations */
  string ifile_path = "input.txt";
  string ofile_path = "output.txt";

  ifstream inputFile;
  ofstream outputFile;

  string username = "Brady Butcher";
  string railroad_name;
  string destination;
  string tempStr;
  int W;
  int numberOfCars;
  float singleCarWeight = 74.5;     // measured in tons
  float totalWeightOfCoal;          // measured in short tons
  float current_price;              // USD per short ton
  float current_surcharge = 0.0031; // set at 0.31% the valueOfShipment
  float total_surcharge;            // USD
  double valueOfShipment;           // USD

  /* Opens source files and does an error check to ensure files can be opened */
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

  /* Starts reading the input file line by line */
  getline(inputFile, railroad_name);
  getline(inputFile, destination);
  getline(inputFile, tempStr); // puts the int numberOfCars to a temporary string to be converted
  numberOfCars = stoi(tempStr);
  getline(inputFile, tempStr); // puts the float current_price to a temporary string to be converted
  current_price = stof(tempStr);

  /* Calculations */
  totalWeightOfCoal = numberOfCars * singleCarWeight;
  valueOfShipment = totalWeightOfCoal * current_price;
  total_surcharge = valueOfShipment * current_surcharge;

  /* Starts the write process to the output file */
  outputFile << "KERBAA & M COAL TRAIN REPORT - " << username << endl;
  outputFile << "\nRailroad Name: " << railroad_name << endl;
  outputFile << "Destination: " << destination << endl;
  outputFile << setw(45) << left << setfill('.') << "\nNumber of Ore Cars: " << right << numberOfCars << endl;
  outputFile << setw(45) << left << setfill('.') << "Total Weight of Coal: " << showpoint << setprecision(6) << right << totalWeightOfCoal << " short tons" << endl;
  outputFile << setw(45) << left << setfill('.') << "Current Cost per Short Ton: " << setprecision(4) << right << "$" << current_price << endl;
  outputFile << setw(45) << left << setfill('.') << "Total Value of Shipment: " << showpoint << setprecision(8) << right << "$" << valueOfShipment << endl;
  outputFile << setw(45) << left << setfill('.') << "Current Surcharge: " << setprecision(2) << right << (current_surcharge * 100) << "%" << endl;
  outputFile << setw(45) << left << setfill('.') << "\nTotal Surcharge (Est): " << setprecision(6) << right << "$" << total_surcharge << endl;

  inputFile.close();
  outputFile.close();
}
