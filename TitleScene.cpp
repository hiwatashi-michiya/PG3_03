#include "TitleScene.h"
#include <Input.h>
#include <Novice.h>

void TitleScene::Init() {

	bgTex_ = Novice::LoadTexture("./Resources/bg.png");
	titleTex_ = Novice::LoadTexture("./Resources/title.png");
	spaceTex_ = Novice::LoadTexture("./Resources/space.png");

}

void TitleScene::Update() {

	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		sceneNo = STAGE;
	}

}

void TitleScene::Draw() {

	Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 0, 0, 16, 9, bgTex_, 0xffffffff);
	Novice::DrawQuad(640 - 256, 100, 640 + 256, 100, 640 - 256, 228, 640 + 256, 228,
		0, 0, 512, 128, titleTex_, 0xffffffff);
	Novice::DrawQuad(640 - 128, 500, 640 + 128, 500, 640 - 128, 564, 640 + 128, 564,
		0, 0, 256, 64, spaceTex_, 0xffffffff);

}
