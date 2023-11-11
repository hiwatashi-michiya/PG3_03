#include "StageScene.h"
#include <Input.h>
#include <Novice.h>

void StageScene::Init() {

	bgTex_ = Novice::LoadTexture("./Resources/bg.png");
	spaceTex_ = Novice::LoadTexture("./Resources/space.png");
	isClear_ = false;
	isShot_ = false;
	playerPos_ = { 500.0f,360.0f };
	playerRad_ = 10;
	enemyPos_ = { 700.0f,360.0f };
	enemyRad_ = 20;
	bulletPos_ = { -100.0f,-100.0f };
	bulletRad_ = 5;

}

void StageScene::Update() {

	if (isClear_) {
		sceneNo = CLEAR;
	}
	
	if (Input::GetInstance()->TriggerKey(DIK_SPACE) && isShot_ == false) {
		bulletPos_ = { playerPos_.x, playerPos_.y };
		isShot_ = true;
	}

	if (isShot_) {
		bulletPos_.x += 5.0f;
	}

	float lengthX = enemyPos_.x - bulletPos_.x;
	float lengthY = enemyPos_.y - bulletPos_.y;

	if (sqrtf(lengthX * lengthX + lengthY * lengthY) <= bulletRad_ + enemyRad_) {
		isClear_ = true;
	}


}

void StageScene::Draw() {

	Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 0, 0, 16, 9, bgTex_, 0xffffffff);

	if (isShot_) {
		Novice::DrawEllipse(int(bulletPos_.x), int(bulletPos_.y), bulletRad_, bulletRad_, 0.0f, 0x88ff88ff, kFillModeSolid);
	}
	else {
		Novice::DrawQuad(640 - 128, 500, 640 + 128, 500, 640 - 128, 564, 640 + 128, 564,
			0, 0, 256, 64, spaceTex_, 0xffffffff);
	}

	Novice::DrawEllipse(int(playerPos_.x), int(playerPos_.y), playerRad_, playerRad_, 0.0f, 0xffffffff, kFillModeSolid);

	if (isClear_ == false) {
		Novice::DrawEllipse(int(enemyPos_.x), int(enemyPos_.y), enemyRad_, enemyRad_, 0.0f, 0xff8888ff, kFillModeSolid);
	}
	

}
