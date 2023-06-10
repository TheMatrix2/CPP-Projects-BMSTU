#ifndef DZ_3_FUNC_H
#define DZ_3_FUNC_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "language.h"

using namespace std;


vector<string> split(string s, string separator);
void run_txt(string filename);
void run(string flag, string filename);
map<string, int> init();
void add_line(string filename, string line);


#endif //DZ_3_FUNC_H