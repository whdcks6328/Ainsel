#include "Music.h"

void Music::SetNewMusic(int map, int storynum, bool existboss) {
	for (i = 0; i < 5; i++) {
		story[i] = false;
		stage[i] = false;
		boss[i] = false;
	}
	if (storynum >= 0) {
		for (i = 0; i < 5; i++) if (i == storynum)story[i] = true;
	}
	else if (!existboss) {
		for (i = 0; i < 5; i++) if (i == map)stage[i] = true;
	}
	else {
		for (i = 0; i < 5; i++) if (i == map)boss[i] = true;
	}
	if (story[0] && !CheckSoundMem(sound_story_start))PlaySoundMem(sound_story_start, DX_PLAYTYPE_LOOP);
	else if (!story[0] && CheckSoundMem(sound_story_start))StopSoundMem(sound_story_start);
	if (story[1] && !CheckSoundMem(sound_story_ED))PlaySoundMem(sound_story_ED, DX_PLAYTYPE_LOOP);
	else if (!story[1] && CheckSoundMem(sound_story_ED))StopSoundMem(sound_story_ED);
	if (story[2] && !CheckSoundMem(sound_story_End))PlaySoundMem(sound_story_End, DX_PLAYTYPE_LOOP);
	else if (!story[2] && CheckSoundMem(sound_story_End))StopSoundMem(sound_story_End);
	if (story[3] && !CheckSoundMem(sound_story_lime))PlaySoundMem(sound_story_lime, DX_PLAYTYPE_LOOP);
	else if (!story[3] && CheckSoundMem(sound_story_lime))StopSoundMem(sound_story_lime);
	if (stage[0] && !CheckSoundMem(sound_title))PlaySoundMem(sound_title, DX_PLAYTYPE_LOOP);
	else if (!stage[0] && CheckSoundMem(sound_title))StopSoundMem(sound_title);
	if (stage[1] && !CheckSoundMem(sound_stage_one))PlaySoundMem(sound_stage_one, DX_PLAYTYPE_LOOP);
	else if (!stage[1] && CheckSoundMem(sound_stage_one))StopSoundMem(sound_stage_one);
	if (stage[2] && !CheckSoundMem(sound_stage_two))PlaySoundMem(sound_stage_two, DX_PLAYTYPE_LOOP);
	else if (!stage[2] && CheckSoundMem(sound_stage_two))StopSoundMem(sound_stage_two);
	if (stage[3] && !CheckSoundMem(sound_stage_three))PlaySoundMem(sound_stage_three, DX_PLAYTYPE_LOOP);
	else if (!stage[3] && CheckSoundMem(sound_stage_three))StopSoundMem(sound_stage_three);
	if (stage[4] && !CheckSoundMem(sound_stage_extra))PlaySoundMem(sound_stage_extra, DX_PLAYTYPE_LOOP);
	else if (!stage[4] && CheckSoundMem(sound_stage_extra))StopSoundMem(sound_stage_extra);
	if (boss[0] && !CheckSoundMem(sound_stage_boss))PlaySoundMem(sound_stage_boss, DX_PLAYTYPE_LOOP);
	else if (!boss[0] && CheckSoundMem(sound_stage_boss))StopSoundMem(sound_stage_boss);
	if (boss[1] && !CheckSoundMem(sound_stage_three_boss)) {
		SetLoopPosSoundMem(59790, sound_stage_three_boss);
		PlaySoundMem(sound_stage_three_boss, DX_PLAYTYPE_LOOP);
	}
	else if (!boss[1] && CheckSoundMem(sound_stage_three_boss))StopSoundMem(sound_stage_three_boss);
	if (boss[2] && !CheckSoundMem(sound_stage_extra_boss_one)) {
		SetLoopPosSoundMem(2080, sound_stage_extra_boss_one);
		PlaySoundMem(sound_stage_extra_boss_one, DX_PLAYTYPE_LOOP);
	}
	else if (!boss[2] && CheckSoundMem(sound_stage_extra_boss_one))StopSoundMem(sound_stage_extra_boss_one);
	if (boss[3] && !CheckSoundMem(sound_stage_extra_boss_two))PlaySoundMem(sound_stage_extra_boss_two, DX_PLAYTYPE_LOOP);
	else if (!boss[3] && CheckSoundMem(sound_stage_extra_boss_two))StopSoundMem(sound_stage_extra_boss_two);
}


