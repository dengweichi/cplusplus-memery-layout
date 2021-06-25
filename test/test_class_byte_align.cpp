#include "gtest/gtest.h"

class ParentWithoutVirtual1{
public:
    char char_var;
    short short_var;
    int int_var;
    double double_var;
public:
    char get_char_val(){
        return char_var;
    }
};

class ParentWithoutVirtual2{
public:
    char char_var;
    short short_var;
    double double_var;
    int int_var;
public:
    short get_short_val(){
        return int_var;
    }
};

class ParentWithVirtual1{
public:
    char char_var;
    short short_var;
    int int_var;
    double double_var;
public:
    virtual int get_int_val(){
        return int_var;
    }
};

class ParentWithVirtual2{
public:
    char char_var;
    short short_var;
    double double_var;
    int int_var;
public:
    virtual double get_double_val(){
        return get_double_val();
    }
};

class SonWithoutVirtualSingleInheritParentWithoutVirtual1: public ParentWithoutVirtual1{
public:
    char char_var;
    short short_var;
    int int_var;
    double double_var;
public:
    int get_int_val(){
        return int_var;
    }
};

class SonWithoutVirtualSingleInheritParentWithVirtual1: public ParentWithVirtual1{
public:
    char char_var;
    short short_var;
    int int_var;
    double double_var;
public:
    int get_int_val(){
        return int_var;
    }
};

class SonWithVirtualSingleInheritParentWithoutVirtual1: public ParentWithoutVirtual1{
public:
    char char_var;
    short short_var;
    int int_var;
    double double_var;
public:
    virtual int get_int_val(){
        return int_var;
    }
};

class SonWithVirtualSingleInheritParentWithVirtual1:public ParentWithVirtual1{
public:
    char char_var;
    short short_var;
    int int_var;
    double double_var;
public:
    virtual int get_int_val() override{
        return int_var;
    }
};
class SonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2: public ParentWithoutVirtual1, public ParentWithoutVirtual2{
public:
    char char_var;
    short short_var;
    int int_var;
    double double_var;
public:
    int get_int_val(){
        return int_var;
    }
};

class SonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1: public ParentWithVirtual1, public  ParentWithoutVirtual1{
public:
    char char_var;
    short short_var;
    int int_var;
    double double_var;
public:
    int get_int_val(){
        return int_var;
    }
};

class SonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithVirtual2: public ParentWithVirtual1, public ParentWithVirtual2{
public:
    char char_var;
    short short_var;
    int int_var;
    double double_var;
public:
    int get_int_val(){
        return int_var;
    }
};


