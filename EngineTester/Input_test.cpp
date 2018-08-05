#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SFML_Practica/Headers/Controllers/Input/InputObserver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EngineTester {
	static bool state;
	bool ReadKey(int waste) {
		return state;
	}

	TEST_CLASS(Input_test) {
public:

	TEST_METHOD(Instatiation) {
		auto a = &ReadKey;
		state = false;
		input::InputObserver<bool> key(a, 10);
		Assert::IsFalse(key.IsPressed());
		Assert::IsFalse(key.PressDown());
		Assert::IsFalse(key.PressUp());
		state = true;
		key.Update();
		Assert::IsTrue(key.IsPressed());
		Assert::IsTrue(key.PressDown());
		Assert::IsFalse(key.PressUp());
		key.Update();
		Assert::IsTrue(key.IsPressed());
		Assert::IsFalse(key.PressDown());
		Assert::IsFalse(key.PressUp());
		state = false;
		key.Update();
		Assert::IsFalse(key.IsPressed());
		Assert::IsFalse(key.PressDown());
		Assert::IsTrue(key.PressUp());
		state = false;
		key.Update();
		Assert::IsFalse(key.IsPressed());
		Assert::IsFalse(key.PressDown());
		Assert::IsFalse(key.PressUp());
	}
	};

	class KeyboardMockup {
	public:
		KeyboardMockup() : m_state(false) {}
		static bool ReadTrue(int a) {
			return true;
		}
		bool ReadFalse() {
			return false;
		}
		bool m_state;
	};
}