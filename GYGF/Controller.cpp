#include "Controller.h"

Controller::Controller()
:m_pSprite(0)
{

}

Controller::~Controller()
{

}

void Controller::SetSprite(Sprite* pSprite)
{
	m_pSprite = pSprite;
}