TEST(test_class_byte_align,test_class_align) {
    EXPECT_EQ(sizeof(char), 1);
    EXPECT_EQ(sizeof(short), 2);
    EXPECT_EQ(sizeof(int), 4);
    EXPECT_EQ(sizeof(double), 8);

    EXPECT_EQ(sizeof( ParentWithoutVirtual1), 16);
    ParentWithoutVirtual1 parentWithoutVirtual1;
    EXPECT_EQ((unsigned long long)&(parentWithoutVirtual1.char_var),(unsigned long long)&parentWithoutVirtual1);
    EXPECT_EQ((unsigned long long)&(parentWithoutVirtual1.short_var) - 2, (unsigned long long)&(parentWithoutVirtual1.char_var));
    EXPECT_EQ((unsigned long long)&(parentWithoutVirtual1.int_var) - 2 , (unsigned long long)&(parentWithoutVirtual1.short_var));
    EXPECT_EQ((unsigned long long)&(parentWithoutVirtual1.double_var) - 4,(unsigned long long)&(parentWithoutVirtual1.int_var));

    EXPECT_EQ(sizeof( ParentWithoutVirtual2), 24);
    ParentWithoutVirtual2 parentWithoutVirtual2;
    EXPECT_EQ((unsigned long long)&(parentWithoutVirtual2.char_var),(unsigned long long)&parentWithoutVirtual2);
    EXPECT_EQ((unsigned long long)&(parentWithoutVirtual2.short_var) - 2, (unsigned long long)&(parentWithoutVirtual2.char_var));
    EXPECT_EQ((unsigned long long)&(parentWithoutVirtual2.double_var) - 6 , (unsigned long long)&(parentWithoutVirtual2.short_var));
    EXPECT_EQ((unsigned long long)&(parentWithoutVirtual2.int_var) - 8,(unsigned long long)&(parentWithoutVirtual2.double_var));

    EXPECT_EQ(sizeof( ParentWithVirtual1), 24);
    ParentWithVirtual1 parentWithVirtual1;
    EXPECT_EQ((unsigned long long)&(parentWithVirtual1.char_var) - 8,(unsigned long long)&parentWithVirtual1);
    EXPECT_EQ((unsigned long long)&(parentWithVirtual1.short_var) - 2, (unsigned long long)&(parentWithVirtual1.char_var));
    EXPECT_EQ((unsigned long long)&(parentWithVirtual1.int_var) - 2 , (unsigned long long)&(parentWithVirtual1.short_var));
    EXPECT_EQ((unsigned long long)&(parentWithVirtual1.double_var) - 4,(unsigned long long)&(parentWithVirtual1.int_var));

    EXPECT_EQ(sizeof( ParentWithVirtual2), 32);
    ParentWithVirtual2 parentWithVirtual2;
    EXPECT_EQ((unsigned long long)&(parentWithVirtual2.char_var) - 8,(unsigned long long)&parentWithVirtual2);
    EXPECT_EQ((unsigned long long)&(parentWithVirtual2.short_var) - 2, (unsigned long long)&(parentWithVirtual2.char_var));
    EXPECT_EQ((unsigned long long)&(parentWithVirtual2.double_var) - 6 , (unsigned long long)&(parentWithVirtual2.short_var));
    EXPECT_EQ((unsigned long long)&(parentWithVirtual2.int_var) - 8,(unsigned long long)&(parentWithVirtual2.double_var));



    EXPECT_EQ(sizeof (SonWithoutVirtualSingleInheritParentWithoutVirtual1), 32);
    SonWithoutVirtualSingleInheritParentWithoutVirtual1 sonWithoutVirtualSingleInheritParentWithoutVirtual1;
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::char_var),
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1)
              );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::short_var) - 2,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::char_var)
              );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::int_var) - 2,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::double_var) - 4,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::int_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.char_var) - 8,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::double_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.short_var) - 2,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.int_var) - 2,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.double_var) - 4,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithoutVirtual1.int_var)
    );

    EXPECT_EQ(sizeof(SonWithoutVirtualSingleInheritParentWithVirtual1), 40);
    SonWithoutVirtualSingleInheritParentWithVirtual1 sonWithoutVirtualSingleInheritParentWithVirtual1;
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::char_var) - 8,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::short_var) - 2,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::int_var) - 2,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::double_var) - 4,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::int_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.char_var) - 8,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::double_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.short_var) - 2,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.int_var) - 2,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.double_var) - 4,
              (unsigned long long)&(sonWithoutVirtualSingleInheritParentWithVirtual1.int_var)
    );


    EXPECT_EQ(sizeof(SonWithVirtualSingleInheritParentWithoutVirtual1), 40);
    SonWithVirtualSingleInheritParentWithoutVirtual1 sonWithVirtualSingleInheritParentWithoutVirtual1;
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::char_var) - 8,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::short_var) - 2,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::int_var) - 2,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::double_var) - 4,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::int_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.char_var) - 8,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.ParentWithoutVirtual1::double_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.short_var) - 2,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.int_var) - 2,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.double_var) - 4,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithoutVirtual1.int_var)
    );

    EXPECT_EQ(sizeof(SonWithVirtualSingleInheritParentWithVirtual1), 40);
    SonWithVirtualSingleInheritParentWithVirtual1 sonWithVirtualSingleInheritParentWithVirtual1;
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::char_var) - 8,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::short_var) - 2,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::int_var) - 2,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::double_var) - 4,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::int_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.char_var) - 8,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.ParentWithVirtual1::double_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.short_var) - 2,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.int_var) - 2,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.double_var) - 4,
              (unsigned long long)&(sonWithVirtualSingleInheritParentWithVirtual1.int_var)
    );

    EXPECT_EQ(sizeof (SonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2), 56);
    SonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2 sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2;
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual1::char_var),
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual1::short_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual1::char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual1::int_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual1::short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual1::double_var) - 4,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual1::int_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual2::char_var) - 8,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual1::double_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual2::short_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual2::char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual2::double_var) - 6,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual2::short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual2::int_var) - 8,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual2::double_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.char_var) - 8,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.ParentWithoutVirtual2::int_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.short_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.int_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.double_var) - 4,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithoutVirtual1AndParentWithoutVirtual2.int_var)
    );

    EXPECT_EQ(sizeof (SonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1), 56);
    SonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1 sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1;

    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithVirtual1::char_var) - 8,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithVirtual1::short_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithVirtual1::char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithVirtual1::int_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithVirtual1::short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithVirtual1::double_var) - 4,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithVirtual1::int_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithoutVirtual1::char_var) - 8,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithVirtual1::double_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithoutVirtual1::short_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithoutVirtual1::char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithoutVirtual1::int_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithoutVirtual1::short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithoutVirtual1::double_var) - 4,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithoutVirtual1::int_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.char_var) - 8,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.ParentWithoutVirtual1::double_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.short_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.char_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.int_var) - 2,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.short_var)
    );
    EXPECT_EQ((unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.double_var) - 4,
              (unsigned long long)&(sonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithoutVirtual1.int_var)
    );

    EXPECT_EQ(sizeof (SonWithoutVirtualMultipleInheritParentWithVirtual1AndParentWithVirtual2), 72);
}


#ifdef WIN_64_GNU
#endif

#ifdef WIN_64_MSVC
#endif

#ifdef WIN_32_MSVC
#endif
