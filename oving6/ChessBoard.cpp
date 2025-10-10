#include "ChessBoard.hpp"

using namespace std;

// ---------- Piece ----------
ChessBoard::Piece::Piece(Color color) : color(color) {}
ChessBoard::Piece::~Piece() {}

string ChessBoard::Piece::color_string() const {
  return color == Color::WHITE ? "white" : "black";
}

string ChessBoard::Piece::short_color_string() const {
  return color == Color::WHITE ? "w" : "b";
}

// ---------- King ----------
ChessBoard::King::King(Color color) : Piece(color) {}

string ChessBoard::King::type() const {
  return color_string() + " king";
}

string ChessBoard::King::short_type() const {
  return short_color_string() + "Ki";
}

bool ChessBoard::King::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  int dx = abs(from_x - to_x);
  int dy = abs(from_y - to_y);
  return dx <= 1 && dy <= 1 && (dx != 0 || dy != 0);
}

// ---------- Knight ----------
ChessBoard::Knight::Knight(Color color) : Piece(color) {}

string ChessBoard::Knight::type() const {
  return color_string() + " knight";
}

string ChessBoard::Knight::short_type() const {
  return short_color_string() + "Kn";
}

bool ChessBoard::Knight::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  int dx = abs(from_x - to_x);
  int dy = abs(from_y - to_y);
  return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}

// ---------- ChessBoard ----------
ChessBoard::ChessBoard() {
  squares.resize(8);
  for (auto &column : squares)
    column.resize(8);
}

bool ChessBoard::move_piece(const string &from, const string &to) {
  int from_x = from[0] - 'a';
  int from_y = stoi(string() + from[1]) - 1;
  int to_x = to[0] - 'a';
  int to_y = stoi(string() + to[1]) - 1;
  auto &piece_from = squares[from_x][from_y];

  if (!piece_from) {
    return false;
  }
  if (!piece_from->valid_move(from_x, from_y, to_x, to_y)) {
    return false;
  }

  auto &piece_to = squares[to_x][to_y];
  if (piece_to && (piece_from->color == piece_to->color)) {
    return false;
  }
  piece_to = move(piece_from);
  if (after_piece_move) {
    after_piece_move(from, to);
  }
  return true;
}
