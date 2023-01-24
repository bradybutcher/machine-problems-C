#include <iostream>
#include <fstream>
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
  string ifile_path = "~/Developer/C++/machine-problems-C/machineprob02/input.txt";
  string ofile_path = "~/Developer/C++/machine-problems-C/machineprob02/output.txt";
  
  ifstream inputFile;
  ofstream outputFile;
  
  string username = "Brady Butcher";
  string railroad_name;
  string destination;
  string tempStr;
  int numberOfCars;
  float singleCarWeight = 74.5; // measured in tons
  float totalWeightOfCoal; // measured in short tons
  float current_price; // USD per short ton 
  float current_surcharge = 0.0031; // set at 0.31% the valueOfShipment
  float total_surcharge; // USD
  double valueOfShipment; // USD
  
  inputFile.open(ifile_path);
  outputFile.open(ofile_path);

  getline(inputFile, railroad_name);
  getline(inputFile, destination);
  getline(inputFile, tempStr);
  numberOfCars = stoi(tempStr);
  getline(inputFile, tempStr);
  current_price = stof(tempStr);

  /* Calculations */
  totalWeightOfCoal = numberOfCars * singleCarWeight;
  valueOfShipment = totalWeightOfCoal * current_price;
  total_surcharge = valueOfShipment * current_surcharge;

  outputFile << "KERBAA & M COAL TRAIN REPORT - " << username << endl;
  outputFile << "\nRailroad Name: " << railroad_name << endl;
  outputFile << "Destination: " << destination << endl; 
}
