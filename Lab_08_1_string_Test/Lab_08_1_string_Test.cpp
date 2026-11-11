
#include "pch.h"
#include "CppUnitTest.h"

#include <string>

#define main lab_main
#include "..\Lab-08.1 string\Lab-08.1 string.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab081StringTests
{
    TEST_CLASS(StringTests)
    {
    public:

        TEST_METHOD(TestFindOGO)
        {
            Assert::IsTrue(FindString("TESTOGO"));
        }

        TEST_METHOD(TestFindAGA)
        {
            Assert::IsTrue(FindString("TESTAGA"));
        }

        TEST_METHOD(TestNoMatch)
        {
            Assert::IsFalse(FindString("HELLOWORLD"));
        }

        TEST_METHOD(TestReplaceOGO)
        {
            std::string s = "TESTOGOEND";

            ReplaceString(s);

            Assert::IsTrue(s == "TEST**END");
        }

        TEST_METHOD(TestReplaceAGA)
        {
            std::string s = "TESTAGAEND";

            ReplaceString(s);

            Assert::IsTrue(s == "TEST**END");
        }

        TEST_METHOD(TestReplaceAll)
        {
            std::string s = "OGOAGAOGO";

            ReplaceString(s);

            Assert::IsTrue(s == "******");
        }

        TEST_METHOD(TestOverlappingGroups)
        {
            std::string s = "OGOGO";

            ReplaceString(s);

            Assert::IsTrue(s == "**GO");
        }

        TEST_METHOD(TestEmptyString)
        {
            std::string s = "";

            Assert::IsFalse(FindString(s));

            ReplaceString(s);

            Assert::IsTrue(s.empty());
        }

        TEST_METHOD(TestShortString)
        {
            std::string s = "OG";

            Assert::IsFalse(FindString(s));

            ReplaceString(s);

            Assert::IsTrue(s == "OG");
        }

        TEST_METHOD(TestMixedText)
        {
            std::string s = "TESTOGOAGAOGOEND";

            Assert::IsTrue(FindString(s));

            ReplaceString(s);

            Assert::IsTrue(s == "TEST******END");
        }
    };
}
