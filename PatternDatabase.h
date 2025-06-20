 
#ifndef RUBIKS_CUBE_SOLVER_PATTERNDATABASE_H
#define RUBIKS_CUBE_SOLVER_PATTERNDATABASE_H

#include "RubiksCube.h"
#include "NibbleArray.h"
 
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <complex>
#include <condition_variable>
#include <cstdio>
 
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>


#include <cstdint>

using namespace std;

class PatternDatabase {

    NibbleArray database;
    size_t size;
    size_t numItems;

    PatternDatabase();

public:
    PatternDatabase(const size_t size);
//    Testing for init_val
    PatternDatabase(const size_t size, uint8_t init_val);

    virtual uint32_t getDatabaseIndex(const RubiksCube &cube) const = 0;

    virtual bool setNumMoves(const RubiksCube &cube, const uint8_t numMoves); //

    virtual bool setNumMoves(const uint32_t ind, const uint8_t numMoves); //

    virtual uint8_t getNumMoves(const RubiksCube &cube) const; //

    virtual uint8_t getNumMoves(const uint32_t ind) const; //

    virtual size_t getSize() const; //

    virtual size_t getNumItems() const; //

    virtual bool isFull() const;//

    virtual void toFile(const string &filePath) const;//

    virtual bool fromFile(const string &filePath); //

    virtual vector<uint8_t> inflate() const; //

    virtual void reset();  //
};


#endif //RUBIKS_CUBE_SOLVER_PATTERNDATABASE_H