#define _CRT_SECURE_NO_WARNINGS
#include "CG.h"


void CG::SinarioRead() {
	start = fopen("Setfile\\Story_Start.txt", "r");
	while (!(feof(start))) {
		fscanf(start, "%d, %s\n", &numsave_char, save_sinario);
		number_char_start.push_back(numsave_char);
		sin_start.push_back(save_sinario);
	}
	fclose(start);
	boss = fopen("Setfile\\Story_3boss_Before.txt", "r");
	while (!(feof(boss))) {
		fscanf(boss, "%d, %s\n", &numsave_char, save_sinario);
		number_char_3boss.push_back(numsave_char);
		sin_3boss.push_back(save_sinario);
	}
	fclose(boss);
	clear = fopen("Setfile\\Story_3boss_After.txt", "r");
	while (!(feof(clear))) {
		fscanf(clear, "%d, %s\n", &numsave_char, save_sinario);
		number_char_3clear.push_back(numsave_char);
		sin_3clear.push_back(save_sinario);
	}
	fclose(clear);
	extrastart = fopen("Setfile\\Story_Extra_Start.txt", "r");
	while (!(feof(extrastart))) {
		fscanf(extrastart, "%d, %s\n", &numsave_char, save_sinario);
		number_char_extrastart.push_back(numsave_char);
		sin_extrastart.push_back(save_sinario);
	}
	fclose(extrastart);
	extraboss = fopen("Setfile\\Story_Extraboss_Before.txt", "r");
	while (!(feof(extraboss))) {
		fscanf(extraboss, "%d, %s\n", &numsave_char, save_sinario);
		number_char_extraboss.push_back(numsave_char);
		sin_extraboss.push_back(save_sinario);
	}
	fclose(extraboss);
	extraclear = fopen("Setfile\\Story_Extraboss_After.txt", "r");
	while (!(feof(extraclear))) {
		fscanf(extraclear, "%d, %s\n", &numsave_char, save_sinario);
		number_char_extraclear.push_back(numsave_char);
		sin_extraclear.push_back(save_sinario);
	}
	fclose(extraclear);
}
void CG::CGName(int charnum) {
	if (charnum == 0)DrawStringToHandle(130, 465, "? ? ? ?", white, normal20);
	if (charnum == 1)DrawStringToHandle(130, 465, "�d��", white, normal20);
	if (charnum == 2)DrawStringToHandle(130, 465, "", white, normal20);
	if (charnum == 3)DrawStringToHandle(130, 465, "���N", white, normal20);
	if (charnum == 4)DrawStringToHandle(130, 465, "���ꂳ��", white, normal20);
	if (charnum == 5)DrawStringToHandle(130, 465, "���C��", white, normal20);
}
void CG::StandName(int charnum) {
	if (charnum == 0)DrawStringToHandle(30, 465, "? ? ? ?", white, normal20);
	if (charnum == 1)DrawStringToHandle(30, 460, "�d��", white, normal20);
	if (charnum == 2)DrawStringToHandle(30, 465, "", white, normal20);
	if (charnum == 3)DrawStringToHandle(30, 465, "���N", white, normal20);
	if (charnum == 4)DrawStringToHandle(30, 465, "���ꂳ��", white, normal20);
	if (charnum == 5)DrawStringToHandle(30, 465, "���C��", white, normal20);
}
bool CG::SinarioStart() {
	if (check_sinario == sin_start.size() - 1) {
		check_sinario = 0;
		finish = true;
	}
	else {
		finish = false;
		check_sinario++;
	}
	return finish;
}
bool CG::SinarioBoss() {
	if (check_sinario == sin_3boss.size() - 1) {
		check_sinario = 0;
		finish = true;
	}
	else {
		check_sinario++;
		finish = false;
	}
	return finish;
}
bool CG::SinarioClear() {
	if (check_sinario == sin_3clear.size() - 1) {
		check_sinario = 0;
		finish = true;
	}
	else {
		check_sinario++;
		finish = false;
	}
	return finish;
}
bool CG::SinarioExtraStart() {
	if (check_sinario == sin_extrastart.size() - 1) {
		check_sinario = 0;
		finish = true;
	}
	else {
		check_sinario++;
		finish = false;
	}
	return finish;
}
bool CG::SinarioExtraBoss() {
	if (check_sinario == sin_extraboss.size() - 1) {
		check_sinario = 0;
		finish = true;
	}
	else {
		check_sinario++;
		finish = false;
	}
	return finish;
}
bool CG::SinarioExtraClear() {
	if (check_sinario == sin_extraclear.size() - 1) {
		check_sinario = 0;
		finish = true;
	}
	else {
		check_sinario++;
		finish = false;
	}
	return finish;
}
bool CG::SinarioProcess(int sinnum, bool check) {
	if (check) {
		switch (sinnum)
		{
		case 1:
			return SinarioStart();
			break;
		case 2:
			return SinarioBoss();
			break;
		case 3:
			return SinarioClear();
			break;
		case 4:
			return SinarioExtraStart();
			break;
		case 5:
			return SinarioExtraBoss();
			break;
		case 6:
			return SinarioExtraClear();
			break;
		}
	}
}
void CG::StartDraw() {
	if (check_sinario && check_sinario < 10)DrawGraph(0, 0, CG_one, TRUE);
	else if (check_sinario >= 10)DrawGraph(0, 0, CG_two, TRUE);
	DrawGraph(100, 450, CG_talkbox, TRUE);
	CGName(number_char_start[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(150, 495, "����́A���閼���Ȃ��d���́A��������Ȃ�����B", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(150, 495, "�u�c�c���`��A�K�x�ɍ����Ă�l�A�������������", white, normal20);
		DrawStringToHandle(170, 525, "���Ȃ��c�c�v", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(150, 495, "�u��ʎ��́A�����߁A���E�c�c���������͎̂R�X����", white, normal20);
		DrawStringToHandle(170, 525, "�ǁA���̗͂��ᖳ���Ȃ��̂΂���c�c�v", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(150, 495, "�u���߂āA���́w�P�ǉ��J�[�r���x���𗧂Ă�΂Ȃ�", white, normal20);
		DrawStringToHandle(170, 525, "�c�c�v", white, normal20);
	}
	else if (check_sinario == 4) {
		DrawStringToHandle(150, 495, "�������悤�B�w�P�ǉ��J�[�r���x�Ƃ́A������������", white, normal20);
		DrawStringToHandle(150, 525, "�𖳗͉��E���Q�Ȃ��̂ɕϖe������A���@�̏��e�ł�", white, normal20);
		DrawStringToHandle(150, 555, "��", white, normal20);
	}
	else if (check_sinario == 5) {
		DrawStringToHandle(150, 495, "�������A�w�P�ǉ��J�[�r���x���甭�˂�����e��e", white, normal20);
		DrawStringToHandle(150, 525, "�͈З͂��������B����Ɍ��ʂ������ɂ́A��������", white, normal20);
		DrawStringToHandle(150, 555, "�đ�����K�v������", white, normal20);
	}
	else if (check_sinario == 6) {
		DrawStringToHandle(150, 495, "���Ȃ݂ɁA�A�˂͉\", white, normal20);
	}
	else if (check_sinario == 7) {
		DrawStringToHandle(150, 495, "�u�͂��c�c�𗧂������Ȃ��A�ق�Ɓv", white, normal20);
	}
	else if (check_sinario == 8) {
		DrawStringToHandle(150, 495, "�u���[��c�c���A�����[��c�c�v", white, normal20);
	}
	else if (check_sinario == 9) {
		DrawStringToHandle(150, 495, "�u��H�@���̐����낤�H�@�Ђǂ��ꂵ�����c�c�v", white, normal20);
	}
	else if (check_sinario == 10) {
		DrawStringToHandle(150, 495, "�u���[��A���[��c�c�������c�c���[��v", white, normal20);
	}
	else if (check_sinario == 11) {
		DrawStringToHandle(150, 495, "�u�����I�@���̎q���I�v", white, normal20);
	}
	else if (check_sinario == 12) {
		DrawStringToHandle(150, 495, "�u�Ȃ񂾂낤�c�c���������ꂵ�����c�c�v", white, normal20);
	}
	else if (check_sinario == 13) {
		DrawStringToHandle(150, 495, "�u�ق�A�����B�����䂾��v", white, normal20);
	}
	else if (check_sinario == 14) {
		DrawStringToHandle(150, 495, "�u���A�����c�c��B�i������������鉹�j���ق�����", white, normal20);
		DrawStringToHandle(170, 525, "���I�v", white, normal20);
	}
	else if (check_sinario == 15) {
		DrawStringToHandle(150, 495, "�u���v�I�H�@�c�c�܂��H�ׂ��Ȃ��񂾂ˁB�����O", white, normal20);
		DrawStringToHandle(170, 525, "�����o�̂Ɂc�c�v", white, normal20);
	}
	else if (check_sinario == 16) {
		DrawStringToHandle(150, 495, "�u�O�����I�H�@�c�c���킢�����c�c�v", white, normal20);
	}
	else if (check_sinario == 17) {
		DrawStringToHandle(150, 495, "�u�c�c�������I�v", white, normal20);
	}
	else if (check_sinario == 18) {
		DrawStringToHandle(150, 495, "�u���́w�P�ǉ��J�[�r���x�Ȃ�A���̎q�̕a�C������", white, normal20);
		DrawStringToHandle(170, 525, "�邩������Ȃ��c�c", white, normal20);
		DrawStringToHandle(170, 555, "���ʋۂ��A�P�ʋۂɕς��邱�ƂŁI�I�v", white, normal20);
	}
	else if (check_sinario == 19) {
		DrawStringToHandle(150, 495, "�u����ŁA�������l����������c�c�v", white, normal20);
	}
	else if (check_sinario == 20) {
		DrawStringToHandle(150, 495, "�u�����ƌ��܂�����c�c�P�͋}���b�I�I�v", white, normal20);
	}
}
void CG::BossDraw() {
	DrawGraph(440, 150, SCG_ainsel, TRUE);
	if (check_sinario > 2)DrawGraph(10, 150, SCG_lime, TRUE);
	DrawGraph(0, 450, CG_talkbox, TRUE);
	StandName(number_char_3boss[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(50, 495, "�u�悵�A�����A�����c�c���������ŁA�����Ɨǂ��Ȃ�", white, normal20);
		DrawStringToHandle(70, 525, "�͂��c�c�v", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(50, 495, "�u�����ǂ��Ȃ���āH�v", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(50, 495, "�u�ӂ��H�@�ȂɁc�c�H�v", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(50, 495, "�u���������u���Ă�񂾂��ǂ˂��A�����v", white, normal20);
	}
	else if (check_sinario == 4) {
		DrawStringToHandle(50, 495, "�u���A���Ȃ��́c�c�b�I�H�v", white, normal20);
	}
	else if (check_sinario == 5) {
		DrawStringToHandle(50, 495, "�u�������H�@�������͂ˁc�c", white, normal20);
	}
	else if (check_sinario == 6) {
		DrawStringToHandle(50, 495, "�E�C���X��ˑR�ψق����ėl�X�ȕa���ۂ�n�����Ă�", white, normal20);
		DrawStringToHandle(70, 525, "��A�a���E�̈̑�Ȃ閂���ɂ��đ�12�㏗��A���C��", white, normal20);
		DrawStringToHandle(70, 555, "�E���U���r�E�E���K���X����I�I�v", white, normal20);
	}
	else if (check_sinario == 7) {
		DrawStringToHandle(50, 495, "�u�c�c�́H�H�H�v", white, normal20);
	}
	else if (check_sinario == 8) {
		DrawStringToHandle(50, 495, "�u�܁A�܂��c�c�Ȍ��Ɍ����΁A���񂽂��|���Ă�E�C", white, normal20);
		DrawStringToHandle(70, 525, "���X�����̐e�ʂ���v", white, normal20);
	}
	else if (check_sinario == 9) {
		DrawStringToHandle(50, 495, "�u���A�Ȃ�قǂ��c�c�c�c���Ă��Ƃ́I�H�v", white, normal20);
	}
	else if (check_sinario == 10) {
		DrawStringToHandle(50, 495, "�u�����B�悭���������̉����q���������S�~�ɕς�", white, normal20);
		DrawStringToHandle(70, 525, "�Ă��ꂽ�ˁI�I�v", white, normal20);
	}
	else if (check_sinario == 11) {
		DrawStringToHandle(50, 495, "�u����Ȃɏ������q�Ɋ���������ق��������ł���I�v", white, normal20);
	}
	else if (check_sinario == 12) {
		DrawStringToHandle(50, 495, "�u����Ȃׂ��׌����Ă�]�T�͂Ȃ��񂾂�i���j�I�v", white, normal20);
	}
	else if (check_sinario == 13) {
		DrawStringToHandle(50, 495, "�i�Ȃ񂩑�ς����c�c�j", white, normal20);
	}
	else if (check_sinario == 14) {
		DrawStringToHandle(50, 495, "�u�Ƃɂ����I�@����ȏ�A�q����������点�͂��Ȃ�", white, normal20);
		DrawStringToHandle(70, 525, "�I�@���񂽂ɂ͂����ŏ����Ă��炤�I�I�v", white, normal20);
	}
}
void CG::ClearDraw() {
	DrawGraph(440, 150, SCG_ainsel, TRUE);
	if (check_sinario < 9)DrawGraph(10, 150, SCG_lime, TRUE);
	DrawGraph(0, 450, CG_talkbox, TRUE);
	StandName(number_char_3clear[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(50, 495, "�u���A�����c�c�ǂ����āA���������������Ƃ��Ɂc�c", white, normal20);
		DrawStringToHandle(70, 525, "�v", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(50, 495, "�u���͏�������Ȃ��I�@����ł����l���Ă�I�v", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(50, 495, "�u�ǂ��ł�������c�c�v", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(50, 495, "�u�悭�Ȃ��I�v", white, normal20);
	}
	else if (check_sinario == 4) {
		DrawStringToHandle(50, 495, "�u�c�c�Ƃɂ����c�c����ŏ���������Ȃ��ԈႢ", white, normal20);
		DrawStringToHandle(70, 525, "����c�c�������͂��̒��x�ł͖łтȂ��I�@�����āA", white, normal20);
		DrawStringToHandle(70, 555, "�������̕v�����݂���I�I�v", white, normal20);
	}
	else if (check_sinario == 5) {
		DrawStringToHandle(50, 495, "�u���΂���A�����҂ł������c�c�v", white, normal20);
	}
	else if (check_sinario == 6) {
		DrawStringToHandle(50, 495, "�u���΂��񂶂�Ȃ����c�c�Ƃɂ����I�@���񂽂̖ړI", white, normal20);
		DrawStringToHandle(70, 525, "�͂܂��ʂ�����Ă��Ȃ��I�@���ꂩ���͂����Ƌ���", white, normal20);
		DrawStringToHandle(70, 555, "�Ȑ킢�ɂȂ邾�낤�I�v", white, normal20);
	}
	else if (check_sinario == 7) {
		DrawStringToHandle(50, 495, "����ł�������C������Ȃ�c�c�v", white, normal20);
	}
	else if (check_sinario == 8) {
		DrawStringToHandle(50, 495, "�u�{�C�̂������������A����ɂȂ��Ă�낤�v", white, normal20);
	}
	else if (check_sinario == 9) {
		DrawStringToHandle(50, 495, "", white, normal20);
	}
	else if (check_sinario == 10) {
		DrawStringToHandle(50, 495, "�u�c�c�܂��A���Ȃ��Ⴂ���Ȃ��̂��c�c�v", white, normal20);
	}
	else if (check_sinario == 11) {
		DrawStringToHandle(50, 495, "�u�c�c�v", white, normal20);
	}
	else if (check_sinario == 12) {
		DrawStringToHandle(50, 495, "�u�ł��c�c���Ȃ���I�I�@���̎q�̂��߂Ɂc�c�I�v", white, normal20);
	}
}
void CG::ExtraStartDraw() {
	if (check_sinario)DrawGraph(330, 100, SCG_ainsel, TRUE);
	DrawGraph(100, 450, CG_talkbox, TRUE);
	CGName(number_char_extrastart[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(150, 495, "����ȍ~�A���N�̑̂����X�܂ŉ�������̂́A�d����", white, normal20);
		DrawStringToHandle(150, 525, "�G�̖{�̂������o�����Ƃ͏o���Ȃ�����", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(150, 495, "�u�͂��c�c��ꂽ�悧�c�c�B�ł��A���ƒ��ׂĂȂ���", white, normal20);
		DrawStringToHandle(170, 525, "�͂��������c�c�v", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(150, 495, "�u���̐�ɂ����ƁA���̂��΂��񂽂�������͂��I�I", white, normal20);
		DrawStringToHandle(170, 525, "�v", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(150, 495, "�u�i������c�c�j�s�����I�v", white, normal20);
	}
}
void CG::ExtraBossDraw() {
	DrawGraph(440, 150, SCG_ainsel, TRUE);
	DrawGraph(10, 150, SCG_lime, TRUE);
	DrawGraph(0, 450, CG_talkbox, TRUE);
	StandName(number_char_extraboss[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(50, 495, "�u�悵�I�@���΂��񔭌��I�v", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(50, 495, "�u���������炨�΂���A���΂���Ɓc�c�܂�21����", white, normal20);
		DrawStringToHandle(70, 525, "���I�v", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(50, 495, "�c�c", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(50, 495, "�u�ق�Ȃ��b�I�I�v", white, normal20);
	}
	else if (check_sinario == 4) {
		DrawStringToHandle(50, 495, "�u�����c�c�܂������B���ꂸ�����֗������Ƃ͖J��", white, normal20);
		DrawStringToHandle(70, 525, "�Ă�낤�A�����B�����c�c�{�C�̂������ƕv�́A�N", white, normal20);
		DrawStringToHandle(70, 555, "�ɂ��肪���Ȃ����c�c����ł����̂��H�v", white, normal20);
	}
	else if (check_sinario == 5) {
		DrawStringToHandle(50, 495, "�u�������I�v", white, normal20);
	}
	else if (check_sinario == 6) {
		DrawStringToHandle(50, 495, "�u�Ȃ�΁c�c���������n�߂悤�B��͂ȏ������A�ǂ�", white, normal20);
		DrawStringToHandle(70, 525, "�܂ōR����̂��c�c�������Ȃ��b�I�I�v", white, normal20);
	}
}
void CG::ExtraClearDraw() {
	if (check_sinario <= 9)DrawGraph(0, 0, CG_three, TRUE);
	else if (check_sinario <= 20)DrawGraph(0, 0, CG_four, TRUE);
	DrawGraph(100, 450, CG_talkbox, TRUE);
	CGName(number_char_extraclear[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(150, 495, "�u�n���ȁc�c��x�����łȂ��A��x���c�c���̂�����", white, normal20);
		DrawStringToHandle(170, 525, "���A���C���E���U���r�E�E���K���X���b�I�H�v", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(150, 495, "�u���΂���c�c�����A��߂ɂ��悤��c�c����ȏ��", white, normal20);
		DrawStringToHandle(170, 525, "���Ă��A�����N����Ȃ�����c�c�v", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(150, 495, "�u�����c�c�����c�c�ӂӂ��c�c�ӂӂ��n�b�n�n�n����", white, normal20);
		DrawStringToHandle(170, 525, "�I�I�v", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(150, 495, "�u���O�͉����킩���Ă��Ȃ��I�@���̂�������|����", white, normal20);
		DrawStringToHandle(170, 525, "�Ƃ���ŁA�w�����������x�ɍ��܂ꂽ�^���́A�ς���", white, normal20);
		DrawStringToHandle(150, 555, "��Ȃ��I�v", white, normal20);
	}
	else if (check_sinario == 4) {
		DrawStringToHandle(150, 495, "�u����܂ł̂��O�̍s���������Ă��Ă��A�����N����", white, normal20);
		DrawStringToHandle(170, 525, "�Ȃ��񂾂�I�@�ς��Ȃ��񂾂�b�I�v", white, normal20);
	}
	else if (check_sinario == 5) {
		DrawStringToHandle(150, 495, "�u�c�c�H�v", white, normal20);
	}
	else if (check_sinario == 6) {
		DrawStringToHandle(150, 495, "�u�ǂ���ɂ���A�����I��肾�c�c�^������͓����", white, normal20);
		DrawStringToHandle(170, 525, "��Ȃ��c�c���������v���A���̎q�̖����Ȃ��b�b�b�I", white, normal20);
		DrawStringToHandle(170, 555, "�I�v", white, normal20);
	}
	else if (check_sinario == 7) {
		if (!cgse.check_once) {
			cgse.PlaySE(10);
			cgse.check_once = true;
		}
		DrawStringToHandle(150, 495, "", white, normal20);
	}
	else if (check_sinario == 8) {
		DrawStringToHandle(150, 495, "�u����ȁc�c������������Ȃ��A���̎q�����A��ɂ�", white, normal20);
		DrawStringToHandle(170, 525, "�悤�Ȃ�āc�c�v", white, normal20);
	}
	else if (check_sinario == 9) {
		DrawStringToHandle(150, 495, "�u����������������c�c����Ȃ̎����Ȃ���c�c", white, normal20);
		DrawStringToHandle(170, 525, "���̂܂܂����΁c�c�����Ȃ�����c�c�v", white, normal20);
	}
	else if (check_sinario == 10) {
		DrawStringToHandle(150, 495, "�u�@��@�΁@�Ɂ@���@���@��@�I�@�I�@�v", white, bold20);
	}
	else if (check_sinario == 11) {
		DrawStringToHandle(150, 495, "�u�c�c�ӂ����c�c�ӂ��c�c�v", white, normal20);
	}
	else if (check_sinario == 12) {
		DrawStringToHandle(150, 495, "�u���Ƃ����������Ă�����ˁB�ꎞ�͂ǂ��Ȃ邱�Ƃ�", white, normal20);
		DrawStringToHandle(170, 525, "�Ǝv�������ǁc�c�v", white, normal20);
	}
	else if (check_sinario == 13) {
		DrawStringToHandle(150, 495, "�u�c�c�������c�c����H�v", white, normal20);
	}
	else if (check_sinario == 14) {
		DrawStringToHandle(150, 495, "�u�����I�H�@���v�Ȃ̂����I�H�v", white, normal20);
	}
	else if (check_sinario == 15) {
		DrawStringToHandle(150, 495, "�u����c�c�d�����񂪎���Ă��ꂽ����A�ւ����v", white, normal20);
	}
	else if (check_sinario == 16) {
		DrawStringToHandle(150, 495, "�u�c�c�H�v", white, normal20);
	}
	else if (check_sinario == 17) {
		DrawStringToHandle(150, 495, "�u���̂ˁA���ꂳ��c�c�d������A�l�̑̂���������", white, normal20);
		DrawStringToHandle(170, 525, "�ɁA�����̑̂��]���ɂ��Ă��ꂽ�񂾂�c�c�l�̑̂�", white, normal20);
		DrawStringToHandle(170, 555, "�ꕔ�ɂȂ��Ă��ꂽ�񂾂�c�c�v", white, normal20);
	}
	else if (check_sinario == 18) {
		DrawStringToHandle(150, 495, "�u�����c�c�v", white, normal20);
	}
	else if (check_sinario == 19) {
		DrawStringToHandle(150, 495, "�u�ǂ������c�c�{���Ɂc�c�v", white, normal20);
	}
	else if (check_sinario == 20) {
		DrawStringToHandle(150, 495, "�u���ꂳ��c�c�v", white, normal20);
	}
	else if (check_sinario == 21) {
		DrawStringToHandle(150, 495, "����́A���閼���Ȃ��d���́A��������Ȃ�����B", white, normal20);
	}
	else if (check_sinario == 22) {
		DrawStringToHandle(150, 495, "Ainsel�i�G�C���Z���j�F", white, normal20);
		DrawStringToHandle(200, 525, "�C���O�����h�̕����ŁA�u�������g�v���Ӗ�����", white, normal20);
	}
	else if (check_sinario == 23) {
		DrawStringToHandle(220, 525, "�\�\The�@End�\�\", white, normal20);
	}
}
void CG::SinarioDraw(int sinnum) {
	switch (sinnum)
	{
	case 1:
		CG::StartDraw();
		break;
	case 2:
		CG::BossDraw();
		break;
	case 3:
		CG::ClearDraw();
		break;
	case 4:
		CG::ExtraStartDraw();
		break;
	case 5:
		CG::ExtraBossDraw();
		break;
	case 6:
		CG::ExtraClearDraw();
		break;
	}
}