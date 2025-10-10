#pragma once
#include "ChessBoard.hpp"

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board);

private:
  ChessBoard &board;

  void print_move(const std::string &from, const std::string &to);
  void print_board();
};
