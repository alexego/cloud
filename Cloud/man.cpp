#include "man.h"
Man::Man(sf::Texture& text, sf::Vector2u size, sf::Vector2f pos) :
man(text),
hp(30.0f),
Destination(0),
CurrFrame(0.0f),
animateTime(0)
{
	man.setOrigin(sf::Vector2f(size.x / 2, size.y));
	man.setScale(0.8, 0.8);
	man.setPosition(pos);
	manSize = size;
	
	int currentStrategy = rand() % 4;
	if (currentStrategy) {
		strategy = new ManStrategyAlive;
	} else {
		strategy = new ManStrategyDead;
	}
	//std::cout << size.x * man.getScale().x << ' ' << man.getPosition().y << std::endl;
}

sf::Sprite Man::getDrawable() {

	return this->man;
}

sf::Vector2f Man::getPosition() {
	return man.getPosition();
}

void Man::setPosition(float x, float y) {
	man.setPosition(x, y);
}

void Man::move(float offsetX, float offsetY) {
	man.move(offsetX, offsetY);
}
float Man::getRight() {
	return man.getPosition().x + manSize.x * man.getScale().x / 2;
}

float Man::getLeft() {
	return man.getPosition().x - manSize.x * man.getScale().x / 2;
}

int Man::getHP() {
	return hp;
}

//void man::hpiterator(float elapsed) {
//
//}

int Man::Redirect() {
	int a = rand() % 501; //случайное от 0 до 100
	int oldDest = Destination;
	//вероятность изменения состояния
	if (a >= 499)
	{
		//while (oldDest == Destination) //пока не сменится направление
		//{
			Destination = strategy->operator()(); //-1, 0 или 1
		//}
		CurrFrame = 0;
	}
	return Destination;
}

int Man::GetDestination()
{
	return Destination;
}

void Man::Animate(float elapsed)
{
	float Anim_Coeff = 8; //4 - 2 шажка в секунду, 8 - 4 шажка

	if (Destination == 0)//если стоит - отрисовываем 
	{
		man.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
	else if (Destination == -1)
	{
		CurrFrame = CurrFrame + Anim_Coeff*elapsed;
		if (CurrFrame > 4) CurrFrame -= 4;
		man.setTextureRect(sf::IntRect(64 * int(CurrFrame), 64, 64, 64));
	}
	else
	{
		CurrFrame = CurrFrame + Anim_Coeff*elapsed;
		if (CurrFrame > 4) CurrFrame -= 4;
		man.setTextureRect(sf::IntRect(64 * int(CurrFrame), 128, 64, 64));
	}
	//std::cout << CurrFrame << std::endl;
}