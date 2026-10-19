#include <iostream>

class Enemy {

public:

	Enemy();

	bool Update();

private:

	using State = void (Enemy::*)();
	State currentState;

	void Approach();
	void Shoot();
	void Retreat();

};

Enemy::Enemy() : currentState(&Enemy::Approach) {}

bool Enemy::Update() {
	if (currentState == nullptr) {
		return false;
	}

	(this->*currentState)();
	return true;
}

void Enemy::Approach()
{
	std::cout << "Approach\n";
	currentState = &Enemy::Shoot;
}

void Enemy::Shoot()
{
	std::cout << "Shoot\n";
	currentState = &Enemy::Retreat;
}

void Enemy::Retreat()
{
	std::cout << "Retreat\n";
	currentState = nullptr;  // 行動終了
}

int main() {
	Enemy enemy;

	while (enemy.Update()) {

	}

	return 0;
}
