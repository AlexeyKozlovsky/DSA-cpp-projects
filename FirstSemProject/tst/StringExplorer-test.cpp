#include "gtest/gtest.h"
#include "../src/StringExplorer.hpp"


TEST(StringExplorer, countSymbols) {
    EXPECT_EQ(StringExplorer::countSymbols("asdfg", 'a'), 1);
}

TEST(StringExplorer, countWords) {
    EXPECT_EQ(StringExplorer::countWords("dfds gfdg"), 2);
    EXPECT_EQ(StringExplorer::countWords(" dfds gfdg "), 2);
}

TEST(StringExplorer, countMinWordLength) {
    EXPECT_EQ(StringExplorer::countMinWordLength("asdg gfd g"), 1);
    EXPECT_EQ(StringExplorer::countMinWordLength("  sdfds gdfd      hg fd        "), 2);
    EXPECT_EQ(StringExplorer::countMinWordLength(""), 0);
    EXPECT_EQ(StringExplorer::countMinWordLength("     f     "), 1);
    EXPECT_EQ(StringExplorer::countMinWordLength("     f"), 1);
    EXPECT_EQ(StringExplorer::countMinWordLength("f       "), 1);
    EXPECT_EQ(StringExplorer::countMinWordLength("       "), 0);
}

TEST(StringExplorer, countMaxWordLength) {
    EXPECT_EQ(StringExplorer::countMaxWordLength("asdg fd hg"), 4);
    EXPECT_EQ(StringExplorer::countMaxWordLength(" fd   hg    "), 2);
    EXPECT_EQ(StringExplorer::countMaxWordLength(" hg   dfsdf   f"), 5);
    EXPECT_EQ(StringExplorer::countMaxWordLength("asdg   fffdhg"), 6);
}

TEST(StringExplorer, reverseLine) {
    EXPECT_STREQ(StringExplorer::reverseLine("asdfgh"), "hgfdsa");
    EXPECT_STREQ(StringExplorer::reverseLine("asd gg"), "gg dsa");
    EXPECT_STREQ(StringExplorer::reverseLine(""), "");
    EXPECT_STREQ(StringExplorer::reverseLine(" "), " ");
}

TEST(StringExplorer, isPalindrom) {
    EXPECT_EQ(StringExplorer::isPalindrom("asddsa"), true);
    EXPECT_EQ(StringExplorer::isPalindrom("aaa"), true);
    EXPECT_EQ(StringExplorer::isPalindrom("asdf fdsa"), true);
    EXPECT_EQ(StringExplorer::isPalindrom("agf sfdh d"), false);
    EXPECT_EQ(StringExplorer::isPalindrom("asdfghj"), false);
}
