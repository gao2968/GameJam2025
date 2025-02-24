#include "DxLib.h"
#include "TimeLimitCircle.h"

////ÉOÉçÅ[ÉoÉãïœêî
//int timelimit_circle_image;
//double AnglePercent = 0.0;
//
//
////êßå¿éûä‘ÇÃâ~ÇÃÉOÉâÉtÇÃèâä˙âª
//void TimeLimitCircleInit(void)
//{
//	//âÊëúÇÃì«Ç›çûÇ›
//	timelimit_circle_image = LoadGraph("Resource/simple_frame_01_circle_red.png");
//}
//
//
////êßå¿éûä‘ÇÃâ~ÇÃÉOÉâÉtÇÃï`âÊ
//void TimeLimitCircleDraw(void)
//{
//	//â~ÇÃÉOÉâÉtÇÃï`âÊ
//	DrawCircleGauge(645, 350, 100.0, timelimit_circle_image, AnglePercent);
//}
//
////êÌì¨éûÇÃÉRÉ}ÉìÉhì¸óÕÉGÉtÉFÉNÉgÇÃï`âÊ
//int BattleSquareDraw(int square)
//{
//	//ê}å`ÇÃílìnÇµ
//	int i = square;
//
//	//éOäpå`ÇÃï`âÊ
//	if (i == 3)
//	{
//		DrawTriangle(460, 475, 830, 475, 645, 125, GetColor(255, 255, 255), TRUE);
//	}
//
//	//éläpå`ÇÃï`âÊ
//	if (i == 4)
//	{
//		DrawTriangle(430, 350, 860, 350, 645, 130, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(430, 350, 860, 350, 645, 560, GetColor(255, 255, 255), TRUE);
//	}
//
//	//å‹äpå`ÇÃï`âÊ
//	if (i == 5)
//	{
//		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 270, 525, 530, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(525, 530, 765, 530, 850, 270, GetColor(255, 255, 255), TRUE);
//	}
//
//	//òZäpå`ÇÃï`âÊ
//	if (i == 6)
//	{
//		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 270, 440, 430, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 430, 850, 430, 850, 270, GetColor(255, 255, 255), TRUE);
//		DrawTriangle(440, 430, 645, 570, 850, 430, GetColor(255, 255, 255), TRUE);
//	}
//
//	//éµäpå`ÇÃï`âÊ
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
////êßå¿éûä‘ÇÃâ~ÇÃÉOÉâÉtÇÃçXêV
//void TimeLimitCircleUpdate(float time)
//{
//	//360ÉtÉåÅ[ÉÄÇ≈àÍé¸Ç∑ÇÈÇÊÇ§Ç…äpìxÅìÇÃílÇâ¡éZ
//	AnglePercent += 100.0 / time;
//
//	//100%Çí¥Ç¶ÇΩÇÁ0%Ç…ñﬂÇ∑
//	if (AnglePercent >= 100.0)
//	{
//		AnglePercent = 0.0;
//	}
//}

void TimeLimitCircle::TimeLimitCircleInit(void)
{
	//âÊëúÇÃì«Ç›çûÇ›
	timelimit_circle_image = LoadGraph("Resource/Images/simple_frame_01_circle_red.png");

	button_images[0] = LoadGraph("Resource/Images/xbox_button_color_a.png");
	button_images[1] = LoadGraph("Resource/Images/xbox_button_color_b.png");
	button_images[2] = LoadGraph("Resource/Images/xbox_button_color_x.png");
	button_images[3] = LoadGraph("Resource/Images/xbox_button_color_y.png");

	button_images_outline[0] = LoadGraph("Resource/Images/xbox_button_color_a_outline.png");
	button_images_outline[1] = LoadGraph("Resource/Images/xbox_button_color_b_outline.png");
	button_images_outline[2] = LoadGraph("Resource/Images/xbox_button_color_x_outline.png");
	button_images_outline[3] = LoadGraph("Resource/Images/xbox_button_color_y_outline.png");
}

void TimeLimitCircle::TimeLimitCircleDraw(void) const
{
	//â~ÇÃÉOÉâÉtÇÃï`âÊ
	DrawCircleGauge(645, 350, 100.0, timelimit_circle_image, AnglePercent);
}

