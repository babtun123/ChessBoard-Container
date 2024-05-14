# ChessBoard-Container
C++ program with a 8x8 (i.e. 2-dimensional matrix) chessboard and an iterator over that chessboard.



The pieces on the chess board have a Color, Piece, and position. The Color is either Black or White. The Piece is one of the following:
• Rook • Knight • Bishop • Queen • King
• Pawn
We suggest you use enums for both Piece and Color.
The position is given by an x,y coordinate, each coordinate on the board is in the range
of 0...7. When the chessboard is set up to play a game, White’s pieces are in rows 0 and 1, while Black’s pieces are in rows 6 and 7.
1
1.1 The container
The container Chessboard should have the methods
• Chessboard() the constructor creates an empty chessboard, that is one with no pieces
on it.
• int place(int x, int y, Color c, Piece p): to place the piece on the chessboard. It should return
– 1 if successful,
– -1 if illegal x coordinate
– -2 if illegal y coordinate
– -3 if square is already occupied – -4 if illegal color
– -5 if illegal piece
• int get(int x, int y, Color &c, Piece &p): to get the value of the piece on the chessboard.
– 1 if successful,
– -1 if illegal x coordinate
– -2 if illegal y coordinate
– -3 if square is not occupied
• int move(int fromX, int fromY, int toX, int toY): to move piece fromX, fromY to toX, toY
– 1 if successful,
– -1 if illegal fromX coordinate
– -2 if illegal fromY coordinate
– -3 if illegal toX coordinate
– -4 if illegal toY coordinate
– -5 if fromX,fromY is not occupied
– -6 if toX, toY is occupied with a piece of the same color as the one being moved – -7 if illegal move other than -6
We consider only simple moves, and thus do not include castling, en-passant, or a pawn becoming another piece through reaching the last row.
Note that move includes capturing a piece which is then removed from the chessboard.
• print() Print the 8x8 board using the iterator.
In a board which is in the initial configuration for chess, the white pieces should be on the bottom and the black pieces the top. Use 3 characters to print each square:
2

“ . “ (space period space) if unoccupied cp (color piece space) if occupied where
– Color is b or w for Black or White.
– Piece is R, N, B, K, Q, P for Rook, Knight, Bishop, King, Queen, and Pawn.
Here is an example of the initial starting position for a game of chess:
bR bN bB bQ bK bB bN bR bP bP bP bP bP bP bP bP ........ ........ ........ ........ wP wP wP wP wP wP wP wP wR wN wB wQ wK wB wN wR
1.2 Iterator
The iterator, nameed ChessboardIterator, should go through the chessboard in the order [0,0],[1,0],...,[7,0],[0,1],[1,1],...
Where [x, y] is the x,y position on the board.
There should be a method which translates the iterator into x,y coordinates for the
chessboard.
• int it.xy(int &x, int &y)
– returns 1 if it refers to a place on the board
– returns -1 if it is not on the board
