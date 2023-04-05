#include "pch.h"
#include "CppUnitTest.h"

#include "../Iress_ToyRobot/Robot.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<>
			static std::wstring ToString<Robot>(const Robot& r) {
				return L"Robot";
			}

			template<>
			static std::wstring ToString<Face>(const Face& f) {
				return L"Face";
			}
		}
	}
}

namespace UnitTestAll
{
	TEST_CLASS(UnitTestAll)
	{
	public:
		TEST_METHOD(TestMethod_Initial)
		{
			Robot testRobot;

			Assert::AreEqual(testRobot.getX(), POS_NOTSET);
			Assert::AreEqual(testRobot.getY(), POS_NOTSET);
			Assert::AreEqual(testRobot.getFace(), FACE_NOTSET);
		}

		TEST_METHOD(TestMethod_Place_1_99_N)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_N);
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_N);
		}
		TEST_METHOD(TestMethod_Place_1_99_S)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_S);
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_S);
		}
		TEST_METHOD(TestMethod_Place_1_99_E)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_E);
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_E);
		}
		TEST_METHOD(TestMethod_Place_1_99_W)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_W);
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_W);
		}

		TEST_METHOD(TestMethod_Place_1_99_N_Left)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_N);
			testRobot.Left();
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_W);
		}

		TEST_METHOD(TestMethod_Place_1_99_S_Left)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_S);
			testRobot.Left();
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_E);
		}

		TEST_METHOD(TestMethod_Place_1_99_E_Left)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_E);
			testRobot.Left();
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_N);
		}

		TEST_METHOD(TestMethod_Place_1_99_W_Left)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_W);
			testRobot.Left();
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_S);
		}

		TEST_METHOD(TestMethod_Place_1_99_N_Right)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_N);
			testRobot.Right();
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_E);
		}

		TEST_METHOD(TestMethod_Place_1_99_S_Right)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_S);
			testRobot.Right();
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_W);
		}

		TEST_METHOD(TestMethod_Place_1_99_E_Right)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_E);
			testRobot.Right();
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_S);
		}

		TEST_METHOD(TestMethod_Place_1_99_W_Right)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_W);
			testRobot.Right();
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_N);
		}

		TEST_METHOD(TestMethod_Place_1_99_N_Move)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_N);
			testRobot.Move();
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 100);
			Assert::AreEqual(testRobot.getFace(), FACE_N);
		}

		TEST_METHOD(TestMethod_Place_1_99_S_Move)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_S);
			testRobot.Move();
			Assert::AreEqual(testRobot.getX(), 1);
			Assert::AreEqual(testRobot.getY(), 98);
			Assert::AreEqual(testRobot.getFace(), FACE_S);
		}

		TEST_METHOD(TestMethod_Place_1_99_E_Move)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_E);
			testRobot.Move();
			Assert::AreEqual(testRobot.getX(), 2);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_E);
		}

		TEST_METHOD(TestMethod_Place_1_99_W_Move)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_W);
			testRobot.Move();
			Assert::AreEqual(testRobot.getX(), 0);
			Assert::AreEqual(testRobot.getY(), 99);
			Assert::AreEqual(testRobot.getFace(), FACE_W);
		}
	};
}
