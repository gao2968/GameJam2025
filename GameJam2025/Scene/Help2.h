#pragma once
#include"SceneBase.h"

class Help2 : public SceneBase
{
private:
	int help_image;
public:
	Help2();
	virtual ~Help2();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};

