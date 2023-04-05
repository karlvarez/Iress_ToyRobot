#include "pch.h"
#include "CppUnitTest.h"

#include "../Iress_ToyRobot/Robot.h"
#include "../Iress_ToyRobot/Table.h"
#include "../Iress_ToyRobot/InputParser_Controller.h"

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
		TEST_METHOD(T_Robot_Initial)
		{
			Robot testRobot;

			Assert::AreEqual(testRobot.GetX(), (long)POS_NOTSET);
			Assert::AreEqual(testRobot.GetY(), (long)POS_NOTSET);
			Assert::AreEqual(testRobot.GetFace(), FACE_NOTSET);
			Assert::IsFalse(testRobot.TryMove(1, 2, 3, 4));
		}

		TEST_METHOD(T_Robot_Place_0_0_N)
		{
			Robot testRobot;

			testRobot.Place(0, 0, FACE_N);
			Assert::AreEqual(testRobot.GetX(), (long)0);
			Assert::AreEqual(testRobot.GetY(), (long)0);
			Assert::AreEqual(testRobot.GetFace(), FACE_N);
		}

		TEST_METHOD(T_Robot_Place_100_100_S)
		{
			Robot testRobot;

			testRobot.Place(100, 100, FACE_S);
			Assert::AreEqual(testRobot.GetX(), (long)100);
			Assert::AreEqual(testRobot.GetY(), (long)100);
			Assert::AreEqual(testRobot.GetFace(), FACE_S);
		}

		TEST_METHOD(T_Robot_Place_0_100_E)
		{
			Robot testRobot;

			testRobot.Place(0, 100, FACE_E);
			Assert::AreEqual(testRobot.GetX(), (long)0);
			Assert::AreEqual(testRobot.GetY(), (long)100);
			Assert::AreEqual(testRobot.GetFace(), FACE_E);
		}

		TEST_METHOD(T_Robot_Place_100_0_W)
		{
			Robot testRobot;

			testRobot.Place(100, 0, FACE_W);
			Assert::AreEqual(testRobot.GetX(), (long)100);
			Assert::AreEqual(testRobot.GetY(), (long)0);
			Assert::AreEqual(testRobot.GetFace(), FACE_W);
		}

		TEST_METHOD(T_Robot_TryPlace)
		{
			Robot testRobot;

			Assert::IsTrue(testRobot.TryPlace(0, 0, 5, 0, 0, 5, FACE_N));
		}

		TEST_METHOD(T_Robot_TryPlace_Invalid_X)
		{
			Robot testRobot;

			Assert::IsFalse(testRobot.TryPlace(100, 0, 5, 0, 0, 5, FACE_N));
		}

		TEST_METHOD(T_Robot_TryPlace_Invalid_Y)
		{
			Robot testRobot;

			Assert::IsFalse(testRobot.TryPlace(0, 0, 5, 100, 0, 5, FACE_N));
		}

		TEST_METHOD(T_Robot_TryPlace_Invalid_FACE)
		{
			Robot testRobot;

			Assert::IsFalse(testRobot.TryPlace(0, 0, 5, 0, 0, 5, FACE_NOTSET));
		}

		TEST_METHOD(T_Robot_Move_N)
		{
			Robot testRobot;

			testRobot.Place(3, 3, FACE_N);
			testRobot.Move();
			Assert::AreEqual(testRobot.GetX(), (long)3);
			Assert::AreEqual(testRobot.GetY(), (long)4);
			Assert::AreEqual(testRobot.GetFace(), FACE_N);
		}

		TEST_METHOD(T_Robot_Move_S)
		{
			Robot testRobot;

			testRobot.Place(3, 3, FACE_S);
			testRobot.Move();
			Assert::AreEqual(testRobot.GetX(), (long)3);
			Assert::AreEqual(testRobot.GetY(), (long)2);
			Assert::AreEqual(testRobot.GetFace(), FACE_S);
		}

		TEST_METHOD(T_Robot_Move_E)
		{
			Robot testRobot;

			testRobot.Place(3, 3, FACE_E);
			testRobot.Move();
			Assert::AreEqual(testRobot.GetX(), (long)4);
			Assert::AreEqual(testRobot.GetY(), (long)3);
			Assert::AreEqual(testRobot.GetFace(), FACE_E);
		}

		TEST_METHOD(T_Robot_Move_W)
		{
			Robot testRobot;

			testRobot.Place(3, 3, FACE_W);
			testRobot.Move();
			Assert::AreEqual(testRobot.GetX(), (long)2);
			Assert::AreEqual(testRobot.GetY(), (long)3);
			Assert::AreEqual(testRobot.GetFace(), FACE_W);
		}

		TEST_METHOD(T_Robot_TryMove_N)
		{
			Robot testRobot;

			testRobot.Place(0, 0, FACE_N);
			Assert::IsTrue(testRobot.TryMove(0, 100, 0, 100));
		}

		TEST_METHOD(T_Robot_TryMove_N_Invalid)
		{
			Robot testRobot;

			testRobot.Place(100, 100, FACE_N);
			Assert::IsFalse(testRobot.TryMove(0, 100, 0, 100));
		}

		TEST_METHOD(T_Robot_TryMove_S)
		{
			Robot testRobot;

			testRobot.Place(100, 100, FACE_S);
			Assert::IsTrue(testRobot.TryMove(0, 100, 0, 100));
		}

		TEST_METHOD(T_Robot_TryMove_S_Invalid)
		{
			Robot testRobot;

			testRobot.Place(0, 0, FACE_S);
			Assert::IsFalse(testRobot.TryMove(0, 100, 0, 100));
		}

		TEST_METHOD(T_Robot_TryMove_E)
		{
			Robot testRobot;

			testRobot.Place(0, 0, FACE_E);
			Assert::IsTrue(testRobot.TryMove(0, 100, 0, 100));
		}

		TEST_METHOD(T_Robot_TryMove_E_Invalid)
		{
			Robot testRobot;

			testRobot.Place(100, 100, FACE_E);
			Assert::IsFalse(testRobot.TryMove(0, 100, 0, 100));
		}

		TEST_METHOD(T_Robot_TryMove_W)
		{
			Robot testRobot;

			testRobot.Place(100, 100, FACE_W);
			Assert::IsTrue(testRobot.TryMove(0, 100, 0, 100));
		}

		TEST_METHOD(T_Robot_TryMove_W_Invalid)
		{
			Robot testRobot;

			testRobot.Place(0, 0, FACE_W);
			Assert::IsFalse(testRobot.TryMove(0, 100, 0, 100));
		}
		TEST_METHOD(T_Robot_Left_N)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_N);
			testRobot.Left();
			Assert::AreEqual(testRobot.GetX(), (long)1);
			Assert::AreEqual(testRobot.GetY(), (long)99);
			Assert::AreEqual(testRobot.GetFace(), FACE_W);
		}
		TEST_METHOD(T_Robot_Left_S)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_S);
			testRobot.Left();
			Assert::AreEqual(testRobot.GetX(), (long)1);
			Assert::AreEqual(testRobot.GetY(), (long)99);
			Assert::AreEqual(testRobot.GetFace(), FACE_E);
		}
		TEST_METHOD(T_Robot_Left_E)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_E);
			testRobot.Left();
			Assert::AreEqual(testRobot.GetX(), (long)1);
			Assert::AreEqual(testRobot.GetY(), (long)99);
			Assert::AreEqual(testRobot.GetFace(), FACE_N);
		}

		TEST_METHOD(T_Robot_Left_W)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_W);
			testRobot.Left();
			Assert::AreEqual(testRobot.GetX(), (long)1);
			Assert::AreEqual(testRobot.GetY(), (long)99);
			Assert::AreEqual(testRobot.GetFace(), FACE_S);
		}
		TEST_METHOD(T_Robot_Right_N)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_N);
			testRobot.Right();
			Assert::AreEqual(testRobot.GetX(), (long)1);
			Assert::AreEqual(testRobot.GetY(), (long)99);
			Assert::AreEqual(testRobot.GetFace(), FACE_E);
		}
		TEST_METHOD(T_Robot_Right_S)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_S);
			testRobot.Right();
			Assert::AreEqual(testRobot.GetX(), (long)1);
			Assert::AreEqual(testRobot.GetY(), (long)99);
			Assert::AreEqual(testRobot.GetFace(), FACE_W);
		}
		TEST_METHOD(T_Robot_Right_E)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_E);
			testRobot.Right();
			Assert::AreEqual(testRobot.GetX(), (long)1);
			Assert::AreEqual(testRobot.GetY(), (long)99);
			Assert::AreEqual(testRobot.GetFace(), FACE_S);
		}
		TEST_METHOD(T_Robot_Right_W)
		{
			Robot testRobot;

			testRobot.Place(1, 99, FACE_W);
			testRobot.Right();
			Assert::AreEqual(testRobot.GetX(), (long)1);
			Assert::AreEqual(testRobot.GetY(), (long)99);
			Assert::AreEqual(testRobot.GetFace(), FACE_N);
		}

		TEST_METHOD(T_Table_Initial) {
			Table testTable;
			testTable.SetSize(10, 10);

			Assert::AreEqual(testTable.GetXSize(), (long)10);
			Assert::AreEqual(testTable.GetYSize(), (long)10);
		}

		TEST_METHOD(T_Table_PlaceRobot) {
			Table testTable;
			testTable.SetSize(10, 10);

			Assert::IsTrue(testTable.PlaceRobot(0, 0, FACE_N));
			Assert::IsTrue(testTable.PlaceRobot(0, 9, FACE_S));
			Assert::IsTrue(testTable.PlaceRobot(9, 0, FACE_E));
			Assert::IsTrue(testTable.PlaceRobot(9, 9, FACE_W));

			Assert::IsFalse(testTable.PlaceRobot(10, 3, FACE_N));
			Assert::IsFalse(testTable.PlaceRobot(3, 10, FACE_N));
			Assert::IsFalse(testTable.PlaceRobot(-1, 0, FACE_N));
			Assert::IsFalse(testTable.PlaceRobot(0, -1, FACE_N));
		}

		TEST_METHOD(T_Table_MoveRobot) {
			Table testTable;
			testTable.SetSize(5, 5);
			testTable.PlaceRobot(3, 3, FACE_N);
			Assert::IsTrue(testTable.MoveRobot()); // now at 3, 4
			Assert::IsFalse(testTable.MoveRobot()); // fall
		}

		TEST_METHOD(T_Table_LeftRobot) {
			Table testTable;
			testTable.SetSize(5, 5);

			testTable.PlaceRobot(3, 3, FACE_W);
			testTable.LeftRobot(); // now facing South
			testTable.LeftRobot(); // now facing East
			testTable.LeftRobot(); // now facing North
			Assert::IsTrue(testTable.MoveRobot()); // now at 3, 4
			Assert::IsFalse(testTable.MoveRobot()); // fall
		}

		TEST_METHOD(T_Table_RightRobot) {
			Table testTable;
			testTable.SetSize(5, 5);

			testTable.PlaceRobot(3, 3, FACE_E);
			testTable.RightRobot(); // now facing South
			testTable.RightRobot(); // now facing West
			testTable.RightRobot(); // now facing North
			Assert::IsTrue(testTable.MoveRobot()); // now at 3, 4
			Assert::IsFalse(testTable.MoveRobot()); // fall
		}
		TEST_METHOD(T_IPC_Place) {
			InputParser_Controller ipc;

			Assert::IsTrue(ipc.Place(3, 3, FACE_N));
			Assert::IsFalse(ipc.Place(10, 10, FACE_S));
			Assert::IsTrue(ipc.Place(4, 4, FACE_E));
			Assert::IsFalse(ipc.Place(5, 4, FACE_W));
		}

	};
}