int TimeLimitCircle::BattleSquareDraw(int square, std::vector<int> button, int num) const
{
	//ê}å`ÇÃílìnÇµ
	int i = square;
	num += 1;

	//éOäpå`ÇÃï`âÊ
	if (i == 3)
	{
		//ê}å`ÇÃï`âÊ
		DrawTriangle(460, 475, 830, 475, 645, 125, GetColor(255, 255, 255), TRUE);

		//É{É^ÉìÇÃï`âÊ
		if (num == 3) {
			DrawGraph(440, 370, button_images[button[0]], TRUE);
			DrawGraph(720, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 125, button_images[button[2]], TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(440, 370, button_images[button[0]], TRUE);
			DrawGraph(720, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 125, button_images_outline[button[2]], TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(440, 370, button_images[button[0]], TRUE);
			DrawGraph(720, 370, button_images_outline[button[1]], TRUE);
			DrawGraph(580, 125, button_images_outline[button[2]], TRUE);
		}
	}

	//éläpå`ÇÃï`âÊ
	if (i == 4)
	{
		//ê}å`ÇÃï`âÊ
		DrawTriangle(430, 350, 860, 350, 645, 130, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 350, 860, 350, 645, 560, GetColor(255, 255, 255), TRUE);

		//É{É^ÉìÇÃï`âÊ
		if (num == 4) 
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images[button[1]], TRUE);
			DrawGraph(740, 280, button_images[button[2]], TRUE);
			DrawGraph(580, 120, button_images[button[3]], TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images[button[1]], TRUE);
			DrawGraph(740, 280, button_images[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images[button[1]], TRUE);
			DrawGraph(740, 280, button_images_outline[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 280, button_images[button[0]], TRUE);
			DrawGraph(580, 450, button_images_outline[button[1]], TRUE);
			DrawGraph(740, 280, button_images_outline[button[2]], TRUE);
			DrawGraph(580, 120, button_images_outline[button[3]], TRUE);
		}
	}

	//å‹äpå`ÇÃï`âÊ
	if (i == 5)
	{
		//ê}å`ÇÃï`âÊ
		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 270, 525, 530, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(525, 530, 765, 530, 850, 270, GetColor(255, 255, 255), TRUE);

		//É{É^ÉìÇÃï`âÊ
		if (num == 5)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images[button[2]], TRUE);
			DrawGraph(740, 230, button_images[button[3]], TRUE);
			DrawGraph(580, 115, button_images[button[4]], TRUE);
		}
		else if (num == 4)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images[button[2]], TRUE);
			DrawGraph(740, 230, button_images[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images[button[1]], TRUE);
			DrawGraph(690, 440, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 230, button_images[button[0]], TRUE);
			DrawGraph(480, 440, button_images_outline[button[1]], TRUE);
			DrawGraph(690, 440, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 230, button_images_outline[button[3]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[4]], TRUE);
		}
	}

	//òZäpå`ÇÃï`âÊ
	if (i == 6)
	{
		//ê}å`ÇÃï`âÊ
		DrawTriangle(440, 270, 645, 130, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 270, 440, 430, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 430, 850, 430, 850, 270, GetColor(255, 255, 255), TRUE);
		DrawTriangle(440, 430, 645, 570, 850, 430, GetColor(255, 255, 255), TRUE);

		//É{É^ÉìÇÃï`âÊ
		if (num == 6)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images[button[3]], TRUE);
			DrawGraph(740, 210, button_images[button[4]], TRUE);
			DrawGraph(580, 115, button_images[button[5]], TRUE);
		}
		else if (num == 5)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images[button[3]], TRUE);
			DrawGraph(740, 210, button_images[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);
		}
		else if (num == 4)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);
		}
		else if (num == 3)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);
		}
		else if (num == 2)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images[button[1]], TRUE);
			DrawGraph(580, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);
		}
		else if (num == 1)
		{
			DrawGraph(420, 210, button_images[button[0]], TRUE);
			DrawGraph(420, 370, button_images_outline[button[1]], TRUE);
			DrawGraph(580, 460, button_images_outline[button[2]], TRUE);
			DrawGraph(740, 370, button_images_outline[button[3]], TRUE);
			DrawGraph(740, 210, button_images_outline[button[4]], TRUE);
			DrawGraph(580, 115, button_images_outline[button[5]], TRUE);
		}
	}

	//éµäpå`ÇÃï`âÊ
	if (i == 7)
	{
		//ê}å`ÇÃï`âÊ
		DrawTriangle(460, 230, 645, 130, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(460, 230, 430, 380, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 380, 860, 380, 830, 230, GetColor(255, 255, 255), TRUE);
		DrawTriangle(430, 380, 550, 550, 860, 380, GetColor(255, 255, 255), TRUE);
		DrawTriangle(550, 550, 730, 550, 860, 380, GetColor(255, 255, 255), TRUE);

		//É{É^ÉìÇÃï`âÊ
		if (num == 7)
		{
			DrawGraph(420, 200, button_images[button[0]], TRUE);
			DrawGraph(400, 340, button_images[button[1]], TRUE);
			DrawGraph(500, 460, button_images[button[2]], TRUE);
			DrawGraph(680, 460, button_images[button[3]], TRUE);
			DrawGraph(760, 340, button_images[button[4]], TRUE);
			DrawGraph(740, 200, button_images[button[5]], TRUE);
			DrawGraph(580, 115, button_images[button[6]], TRUE);
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
		}
	}

	return i;
}

void TimeLimitCircle::TimeLimitCircleUpdate(float time)
{
	//360ÉtÉåÅ[ÉÄÇ≈àÍé¸Ç∑ÇÈÇÊÇ§Ç…äpìxÅìÇÃílÇâ¡éZ
	AnglePercent += 100.0 / time;

	//100%Çí¥Ç¶ÇΩÇÁ0%Ç…ñﬂÇ∑
	if (AnglePercent >= 100.0)
	{
		AnglePercent = 0.0;
	}
}
