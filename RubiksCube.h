#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

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


using namespace std;

class RubiksCube {
    public:
        enum class FACE {
            UP,
            LEFT,
            FRONT,
            RIGHT,
            BACK,
            DOWN
        };
    
        enum class COLOR {
            WHITE,
            GREEN,
            RED,
            BLUE,
            ORANGE,
            YELLOW
        };
    
        enum class MOVE {
            L, LPRIME, L2,
            R, RPRIME, R2,
            U, UPRIME, U2,
            D, DPRIME, D2,
            F, FPRIME, F2,
            B, BPRIME, B2
        };
            /*
     * Returns the color of the cell at (row, col) in face.
     * If Rubik's Cube face is pointing at you, then the row numbering starts from the
     * top to bottom, and column numbering starts from the left to right.
     * The rows and columns are 0-indexed.
     * @param Face, row, and column index
     */
        virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;
            /*
     * Returns the first letter of the given COLOR
     * Eg: For COLOR::GREEN, it returns 'G'
     */
        static char getColorLetter(COLOR color);  //

    /*
     * Returns true if the Rubik Cube is solved, otherwise returns false.
     */
        virtual bool isSolved() const = 0;
    /*
     * Returns the move in the string format.
     */
        static string getMove(MOVE ind);  //
        void print() const;
            /*
     * Randomly shuffle the cube with 'times' moves and returns the moves performed.
     */
        vector<MOVE> randomShuffleCube(unsigned int times);
            /*
     * Perform moves on the Rubik Cube
     */
        RubiksCube &move(MOVE ind);  //

            /*
     * Invert a move
     */
        RubiksCube &invert(MOVE ind);  ///

        virtual RubiksCube &f() = 0;

    virtual RubiksCube &fPrime() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uPrime() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lPrime() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dPrime() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &rPrime() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bPrime() = 0;

    virtual RubiksCube &b2() = 0;

    
    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;
    
 
};

 

#endif