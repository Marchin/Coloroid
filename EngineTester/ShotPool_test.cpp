#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SFML_Practica/Headers/Shot/ShotPool.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EngineTester {
	TEST_CLASS(ShotPool_test) {
public:

	TEST_METHOD(Instatiation) {
		sf::View view(sf::FloatRect(0, 0, 256, 240));
		shotSys::ShotPool shotPool(&view, 3);
		Assert::IsTrue(shotPool.RequestShot(10, sf::Color::Red));
		Assert::IsTrue(shotPool.RequestShot(10, sf::Color::Red));
		Assert::IsTrue(shotPool.RequestShot(10, sf::Color::Red));
		Assert::IsFalse(shotPool.RequestShot(10, sf::Color::Red));
	}


	TEST_METHOD(Refill) {
		float deltaTime = 0.f;
		std::vector<sf::Sprite> obstacles;
		sf::View view(sf::FloatRect(0, 0, 256, 240));
		shotSys::ShotPool shotPool(&view, 3);
		shotPool.RequestShot(10, sf::Color::Red);
		shotPool.RequestShot(10, sf::Color::Red);
		shotPool.RequestShot(10, sf::Color::Red);
		shotPool.RequestShot(10, sf::Color::Red);
		while (deltaTime < 5.f) {
			shotPool.Update(deltaTime, obstacles);
			deltaTime += .33f;
		}
		Assert::IsTrue(shotPool.RequestShot(10, sf::Color::Red));
		Assert::IsTrue(shotPool.RequestShot(10, sf::Color::Red));
		Assert::IsTrue(shotPool.RequestShot(10, sf::Color::Red));
		Assert::IsFalse(shotPool.RequestShot(10, sf::Color::Red));
	}

	};
}