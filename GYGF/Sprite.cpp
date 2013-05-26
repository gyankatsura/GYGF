#include "Sprite.h"
#include "FrameBasedController.h"
#include "Layer.h"

Sprite::~Sprite()
{
	DetachController();
}

void Sprite::SetController(FrameBasedController* c)
{
	if (m_pController != NULL)
		m_pController->SetSprite(NULL);
	m_pController = c;
	if (c != NULL)
		c->SetSprite(this);
}

void Sprite::DetachAndDestroy()
{
	if (m_pLayer == NULL) return;
	m_pLayer->RemoveSprite(this);
}

void Sprite::DetachController()
{
	if (m_pController != NULL)
	{
		delete m_pController;
		m_pController = NULL;
	}
}