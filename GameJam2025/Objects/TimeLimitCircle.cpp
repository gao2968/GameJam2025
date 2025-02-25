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

//í“¬‰‰o‚Ì‰Šú‰»
void TimeLimitCircle::TimeLimitCircleInit(void)
{
	//‰æ‘œ‚Ì“Ç‚İ‚İ
	timelimit_circle_image = LoadGraph("Resource/Images/simple_frame_01_circle_red.png");
	cursor_aura = LoadGraph("Resource/Images/command_aura.png");

	button_images[0] = LoadGraph("Resource/Images/xbox_button_color_a.png");
	button_images[1] = LoadGraph("Resource/Images/xbox_button_color_b.png");
	button_images[2] = LoadGraph("Resource/Images/xbox_button_color_x.png");
	button_images[3] = LoadGraph("Resource/Images/xbox_button_color_y.png");

	button_images_outline[0] = LoadGraph("Resource/Images/xbox_button_color_a_outline.png");
	button_images_outline[1] = LoadGraph("Resource/Images/xbox_button_color_b_outline.png");
	button_images_outline[2] = LoadGraph("Resource/Images/xbox_button_color_x_outline.png");
	button_images_outline[3] = LoadGraph("Resource/Images/xbox_button_color_y_outline.png");
}

//§ŒÀŠÔ‚Ì‰~Œ^ƒQ[ƒW‚Ì•`‰æ
void TimeLimitCircle::TimeLimitCircleDraw(void) const
{
	//‰~‚ÌƒOƒ‰ƒt‚Ì•`‰æ
	DrawCircleGauge(645, 350, 100.0, timelimit_circle_image, AnglePercent);
}

