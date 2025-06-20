
#include "RubiksCube.h"

class RubiksCube3dArray : public RubiksCube {
    private:
    
        void rotateFace(int ind) {
            char temp_arr[3][3] = {};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    temp_arr[i][j] = cube[ind][i][j];
                }
            }
            for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
            for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
            for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
            for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];
        }
    public:
        char cube[6][3][3]{};

        RubiksCube3dArray() {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++)
                        cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }

        COLOR getColor(FACE face, unsigned row, unsigned col) const override {
            char color = cube[int(face)][row][col];
            switch (color) {
                case 'B':
                    return COLOR::BLUE;
                case 'R':
                    return COLOR::RED;
                case 'G':
                    return COLOR::GREEN;
                case 'O':
                    return COLOR::ORANGE;
                case 'Y':
                    return COLOR::YELLOW;
                default:
                    return COLOR::WHITE;
            }
        }

        bool isSolved() const override {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                        return false;
                    }
                }
            }
            return true;
        }

        RubiksCube &u() override {
            this->rotateFace(0);
    
            char temp_arr[3] = {};
            for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
            for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
            for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
            for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
            for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];
    
            return *this;
        }
    
        RubiksCube &uPrime() override {
            this->u();
            this->u();
            this->u();
    
            return *this;
        }
    
        RubiksCube &u2() override {
            this->u();
            this->u();
    
            return *this;
        }


        RubiksCube &l() override {
            this->rotateFace(1);
    
            char temp_arr[3] = {};
            for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
            for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
            for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
            for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
            for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];
    
            return *this;
        }
    
        RubiksCube &lPrime() override {
            this->l();
            this->l();
            this->l();
    
            return *this;
        }
    
        RubiksCube &l2() override {
            this->l();
            this->l();
    
            return *this;
        }
    
        RubiksCube &f() override {
            this->rotateFace(2);
    
            char temp_arr[3] = {};
            for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
            for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
            for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
            for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
            for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];
    
            return *this;
        }
    
        RubiksCube &fPrime() override {
            this->f();
            this->f();
            this->f();
    
            return *this;
        }
    
        RubiksCube &f2() override {
            this->f();
            this->f();
    
            return *this;
        }
    
        RubiksCube &r() override {
            this->rotateFace(3);
    
            char temp_arr[3] = {};
            for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
            for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
            for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
            for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
            for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];
    
            return *this;
        }
    
        RubiksCube &rPrime() override {
            this->r();
            this->r();
            this->r();
    
            return *this;
        }
    
        RubiksCube &r2() override {
            this->r();
            this->r();
    
            return *this;
        }
    
        RubiksCube &b() override {
            this->rotateFace(4);
    
            char temp_arr[3] = {};
            for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
            for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
            for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
            for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
            for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];
    
            return *this;
        }
    
        RubiksCube &bPrime() override {
            this->b();
            this->b();
            this->b();
    
            return *this;
        }
    
        RubiksCube &b2() override {
            this->b();
            this->b();
    
            return *this;
        }
    
        RubiksCube &d() override {
            this->rotateFace(5);
    
            char temp_arr[3] = {};
            for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
            for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
            for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
            for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
            for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];
    
            return *this;
        }
    
        RubiksCube &dPrime() override {
            this->d();
            this->d();
            this->d();
    
            return *this;
        }
    
        RubiksCube &d2() override {
            this->d();
            this->d();
    
            return *this;
        }
    
        bool operator==(const RubiksCube3dArray &r1) const {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                    }
                }
            }
            return true;
        }
    
        RubiksCube3dArray &operator=(const RubiksCube3dArray &r1) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        cube[i][j][k] = r1.cube[i][j][k];
                    }
                }
            }
            return *this;
        }

    };


    struct Hash3d {
        size_t operator()(const RubiksCube3dArray &r1) const {
            string str = "";
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        str += r1.cube[i][j][k];
                    }
                }
            }
            return hash<string>()(str);
        }
    
    };

    



    /*
    #include "RubiksCube3dArray.h"

    RubiksCube3dArray::RubiksCube3dArray() {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = getColorLetter(COLOR(i));
    }
    
    void RubiksCube3dArray::rotateFace(int ind) {
        char temp_arr[3][3] = {};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                temp_arr[i][j] = cube[ind][i][j];
    
        for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
        for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
        for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
        for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];
    }
    
    RubiksCube3dArray::COLOR RubiksCube3dArray::getColor(FACE face, unsigned row, unsigned col) const {
        char color = cube[int(face)][row][col];
        switch (color) {
            case 'B': return COLOR::BLUE;
            case 'R': return COLOR::RED;
            case 'G': return COLOR::GREEN;
            case 'O': return COLOR::ORANGE;
            case 'Y': return COLOR::YELLOW;
            default:  return COLOR::WHITE;
        }
    }
    
    bool RubiksCube3dArray::isSolved() const {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    if (cube[i][j][k] != getColorLetter(COLOR(i)))
                        return false;
        return true;
    }
    
    // --- Movement methods ---
    RubiksCube& RubiksCube3dArray::u() {
        rotateFace(0);
        char temp[3];
        for (int i = 0; i < 3; i++) temp[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp[i];
        return *this;
    }
    
    RubiksCube& RubiksCube3dArray::uPrime() { return u().u().u(); }
    RubiksCube& RubiksCube3dArray::u2()     { return u().u(); }
    
    RubiksCube& RubiksCube3dArray::l() {
        rotateFace(1);
        char temp[3];
        for (int i = 0; i < 3; i++) temp[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp[i];
        return *this;
    }
    
    RubiksCube& RubiksCube3dArray::lPrime() { return l().l().l(); }
    RubiksCube& RubiksCube3dArray::l2()     { return l().l(); }
    
    RubiksCube& RubiksCube3dArray::f() {
        rotateFace(2);
        char temp[3];
        for (int i = 0; i < 3; i++) temp[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp[i];
        return *this;
    }
    
    RubiksCube& RubiksCube3dArray::fPrime() { return f().f().f(); }
    RubiksCube& RubiksCube3dArray::f2()     { return f().f(); }
    
    RubiksCube& RubiksCube3dArray::r() {
        rotateFace(3);
        char temp[3];
        for (int i = 0; i < 3; i++) temp[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp[i];
        return *this;
    }
    
    RubiksCube& RubiksCube3dArray::rPrime() { return r().r().r(); }
    RubiksCube& RubiksCube3dArray::r2()     { return r().r(); }
    
    RubiksCube& RubiksCube3dArray::b() {
        rotateFace(4);
        char temp[3];
        for (int i = 0; i < 3; i++) temp[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp[i];
        return *this;
    }
    
    RubiksCube& RubiksCube3dArray::bPrime() { return b().b().b(); }
    RubiksCube& RubiksCube3dArray::b2()     { return b().b(); }
    
    RubiksCube& RubiksCube3dArray::d() {
        rotateFace(5);
        char temp[3];
        for (int i = 0; i < 3; i++) temp[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp[i];
        return *this;
    }
    
    RubiksCube& RubiksCube3dArray::dPrime() { return d().d().d(); }
    RubiksCube& RubiksCube3dArray::d2()     { return d().d(); }
    
    bool RubiksCube3dArray::operator==(const RubiksCube3dArray& r1) const {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
        return true;
    }
    
    RubiksCube3dArray& RubiksCube3dArray::operator=(const RubiksCube3dArray& r1) {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = r1.cube[i][j][k];
        return *this;
    }
    
    size_t Hash3d::operator()(const RubiksCube3dArray& r1) const {
        std::string str;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    str += r1.cube[i][j][k];
        return std::hash<std::string>()(str);
    }
    */