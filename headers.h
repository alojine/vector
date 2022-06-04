#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <Vector>
#include <deque>
#include <list>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#include <functional>
#include <fstream>
#include <ratio>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;

struct data {
	string vardas = "", pavarde = "";
	vector<int> p;
	int n = 0;
	int egz = 0;
	double v = 0, m = 0;
};

