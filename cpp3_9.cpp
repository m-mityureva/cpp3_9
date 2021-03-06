// cpp3_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Set.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
#pragma region  set<int>

	cout << "--------int----------" << endl;

	Set<int> set1;
	set1.Add(1);
	set1.Add(3);
	set1.Add(5);

	cout << "--set1:" << endl;
	for (int* item : set1) {
		cout << *item << endl;
	}
	cout << endl << endl;

	Set<int> set2;
	set2.Add(5);
	set2.Add(100);
	set2.Add(150);

	cout << "--set2:" << endl;
	for (int* item : set2) {
		cout << *item << endl;
	}
	cout << endl << endl;

	Set<int> set = set1;

	set1.IntersectWith(&set2);

	cout << "--Intersect:" << endl;
	for (int* item : set1) {
		cout << *item << endl;
	}
	cout << endl << endl;

	set1 = set;
	set1.UnionWith(&set2);
	cout << "--Union:" << endl;
	for (int* item : set1) {
		cout << *item << endl;
	}
	cout << endl << endl;

	set1 = set;
	set1.ExceptWith(&set2);
	cout << "--Except:" << endl;
	for (int* item : set1) {
		cout << *item << endl;
	}
	cout << endl << endl;
#pragma endregion


#pragma region  set<string>

	cout << "--------string----------" << endl;
	
	Set<string> strSet1;
	strSet1.Add("str0");
	strSet1.Add("str1");
	strSet1.Add("str2");

	cout << "--set1:" << endl;
	for (string* item : strSet1) {
		cout << *item << endl;
	}
	cout << endl << endl;

	Set<string> strSet2;
	strSet2.Add("str0");
	strSet2.Add("str10");
	strSet2.Add("str20");

	cout << "--set2:" << endl;
	for (string* item : strSet2) {
		cout << *item << endl;
	}
	cout << endl << endl;

	Set<string> strSet = strSet1;

	strSet1.UnionWith(&strSet2);
	cout << "--Union:" << endl;
	for (string* item : strSet1) {
		cout << *item << endl;
	}
	cout << endl << endl;

	strSet1 = strSet;
	strSet1.ExceptWith(&strSet2);
	cout << "--Except:" << endl;
	for (string* item : strSet1) {
		cout << *item << endl;
	}
	cout << endl << endl;


	strSet1 = strSet;
	strSet1.IntersectWith(&strSet2);
	cout << "--Intersect:" << endl;
	for (string* item : strSet1) {
		cout << *item << endl;
	}
	cout << endl << endl;

	
#pragma endregion


	cin.get();
	return 0;
}

