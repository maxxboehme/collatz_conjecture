// --------
// includes
// --------

#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

TEST(Collatz, read) {
    std::istringstream r("1 10\n");
    const std::pair<int, int> p = collatz_read(r);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);}

// ----
// eval
// ----

TEST(Collatz, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(Collatz, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(Collatz, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(Collatz, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(Collatz, eval_5) {
    const int v = collatz_eval(111111, 999999);
    ASSERT_EQ(525, v);}

TEST(Collatz, eval_6) {
    const int v = collatz_eval(10100, 200201);
    ASSERT_EQ(383, v);}

TEST(Collatz, eval_7) {
    const int v = collatz_eval(1, 999999);
    ASSERT_EQ(525, v);}

TEST(Collatz, eval_8) {
    const int v = collatz_eval(3, 3);
    ASSERT_EQ(8, v);}

TEST(Collatz, eval_9) {
    const int v = collatz_eval(999999, 111111);
    ASSERT_EQ(525, v);}

TEST(Collatz, eval_10) {
    const int v = collatz_eval(999999, 1);
    ASSERT_EQ(525, v);}


TEST(Collatz, qeval_1) {
    const int v = eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(Collatz, qeval_2) {
    const int v = eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(Collatz, qeval_3) {
    const int v = eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(Collatz, qeval_4) {
    const int v = eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(Collatz, qeval_5) {
    const int v = eval(111111, 999999);
    ASSERT_EQ(525, v);}

TEST(Collatz, qeval_6) {
    const int v = eval(10100, 200201);
    ASSERT_EQ(383, v);}

TEST(Collatz, qeval_7) {
    const int v = eval(1, 999999);
    ASSERT_EQ(525, v);}

TEST(Collatz, qeval_8) {
    const int v = eval(3, 3);
    ASSERT_EQ(8, v);}

TEST(Collatz, qeval_9) {
    const int v = eval(999999, 111111);
    ASSERT_EQ(525, v);}

TEST(Collatz, qeval_10) {
    const int v = eval(999999, 1);
    ASSERT_EQ(525, v);}

// -----
// Cycle
// -----
/*
TEST(Collatz, cycle_1) {
    const int v = collatz_cycle(5);
    ASSERT_EQ(6, v);}

TEST(Collatz, cycle_2) {
    const int v = collatz_cycle(10);
    ASSERT_EQ(7, v);}

TEST(Collatz, cycle_3) {
    const int v = collatz_cycle(419839);
    ASSERT_EQ(162, v);}

// -----
// range_index
// -----
TEST(Collatz, range_index_1) {
    std::pair<int, int> pair = range_index(200000, 700000);
    ASSERT_EQ(2, pair.first);
    ASSERT_EQ(6, pair.second);}

TEST(Collatz, range_index_2) {
    std::pair<int, int> pair = range_index(200009, 700009);
    ASSERT_EQ(3, pair.first);
    ASSERT_EQ(6, pair.second);}

// -----
// range_index
// -----
TEST(Collatz, max_cached_1) {
    int result = max_cached(1, 1);
    ASSERT_EQ(383, result);}

TEST(Collatz, max_cached_2) {
    int result = max_cached(1, 0);
    ASSERT_EQ(-1, result);}

TEST(Collatz, max_cached_3) {
    unsigned int result = max_cached(1, 8);
    ASSERT_EQ(525, result);}

*/
// -----
// print
// -----

TEST(Collatz, print) {
    std::ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(Collatz, solve) {
    std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    std::ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
