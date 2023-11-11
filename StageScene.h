#pragma once
#include "IScene.h"
#include <Vector2.h>

class StageScene : public IScene
{

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	int bgTex_;
	int spaceTex_;
	//クリアしたかどうか
	bool isClear_;
	//弾発射フラグ
	bool isShot_;

	Vector2 playerPos_;
	int playerRad_;
	Vector2 enemyPos_;
	int enemyRad_;
	Vector2 bulletPos_;
	int bulletRad_;


};

