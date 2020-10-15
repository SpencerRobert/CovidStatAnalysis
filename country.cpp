/*
	Spencer Poultney 250982673
	country.cpp file includes constructors, getters & setters
															*/
#include <iostream>
#include "country.h"
using namespace std;
		
		country::country() {
			countryName = "";
			countryCode = "";
			newConfirmedCases = 0;
			newDeaths = 0;
			newRecoveredCases = 0;
			totalConfirmedCases = 0;
			totalDeaths = 0;
			totalRecoveredCases = 0;
			
		}
		
		country::country(string countryNameP, string countryCodeP, int newConfirmedCasesP, int newDeathsP, int newRecoveredCasesP, int totalConfirmedCasesP, int totalDeathsP, int totalRecoveredCasesP) {
			
			countryName = countryNameP;
			countryCode = countryCodeP;
			newConfirmedCases = newConfirmedCasesP;
			newDeaths = newDeathsP;
			newRecoveredCases = newRecoveredCasesP;
			totalConfirmedCases = totalConfirmedCasesP;
			totalDeaths = totalDeathsP;
			totalRecoveredCases = totalRecoveredCasesP;
		}
		
		
		void country::setName(string newCountryName) {
			country::countryName = newCountryName;
		}
		
		string country::getName() {
			return country::countryName;
		}
		
		void country::setCode(string newCountryCode) {
			country::countryCode = newCountryCode;
		}
		
		string country::getCode() {
			return country::countryCode;
		} 
		
		void country::setNewConfirmedCases(int newNewConfirmedCases) {
			country::newConfirmedCases = newNewConfirmedCases;
		}
		
		int country::getNewConfirmedCases() {
			return country::newConfirmedCases;
		}
		
		void country::setNewDeaths(int newNewDeaths) {
			country::newDeaths = newNewDeaths;
		}
		
		int country::getNewDeaths() {
			return country::newDeaths;
		}
		
		void country::setNewRecoveredCases(int newNewRecoveredCases) {
			country::newRecoveredCases = newNewRecoveredCases;
		}
		
		int country::getNewRecoveredCases() {
			return country::newRecoveredCases;
		}
		
		void country::setTotalConfirmedCases(int newTotalConfirmedCases) {
			country::totalConfirmedCases = newTotalConfirmedCases;
		}
		
		int country::getTotalConfirmedCases() {
			return totalConfirmedCases;
		}
		
		void country::setTotalDeaths(int newTotalDeaths) {
			country::totalDeaths = newTotalDeaths;
		}
		
		int country::getTotalDeaths() {
			return country::totalDeaths;
		}
		
		void country::setTotalRecoveredCases(int newTotalRecoveredCases) {
			country::totalRecoveredCases = newTotalRecoveredCases;
		}
		
		int country::getTotalRecoveredCases() {
			return country::totalRecoveredCases;
		}
		
		country::~country() { }
			
			
		


