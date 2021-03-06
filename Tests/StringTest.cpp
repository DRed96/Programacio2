#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/String.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(StringTest)
	{
	public:
		
		TEST_METHOD(SString_empty_ctor)
		{
			String s;
			Assert::AreEqual((int)s.getLen(), 0);
		}
		TEST_METHOD(SString_char_ctor)
		{
			String s("Hola mundo");
			Assert::AreEqual((int)s.getLen(), 10);
		}
		TEST_METHOD(SString_format_ctor)
		{
			String s("%s %s %d", "hola", "mundo", 12);
			Assert::AreEqual((int)s.getLen(), 13);
		}
		TEST_METHOD(SString_copy_ctor)
		{
			String s("%s %s %d", "hola", "mundo", 12);
			String s2(s);
			Assert::AreEqual((int)s2.getLen(), 13);
		}
		TEST_METHOD(SString_op_equal)
		{
			String s1("Hola mundo");
			String s2("Hola mundo");
			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(SString_op_notequal)
		{
			String s1("Hola mundo 1");
			String s2("Hola mundo 2");
			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(SString_op_equal_cstr)
		{
			String s1("Hola mundo");
			Assert::IsTrue(s1 == "Hola mundo");
		}
		TEST_METHOD(SString_op_notequal_cstr)
		{
			String s1("Hola mundo 1");
			Assert::IsTrue(s1 != "test");
		}
		TEST_METHOD(SString_op_assign)
		{
			String s1("Hola mundo");
			String s2;
			s2 = s1;
			Assert::IsTrue(s2 == "Hola mundo");
		}
		TEST_METHOD(SString_op_assign_cstr)
		{
			String s1("Hola mundo");
			s1 = "this is a test";
			Assert::IsTrue(s1 == "this is a test");
		}
		TEST_METHOD(SString_op_concat)
		{
			String s1("Hola mundo");
			String s2("this is a test");
			s1 += s2;
			Assert::IsTrue(s1 == "Hola mundothis is a test");
		}
		TEST_METHOD(SString_op_concat_cstr)
		{
			String s1("Hola mundo");
			s1 += "this is a test";
			Assert::IsTrue(s1 == "Hola mundothis is a test");
		}
		TEST_METHOD(SString_length)
		{
			String s1("Hola mundo");
			Assert::AreEqual((int)s1.getLen(), 10);
		}
		TEST_METHOD(SString_capacity)
		{
			String s1("Hola mundo");
			Assert::AreEqual((int)s1.getSize(), 11);
		}
		TEST_METHOD(SString_getstr)
		{
			String s1("Hola mundo");
			Assert::AreEqual((int)strcmp("Hola mundo", s1.getString()), 0);
		}
		TEST_METHOD(SString_clear)
		{
			String s1("Hola mundo");
			s1.Clear();
			Assert::AreEqual((int)s1.getLen(), 0);
		}
		
		TEST_METHOD(String_Trim)
		{
			String test("    Hola mundo      ");//4 esquerra, 6 dreta
			test.Trim(true, true, ' ');
			const char * cpy = test.getString();
			Assert::AreEqual(cpy[0], 'H');
			Assert::AreEqual(cpy[1], 'o');
			Assert::AreEqual(cpy[2], 'l');
			Assert::AreEqual(cpy[3], 'a');
			Assert::AreEqual(cpy[4], ' ');
			Assert::AreEqual(cpy[5], 'm');
			Assert::AreEqual(cpy[6], 'u');
			Assert::AreEqual(cpy[7], 'n');
			Assert::AreEqual(cpy[8], 'd');
			Assert::AreEqual(cpy[9], 'o');
			Assert::AreEqual(cpy[10],'\0');
			Assert::AreEqual(cpy[20],'\0');
		}

		TEST_METHOD(String_Substitute)
		{
			String test("Hola mundo");//4 esquerra, 6 dreta
			test.Substitute("mundo", "loli");


			const char * cpy = test.getString();

			/*Assert::AreEqual(cpy[0], 'H');
			Assert::AreEqual(cpy[1], 'o');
			Assert::AreEqual(cpy[2], 'l');
			Assert::AreEqual(cpy[3], 'a');
			Assert::AreEqual(cpy[4], ' ');
			Assert::AreEqual(cpy[5], 'l');
			Assert::AreEqual(cpy[6], 'o');
			Assert::AreEqual(cpy[7], 'l');
			Assert::AreEqual(cpy[8], 'i');
			Assert::AreEqual(cpy[9], 'o');
			Assert::AreEqual(cpy[10], '\0');
			Assert::AreEqual(cpy[20], '\0');*/
		}

		TEST_METHOD(String_Find_Queue)
		{
			String test("hola mundo hola mundo mundo hola hol mun mundo");
			Queue<unsigned int> t1;
			test.Find("mund", t1);
			Assert::AreEqual((int)t1.getElem(), 4);
			
		}

	
	};
	
}