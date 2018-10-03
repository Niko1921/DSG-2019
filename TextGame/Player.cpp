#include "stdafx.h"
#include "Player.h"
#include "World.h"




//int x, y, coins=0, limitx, limity;


Player::Player()
{
}


Player::~Player()
{
}

void Player::setcoord(int q, int w) {
	x = q;
	y = w;

}



bool Player::movegeneral (int x1, int  y1) {

	char a = World::getInstance()->checkbox(x1, y1);
	if (World::getInstance()->iswall(a))
	{
	 return false;
	}
	if (World::getInstance()->isplayer(a))
	{
		return false;
	}
	if (World::getInstance()->iscoin(a))
	{
		coins++;
		return true;
	}
	if (World::getInstance()->isempty(a))
	{
		return true;

	}
	return false;

}


void Player::moveUp()
{
	if (x!=limitx) {
		if (movegeneral(x + 1, y))
		{
			x++;
		};
	}


}

void Player::moveDown()
{ 

	if (x != 0) {
		if (movegeneral(x -1, y))
		{
			x--;
		};
	}
}

void Player::moveRight()
{
	if (y != limity) {
		if (movegeneral(x, y+1))
		{
			y++;
		};
	}
}

void Player::moveLeft()
{

	if (y != 0) {

		if (movegeneral(x, y-1))
		{
			y--;
		};
	}
}


