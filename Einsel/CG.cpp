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
	if (charnum == 1)DrawStringToHandle(130, 465, "妖精", white, normal20);
	if (charnum == 2)DrawStringToHandle(130, 465, "", white, normal20);
	if (charnum == 3)DrawStringToHandle(130, 465, "少年", white, normal20);
	if (charnum == 4)DrawStringToHandle(130, 465, "お母さん", white, normal20);
	if (charnum == 5)DrawStringToHandle(130, 465, "ライム", white, normal20);
}
void CG::StandName(int charnum) {
	if (charnum == 0)DrawStringToHandle(30, 465, "? ? ? ?", white, normal20);
	if (charnum == 1)DrawStringToHandle(30, 460, "妖精", white, normal20);
	if (charnum == 2)DrawStringToHandle(30, 465, "", white, normal20);
	if (charnum == 3)DrawStringToHandle(30, 465, "少年", white, normal20);
	if (charnum == 4)DrawStringToHandle(30, 465, "お母さん", white, normal20);
	if (charnum == 5)DrawStringToHandle(30, 465, "ライム", white, normal20);
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
		DrawStringToHandle(150, 495, "これは、ある名もない妖精の、語られもしない物語。", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(150, 495, "「……う～ん、適度に困ってる人、今日も見つからな", white, normal20);
		DrawStringToHandle(170, 525, "いなあ……」", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(150, 495, "「交通事故、いじめ、自殺……助けたいのは山々だけ", white, normal20);
		DrawStringToHandle(170, 525, "ど、私の力じゃ無理なものばかり……」", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(150, 495, "「せめて、この『善良化カービン』が役立てればなあ", white, normal20);
		DrawStringToHandle(170, 525, "……」", white, normal20);
	}
	else if (check_sinario == 4) {
		DrawStringToHandle(150, 495, "説明しよう。『善良化カービン』とは、当たったもの", white, normal20);
		DrawStringToHandle(150, 525, "を無力化・無害なものに変貌させる、魔法の小銃であ", white, normal20);
		DrawStringToHandle(150, 555, "る", white, normal20);
	}
	else if (check_sinario == 5) {
		DrawStringToHandle(150, 495, "ただし、『善良化カービン』から発射される一弾一弾", white, normal20);
		DrawStringToHandle(150, 525, "は威力が小さい。相手に効果が現れるには、何発も当", white, normal20);
		DrawStringToHandle(150, 555, "て続ける必要がある", white, normal20);
	}
	else if (check_sinario == 6) {
		DrawStringToHandle(150, 495, "ちなみに、連射は可能", white, normal20);
	}
	else if (check_sinario == 7) {
		DrawStringToHandle(150, 495, "「はぁ……役立たずだなあ、ほんと」", white, normal20);
	}
	else if (check_sinario == 8) {
		DrawStringToHandle(150, 495, "「うーん……う、うぅーん……」", white, normal20);
	}
	else if (check_sinario == 9) {
		DrawStringToHandle(150, 495, "「ん？　何の声だろう？　ひどく苦しそう……」", white, normal20);
	}
	else if (check_sinario == 10) {
		DrawStringToHandle(150, 495, "「うーん、うーん……うぉっ……うーん」", white, normal20);
	}
	else if (check_sinario == 11) {
		DrawStringToHandle(150, 495, "「あっ！　あの子だ！」", white, normal20);
	}
	else if (check_sinario == 12) {
		DrawStringToHandle(150, 495, "「なんだろう……すっごく苦しそう……」", white, normal20);
	}
	else if (check_sinario == 13) {
		DrawStringToHandle(150, 495, "「ほら、○○。おかゆだよ」", white, normal20);
	}
	else if (check_sinario == 14) {
		DrawStringToHandle(150, 495, "「う、ぅう……ん。（おかゆをすする音）げほっげほ", white, normal20);
		DrawStringToHandle(170, 525, "っ！」", white, normal20);
	}
	else if (check_sinario == 15) {
		DrawStringToHandle(150, 495, "「大丈夫！？　……まだ食べられないんだね。もう三", white, normal20);
		DrawStringToHandle(170, 525, "日も経つのに……」", white, normal20);
	}
	else if (check_sinario == 16) {
		DrawStringToHandle(150, 495, "「三日も！？　……かわいそう……」", white, normal20);
	}
	else if (check_sinario == 17) {
		DrawStringToHandle(150, 495, "「……そうだ！」", white, normal20);
	}
	else if (check_sinario == 18) {
		DrawStringToHandle(150, 495, "「私の『善良化カービン』なら、あの子の病気を治せ", white, normal20);
		DrawStringToHandle(170, 525, "るかもしれない……", white, normal20);
		DrawStringToHandle(170, 555, "悪玉菌を、善玉菌に変えることで！！」", white, normal20);
	}
	else if (check_sinario == 19) {
		DrawStringToHandle(150, 495, "「これで、私も他人を助けられる……」", white, normal20);
	}
	else if (check_sinario == 20) {
		DrawStringToHandle(150, 495, "「そうと決まったら……善は急げッ！！」", white, normal20);
	}
}
void CG::BossDraw() {
	DrawGraph(440, 150, SCG_ainsel, TRUE);
	if (check_sinario > 2)DrawGraph(10, 150, SCG_lime, TRUE);
	DrawGraph(0, 450, CG_talkbox, TRUE);
	StandName(number_char_3boss[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(50, 495, "「よし、順調、順調……もう少しで、きっと良くなる", white, normal20);
		DrawStringToHandle(70, 525, "はず……」", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(50, 495, "「何が良くなるって？」", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(50, 495, "「ふぇ？　なに……？」", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(50, 495, "「あたしが訊いてるんだけどねえ、小娘」", white, normal20);
	}
	else if (check_sinario == 4) {
		DrawStringToHandle(50, 495, "「あ、あなたは……ッ！？」", white, normal20);
	}
	else if (check_sinario == 5) {
		DrawStringToHandle(50, 495, "「あたし？　あたしはね……", white, normal20);
	}
	else if (check_sinario == 6) {
		DrawStringToHandle(50, 495, "ウイルスを突然変異させて様々な病原菌を創造してい", white, normal20);
		DrawStringToHandle(70, 525, "る、病魔界の偉大なる魔女にして第12代女帝、ライム", white, normal20);
		DrawStringToHandle(70, 555, "・ンザンビ・ウンガンスだよ！！」", white, normal20);
	}
	else if (check_sinario == 7) {
		DrawStringToHandle(50, 495, "「……は？？？」", white, normal20);
	}
	else if (check_sinario == 8) {
		DrawStringToHandle(50, 495, "「ま、まあ……簡潔に言えば、あんたが倒してるウイ", white, normal20);
		DrawStringToHandle(70, 525, "ルスたちの親玉だよ」", white, normal20);
	}
	else if (check_sinario == 9) {
		DrawStringToHandle(50, 495, "「あ、なるほどぉ…………ってことは！？」", white, normal20);
	}
	else if (check_sinario == 10) {
		DrawStringToHandle(50, 495, "「そう。よくもあたしの可愛い子供たちをゴミに変え", white, normal20);
		DrawStringToHandle(70, 525, "てくれたね！！」", white, normal20);
	}
	else if (check_sinario == 11) {
		DrawStringToHandle(50, 495, "「あんなに小さい子に感染させるほうが悪いでしょ！」", white, normal20);
	}
	else if (check_sinario == 12) {
		DrawStringToHandle(50, 495, "「そんなつべこべ言ってる余裕はないんだよ（泣）！」", white, normal20);
	}
	else if (check_sinario == 13) {
		DrawStringToHandle(50, 495, "（なんか大変そう……）", white, normal20);
	}
	else if (check_sinario == 14) {
		DrawStringToHandle(50, 495, "「とにかく！　これ以上、子供たちをやらせはしない", white, normal20);
		DrawStringToHandle(70, 525, "！　あんたにはここで消えてもらう！！」", white, normal20);
	}
}
void CG::ClearDraw() {
	DrawGraph(440, 150, SCG_ainsel, TRUE);
	if (check_sinario < 9)DrawGraph(10, 150, SCG_lime, TRUE);
	DrawGraph(0, 450, CG_talkbox, TRUE);
	StandName(number_char_3clear[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(50, 495, "「く、くそ……どうして、あたしが小娘ごときに……", white, normal20);
		DrawStringToHandle(70, 525, "」", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(50, 495, "「私は小娘じゃない！　これでも成人してる！」", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(50, 495, "「どうでもいいわ……」", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(50, 495, "「よくない！」", white, normal20);
	}
	else if (check_sinario == 4) {
		DrawStringToHandle(50, 495, "「……とにかく……これで勝ったつもりなら大間違い", white, normal20);
		DrawStringToHandle(70, 525, "だよ……あたしはこの程度では滅びない！　そして、", white, normal20);
		DrawStringToHandle(70, 555, "あたしの夫も健在だよ！！」", white, normal20);
	}
	else if (check_sinario == 5) {
		DrawStringToHandle(50, 495, "「おばさん、既婚者でしたか……」", white, normal20);
	}
	else if (check_sinario == 6) {
		DrawStringToHandle(50, 495, "「おばさんじゃないし……とにかく！　あんたの目的", white, normal20);
		DrawStringToHandle(70, 525, "はまだ果たされていない！　これから先はもっと凶悪", white, normal20);
		DrawStringToHandle(70, 555, "な戦いになるだろう！」", white, normal20);
	}
	else if (check_sinario == 7) {
		DrawStringToHandle(50, 495, "それでも続ける気があるなら……」", white, normal20);
	}
	else if (check_sinario == 8) {
		DrawStringToHandle(50, 495, "「本気のあたしたちが、相手になってやろう」", white, normal20);
	}
	else if (check_sinario == 9) {
		DrawStringToHandle(50, 495, "", white, normal20);
	}
	else if (check_sinario == 10) {
		DrawStringToHandle(50, 495, "「……まだ、戦わなきゃいけないのか……」", white, normal20);
	}
	else if (check_sinario == 11) {
		DrawStringToHandle(50, 495, "「……」", white, normal20);
	}
	else if (check_sinario == 12) {
		DrawStringToHandle(50, 495, "「でも……やらなきゃ！！　あの子のために……！」", white, normal20);
	}
}
void CG::ExtraStartDraw() {
	if (check_sinario)DrawGraph(330, 100, SCG_ainsel, TRUE);
	DrawGraph(100, 450, CG_talkbox, TRUE);
	CGName(number_char_extrastart[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(150, 495, "あれ以降、少年の体を隅々まで回ったものの、妖精は", white, normal20);
		DrawStringToHandle(150, 525, "敵の本体を見つけ出すことは出来なかった", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(150, 495, "「はぁ……疲れたよぉ……。でも、あと調べてないの", white, normal20);
		DrawStringToHandle(170, 525, "はここだけ……」", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(150, 495, "「この先にきっと、あのおばさんたちがいるはず！！", white, normal20);
		DrawStringToHandle(170, 525, "」", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(150, 495, "「（だから……）行こう！」", white, normal20);
	}
}
void CG::ExtraBossDraw() {
	DrawGraph(440, 150, SCG_ainsel, TRUE);
	DrawGraph(10, 150, SCG_lime, TRUE);
	DrawGraph(0, 450, CG_talkbox, TRUE);
	StandName(number_char_extraboss[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(50, 495, "「よし！　おばさん発見！」", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(50, 495, "「さっきからおばさん、おばさんと……まだ21じゃ", white, normal20);
		DrawStringToHandle(70, 525, "あ！」", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(50, 495, "……", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(50, 495, "「黙るなぁッ！！」", white, normal20);
	}
	else if (check_sinario == 4) {
		DrawStringToHandle(50, 495, "「くっ……まあいい。恐れずここへ来たことは褒め", white, normal20);
		DrawStringToHandle(70, 525, "てやろう、小娘。だが……本気のあたしと夫は、誰", white, normal20);
		DrawStringToHandle(70, 555, "にも手がつられないぞ……それでもやるのか？」", white, normal20);
	}
	else if (check_sinario == 5) {
		DrawStringToHandle(50, 495, "「もちろん！」", white, normal20);
	}
	else if (check_sinario == 6) {
		DrawStringToHandle(50, 495, "「ならば……さっそく始めよう。非力な小娘が、どこ", white, normal20);
		DrawStringToHandle(70, 525, "まで抗えるのか……見物だなあッ！！」", white, normal20);
	}
}
void CG::ExtraClearDraw() {
	if (check_sinario <= 9)DrawGraph(0, 0, CG_three, TRUE);
	else if (check_sinario <= 20)DrawGraph(0, 0, CG_four, TRUE);
	DrawGraph(100, 450, CG_talkbox, TRUE);
	CGName(number_char_extraclear[check_sinario]);
	if (check_sinario == 0) {
		DrawStringToHandle(150, 495, "「馬鹿な……一度だけでなく、二度も……このあたし", white, normal20);
		DrawStringToHandle(170, 525, "が、ライム・ンザンビ・ウンガンスがッ！？」", white, normal20);
	}
	else if (check_sinario == 1) {
		DrawStringToHandle(150, 495, "「おばさん……もう、やめにしようよ……これ以上戦", white, normal20);
		DrawStringToHandle(170, 525, "っても、何も起こらないから……」", white, normal20);
	}
	else if (check_sinario == 2) {
		DrawStringToHandle(150, 495, "「おｂ……くっ……ふふっ……ふふっハッハハハあっ", white, normal20);
		DrawStringToHandle(170, 525, "！！」", white, normal20);
	}
	else if (check_sinario == 3) {
		DrawStringToHandle(150, 495, "「お前は何もわかっていない！　このあたしを倒した", white, normal20);
		DrawStringToHandle(170, 525, "ところで、『あたしたち』に刻まれた運命は、変えら", white, normal20);
		DrawStringToHandle(150, 555, "れない！」", white, normal20);
	}
	else if (check_sinario == 4) {
		DrawStringToHandle(150, 495, "「これまでのお前の行動をもってしても、何も起こら", white, normal20);
		DrawStringToHandle(170, 525, "ないんだよ！　変わらないんだよッ！」", white, normal20);
	}
	else if (check_sinario == 5) {
		DrawStringToHandle(150, 495, "「……？」", white, normal20);
	}
	else if (check_sinario == 6) {
		DrawStringToHandle(150, 495, "「どちらにしろ、もう終わりだ……運命からは逃れら", white, normal20);
		DrawStringToHandle(170, 525, "れない……あたしも夫も、この子の命もなあッッッ！", white, normal20);
		DrawStringToHandle(170, 555, "！」", white, normal20);
	}
	else if (check_sinario == 7) {
		if (!cgse.check_once) {
			cgse.PlaySE(10);
			cgse.check_once = true;
		}
		DrawStringToHandle(150, 495, "", white, normal20);
	}
	else if (check_sinario == 8) {
		DrawStringToHandle(150, 495, "「そんな……自分だけじゃなく、あの子も道連れにし", white, normal20);
		DrawStringToHandle(170, 525, "ようなんて……」", white, normal20);
	}
	else if (check_sinario == 9) {
		DrawStringToHandle(150, 495, "「損傷が激しすぎる……こんなの治せないよ……", white, normal20);
		DrawStringToHandle(170, 525, "このままじゃ絶対……こうなったら……」", white, normal20);
	}
	else if (check_sinario == 10) {
		DrawStringToHandle(150, 495, "「　絶　対　に　助　け　る　！　！　」", white, bold20);
	}
	else if (check_sinario == 11) {
		DrawStringToHandle(150, 495, "「……ふぅっ……ふぅ……」", white, normal20);
	}
	else if (check_sinario == 12) {
		DrawStringToHandle(150, 495, "「何とか落ち着いてきたわね。一時はどうなることか", white, normal20);
		DrawStringToHandle(170, 525, "と思ったけど……」", white, normal20);
	}
	else if (check_sinario == 13) {
		DrawStringToHandle(150, 495, "「……おかあ……さん？」", white, normal20);
	}
	else if (check_sinario == 14) {
		DrawStringToHandle(150, 495, "「○○！？　大丈夫なのかい！？」", white, normal20);
	}
	else if (check_sinario == 15) {
		DrawStringToHandle(150, 495, "「うん……妖精さんが守ってくれたから、へいき」", white, normal20);
	}
	else if (check_sinario == 16) {
		DrawStringToHandle(150, 495, "「……？」", white, normal20);
	}
	else if (check_sinario == 17) {
		DrawStringToHandle(150, 495, "「あのね、お母さん……妖精さん、僕の体を治すため", white, normal20);
		DrawStringToHandle(170, 525, "に、自分の体を犠牲にしてくれたんだよ……僕の体の", white, normal20);
		DrawStringToHandle(170, 555, "一部になってくれたんだよ……」", white, normal20);
	}
	else if (check_sinario == 18) {
		DrawStringToHandle(150, 495, "「○○……」", white, normal20);
	}
	else if (check_sinario == 19) {
		DrawStringToHandle(150, 495, "「良かった……本当に……」", white, normal20);
	}
	else if (check_sinario == 20) {
		DrawStringToHandle(150, 495, "「お母さん……」", white, normal20);
	}
	else if (check_sinario == 21) {
		DrawStringToHandle(150, 495, "これは、ある名もない妖精の、語られもしない物語。", white, normal20);
	}
	else if (check_sinario == 22) {
		DrawStringToHandle(150, 495, "Ainsel（エインセル）：", white, normal20);
		DrawStringToHandle(200, 525, "イングランドの方言で、「自分自身」を意味する", white, normal20);
	}
	else if (check_sinario == 23) {
		DrawStringToHandle(220, 525, "――The　End――", white, normal20);
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