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
  int numberOfCars;
  float singleCarWeight = 74.5;     // measured in tons
  float totalWeightOfCoal;          // measured in short tons
  float current_price;              // USD per short ton
  float current_surcharge = 0.0031; // set at 0.31% the valueOfShipment
  float total_surcharge;            // USD
  double valueOfShipment;           // USD

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

  getline(inputFile, railroad_name);
  getline(inputFile, destination);
  getline(inputFile, tempStr);
  numberOfCars = stoi(tempStr); // throws run-time error here: "std::stoi no conversion"
  getline(inputFile, tempStr);
  current_price = stof(tempStr);

  /* Calculations */
  totalWeightOfCoal = numberOfCars * singleCarWeight;
  valueOfShipment = totalWeightOfCoal * current_price;
  total_surcharge = valueOfShipment * current_surcharge;

  outputFile << "KERBAA & M COAL TRAIN REPORT - " << username << endl;
  outputFile << "\nRailroad Name: " << railroad_name << endl;
  outputFile << "Destination: " << destination << endl;
  outputFile << "\nNumber of Ore Cars: " << numberOfCars << endl;
  outputFile << "Total Weight of Coal: " << totalWeightOfCoal << " short tons" << endl;
  outputFile << "Current Cost per Short Ton: $" << current_price << endl;
  outputFile << "Total Value of Shipment: $" << valueOfShipment << endl;
  outputFile << "Current Surcharge: " << (current_surcharge * 100) << "%" << endl;
  outputFile << "\nTotal Surcharge (Est): $" << total_surcharge << endl;

  inputFile.close();
  outputFile.close();
}
