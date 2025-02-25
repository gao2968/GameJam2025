#pragma once


#define INITHP 10800

class Ui
{
private:
	int hp = INITHP;	//hpŒ“timer
	int score = 0;
	int enemy_cnt;	//Žc‚è‚Ì“G

	int stopwatch_image;
	int meibo_image;

public:
	Ui();
	~Ui();

	void Initialize();
	void Update();
	void Draw();
	void Finalize();

	void SetHp(int hp_ui);
	void SetScore(int score_ui);
	void Setenemy_cnt(int enemy_cnt_ui);
};