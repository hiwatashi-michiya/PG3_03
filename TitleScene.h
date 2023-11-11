#pragma once
#include "IScene.h"

class TitleScene : public IScene
{

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	int bgTex_;
	int titleTex_;
	int spaceTex_;

};

