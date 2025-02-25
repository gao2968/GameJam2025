#pragma once
#include"SceneBase.h"

class Help3 : public SceneBase
{
private:
	int help_image;
public:
	Help3();
	virtual ~Help3();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};

