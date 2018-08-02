#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SFML_Practica/Headers/Shot/Shot.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EngineTester {
	TEST_CLASS(Shot_test) {
public:

	TEST_METHOD(Instatiation) {
		shotSys::Shot shot;
		Assert::AreEqual(shot.Width(), 8.f);
		Assert::AreEqual(shot.Height(), 8.f);
		Assert::AreEqual(shot.IsAvailable(), true);
		Assert::AreEqual(shot.GetPosition().x, 0.f);
		Assert::AreEqual(shot.GetPosition().y, 0.f);
		Assert::AreEqual((char)shot.GetColor().r, (char)0);
		Assert::AreEqual((char)shot.GetColor().g, (char)0);
		Assert::AreEqual((char)shot.GetColor().b, (char)255);
		Assert::AreEqual((char)shot.GetColor().a, (char)0);
	}

	TEST_METHOD(Positioning) {
		shotSys::Shot shot;
		shot.SetPosition(sf::Vector2f(3.f, 4.f));
		Assert::AreEqual(shot.GetPosition().x, 3.f);
		Assert::AreEqual(shot.GetPosition().y, 4.f);
	}

	};
}