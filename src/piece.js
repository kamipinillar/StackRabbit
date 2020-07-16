import { NUM_ROW, NUM_COLUMN, VACANT, COLOR_PALETTE } from "./constants.js";
import { GetLevel, TriggerGameOver } from "./tetris";

// The Object Piece
export function Piece(pieceData, board, canvas) {
  this.rotationList = pieceData[0]; // All of the available rotations
  this.colorId = pieceData[1];
  this.id = pieceData[2];
  this.board = board;
  this.canvas = canvas;

  this.rotationIndex = 0; // Start from the first rotation
  this.activeTetromino = this.rotationList[this.rotationIndex];

  this.x = 3;
  this.y = -1;
}

Piece.prototype.equals = function (otherPiece) {
  return this.id === otherPiece.id;
};

// Get the height of the lowest row that the piece occupies
Piece.prototype.getHeightFromBottom = function () {
  let maxY = 0;
  for (let r = 0; r < this.activeTetromino.length; r++) {
    for (let c = 0; c < this.activeTetromino[r].length; c++) {
      // If the square is occupied by the piece, update the max
      if (this.activeTetromino[r][c]) {
        maxY = Math.max(maxY, this.y + r);
      }
    }
  }
  return NUM_ROW - maxY;
};

Piece.prototype.shouldLock = function () {
  return this.collision(0, 1, this.activeTetromino);
};

// move Down the piece
Piece.prototype.moveDown = function () {
  this.y++;
  this.canvas.drawBoard();
};

/**
 * Attempt to move the piece right.
 * @returns true if the piece moved */
Piece.prototype.moveRight = function () {
  if (this.collision(1, 0, this.activeTetromino)) {
    return false;
  } else {
    // No collision, move the piece
    this.x++;
    this.canvas.drawBoard();
    return true;
  }
};

/**
 * Attempt to move the piece left.
 * @returns true if the piece moved */
Piece.prototype.moveLeft = function () {
  if (this.collision(-1, 0, this.activeTetromino)) {
    return false;
  } else {
    // No collision, move the piece
    this.x--;
    this.canvas.drawBoard();
    return true;
  }
};

// rotate the piece
Piece.prototype.rotate = function (directionInversed) {
  const offset = directionInversed ? -1 : 1;
  const nextIndex =
    (this.rotationIndex + offset + this.rotationList.length) %
    this.rotationList.length;
  const nextPattern = this.rotationList[nextIndex];

  if (!this.collision(0, 0, nextPattern)) {
    this.rotationIndex = nextIndex;
    this.activeTetromino = this.rotationList[this.rotationIndex];
    this.canvas.drawBoard();
  }
};

// Lock the piece in place
Piece.prototype.lock = function () {
  for (let r = 0; r < this.activeTetromino.length; r++) {
    for (let c = 0; c < this.activeTetromino[r].length; c++) {
      // we skip the vacant squares
      if (!this.activeTetromino[r][c]) {
        continue;
      }
      // pieces to lock on top = game over
      if (this.y + r < 0) {
        TriggerGameOver();
        break;
      }
      // we lock the piece
      this.board[this.y + r][this.x + c] = this.colorId;
    }
  }

  // update the board
  this.canvas.drawBoard();
};

// Collision fucntion
Piece.prototype.collision = function (x, y, piece) {
  for (let r = 0; r < piece.length; r++) {
    for (let c = 0; c < piece[r].length; c++) {
      // if the square is empty, we skip it
      if (!piece[r][c]) {
        continue;
      }
      // coordinates of the piece after movement
      let newX = this.x + c + x;
      let newY = this.y + r + y;

      // conditions
      if (newX < 0 || newX >= NUM_COLUMN || newY >= NUM_ROW) {
        return true;
      }
      // skip newY < 0; board[-1] will crush our game
      if (newY < 0) {
        continue;
      }
      // check if there is a locked piece alrady in place
      if (this.board[newY][newX] != 0) {
        return true;
      }
    }
  }
  return false;
};
