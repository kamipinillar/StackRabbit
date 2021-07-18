#ifndef TETROMINOES
#define TETROMINOES

#include "types.h"

const Piece PIECE_I{ 'I', 0, {
  {0, 0, 960, 0},     // e.g. 960 = 1111000000
  {128, 128, 128, 128},
  {-1, -1, -1, -1},   // -1s indicate that there are no more rotations of this piece
  {-1, -1, -1, -1}
},{
  {2, 2, 2, 2},
  {-1, -1, 0, -1},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
},{
  {3, 3, 3, 3},
  {-1, -1, 4, -1}, 
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
},{ 17, 16, -1, -1},  
  -2 };

const Piece PIECE_O{ 'O', 1, {
  {0, 384, 384, 0},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1}
},{
  {-1, 1, 1, -1},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
},{
  {-1, 3, 3, -1},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
},{17, -1, -1, -1},  
  -1 };

const Piece PIECE_L{ 'L', 2, {
  {0, 448, 256, 0},
  {384, 128, 128, 0},
  {64, 448, 0, 0},
  {128, 128, 192, 0}
},{
  {-1, 1, 1, 1},
  {-1, 0, 0, -1},
  {-1, 1, 1, 0},
  {-1, -1, 0, 2}
},{
  {-1, 3, 2, 2},
  {-1, 1, 3, -1},
  {-1, 2, 2, 2},
  {-1, -1, 3, 3},
},{17, 17, 18, 17},  
   -1 };

const Piece PIECE_J{ 'J', 3, {
  {0, 448, 64, 0},
  {128, 128, 384, 0},
  {256, 448, 0, 0},
  {192, 128, 128, 0}
},{
  {-1, 1, 1, 1},
  {-1, 2, 0, -1},
  {-1, 0, 1, 1},
  {-1, -1, 0, 0}
},{
  {-1, 2, 2, 3},
  {-1, 3, 3, -1},
  {-1, 2, 2, 2},
  {-1, -1, 3, 1},
},{17, 17, 18, 17},  
   -1 };

const Piece PIECE_T{ 'T', 4, {
  {0, 448, 128, 0},
  {128, 384, 128, 0},
  {128, 448, 0, 0},
  {128, 192, 128, 0}
},{
  {-1, 1, 1, 1},
  {-1, 1, 0, -1},
  {-1, 1, 0, 1},
  {-1, -1, 0, 1}
},{
  {-1, 2, 3, 2},
  {-1, 2, 3, -1},
  {-1, 2, 2, 2},
  {-1, -1, 3, 2},
},{ 17, 17, 18, 17},  
   -1 };

const Piece PIECE_S{ 'S', 5, {
  {0, 192, 384, 0},
  {128, 192, 64, 0},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1}
},{
  {-1, 2, 1, 1},
  {-1, -1, 0, 1},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
},{
  {-1, 3, 3, 2},
  {-1, -1, 2, 3},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
},{ 17, 17, -1, -1},  
   -1 };

const Piece PIECE_Z{ 'Z', 6, {
  {0, 384, 192, 0},
  {64, 192, 128, 0},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
},{
  {-1, 1, 1, 2},
  {-1, -1, 1, 0},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
},{
  {-1, 2, 3, 3},
  {-1, -1, 3, 2},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
},{ 17, 17, -1, -1},  
    -1 };

const Piece PIECE_LIST[7] = {PIECE_I, PIECE_O, PIECE_L, PIECE_J, PIECE_T, PIECE_S, PIECE_Z};

#endif