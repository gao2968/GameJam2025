#include "DxLib.h"

//ƒOƒ[ƒoƒ‹•Ï”
int timelimit_circle_image;
double AnglePercent = 0.0;


//§ŒÀŽžŠÔ‚Ì‰~‚ÌƒOƒ‰ƒt‚Ì‰Šú‰»
void TimeLimitCircleInit(void)
{
	//‰æ‘œ‚Ì“Ç‚Ýž‚Ý
	timelimit_circle_image = LoadGraph("Resource/timelimit_circle.png");
}


//§ŒÀŽžŠÔ‚Ì‰~‚ÌƒOƒ‰ƒt‚Ì•`‰æ
void TimeLimitCircleDraw(void)
{
	//‰~‚ÌƒOƒ‰ƒt‚Ì•`‰æ
	DrawCircleGauge(300, 200, 100.0, timelimit_circle_image, AnglePercent);
}

//§ŒÀŽžŠÔ‚Ì‰~‚ÌƒOƒ‰ƒt‚ÌXV
void TimeLimitCircleUpdate(void)
{
	//360ƒtƒŒ[ƒ€‚ÅˆêŽü‚·‚é‚æ‚¤‚ÉŠp“x“‚Ì’l‚ð‰ÁŽZ
	AnglePercent += 100.0 / 360.0;

	//100%‚ð’´‚¦‚½‚ç0%‚É–ß‚·
	if (AnglePercent >= 100.0)
	{
		AnglePercent = 0.0;
	}
}