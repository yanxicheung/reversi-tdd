#include "gtest/gtest.h"
#include "Board.h"

TEST(BoardTest, should_init_board_with_black_in_e4_d5_and_white_in_d4_e5)
{
    Board board;
    ASSERT_TRUE(board.at(e4).isBlack());
    ASSERT_TRUE(board.at(d5).isBlack());
    ASSERT_TRUE(board.at(d4).isWhite());
    ASSERT_TRUE(board.at(e5).isWhite());
}

TEST(BoardTest, should_not_occupied_except_e4_d5_d4_e5)
{
    Board board;
    ASSERT_FALSE(board.isOccupied(a1));
    ASSERT_FALSE(board.isOccupied(h8));
}

TEST(BoardTest, should_return_ture_given_a1_to_h8)
{
    Board board;
    ASSERT_TRUE(board.onBoard(a1));
    ASSERT_TRUE(board.onBoard(h8));
}

TEST(BoardTest, should_return_false_given_out_of_range_of_a1_to_h8)
{
    Board board;
    Position lessThana1 = static_cast<Position>(a1-1);
    Position moreThanh8 = static_cast<Position>(h8+1);
    ASSERT_FALSE(board.onBoard(lessThana1));
    ASSERT_FALSE(board.onBoard(moreThanh8));
    ASSERT_FALSE(board.isOccupied(lessThana1));
    ASSERT_FALSE(board.isOccupied(moreThanh8));
}

TEST(BoardTest, should_place_disk_given_a_positon_in_the_board)
{
    Board board;
    board.place(a1, W);
    ASSERT_TRUE(board.at(a1).isOccupied());
    ASSERT_TRUE(board.at(a1).isWhite());
}

TEST(BoardTest, should_turn_over_given_a_valied_positon_which_is_occupided)
{
    Board board;
    board.place(a1, W);
    board.turnOver(a1);
    ASSERT_TRUE(board.at(a1).isOccupied());
    ASSERT_TRUE(board.at(a1).isBlack());
}
