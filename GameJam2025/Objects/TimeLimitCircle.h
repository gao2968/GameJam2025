#pragma once
#include <vector>
class TimeLimitCircle
{
private:
	int timelimit_circle_image;
	double AnglePercent = 0.0;
	int button_images[4];
	int button_images_outline[4];
public:
	void TimeLimitCircleInit(void);
	void TimeLimitCircleDraw(void) const;
	int BattleSquareDraw(int square, std::vector<int> button, int num) const;
	void TimeLimitCircleUpdate(float time);
};

