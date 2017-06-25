#include <gtest/gtest.h>
#include "rsa.h"

TEST(rsa_check, one_is_not_prime) {
    EXPECT_EQ(0, is_prime(1));
}

TEST(rsa_check, two_is_prime) {
    EXPECT_EQ(1, is_prime(2));
}

TEST(rsa_check, first_prime_numbers_are_prime) {
    int primes[] = {3, 5, 7, 11, 13, 17, 19, 23};
    for (int i = 0; i < (sizeof(primes) / sizeof(*primes)); i++)
        EXPECT_EQ(1, is_prime(primes[i]));
}

TEST(rsa_check, even_number_is_always_not_prime) {
    EXPECT_EQ(0, is_prime(rand() * 2));
}
