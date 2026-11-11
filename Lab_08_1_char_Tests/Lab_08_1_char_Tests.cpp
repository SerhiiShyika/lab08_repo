
#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

#define main lab_main
#include "..\Lab_08_1_char\Lab_08_1_char.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab081CharTests
{
    TEST_CLASS(CharTests)
    {
    public:
        TEST_METHOD(TestCharFind)
        {
            Assert::IsTrue(FindChar("OGO"));
            Assert::IsTrue(FindChar("TESTAGA"));
            Assert::IsFalse(FindChar("HELLO"));
        }

        TEST_METHOD(TestCharReplace)
        {
            char s[100] = "OGOAGAOGO";

            ReplaceChar(s);

            Assert::IsTrue(strcmp(s, "******") == 0);
        }

        TEST_METHOD(TestCharOverlapping)
        {
            char s[100] = "OGOGO";

            ReplaceChar(s);

            Assert::IsTrue(strcmp(s, "**GO") == 0);
        }

        TEST_METHOD(TestCharEmpty)
        {
            char s[100] = "";

            Assert::IsFalse(FindChar(s));

            ReplaceChar(s);

            Assert::IsTrue(strcmp(s, "") == 0);
        }
    };
}
