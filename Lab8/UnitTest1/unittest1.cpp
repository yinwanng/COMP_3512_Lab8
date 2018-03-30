#include "../Lab8/FixedList.h"
#include "CppUnitTest.h"
#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		FixedList<double, 8> list1;
		FixedList<string, 10> list2;
		TEST_METHOD_INITIALIZE(TestMethod1)
		{
			list1.add(1.0);
			list1.add(2.0);
			list1.add(3.0);
			list1.add(4.0);
			list1.add(5.0);
			list2.add("Johnny");
			list2.add("Bob");
			list2.add("Chris");
			list2.add("Fiona");
		}

		TEST_METHOD(TestAdd1)
		{
			Assert::IsTrue(list1.add(6));
		}

		TEST_METHOD(TestAdd2)
		{
			Assert::IsTrue(list2.add("Tom"));
		}

		TEST_METHOD(TestSize1)
		{
			Assert::AreEqual(static_cast<size_t>(5), list1.size());
		}

		TEST_METHOD(TestSize2)
		{
			Assert::AreEqual(static_cast<size_t>(4), list2.size());
		}

		TEST_METHOD(TestCapacity1)
		{
			Assert::AreEqual(static_cast<size_t>(8), list1.capacity());
		}

		TEST_METHOD(TestCapacity2)
		{
			Assert::AreEqual(static_cast<size_t>(10), list2.capacity());
		}


		TEST_METHOD(TestGetIndexValue1)
		{
			Assert::AreEqual(1.0, list1.get(0));
		}

		TEST_METHOD(TestGetIndexValue2)
		{
			string s = "Chris";
			Assert::AreEqual(s, list2.get(2));
		}

		TEST_METHOD(TestGetIndexValue3)
		{

			bool exceptionThrown = false;
			try {
				list2.get(20);
			}
			catch (std::range_error) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown);
		}


		TEST_METHOD(TestBrackets1)
		{
			Assert::AreEqual(1.0, list1[0]);
		}

		TEST_METHOD(TestBrackets2)
		{
			string s = "Johnny";
			Assert::AreEqual(s, list2[0]);
		}

		TEST_METHOD(TestBrackets3)
		{

			bool exceptionThrown = false;
			try {
				list2[29];
			}
			catch (std::range_error) {
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(TestGetFirstIndex1)
		{
			Assert::AreEqual(2, list1.getFirstIndex(3));
		}

		TEST_METHOD(TestGetFirstIndex2)
		{
			Assert::AreEqual(2, list2.getFirstIndex("Chris"));
		}

		TEST_METHOD(TestGetFirstIndex3)
		{
			Assert::AreEqual(-1, list1.getFirstIndex(99));
		}

		TEST_METHOD(TestGetFirstIndex4)
		{
			Assert::AreEqual(-1, list2.getFirstIndex("Adrian"));
		}

		TEST_METHOD(TestRemove1)
		{
			Assert::AreEqual(1.0, list1.remove(1.0));
		}

		TEST_METHOD(TestRemove2)
		{
			string s = "Chris";
			Assert::AreEqual(s, list2.remove("Chris"));
		}


		TEST_METHOD(TestRemove3)
		{
			string s = "";
			Assert::AreEqual(s, list2.remove("Kevin"));
		}

		TEST_METHOD(TestRemove4)
		{
			Assert::AreEqual(0.0, list1.remove(345345));
		}
	};
}