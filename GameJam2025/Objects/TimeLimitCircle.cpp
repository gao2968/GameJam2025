#include "DxLib.h"
#include "TimeLimitCircle.h"

////ƒOƒ[ƒoƒ‹•Ï”
//int timelimit_circle_image;
//double AnglePercent = 0.0;
//
//
////§ŒÀŠÔ‚Ì‰~‚ÌƒOƒ‰ƒt‚Ì‰Šú‰»
//void TimeLimitCircleInit(void)
//{
//	//‰æ‘œ‚Ì“Ç‚İ‚İ
//	timelimit_circle_image = LoadGraph("Resource/simple_frame_01_circle_red.png");
//}
//
//
////§ŒÀŠÔ‚Ì‰~‚ÌƒOƒ‰ƒt‚Ì•`‰æ
//void TimeLimitCircleDraw(void)
//{
//	//‰~‚ÌƒOƒ‰ƒt‚Ì•`‰æ
//	DrawCircleGauge(645, 350, 100.0, timelimit_circle_image, AnglePercent);
//}
//
////í“¬‚ÌƒRƒ}ƒ“ƒh“ü—ÍƒGƒtƒFƒNƒg‚Ì•`‰æ
//int BattleSquareDraw(int square)
//{
//	//}Œ`‚Ì’l“n‚µ
//	int i = square;
//
//	//OŠpŒ`‚Ì•`‰æ
//	if (i == 3)
//	{
//		DrawTriangle(460, 475, 830, 475, 645, 125, GetColor(255, 255, 255), TRUE);
//	}
//
//	//lŠpŒ`‚Ì•`‰æ
//	if (i == 4)
//	{
//		DrawTriangle(430, 350, 860, 350, 645, 130, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(430, 350, 860, 350, 645, 560, GetColor(255, 255, 255), TRUE);
//	}
//
//	//ŒÜŠpŒ`‚Ì•`‰æ
//	if (i == 5)
//	{
//		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 270, 525, 530, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(525, 530, 765, 530, 850, 270, GetColor(255, 255, 255), TRUE);
//	}
//
//	//˜ZŠpŒ`‚Ì•`‰æ
//	if (i == 6)
//	{
//		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 270, 440, 430, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 430, 850, 430, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 430, 645, 570, 850, 430, GetColor(255, 255, 255), TRUE);
//	}
//
//	//µŠpŒ`‚Ì•`‰æ
//	if (i == 7)
//	{
//		DrawTriangle(460, 230, 645, 130, 830, 230, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(460, 230, 430, 380, 830, 230, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(430, 380, 860, 380, 830, 230, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(430, 380, 550, 550, 860, 380, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(550, 550, 730, 550, 860, 380, GetColor(255, 255, 255), TRUE);
//	}
//
//	return i;
//}
//
////§ŒÀŠÔ‚Ì‰~‚ÌƒOƒ‰ƒt‚ÌXV
//void TimeLimitCircleUpdate(float time)
//{
//	//360ƒtƒŒ[ƒ€‚Åˆêü‚·‚é‚æ‚¤‚ÉŠp“x“‚Ì’l‚ğ‰ÁZ
//	AnglePercent += 100.0 / time;
//
//	//100%‚ğ’´‚¦‚½‚ç0%‚É–ß‚·
//	if (AnglePercent >= 100.0)
//	{
//		AnglePercent = 0.0;
//	}
//}

void TimeLimitCircle::TimeLimitCircleInit(void)
{
	//‰æ‘œ‚Ì“Ç‚İ‚İ
	timelimit_circle_image = LoadGraph("Resource/Images/simple_frame_01_circle_red.png");

	button_images[0] = LoadGraph("Resource/Images/xbox_button_color_a.png");
	button_images[1] = LoadGraph("Resource/Images/xbox_button_color_b.png");
	button_images[2] = LoadGraph("Resource/Images/xbox_button_color_x.png");
	button_images[3] = LoadGraph("Resource/Images/xbox_button_color_y.png");
}

void TimeLimitCircle::TimeLimitCircleDraw(void) const
{
	//‰~‚ÌƒOƒ‰ƒt‚Ì•`‰æ
	DrawCircleGauge(645, 350, 100.0, timelimit_circle_image, AnglePercent);
}

int TimeLimitCircle::BattleSquareDraw(int square, std::vector<int> button) const
{
	//}Œ`‚Ì’l“n‚µ
	int i = square;

	//OŠpŒ`‚Ì•`‰æ
	if (i == 3)
	{
		DrawTriangle(460, 475, 830, 475, 645, 125, GetColor(255, 255, 255), TRUE);
		DrawGraph(645, 125, button_images[button[0]], TRUE);
		DrawGraph(830, 475, button_images[button[1]], TRUE);
		DrawGraph(460, 475, button_images[button[2]], TRUE);
	}

	//lŠpŒ`‚Ì•`‰æ
	if (i == 4)
	{
		DrawTriangle(430, 350, 860, 350, 645, 130, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 350, 860, 350, 645, 560, GetColor(255, 255, 255), TRUE);
	}

	//ŒÜŠpŒ`‚Ì•`‰æ
	if (i == 5)
	{
		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 270, 525, 530, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(525, 530, 765, 530, 850, 270, GetColor(255, 255, 255), TRUE);
	}

	//˜ZŠpŒ`‚Ì•`‰æ
	if (i == 6)
	{
		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 270, 440, 430, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 430, 850, 430, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 430, 645, 570, 850, 430, GetColor(255, 255, 255), TRUE);
	}

	//µŠpŒ`‚Ì•`‰æ
	if (i == 7)
	{
		DrawTriangle(460, 230, 645, 130, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(460, 230, 430, 380, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 380, 860, 380, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 380, 550, 550, 860, 380, GetColor(255, 255, 255), TRUE);
		DrawTriangle(550, 550, 730, 550, 860, 380, GetColor(255, 255, 255), TRUE);
	}

	return i;
}

void TimeLimitCircle::TimeLimitCircleUpdate(float time)
{
	//360ƒtƒŒ[ƒ€‚Åˆêü‚·‚é‚æ‚¤‚ÉŠp“x“‚Ì’l‚ğ‰ÁZ
	AnglePercent += 100.0 / time;

	//100%‚ğ’´‚¦‚½‚ç0%‚É–ß‚·
	if (AnglePercent >= 100.0)
	{
		AnglePercent = 0.0;
	}
}