void Music::PlayMusic() {
	if (story[0] && !CheckSoundMem(sound_story_start))PlaySoundMem(sound_story_start, DX_PLAYTYPE_LOOP);
	else if (!story[0] && CheckSoundMem(sound_story_start))StopSoundMem(sound_story_start);
	if (story[1] && !CheckSoundMem(sound_story_ED))PlaySoundMem(sound_story_ED, DX_PLAYTYPE_LOOP);
	else if (!story[1] && CheckSoundMem(sound_story_ED))StopSoundMem(sound_story_ED);
	if (story[2] && !CheckSoundMem(sound_story_End))PlaySoundMem(sound_story_End, DX_PLAYTYPE_LOOP);
	else if (!story[2] && CheckSoundMem(sound_story_End))StopSoundMem(sound_story_End);
	if (stage[0] && !CheckSoundMem(sound_title))PlaySoundMem(sound_title, DX_PLAYTYPE_LOOP);
	else if (!stage[0] && CheckSoundMem(sound_title))StopSoundMem(sound_title);
	if (stage[1] && !CheckSoundMem(sound_stage_one))PlaySoundMem(sound_stage_one, DX_PLAYTYPE_LOOP);
	else if (!stage[1] && CheckSoundMem(sound_stage_one))StopSoundMem(sound_stage_one);
	if (stage[2] && !CheckSoundMem(sound_stage_two))PlaySoundMem(sound_stage_two, DX_PLAYTYPE_LOOP);
	else if (!stage[2] && CheckSoundMem(sound_stage_two))StopSoundMem(sound_stage_two);
	if (stage[3] && !CheckSoundMem(sound_stage_three))PlaySoundMem(sound_stage_three, DX_PLAYTYPE_LOOP);
	else if (!stage[3] && CheckSoundMem(sound_stage_three))StopSoundMem(sound_stage_three);
	if (stage[4] && !CheckSoundMem(sound_stage_extra))PlaySoundMem(sound_stage_extra, DX_PLAYTYPE_LOOP);
	else if (!stage[4] && CheckSoundMem(sound_stage_extra))StopSoundMem(sound_stage_extra);
	if (boss[0] && !CheckSoundMem(sound_stage_boss))PlaySoundMem(sound_stage_boss, DX_PLAYTYPE_LOOP);
	else if (!boss[0] && CheckSoundMem(sound_stage_boss))StopSoundMem(sound_stage_boss);
	if (boss[1] && !CheckSoundMem(sound_stage_three_boss)) {
		SetLoopPosSoundMem(59790, sound_stage_three_boss);
		PlaySoundMem(sound_stage_three_boss, DX_PLAYTYPE_LOOP);
	}
	else if (!boss[1] && CheckSoundMem(sound_stage_three_boss))StopSoundMem(sound_stage_three_boss);
	if (boss[2] && !CheckSoundMem(sound_stage_extra_boss_one)) {
		SetLoopPosSoundMem(2080, sound_stage_extra_boss_one);
		PlaySoundMem(sound_stage_extra_boss_one, DX_PLAYTYPE_LOOP);
	}
	else if (!boss[2] && CheckSoundMem(sound_stage_extra_boss_one))StopSoundMem(sound_stage_extra_boss_one);
	if (boss[3] && !CheckSoundMem(sound_stage_extra_boss_two))PlaySoundMem(sound_stage_extra_boss_two, DX_PLAYTYPE_LOOP);
	else if (!boss[3] && CheckSoundMem(sound_stage_extra_boss_two))StopSoundMem(sound_stage_extra_boss_two);
}