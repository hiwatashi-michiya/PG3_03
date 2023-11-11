#pragma once

#include <memory>
#include <array>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

class GameManager
{
private:

	std::array<std::unique_ptr<IScene>, 3> scenes_;

	int currentScene_; //現在のシーン
	int prevScene_; //前のシーン

public:

	GameManager();
	~GameManager();

	int Run();

};

