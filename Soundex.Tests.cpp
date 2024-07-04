#include <gtest/gtest.h>
#include "Soundex.h"

// Test case for empty string
TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

// Test case for single character
TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("B"), "B000");
}

// Test case for multiple characters with the same Soundex code
TEST(SoundexTest, HandlesSameSoundexCodeCharacters) {
    EXPECT_EQ(generateSoundex("BFPV"), "B100");
    EXPECT_EQ(generateSoundex("CGJKQSXZ"), "C220");
}

// Test case for characters that should be skipped (vowels and certain consonants)
TEST(SoundexTest, HandlesSkippedCharacters) {
    EXPECT_EQ(generateSoundex("Aeiouhwy"), "A000");
    EXPECT_EQ(generateSoundex("Hhwy"), "H000");
}

// Test case for input string that produces exactly 4 characters
TEST(SoundexTest, ProducesExactlyFourCharacters) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}

// Test case for input string that produces less than 4 characters
TEST(SoundexTest, ProducesLessThanFourCharacters) {
    EXPECT_EQ(generateSoundex("Jo"), "J000");
    EXPECT_EQ(generateSoundex("Li"), "L000");
}

// Test case for input string that produces more than 4 characters
TEST(SoundexTest, ProducesMoreThanFourCharacters) {
    EXPECT_EQ(generateSoundex("Pfister"), "P123");
    EXPECT_EQ(generateSoundex("Honeyman"), "H555");
}

// Additional tests for edge cases and typical inputs
TEST(SoundexTest, HandlesDuplicatesAndSkips) {
    EXPECT_EQ(generateSoundex("AABBBB"), "A100");
}

// Test case for mixed case input
TEST(SoundexTest, HandlesMixedCase) {
    EXPECT_EQ(generateSoundex("McDonald"), "M235");
}

// Test case for non-alphabetic characters in the input
TEST(SoundexTest, HandlesNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("John123"), "J500");
}

// Test case for long input strings
TEST(SoundexTest, HandlesLongInput) {
    EXPECT_EQ(generateSoundex("Washington"), "W252");
}

// Test case for input with only characters that map to zero codes
TEST(SoundexTest, HandlesAllZeros) {
    EXPECT_EQ(generateSoundex("AEIOU"), "A000");
}