//í“¬‚ÌƒRƒ}ƒ“ƒh‰æ–Ê‚Ì•`‰æ
int TimeLimitCircle::BattleSquareDraw(int square, std::vector<int> button, int num) const
{
	//}Œ`‚Ì’l“n‚µ
	int i = square;
	num += 1;

	int SlideX = 0;
	int SlideY = 0;

	//OŠpŒ`‚Ì•`‰æ
	if (i == 3)
	{
		//}Œ`‚Ì•`‰æ
		DrawTriangle(460, 475, 830, 475, 645, 125, GetColor(255, 255, 255), TRUE);

		//ƒ{ƒ^ƒ“‚Ì•`‰æ
		if (num == 3) {
			DrawGraph(440, 370, button_images[button[0]], TRUE);
			DrawGraph(720, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 125, button_images[button[2]], TRUE);

			if (miss_flg)
			{
				SlideX = GetRand(6) - 3;
				SlideY = GetRand(6) - 3;	

				DrawGraph(580 + SlideX, 125 + SlideY, cursor_aura, TRUE);

			}
			else
			{
				DrawGraph(580, 125, cursor_aura, TRUE);
			}
		}
		else if (num == 2)
		{
			DrawGraph(440, 370, button_images[button[0]], TRUE);
			DrawGraph(720, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 125, button_images_outline[button[2]], TRUE);

			DrawGraph(720, 370, cursor_aura, TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(440, 370, button_images[button[0]], TRUE);
			DrawGraph(720, 370, button_images_outline[button[1]], TRUE);
			DrawGraph(580, 125, button_images_outline[button[2]], TRUE);

			DrawGraph(440, 370, cursor_aura, TRUE);
		}
		else
		{
			DrawGraph(440, 370, button_images_outline[button[0]], TRUE);
			DrawGraph(720, 370, button_images_outline[button[1]], TRUE);
			DrawGraph(580, 125, button_images_outline[button[2]], TRUE);
		}
	}

	//lŠpŒ`‚Ì•`‰æ
	if (i == 4)
	{
		//}Œ`‚Ì•`‰æ
		DrawTriangle(430, 350, 860, 350, 645, 130, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 350, 860, 350, 645, 560, GetColor(255, 255, 255), TRUE);

		//ƒ{ƒ^ƒ“‚Ì•`‰æ
		if (num == 4) 
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images[button[1]], TRUE);
			DrawGraph(740, 280, button_images[button[2]], TRUE);
			DrawGraph(580, 120, button_images[button[3]], TRUE);

			DrawGraph(580, 120, cursor_aura, TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images[button[1]], TRUE);
			DrawGraph(740, 280, button_images[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);

			DrawGraph(740, 280, cursor_aura, TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images[button[1]], TRUE);
			DrawGraph(740, 280, button_images_outline[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);

			DrawGraph(580, 450, cursor_aura, TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images_outline[button[1]], TRUE);
			DrawGraph(740, 280, button_images_outline[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);

			DrawGraph(420, 280, cursor_aura, TRUE);
		}
		else
		{
			DrawGraph(420, 280, button_images_outline[button[0]], TRUE);
			DrawGraph(580, 450, button_images_outline[button[1]], TRUE);
			DrawGraph(740, 280, button_images_outline[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);
		}
	}

	//ŒÜŠpŒ`‚Ì•`‰æ
	if (i == 5)
	{
		//}Œ`‚Ì•`‰æ
		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 270, 525, 530, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(525, 530, 765, 530, 850, 270, GetColor(255, 255, 255), TRUE);

		//ƒ{ƒ^ƒ“‚Ì•`‰æ
		if (num == 5)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images[button[2]], TRUE);
			DrawGraph(740, 230, button_images[button[3]], TRUE);
			DrawGraph(580, 115, button_images[button[4]], TRUE);

			DrawGraph(580, 115, cursor_aura, TRUE);
		}
		else if (num == 4)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images[button[2]], TRUE);
			DrawGraph(740, 230, button_images[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);

			DrawGraph(740, 230, cursor_aura, TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);

			DrawGraph(690, 440, cursor_aura, TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);

			DrawGraph(480, 440, cursor_aura, TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images_outline[button[1]], TRUE);
			DrawGraph(690, 440, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);

			DrawGraph(420, 230, cursor_aura, TRUE);
		}
		else
		{
			DrawGraph(420, 230, button_images_outline[button[0]], TRUE);
			DrawGraph(480, 440, button_images_outline[button[1]], TRUE);
			DrawGraph(690, 440, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);
		}
	}

	//˜ZŠpŒ`‚Ì•`‰æ
	if (i == 6)
	{
		//}Œ`‚Ì•`‰æ
		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 270, 440, 430, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 430, 850, 430, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 430, 645, 570, 850, 430, GetColor(255, 255, 255), TRUE);

		//ƒ{ƒ^ƒ“‚Ì•`‰æ
		if (num == 6)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images[button[3]], TRUE);
			DrawGraph(740, 210, button_images[button[4]], TRUE);
			DrawGraph(580, 115, button_images[button[5]], TRUE);

			DrawGraph(580, 115, cursor_aura, TRUE);
		}
		else if (num == 5)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images[button[3]], TRUE);
			DrawGraph(740, 210, button_images[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);

			DrawGraph(740, 210, cursor_aura, TRUE);
		}
		else if (num == 4)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);

			DrawGraph(740, 370, cursor_aura, TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);

			DrawGraph(580, 460, cursor_aura, TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);

			DrawGraph(420, 370, cursor_aura, TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images_outline[button[1]], TRUE);
			DrawGraph(580, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);

			DrawGraph(420, 210, cursor_aura, TRUE);
		}
		else
		{
			DrawGraph(420, 210, button_images_outline[button[0]], TRUE);
			DrawGraph(420, 370, button_images_outline[button[1]], TRUE);
			DrawGraph(580, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);
		}
	}

	//µŠpŒ`‚Ì•`‰æ
	if (i == 7)
	{
		//}Œ`‚Ì•`‰æ
		DrawTriangle(460, 230, 645, 130, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(460, 230, 430, 380, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 380, 860, 380, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 380, 550, 550, 860, 380, GetColor(255, 255, 255), TRUE);
		DrawTriangle(550, 550, 730, 550, 860, 380, GetColor(255, 255, 255), TRUE);

		//ƒ{ƒ^ƒ“‚Ì•`‰æ
		if (num == 7)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images[button[3]], TRUE);
			DrawGraph(760, 340, button_images[button[4]], TRUE);
			DrawGraph(740, 200, button_images[button[5]], TRUE);
			DrawGraph(580, 115, button_images[button[6]], TRUE);

			DrawGraph(580, 115, cursor_aura, TRUE);
		}
		else if (num == 6)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images[button[3]], TRUE);
			DrawGraph(760, 340, button_images[button[4]], TRUE);
			DrawGraph(740, 200, button_images[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(740, 200, cursor_aura, TRUE);
		}
		else if (num == 5)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images[button[3]], TRUE);
			DrawGraph(760, 340, button_images[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(760, 340, cursor_aura, TRUE);
		}
		else if (num == 4)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images[button[3]], TRUE);
			DrawGraph(760, 340, button_images_outline[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(680, 460, cursor_aura, TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images_outline[button[3]], TRUE);
			DrawGraph(760, 340, button_images_outline[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(500, 460, cursor_aura, TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(680, 460, button_images_outline[button[3]], TRUE);
			DrawGraph(760, 340, button_images_outline[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(400, 340, cursor_aura, TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images_outline[button[1]], TRUE);
			DrawGraph(500, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(680, 460, button_images_outline[button[3]], TRUE);
			DrawGraph(760, 340, button_images_outline[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);

			DrawGraph(420, 200, cursor_aura, TRUE);
		}
		else
		{
			DrawGraph(420, 200, button_images_outline[button[0]], TRUE);
			DrawGraph(400, 340, button_images_outline[button[1]], TRUE);
			DrawGraph(500, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(680, 460, button_images_outline[button[3]], TRUE);
			DrawGraph(760, 340, button_images_outline[button[4]], TRUE);
			DrawGraph(740, 200, button_images_outline[button[5]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[6]], TRUE);
		}
	}

	return i;
}

//§ŒÀŠÔ‚ÌXV
void TimeLimitCircle::TimeLimitCircleUpdate(float time, bool miss)
{
	miss_flg = miss;

	//360ƒtƒŒ[ƒ€‚Åˆêü‚·‚é‚æ‚¤‚ÉŠp“x“‚Ì’l‚ğ‰ÁZ
	AnglePercent += 100.0 / time;

	//100%‚ğ’´‚¦‚½‚ç0%‚É–ß‚·
	if (AnglePercent >= 100.0)
	{
		AnglePercent = 0.0;
	}
}
