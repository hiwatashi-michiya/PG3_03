#include "IScene.h"

//タイトルシーンで初期化
int IScene::sceneNo = TITLE;

IScene::~IScene(){}

//シーン番号のゲッター
int IScene::GetSceneNo() { return sceneNo; }
