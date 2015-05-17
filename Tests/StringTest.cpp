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
		//	test.Trim();
			const char * cpy = test.getString();
			Assert::AreEqual(cpy[0], 'H');
		}
	};
	
}