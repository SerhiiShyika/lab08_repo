
#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

// Підключення основного коду лабораторної
#define main lab_main
#include "..\Lab_08.1 it\Lab_08.1 it.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab08Tests
{
    TEST_CLASS(Lab_08_1_It_Test)
    {
    public:
        TEST_METHOD(TestFindOGO)
        {
            Assert::IsTrue(FindIterative("TESTOGO"));
        }

        TEST_METHOD(TestFindAGA)
        {
            Assert::IsTrue(FindIterative("TESTAGA"));
        }

        TEST_METHOD(TestNoMatches)
        {
            Assert::IsFalse(FindIterative("HELLOWORLD"));
        }

        TEST_METHOD(TestReplaceAll)
        {
            char result[100];

            ReplaceIterative("OGOAGAOGO", result);

            Assert::IsTrue(
                strcmp(result, "******") == 0
            );
        }

        TEST_METHOD(TestOverlapping)
        {
            char result[100];

            ReplaceIterative("OGOGO", result);

            Assert::IsTrue(
                strcmp(result, "**GO") == 0
            );
        }

        TEST_METHOD(TestEmptyString)
        {
            char result[100];

            Assert::IsFalse(FindIterative(""));

            ReplaceIterative("", result);

            Assert::IsTrue(
                strcmp(result, "") == 0
            );
        }
    };
}
