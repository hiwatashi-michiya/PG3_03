#include "GameManager.h"
#include <Novice.h>
#include <Input.h>

GameManager::GameManager() {
	scenes_[IScene::TITLE] = std::make_unique<TitleScene>();
	scenes_[IScene::STAGE] = std::make_unique<StageScene>();
	scenes_[IScene::CLEAR] = std::make_unique<ClearScene>();

	currentScene_ = IScene::TITLE;
	scenes_[currentScene_]->Init();

}

GameManager::~GameManager() {

}

int GameManager::Run() {

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		//シーンのチェック
		prevScene_ = currentScene_;
		currentScene_ = scenes_[currentScene_]->GetSceneNo();

		//シーン変更チェック
		if (prevScene_ != currentScene_) {
			scenes_[currentScene_]->Init();
		}

		//更新
		scenes_[currentScene_]->Update();

		//描画
		scenes_[currentScene_]->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Input::GetInstance()->TriggerKey(DIK_ESCAPE)) {
			break;
		}
	}

	return 0;

}
