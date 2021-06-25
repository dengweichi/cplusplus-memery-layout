#include "gtest/gtest.h"


struct test_struct1{
    char char_var;
    short short_var;
    int int_var;
    double double_var;
};

struct test_struct2{
    char char_var;
    short short_var;
    double double_var;
    int int_var;
};

struct test_struct3{
    char char_var;
};

struct test_struct4{
    short char_var;
};

#ifdef LINUX_64_GNU
TEST(test_struct_byte_align,test_struct_align) {
    EXPECT_EQ(sizeof (char), 1);
    EXPECT_EQ(sizeof (short ), 2);
    EXPECT_EQ(sizeof (int), 4);
    EXPECT_EQ(sizeof (double), 8);

    // 测试testStruct1字节对齐
    EXPECT_EQ(sizeof (test_struct1), 16);
    test_struct1 testStruct1;
    EXPECT_EQ((unsigned  long long)(&testStruct1.char_var), (unsigned  long long)(&testStruct1));
    EXPECT_EQ((unsigned  long long)(&testStruct1.short_var) - 2, (unsigned  long long)(&testStruct1.char_var));
    EXPECT_EQ((unsigned  long long)(&testStruct1.int_var) - 2, (unsigned  long long)(&testStruct1.short_var));
    EXPECT_EQ((unsigned  long long)(&testStruct1.double_var) - 4, (unsigned  long long)(&testStruct1.int_var));

    EXPECT_EQ(sizeof (test_struct2), 24);
    test_struct2 testStruct2;
    EXPECT_EQ((unsigned  long long)(&testStruct2.char_var), (unsigned  long long)(&testStruct2));
    EXPECT_EQ((unsigned  long long)(&testStruct2.short_var) - 2, (unsigned  long long)(&testStruct2.char_var));
    EXPECT_EQ((unsigned  long long)(&testStruct2.double_var) - 6, (unsigned  long long)(&testStruct2.short_var));
    EXPECT_EQ((unsigned  long long)(&testStruct2.int_var) - 8, (unsigned  long long)(&testStruct2.double_var));

    EXPECT_EQ(sizeof (test_struct3), 1);
    EXPECT_EQ(sizeof (test_struct4), 2);
}
#endif

#ifdef WIN_64_GNU
TEST(test_struct_byte_align,test_struct_align) {
    EXPECT_EQ(sizeof (char), 1);
    EXPECT_EQ(sizeof (short ), 2);
    EXPECT_EQ(sizeof (int), 4);
    EXPECT_EQ(sizeof (double), 8);

    // 测试testStruct1字节对齐
    EXPECT_EQ(sizeof (test_struct1), 16);
    test_struct1 testStruct1;
    EXPECT_EQ((unsigned  long long)(&testStruct1.char_var), (unsigned  long long)(&testStruct1));
    EXPECT_EQ((unsigned  long long)(&testStruct1.short_var) - 2, (unsigned  long long)(&testStruct1.char_var));
    EXPECT_EQ((unsigned  long long)(&testStruct1.int_var) - 2, (unsigned  long long)(&testStruct1.short_var));
    EXPECT_EQ((unsigned  long long)(&testStruct1.double_var) - 4, (unsigned  long long)(&testStruct1.int_var));

    EXPECT_EQ(sizeof (test_struct2), 24);
    test_struct2 testStruct2;
    EXPECT_EQ((unsigned  long long)(&testStruct2.char_var), (unsigned  long long)(&testStruct2));
    EXPECT_EQ((unsigned  long long)(&testStruct2.short_var) - 2, (unsigned  long long)(&testStruct2.char_var));
    EXPECT_EQ((unsigned  long long)(&testStruct2.double_var) - 6, (unsigned  long long)(&testStruct2.short_var));
    EXPECT_EQ((unsigned  long long)(&testStruct2.int_var) - 8, (unsigned  long long)(&testStruct2.double_var));

    EXPECT_EQ(sizeof (test_struct3), 1);
    EXPECT_EQ(sizeof (test_struct4), 2);
}
#endif

#ifdef WIN_64_MSVC
TEST(test_struct_byte_align,test_struct_align) {
    EXPECT_EQ(sizeof (char), 1);
    EXPECT_EQ(sizeof (short), 2);
    EXPECT_EQ(sizeof (int), 4);
    EXPECT_EQ(sizeof (double), 8);

     // 测试testStruct1字节对齐
    EXPECT_EQ(sizeof (test_struct1), 16);
    test_struct1 testStruct1;
    EXPECT_EQ((unsigned  long long)(&testStruct1.char_var), (unsigned  long long)(&testStruct1));
    EXPECT_EQ((unsigned  long long)(&testStruct1.short_var) - 2, (unsigned  long long)(&testStruct1.char_var));
    EXPECT_EQ((unsigned  long long)(&testStruct1.int_var) - 2, (unsigned  long long)(&testStruct1.short_var));
    EXPECT_EQ((unsigned  long long)(&testStruct1.double_var) - 4, (unsigned  long long)(&testStruct1.int_var));

    EXPECT_EQ(sizeof (test_struct2), 24);
    test_struct2 testStruct2;
    EXPECT_EQ((unsigned  long long)(&testStruct2.char_var), (unsigned  long long)(&testStruct2));
    EXPECT_EQ((unsigned  long long)(&testStruct2.short_var) - 2, (unsigned  long long)(&testStruct2.char_var));
    EXPECT_EQ((unsigned  long long)(&testStruct2.double_var) - 6, (unsigned  long long)(&testStruct2.short_var));
    EXPECT_EQ((unsigned  long long)(&testStruct2.int_var) - 8, (unsigned  long long)(&testStruct2.double_var));

    EXPECT_EQ(sizeof (test_struct3), 1);
    EXPECT_EQ(sizeof (test_struct4), 2);
}
#endif

#ifdef WIN_32_MSVC
TEST(test_struct_byte_align,test_struct_align) {
    EXPECT_EQ(sizeof (char), 1);
    EXPECT_EQ(sizeof (short), 2);
    EXPECT_EQ(sizeof (int), 4);
    EXPECT_EQ(sizeof (double), 8);

    // 测试testStruct1字节对齐
    EXPECT_EQ(sizeof (test_struct1), 16);
    test_struct1 testStruct1;
    EXPECT_EQ((unsigned  long long)(&testStruct1.char_var), (unsigned  long long)(&testStruct1));
    EXPECT_EQ((unsigned  long long)(&testStruct1.short_var) - 2, (unsigned  long long)(&testStruct1.char_var));
    EXPECT_EQ((unsigned  long long)(&testStruct1.int_var) - 2, (unsigned  long long)(&testStruct1.short_var));
    EXPECT_EQ((unsigned  long long)(&testStruct1.double_var) - 4, (unsigned  long long)(&testStruct1.int_var));

    EXPECT_EQ(sizeof (test_struct2), 24);
    test_struct2 testStruct2;
    EXPECT_EQ((unsigned  long long)(&testStruct2.char_var), (unsigned  long long)(&testStruct2));
    EXPECT_EQ((unsigned  long long)(&testStruct2.short_var) - 2, (unsigned  long long)(&testStruct2.char_var));
    EXPECT_EQ((unsigned  long long)(&testStruct2.double_var) - 6, (unsigned  long long)(&testStruct2.short_var));
    EXPECT_EQ((unsigned  long long)(&testStruct2.int_var) - 8, (unsigned  long long)(&testStruct2.double_var));

    EXPECT_EQ(sizeof (test_struct3), 1);
    EXPECT_EQ(sizeof (test_struct4), 2);
}
#endif
