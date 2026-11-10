#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

#define main lab_rec_main
#include "..\Lab_08.1 rec\Lab_08.1_rec.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab08RecTests
{
	TEST_CLASS(Lab_08_1_Rec_Test)
	{
	public:
		TEST_METHOD(TestFindOGO)
		{
			Assert::IsTrue(FindRecursive("TESTOGO"));
		}

		TEST_METHOD(TestFindAGA)
		{
			Assert::IsTrue(FindRecursive("TESTAGA"));
		}

		TEST_METHOD(TestNoMatches)
		{
			Assert::IsFalse(FindRecursive("HELLOWORLD"));
		}

		TEST_METHOD(TestFindGroupAtStringStart)
		{
			Assert::IsTrue(FindRecursive("OGO-text"));
			Assert::IsTrue(FindRecursive("AGA-text"));
		}

		TEST_METHOD(TestGroupAtBoundaries)
		{
			Assert::IsTrue(IsGroupAt("OGO"));
			Assert::IsTrue(IsGroupAt("AGA"));
			Assert::IsFalse(IsGroupAt("OG"));
			Assert::IsFalse(IsGroupAt("AG"));
			Assert::IsFalse(IsGroupAt("XYZ"));
		}

		TEST_METHOD(TestReplaceAll)
		{
			char result[100];

			ReplaceRecursive("OGOAGAOGO", result);

			Assert::AreEqual("******", result);
		}

		TEST_METHOD(TestReplaceOverlapping)
		{
			char result[100];

			ReplaceRecursive("OGOGO", result);

			Assert::AreEqual("**GO", result);
		}

		TEST_METHOD(TestReplaceMixedText)
		{
			char result[100];

			ReplaceRecursive("OGO-TEST-AGA", result);

			Assert::AreEqual("**-TEST-**", result);
		}

		TEST_METHOD(TestEmptyString)
		{
			char result[100];

			Assert::IsFalse(FindRecursive(""));

			ReplaceRecursive("", result);

			Assert::AreEqual("", result);
		}
	};
}
