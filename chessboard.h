//
// Created by Samuel Shodiya on 9/17/23.
//

#ifndef PRO1CS341_CHESSBOARD_H
#define PRO1CS341_CHESSBOARD_H

// see for background
//  https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html

#include <iostream>
#include <iterator>
using namespace std;

// define separate containers for Color, Piece (enums recommended)
enum Color{White, Black, NoColor};  // enum definition of color
enum Piece{Rook, Knight, Bishop, King, Queen, Pawn, Empty}; // enum definition of piece

// a chessboard contains squares
class Square {
private:
    Piece piece;
    Color color;
    bool occupied;

public:
    Square() { // default, square unoccupied
        // fill out
        piece = Empty;
        color = NoColor;
        occupied = false;
    }
    Square(Color c, Piece p) { // an occupied square
        // fill out
        piece = p;
        color = c;
        occupied = true;
    }

    // TA said we can make this function void on piazza post: @136_f1
    void get(bool &o, Color &c, Piece &p) {
        // fill out
        // check if the
        if (occupied) {
            o = true;
            c = color;
            p = piece;
        }
        else{
            o = false;
        }

    }

    void print();
};

class ChessboardIterator;

class Chessboard {
    // make the container iterator friendly
    typedef ChessboardIterator iterator;


private:
    Square chessboard[8][8];


public:
    friend class ChessboardIterator;

    Chessboard() {

        for (auto & x : chessboard) {
            for (auto & y : x) {
                y = Square();
            }
        }
    } // Square does all the initialization

    // return an x,y square from chessboard
    Square square(int x, int y) {
        // fill out
        return chessboard[x][y];
    }

    ChessboardIterator begin();
    ChessboardIterator end();

    // THis function checks if the piece listed for place function is defined in my piece enum
    bool pieceListed(Piece p){
        if(p != Rook && p != Knight && p != Bishop && p != King && p != Queen && p != Pawn){
            return true;
        }
        return false;
    }

    // place a piece on a x,y square in the chessboard
    int place(int x, int y, Color c, Piece p) {
        // fill out
        if(x < 0 || x > 7){
            return -1;
        }
        if(y < 0 || y > 7){
            return -2;
        }

        bool occ;
        chessboard[x][y].get(occ, c, p);

        // return -3 if the square is occupied by any piece
        if(occ){
            return -3;
        }

        // If the color is false return -4. Not white or black
        if(c != White && c != Black){
            return -4;
        }

        // If the piece is not any listed return -5
        if(pieceListed(p)){
            return -5;
        }

        // Otherwise set the piece to a square in the location given
        chessboard[x][y] = Square(c, p);
        return 1;
    }
    int get(int x, int y, Color &c, Piece &p) {
        // fill out
        // First check if x coordinate is out of bound
        if(x < 0 || x > 7){
            return -1;
        }
        if(y < 0 || y > 7){
            return -2;
        }

        bool occ;
        chessboard[x][y].get(occ, c, p);
        // return -3 if the square in not occupied by any piece
        if(!occ){
            return -3;
        }
        return 1;
    }

    int move(int fromX, int fromY, int toX, int toY) {
        // fill out

        // If from x is illegal return -1
        if(fromX < 0 || fromX > 7){
            return -1;
        }
        // If from y is illegal return -2
        if(fromY < 0 || fromY > 7){
            return -2;
        }

        // If to X is illegal return -3
        if(toX < 0 || toX > 7){
            return -3;
        }

        // If to Y is illegal return -4
        if(toY < 0 || toY > 7){
            return -4;
        }

        bool occuForFrom;
        Color FromCol;
        Piece FromPie;
        // This will be used to check if the from X and Y are occupied
        chessboard[fromX][fromY].get(occuForFrom, FromCol, FromPie);
        // if square is not occupied return -5
        if(!occuForFrom){
            return -5;
        }

        bool occuForTo;
        Color ToCol;
        Piece ToPie;
        // To check if the square is occupied
        chessboard[toX][toY].get(occuForTo, ToCol, ToPie);
        if(occuForTo && FromCol == ToCol){
            return -6;
        }

        if(!occuForTo && FromCol == ToCol){
            return -7;
        }

        // otherwise update the chessboard;
        chessboard[toX][toY] = Square(FromCol, FromPie);
        // clear the moved item
        chessboard[fromX][fromY] = Square();
        return 1;
    }

    void print();
};

class ChessboardIterator {
private:
    int position; // a number in [0..64]
    Chessboard chessboard;

public:
    ChessboardIterator(Chessboard &board,
                       int pos) { // start out with an empty board
        // fill out
        chessboard = board;
        position = pos;
    }

    void xy(int &x, int &y) const { // break position down into x and y
        // fill out
        x = position % 8;
        y = position / 8;
    }

    // return the square
    Square operator*() {
        // fill out
        int x,y;
        xy(x, y);
        return chessboard.square(x, y);
    }

    // pre-increment
    ChessboardIterator &operator++() {
        // fill out
        // increment position using pre-increment as stated in the document
        ++position;
        // return
        return *this;
    }

    // needed to support foreach
    int operator!=(const ChessboardIterator &a) const {
        // fill out
        // check if two operator are not equal
        return position != a.position;
    }
};

#endif //PRO1CS341_CHESSBOARD_H
