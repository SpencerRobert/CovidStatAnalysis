/*
	Spencer Poultney 250982673
	driver.cpp file includes my main method and implements my country.cpp
															               */
#include <stdio.h>
#include "country.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 


int main() {

	vector<country> ctryVector;	//Vector to store each country object created in loop
	string line; 
	ifstream file; 
	string rmvFirstLine; 
	const int MAXHASHMARKS = 70;
	
	
	//Get name of file from user input
	string fileName;
	cout << "Enter the name of the data file" << endl;
	cin >> fileName;
	
	file.open(fileName);
	getline(file, rmvFirstLine);	//Take the first line which stores no real data and get rid of it into string
	
	while(getline(file, line)) {	//Store each line in file in line
	
		stringstream strStream(line);
		vector<string> tokenVec;	//To store string tokens
		vector<int> tokenIntVec;	//To store int tokens
		string token; 
	
		int i = 0; 
		
		while(getline(strStream, token, ',')) {	//Break each comma seperated val into tokens
		
			token.erase(remove(token.begin(), token.end(), '"'), token.end());	//to remove qoutes
			
			if(i == 3 || i == 4 || i == 5 || i == 8 || i == 9 || i == 10) {
				int j;
				std::istringstream(token) >> j;
				tokenIntVec.push_back(j);
			}
			else{
			tokenVec.push_back(token);
		}
			i++;
		}
		
		country tempCountryObj = country(tokenVec[0], tokenVec[1], tokenIntVec[0], tokenIntVec[1], tokenIntVec[2], tokenIntVec[3], tokenIntVec[4], tokenIntVec[5]);
		ctryVector.push_back(tempCountryObj);
	}
	
	//Get user input
	
	//Get sort order
	cout << endl << "Sort order options:" << endl << "0 -----> Ascending" << endl << "1 -----> Descending" << endl;
	int sortOrder;
	cin >> sortOrder;
	
	//Get data option
	cout << endl << "Data options:" << endl << "0 -----> New Confirmed Cases" << endl << "1 -----> New Deaths" << endl << "2 -----> New Recovered Cases" << endl << "3 -----> Total Confirmed Cases" << endl << "4 -----> Total Deaths" << endl << "5 -----> Total Recovered Cases" << endl;
	int dataOption; 
	cin >> dataOption;
	
	
	//Sort and Graph
	switch (dataOption) {
		
		int val1;	//Value to be displayed
		int val2;	//Value for hashmarks
		
		case 0:	//New Confirmed Cases option
			
			sort(ctryVector.begin(), ctryVector.end(), [](country x, country y) {return x.getNewConfirmedCases() < y.getNewConfirmedCases();});	//sort
			if (sortOrder == 1) {
				reverse(ctryVector.begin(), ctryVector.end());
			}
			ctryVector.resize(10);	//Only keep first 10 objects
			
			if (sortOrder == 0) {	//Ascending order option
					val1 = ctryVector[9].getNewConfirmedCases() / MAXHASHMARKS;
					
				}
				
				if (sortOrder == 1) {	//Descending order option
					val1 = ctryVector[0].getNewConfirmedCases() / MAXHASHMARKS;
				}
				
				if (val1 == 0) {	//To avoid dividing by 0
						val1 = 1;
					}
					
				for (int z = 0; (unsigned)z < ctryVector.size(); z++) {
					
					cout << ctryVector[z].getCode() << " | ";
					
					val2 = ctryVector[z].getNewConfirmedCases();
					val2 /= val1;	//Scale
					
					for (val2; val2 > 0; val2--) {
						cout << "#";	//print val2 number of hashmarks
					}
					
					cout << endl << "   |" << endl;
				
				}
				
				cout << "---------------------------------------------" << endl << "New Confirmed Cases; Each # is approx. " << val1 << " cases." << endl;	//Bottom message
			
			
			break;
			
		case 1:	//New Deaths option
		
			sort(ctryVector.begin(), ctryVector.end(), [](country x, country y) {return x.getNewDeaths() < y.getNewDeaths();});
			if (sortOrder == 1) {
				reverse(ctryVector.begin(), ctryVector.end());
			}
			ctryVector.resize(10);
			
			if (sortOrder == 0) {
					val1 = ctryVector[9].getNewDeaths() / MAXHASHMARKS;
					
				}
				
				if (sortOrder == 1) {
					val1 = ctryVector[0].getNewDeaths() / MAXHASHMARKS;
				}
				
				if (val1 == 0) {
						val1 = 1;
					}
					
				for (int z = 0; (unsigned)z < ctryVector.size(); z++) {
					
					cout << ctryVector[z].getCode() << " | ";
					
					val2 = ctryVector[z].getNewDeaths();
					val2 /= val1;
					
					for (val2; val2 > 0; val2--) {
						cout << "#";
					}
					
					cout << endl << "   |" << endl;
				
				}
				
				cout << "---------------------------------------------" << endl << "New Deaths; Each # is approx. " << val1 << " deaths." << endl;
		
			break;
			
		case 2:	//New Recovered Cases option
		
			sort(ctryVector.begin(), ctryVector.end(), [](country x, country y) {return x.getNewRecoveredCases() < y.getNewRecoveredCases();});
			if (sortOrder == 1) {
				reverse(ctryVector.begin(), ctryVector.end());
			}
			ctryVector.resize(10);
			
			if (sortOrder == 0) {
					val1 = ctryVector[9].getNewRecoveredCases() / MAXHASHMARKS;
					
				}
				
				if (sortOrder == 1) {
					val1 = ctryVector[0].getNewRecoveredCases() / MAXHASHMARKS;
				}
				
				if (val1 == 0) {
						val1 = 1;
					}
					
				for (int z = 0; (unsigned)z < ctryVector.size(); z++) {
					
					cout << ctryVector[z].getCode() << " | ";
					
					val2 = ctryVector[z].getNewRecoveredCases();
					val2 /= val1;
					
					for (val2; val2 > 0; val2--) {
						cout << "#";
					}
					
					cout << endl << "   |" << endl;
				
				}
				
				cout << "---------------------------------------------" << endl << "New Recovered Cases; Each # is approx. " << val1 << " cases." << endl;
		
			break;
			
		case 3:	//Total Confirmed Cases option
		
			sort(ctryVector.begin(), ctryVector.end(), [](country x, country y) {return x.getTotalConfirmedCases() < y.getTotalConfirmedCases();});
			if (sortOrder == 1) {
				reverse(ctryVector.begin(), ctryVector.end());
			}
			ctryVector.resize(10);
			
			if (sortOrder == 0) {
					val1 = ctryVector[9].getTotalConfirmedCases() / MAXHASHMARKS;
					
				}
				
				if (sortOrder == 1) {
					val1 = ctryVector[0].getTotalConfirmedCases() / MAXHASHMARKS;
				}
				
				if (val1 == 0) {
						val1 = 1;
					}
					
				for (int z = 0; (unsigned)z < ctryVector.size(); z++) {
					
					cout << ctryVector[z].getCode() << " | ";
					
					val2 = ctryVector[z].getTotalConfirmedCases();
					val2 /= val1;
					
					for (val2; val2 > 0; val2--) {
						cout << "#";
					}
					
					cout << endl << "   |" << endl;
				
				}
				
				cout << "---------------------------------------------" << endl << "Total Confirmed Cases; Each # is approx. " << val1 << " cases." << endl;
		
			break;
			
		case 4:	//Total Deaths option
		
			sort(ctryVector.begin(), ctryVector.end(), [](country x, country y) {return x.getTotalDeaths() < y.getTotalDeaths();});
			if (sortOrder == 1) {
				reverse(ctryVector.begin(), ctryVector.end());
			}
			ctryVector.resize(10);
			
			if (sortOrder == 0) {
					val1 = ctryVector[9].getTotalDeaths() / MAXHASHMARKS;
					
				}
				
				if (sortOrder == 1) {
					val1 = ctryVector[0].getTotalDeaths() / MAXHASHMARKS;
				}
				
				if (val1 == 0) {
						val1 = 1;
					}
					
				for (int z = 0; (unsigned)z < ctryVector.size(); z++) {
					
					cout << ctryVector[z].getCode() << " | ";
					
					val2 = ctryVector[z].getTotalDeaths();
					val2 /= val1;
					
					for (val2; val2 > 0; val2--) {
						cout << "#";
					}
					
					cout << endl << "   |" << endl;
				
				}
				
				cout << "---------------------------------------------" << endl << "Total Deaths; Each # is approx. " << val1 << " deaths." << endl;
			
			break;
		
		case 5:	//Total Recovered Cases option
		
			sort(ctryVector.begin(), ctryVector.end(), [](country x, country y) {return x.getTotalRecoveredCases() < y.getTotalRecoveredCases();});
			if (sortOrder == 1) {
				reverse(ctryVector.begin(), ctryVector.end());
			}
			ctryVector.resize(10);
			
			if (sortOrder == 0) {
					val1 = ctryVector[9].getTotalRecoveredCases() / MAXHASHMARKS;
					
				}
				
				if (sortOrder == 1) {
					val1 = ctryVector[0].getTotalRecoveredCases() / MAXHASHMARKS;
				}
				
				if (val1 == 0) {
						val1 = 1;
					}
					
				for (int z = 0; (unsigned)z < ctryVector.size(); z++) {
					
					cout << ctryVector[z].getCode() << " | ";
					
					val2 = ctryVector[z].getTotalRecoveredCases();
					val2 /= val1;
					
					for (val2; val2 > 0; val2--) {
						cout << "#";
					}
					
					cout << endl << "   |" << endl;
				
				}
				
				cout << "---------------------------------------------" << endl << "Total Recovered Cases; Each # is approx. " << val1 << " cases." << endl;
			
			break;
		
		default:	//Invalid option
		
			cout << "Invalid data option entered!" << endl;
			exit (EXIT_FAILURE);
			
			break;
		
	}
		
	return 0;

}
