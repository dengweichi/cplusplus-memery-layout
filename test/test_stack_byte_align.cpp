#include "gtest/gtest.h"

/**
 * 判断地址是否为某个值的对齐
 * @param value
 * @param alignment
 * @return
 */
bool IsAligned(unsigned long long address, unsigned int alignment) {
    return (address & (alignment - 1)) == 0;
}

#ifdef LINUX_64_GNU
TEST(test_stack_byte_align, test_stack_align) {
    char char_var = 1;
    short short_var = 2;
    int int_var = 3;
    EXPECT_EQ(sizeof(char_var), 1);
    EXPECT_EQ(sizeof(short_var), 2);
    EXPECT_EQ(sizeof(int_var), 4);
    unsigned long long char_var_address = (unsigned long long)&char_var;
    unsigned long long short_var_address = (unsigned long long)&short_var;
    unsigned long long int_var_address = (unsigned long long)&int_var;
    EXPECT_GT(short_var_address, char_var_address);
    EXPECT_GT(int_var_address, short_var_address);

    EXPECT_EQ(char_var_address + 1, short_var_address);
    EXPECT_EQ(short_var_address + 2, int_var_address);
}
#endif

#ifdef WIN_64_GNU
TEST(test_stack_byte_align, test_stack_align) {
    char char_var = 1;
    short short_var = 2;
    int int_var = 3;
    EXPECT_EQ(sizeof(char_var), 1);
    EXPECT_EQ(sizeof(short_var), 2);
    EXPECT_EQ(sizeof(int_var), 4);
    unsigned long long char_var_address = (unsigned long long)&char_var;
    unsigned long long short_var_address = (unsigned long long)&short_var;
    unsigned long long int_var_address = (unsigned long long)&int_var;
    EXPECT_GT(short_var_address, char_var_address);
    EXPECT_GT(int_var_address, short_var_address);
    EXPECT_EQ(char_var_address + 1, short_var_address);
    EXPECT_EQ(short_var_address + 2, int_var_address);
}
#endif

#ifdef WIN_64_MSVC
TEST(test_stack_byte_align, test_stack_align) {
    char char_var = 1;
    short short_var = 2;
    int int_var = 3;
    EXPECT_EQ(sizeof(char_var), 1);
    EXPECT_EQ(sizeof(short_var), 2);
    EXPECT_EQ(sizeof(int_var), 4);
    unsigned long long char_var_address = (unsigned long long)&char_var;
    unsigned long long short_var_address = (unsigned long long)&short_var;
    unsigned long long int_var_address = (unsigned long long)&int_var;

    EXPECT_GT(short_var_address, char_var_address);
    EXPECT_GT(int_var_address, short_var_address);

    EXPECT_TRUE(IsAligned(char_var_address, 4));
    EXPECT_TRUE(IsAligned(short_var_address, 4));
    EXPECT_TRUE(IsAligned(int_var_address, 4));
}
#endif

#ifdef WIN_32_MSVC
TEST(test_stack_byte_align, test_stack_align) {
    char char_var = 1;
    short short_var = 2;
    int int_var = 3;
    EXPECT_EQ(sizeof(char_var), 1);
    EXPECT_EQ(sizeof(short_var), 2);
    EXPECT_EQ(sizeof(int_var), 4);
    unsigned long long char_var_address = (unsigned long long)&char_var;
    unsigned long long short_var_address = (unsigned long long)&short_var;
    unsigned long long int_var_address = (unsigned long long)&int_var;
    EXPECT_LT(short_var_address, char_var_address);
    EXPECT_LT(int_var_address, short_var_address);
}
#endif