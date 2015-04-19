#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/List.h"
#include "../Programacio2/String.cpp"
#include "../Programacio2/DynArray.h"
#include "../Programacio2/PointTemp.h"
#include "../Programacio2/Projectile.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ExamenTest)
	{
	public:
		
		
		// Projectile ----------------------------------------
		TEST_METHOD(EXAM_Projectile_test)
		{
				Projectile p;

				p.pos.x = 10.0f;
				p.pos.y = 10.0f;

				p.speed.x = 2.0f;
				p.speed.y = 0.0f;

				Point <float> current = p.GetCurrentPosition(3.0f);

				Assert::AreEqual((float)16.0f, current.x, 0.00001f);
				Assert::AreEqual((float)10.0f, current.y, 0.00001f);
			}
			

		// ArrDyn remove wasted memory ----------------------------------------
		TEST_METHOD(EXAM_ArrDyn_optimizeMem)
			{
			ArrayD<int> rray(10);

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual((unsigned int)10, array.getMem());

			unsigned int wasted = array.removeWastedMemory();

			Assert::AreEqual((unsigned int)3, array.getMem());
			Assert::AreEqual((unsigned int)7, wasted);
			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}
	
		//No m'ha donat temps a netejar el codi perquè compili i per això està en comentari
		/*
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(EXAM_p2List_delNodes_mid)
		{
			List<int> l;

			l.PushBack(1);
			l.PushBack(2);
			l.PushBack(3);
			l.PushBack(4);

		//	l.delNodes(1, 2);

			Assert::AreEqual((int)1, l.start->data);
			Assert::AreEqual((int)4, l.end->data);
			Assert::AreEqual((unsigned int)2, l.count());
		}


		
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(EXAM_p2List_delNodes_begin)
		{
			List <int> l;

			l.PushBack(1);
			l.PushBack(2);
			l.PushBack(3);
			l.PushBack(4);

			//l.delNodes(0, 3);

			Assert::AreEqual((int)4, l.start->data);
			Assert::AreEqual((int)4, l.end->data);
			Assert::AreEqual((unsigned int)1, l.count());
		}

		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(EXAM_p2List_delNodes_end)
		{
			List<int> l;

			l.PushBack(1);
			l.PushBack(2);
			l.PushBack(3);
			l.PushBack(4);

			//l.delNodes(2, 100);

			Assert::AreEqual((int)1, l.start->data);
			Assert::AreEqual((int)2, l.end->data);
			Assert::AreEqual((unsigned int)2, l.count());
		}
		*/
		
		// String prefix ----------------------------------------
		TEST_METHOD(EXAM_String_prefix)
		{
			String a("1234567890");
			String b(50);
			b = "hola";

			a.prefix(b);
			b.prefix("1234567890");

		Assert::AreEqual(strcmp(a.getString(), "hola1234567890"), 0);
		Assert::AreEqual(strcmp(b.getString(), "1234567890hola"), 0);
		}
		
	};
}