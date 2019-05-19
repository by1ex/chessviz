#include "ctest.h"

CTEST(check, test_1)
{
    ASSERT_EQUAL(0, 0);
}

CTEST(check, test_2)
{
    ASSERT_EQUAL(0, 1);
}

CTEST(check, test_3)
{
    ASSERT_STR("str", "str");
}

CTEST(check, test_4)
{
    ASSERT_STR("str1", "str2");
}