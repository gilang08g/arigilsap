#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>


using namespace std;

vector<vector<string>> items{{ "knife","3" }, { "knife","3" }, { "knife","3" }, { "knife","3" }, { "knife","3" }, { "knife","3" }, { "sword", "5" }, { "sword", "5" },{ "sword", "5" }, { "sword", "5" }, { "sword", "5" }, { "gun","8" }, { "gun","8" }, { "gun","8" }, { "gun","8" }, { "hammer","10" }, { "hammer","10" }, { "hammer","10" }, {"axe", "12"}, {"axe", "12"}, {"axecalibur", "999"}}; //item pool
vector<vector<string>> inventory;
vector<string> maximum{"a", "0"};
vector<vector<string>> enemy{{"Minotaur", "2"}, {"King Minotaur", "5"}};
vector<vector<string>>::iterator iter1; //iterator1 untuk isi inventory
vector<string>::iterator iter2;//iterator2 untuk isi inventory

/// irand = item_random
unsigned int irand, maksInventory = 5, stats, jumlahInventory = 0;
long int maksItem = items.size();
int floor=0;
bool first=true;




#endif // HEADER_H_INCLUDED
