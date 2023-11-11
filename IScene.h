#pragma once

class IScene
{
protected:

	//シーン番号の管理
	static int sceneNo;

public:

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	enum SCENE {
		TITLE,
		STAGE,
		CLEAR
	};

	//シーン番号のゲッター
	int GetSceneNo();

};

