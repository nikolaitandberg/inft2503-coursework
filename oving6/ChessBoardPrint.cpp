#include "ChessBoardPrint.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

ChessBoardPrint::ChessBoardPrint(ChessBoard &board) : board(board) {
  board.after_piece_move = [this](const std::string &from, const std::string &to) {
    print_move(from, to);
    print_board();
  };
}

void ChessBoardPrint::print_move(const std::string &from, const std::string &to) {
  auto &piece = board.squares[to[0] - 'a'][stoi(string() + to[1]) - 1];
  if (piece)
    cout << piece->type() << " moved from " << from << " to " << to << endl;
}

void ChessBoardPrint::print_board() {
  ostringstream oss;
  size_t cols = board.squares.size();
  size_t rows = board.squares[0].size();

  oss << endl;
  oss << "   ";
  for (size_t col = 0; col < cols; ++col)
    oss << "  " << static_cast<char>('a' + col) << " ";
  oss << endl;

  oss << "  ";
  for (size_t col = 0; col < cols; ++col)
    oss << "----";
  oss << "-" << endl;

  for (int row = rows - 1; row >= 0; --row) {
    oss << row + 1 << " |";
    for (size_t col = 0; col < cols; ++col) {
      string cell = "";
      if (board.squares[col][row])
        cell = board.squares[col][row]->short_type();
      oss << setw(3) << cell << "|";
    }
    oss << " " << row + 1 << endl;

    oss << "  ";
    for (size_t col = 0; col < cols; ++col)
      oss << "----";
    oss << "-" << endl;
  }

  oss << "   ";
  for (size_t col = 0; col < cols; ++col)
    oss << "  " << static_cast<char>('a' + col) << " ";
  oss << endl;

  cout << oss.str();
}
