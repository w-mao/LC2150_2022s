/*
 * TestSTLMap.cpp
 *
 *  Created on: Feb 26, 2022
 *      Author: mao
 */

#include <iostream>
#include <map>
using namespace std;

int testSTLMap()
{
  map<string, int> myMap;				// a (string,int) map
  map<string, int>::iterator p;				// an iterator to the map
  myMap.insert(pair<string, int>("Rob", 28));		// insert ("Rob",28)
  myMap["Joe"] = 38;					// insert("Joe",38)
  myMap["Joe"] = 50;					// change to ("Joe",50)
  myMap["Sue"] = 75;					// insert("Sue",75)
  p = myMap.find("Joe");				// *p = ("Joe",50)
  myMap.erase(p);					// remove ("Joe",50)
  myMap.erase("Sue");					// remove ("Sue",75)
  p = myMap.find("Joe");
  if (p == myMap.end()) cout << "nonexistent\n";	// outputs: "nonexistent"
  for (p = myMap.begin(); p != myMap.end(); ++p) {	// print all entries
    cout << "(" << p->first << "," << p->second << ")\n";
  }
  return 0;
}

