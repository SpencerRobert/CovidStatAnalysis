/*
	Spencer Poultney 250982673
	Header file for my country.cpp
															*/
#ifndef COUNTRY_CLASS_H
#define COUNTRY_CLASS_H

#include <string>
using namespace std;

class country {
	
	
	private:

		string countryName; 
		string countryCode;
		int newConfirmedCases;
		int newDeaths;
		int newRecoveredCases;
		int totalConfirmedCases;
		int totalDeaths;
		int totalRecoveredCases;
	
	
	public: 
	
		country();
		country(string countryNameP, string countryCodeP, int newConfirmedCasesP, int newDeathsP, int newRecoveredCasesP, int totalConfirmedCasesP, int totalDeathsP, int totalRecoveredCasesP);
		
		void setName(string newCountryName);
		string getName();
		
		void setCode(string newCountryCode);
		string getCode();
		
		void setNewConfirmedCases(int newNewConfirmedCases);
		int getNewConfirmedCases();
		
		void setNewDeaths(int newNewDeaths);
		int getNewDeaths();
		
		void setNewRecoveredCases(int newNewRecoveredCases);
		int getNewRecoveredCases();
		
		void setTotalConfirmedCases(int newTotalConfirmedCases);
		int getTotalConfirmedCases();
		
		void setTotalDeaths(int newTotalDeaths);
		int getTotalDeaths();
		
		void setTotalRecoveredCases(int newTotalRecoveredCases);
		int getTotalRecoveredCases();
		
		~country();
	};
	
#endif
	

