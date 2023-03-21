#pragma once
#include<cstdio>
#include<string>
#include<deque>
#include<DxLib.h>
#include"SE.h"
using namespace std;

class CG {
public:
	SE cgse;
	bool finish = false;
	int i, j, check_story = 1, check_sinario = 0;
	static int CG_talkbox,
				CG_one, // = DrawGraph("Graphics\\img_CG_one");
				CG_two,	// = DrawGraph("Graphics\\img_CG_two");
				CG_three, // = DrawGraph("Graphics\\img_CG_three");
				CG_four, // = DrawGraph("Graphics\\img_CG_four");
				SCG_ainsel,// = DrawGraph("Graphics\\img_SCG_ainsel");
				SCG_lime;// = DrawGraph("Graphics\\img_SCG_lime");
	std::deque<int> number_char_start,
					number_char_3boss,
					number_char_3clear,
					number_char_extrastart,
					number_char_extraboss,
					number_char_extraclear;
	std::deque<string> sin_start,
					sin_3boss,
					sin_3clear,
					sin_extrastart,
					sin_extraboss,
					sin_extraclear;
	FILE *start, *boss, *clear, *extrastart, *extraboss, *extraclear;
	unsigned int white = GetColor(255, 255, 255);
	int normal20 = CreateFontToHandle(NULL, 20, 3, -1), 
		bold20 = CreateFontToHandle(NULL, 20, 4, -1),
		numsave_char;
	char save_sinario[500];
	void SinarioRead();
	void CGName(int charnum);
	void StandName(int charnum);
	bool SinarioStart();
	bool SinarioBoss();
	bool SinarioClear();
	bool SinarioExtraStart();
	bool SinarioExtraBoss();
	bool SinarioExtraClear();
	bool SinarioProcess(int sinnum, bool check);
	void StartDraw();
	void BossDraw();
	void ClearDraw();
	void ExtraStartDraw();
	void ExtraBossDraw();
	void ExtraClearDraw();
	void SinarioDraw(int sinnum);
};
