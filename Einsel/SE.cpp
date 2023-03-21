#include "SE.h"

void SE::PlaySE(int num) {
	switch (num)
	{
	case 0:
		if (!(CheckSoundMem(decide)))PlaySoundMem(decide, DX_PLAYTYPE_BACK);
		break;
	case 1:
		if (!(CheckSoundMem(shoot))) {
			ChangeVolumeSoundMem(255 * 40 / 100, shoot);
			PlaySoundMem(shoot, DX_PLAYTYPE_BACK);
		}
		break;
	case 2:
		if (!(CheckSoundMem(heal)))PlaySoundMem(heal, DX_PLAYTYPE_BACK);
		break;
	case 3:
		if (!(CheckSoundMem(enemy_broken)))PlaySoundMem(enemy_broken, DX_PLAYTYPE_BACK);
		break;
	case 4:
		if (!(CheckSoundMem(warning))) {
			ChangeVolumeSoundMem(255 * 60 / 100, warning);
			PlaySoundMem(warning, DX_PLAYTYPE_BACK);
		}
		break;
	case 5:
		if (!(CheckSoundMem(boss_damaged)))PlaySoundMem(boss_damaged, DX_PLAYTYPE_BACK);
		break;
	case 6:
		if (!(CheckSoundMem(lime_damaged)))PlaySoundMem(lime_damaged, DX_PLAYTYPE_BACK);
		break;
	case 7:
		if (!(CheckSoundMem(palime_damaged)))PlaySoundMem(palime_damaged, DX_PLAYTYPE_BACK);
		break;
	case 8:
		if (!(CheckSoundMem(boss_clear)))PlaySoundMem(boss_clear, DX_PLAYTYPE_BACK);
		break;
	case 9:
		if (!(CheckSoundMem(palime_broken)))PlaySoundMem(palime_broken, DX_PLAYTYPE_BACK);
		break;
	case 10:
		if (!(CheckSoundMem(final_broken)))PlaySoundMem(final_broken, DX_PLAYTYPE_BACK);
		break;
	}
}