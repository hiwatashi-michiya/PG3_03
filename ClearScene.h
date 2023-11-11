#pragma once
#include "IScene.h"

class ClearScene : public IScene
{

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	int bgTex_;
	int clearTex_;
	int spaceTex_;

};

