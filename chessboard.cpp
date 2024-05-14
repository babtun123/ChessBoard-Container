//
// Created by Samuel Shodiya on 9/17/23.
//

// chessboard.cpp

#include "chessboard.h"

// define containers for color mappings (2 colors) and piece mappings (6 pieces)
//
ChessboardIterator Chessboard::begin() {
    // fill out
    return ChessboardIterator({*this, 0});
}

ChessboardIterator Chessboard::end() {
    // fill out
    return ChessboardIterator({*this, 64});
}

// Print the square
void Square::print() {
    // This will set the piece and color to a char var to print out
    char p;
    char c;

    if(!occupied){
        cout << " . ";
    }
    else{
        if(piece == Rook){
            p = 'R';
    }
        else if(piece == Knight){
            p = 'N';
        }
        else if(piece == Bishop){
            p = 'B';
        }
        else if(piece == King){
            p = 'K';
        }
        else if(piece == Queen){
            p = 'Q';
        }
        else if(piece == Pawn){
            p = 'P';
        }
        else{
            p = ' ';  // Empty
        }

        if(color == White){
            c = 'w';
        }
        else{
            c = 'b';
        }

        cout << c << p << " ";
    }
}

// print the chessboard with white at the bottom (traditional view)
void Chessboard::print() {
    // fill out
//    ChessboardIterator it(begin());
//    ChessboardIterator it2(end());
//    ChessboardIterator itTemp(int);



//    ChessboardIterator it(*this, 56);


    int i = 0;
    int startPos = 56;
    int endPos = 64;

    //This loop will execute 7 times and print out the iterator loop.
    while(i <= 7) {
        // Using chessboardIterator!!!!!
        for (ChessboardIterator it(*this, startPos); it != ChessboardIterator (*this, endPos); ++it) {
            int x, y;
            it.xy(x, y);
//            it.operator*().print();

            chessboard[x][y].print();
        }

        // To reset position and print next line
        startPos = startPos - 8;
        endPos = endPos - 8;

        std::cout << std::endl;

        i++;
    }



}

