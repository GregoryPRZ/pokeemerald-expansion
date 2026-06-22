EmeraldTower_Lobby_MapScripts::
	.byte 0

EmeraldTower_Lobby_EventScript_TowerChief::
	lock
	faceplayer
	msgbox EmeraldTower_Lobby_Text_TowerChiefWelcome, MSGBOX_DEFAULT
	call EmeraldTower_Lobby_EventScript_GiveGimmickItemSet
	msgbox EmeraldTower_Lobby_Text_TowerChiefRecruitTeam, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0

EmeraldTower_Lobby_EventScript_TowerChiefRecruitLoop::
	goto_if_ge VAR_TEMP_0, PARTY_SIZE, EmeraldTower_Lobby_EventScript_TowerChiefRecruitDone
	specialvar VAR_RESULT, Script_EmeraldTowerIsPartyFull
	goto_if_eq VAR_RESULT, TRUE, EmeraldTower_Lobby_EventScript_TowerChiefRecruitDone
	special Script_OpenEmeraldTowerRecruitMenu
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_TowerChiefRecruitCancel
	addvar VAR_TEMP_0, 1
	goto EmeraldTower_Lobby_EventScript_TowerChiefRecruitLoop

EmeraldTower_Lobby_EventScript_TowerChiefRecruitDone::
	setflag FLAG_SYS_POKEMON_GET
	msgbox EmeraldTower_Lobby_Text_TowerChiefReady, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_TowerChiefRecruitCancel::
	msgbox EmeraldTower_Lobby_Text_TowerChiefRecruitCancel, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_GiveGimmickItemSet::
	checkitem ITEM_MEGA_RING
	goto_if_eq VAR_RESULT, TRUE, EmeraldTower_Lobby_EventScript_CheckZPowerRing
	giveitem ITEM_MEGA_RING

EmeraldTower_Lobby_EventScript_CheckZPowerRing::
	checkitem ITEM_Z_POWER_RING
	goto_if_eq VAR_RESULT, TRUE, EmeraldTower_Lobby_EventScript_CheckDynamaxBand
	giveitem ITEM_Z_POWER_RING

EmeraldTower_Lobby_EventScript_CheckDynamaxBand::
	checkitem ITEM_DYNAMAX_BAND
	goto_if_eq VAR_RESULT, TRUE, EmeraldTower_Lobby_EventScript_CheckTeraOrb
	giveitem ITEM_DYNAMAX_BAND

EmeraldTower_Lobby_EventScript_CheckTeraOrb::
	checkitem ITEM_TERA_ORB
	goto_if_eq VAR_RESULT, TRUE, EmeraldTower_Lobby_EventScript_GimmickItemSetDone
	giveitem ITEM_TERA_ORB

EmeraldTower_Lobby_EventScript_GimmickItemSetDone::
	return

EmeraldTower_Lobby_EventScript_Recruiter::
	lock
	faceplayer
	specialvar VAR_RESULT, Script_EmeraldTowerIsPartyFull
	goto_if_eq VAR_RESULT, TRUE, EmeraldTower_Lobby_EventScript_RecruiterPartyFull
	msgbox EmeraldTower_Lobby_Text_RecruiterIntro, MSGBOX_DEFAULT
	special Script_OpenEmeraldTowerRecruitMenu
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_RecruiterCancel
	msgbox EmeraldTower_Lobby_Text_RecruiterJoined, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_RecruiterPartyFull::
	msgbox EmeraldTower_Lobby_Text_RecruiterPartyFull, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_RecruiterCancel::
	msgbox EmeraldTower_Lobby_Text_RecruiterCancel, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_BattleMusicNpc::
	lock
	faceplayer
	msgbox EmeraldTower_Lobby_Text_BattleMusicIntro, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_EMERALD_TOWER_BATTLE_MUSIC, TRUE
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_SetDefaultBattleMusic
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_ChooseEmeraldBattleMusic
	goto_if_eq VAR_RESULT, 2, EmeraldTower_Lobby_EventScript_ChooseFrlgBattleMusic
	goto_if_eq VAR_RESULT, 3, EmeraldTower_Lobby_EventScript_ChooseDpptBattleMusic
	goto_if_eq VAR_RESULT, 4, EmeraldTower_Lobby_EventScript_ChooseHgssBattleMusic
	release
	end

EmeraldTower_Lobby_EventScript_SetDefaultBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, 0
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_ChooseEmeraldBattleMusic::
	setvar VAR_0x8004, SCROLL_MULTI_EMERALD_TOWER_MUSIC_EMERALD
	special ShowScrollableMultichoice
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_SetEmeraldTrainerBattleMusic
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_SetEmeraldGymLeaderBattleMusic
	goto_if_eq VAR_RESULT, 2, EmeraldTower_Lobby_EventScript_SetEmeraldEliteFourBattleMusic
	goto_if_eq VAR_RESULT, 3, EmeraldTower_Lobby_EventScript_SetEmeraldChampionBattleMusic
	goto_if_eq VAR_RESULT, 4, EmeraldTower_Lobby_EventScript_SetEmeraldFrontierBrainBattleMusic
	goto_if_eq VAR_RESULT, 5, EmeraldTower_Lobby_EventScript_SetEmeraldRivalBattleMusic
	goto_if_eq VAR_RESULT, 6, EmeraldTower_Lobby_EventScript_SetEmeraldLegendaryBattleMusic
	release
	end

EmeraldTower_Lobby_EventScript_SetEmeraldTrainerBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_VS_TRAINER
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetEmeraldGymLeaderBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_VS_GYM_LEADER
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetEmeraldEliteFourBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_VS_ELITE_FOUR
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetEmeraldChampionBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_VS_CHAMPION
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetEmeraldFrontierBrainBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_VS_FRONTIER_BRAIN
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetEmeraldRivalBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_VS_RIVAL
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetEmeraldLegendaryBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_RG_VS_LEGEND
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_ChooseFrlgBattleMusic::
	setvar VAR_0x8004, SCROLL_MULTI_EMERALD_TOWER_MUSIC_FRLG
	special ShowScrollableMultichoice
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_SetFrlgTrainerBattleMusic
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_SetFrlgWildBattleMusic
	goto_if_eq VAR_RESULT, 2, EmeraldTower_Lobby_EventScript_SetFrlgGymLeaderBattleMusic
	goto_if_eq VAR_RESULT, 3, EmeraldTower_Lobby_EventScript_SetFrlgChampionBattleMusic
	goto_if_eq VAR_RESULT, 4, EmeraldTower_Lobby_EventScript_SetFrlgDeoxysBattleMusic
	goto_if_eq VAR_RESULT, 5, EmeraldTower_Lobby_EventScript_SetFrlgMewtwoBattleMusic
	goto_if_eq VAR_RESULT, 6, EmeraldTower_Lobby_EventScript_SetFrlgLegendaryBattleMusic
	release
	end

EmeraldTower_Lobby_EventScript_SetFrlgTrainerBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_RG_VS_TRAINER
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetFrlgWildBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_RG_VS_WILD
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetFrlgGymLeaderBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_RG_VS_GYM_LEADER
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetFrlgChampionBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_RG_VS_CHAMPION
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetFrlgDeoxysBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_RG_VS_DEOXYS
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetFrlgMewtwoBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_RG_VS_MEWTWO
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetFrlgLegendaryBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_RG_VS_LEGEND
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_ChooseDpptBattleMusic::
	setvar VAR_0x8004, SCROLL_MULTI_EMERALD_TOWER_MUSIC_DPPT
	special ShowScrollableMultichoice
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_SetDpptTrainerBattleMusic
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_SetDpptWildBattleMusic
	goto_if_eq VAR_RESULT, 2, EmeraldTower_Lobby_EventScript_SetDpptGymLeaderBattleMusic
	goto_if_eq VAR_RESULT, 3, EmeraldTower_Lobby_EventScript_SetDpptEliteFourBattleMusic
	goto_if_eq VAR_RESULT, 4, EmeraldTower_Lobby_EventScript_SetDpptChampionBattleMusic
	goto_if_eq VAR_RESULT, 5, EmeraldTower_Lobby_EventScript_SetDpptRivalBattleMusic
	goto_if_eq VAR_RESULT, 6, EmeraldTower_Lobby_EventScript_SetDpptGalacticBattleMusic
	goto_if_eq VAR_RESULT, 7, EmeraldTower_Lobby_EventScript_SetDpptGalacticCommanderBattleMusic
	goto_if_eq VAR_RESULT, 8, EmeraldTower_Lobby_EventScript_SetDpptGalacticBossBattleMusic
	goto_if_eq VAR_RESULT, 9, EmeraldTower_Lobby_EventScript_ChooseDpptLegendBattleMusic
	release
	end

EmeraldTower_Lobby_EventScript_SetDpptTrainerBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_TRAINER
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptWildBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_WILD
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptGymLeaderBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_GYM_LEADER
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptEliteFourBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_ELITE_FOUR
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptChampionBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_CHAMPION
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptRivalBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_RIVAL
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptGalacticBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_GALACTIC
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptGalacticCommanderBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_GALACTIC_COMMANDER
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptGalacticBossBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_GALACTIC_BOSS
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_ChooseDpptLegendBattleMusic::
	setvar VAR_0x8004, SCROLL_MULTI_EMERALD_TOWER_MUSIC_DPPT_LEGEND
	special ShowScrollableMultichoice
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_SetDpptLakeTrioBattleMusic
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_SetDpptDialgaPalkiaBattleMusic
	goto_if_eq VAR_RESULT, 2, EmeraldTower_Lobby_EventScript_SetDpptArceusBattleMusic
	goto_if_eq VAR_RESULT, 3, EmeraldTower_Lobby_EventScript_SetDpptLegendaryBattleMusic
	release
	end

EmeraldTower_Lobby_EventScript_SetDpptLakeTrioBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_UXIE_MESPRIT_AZELF
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptDialgaPalkiaBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_DIALGA_PALKIA
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptArceusBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_ARCEUS
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetDpptLegendaryBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_DP_VS_LEGEND
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_ChooseHgssBattleMusic::
	setvar VAR_0x8004, SCROLL_MULTI_EMERALD_TOWER_MUSIC_HGSS
	special ShowScrollableMultichoice
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_SetHgssTrainerBattleMusic
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_SetHgssWildBattleMusic
	goto_if_eq VAR_RESULT, 2, EmeraldTower_Lobby_EventScript_SetHgssGymLeaderBattleMusic
	goto_if_eq VAR_RESULT, 3, EmeraldTower_Lobby_EventScript_SetHgssRivalBattleMusic
	goto_if_eq VAR_RESULT, 4, EmeraldTower_Lobby_EventScript_SetHgssRocketBattleMusic
	goto_if_eq VAR_RESULT, 5, EmeraldTower_Lobby_EventScript_SetHgssChampionBattleMusic
	goto_if_eq VAR_RESULT, 6, EmeraldTower_Lobby_EventScript_ChooseHgssKantoBattleMusic
	goto_if_eq VAR_RESULT, 7, EmeraldTower_Lobby_EventScript_ChooseHgssLegendBattleMusic
	goto_if_eq VAR_RESULT, 8, EmeraldTower_Lobby_EventScript_SetHgssFrontierBrainBattleMusic
	release
	end

EmeraldTower_Lobby_EventScript_SetHgssTrainerBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_TRAINER
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssWildBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_WILD
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssGymLeaderBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_GYM_LEADER
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssRivalBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_RIVAL
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssRocketBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_ROCKET
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssChampionBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_CHAMPION
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_ChooseHgssKantoBattleMusic::
	setvar VAR_0x8004, SCROLL_MULTI_EMERALD_TOWER_MUSIC_HGSS_KANTO
	special ShowScrollableMultichoice
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_SetHgssKantoTrainerBattleMusic
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_SetHgssKantoWildBattleMusic
	goto_if_eq VAR_RESULT, 2, EmeraldTower_Lobby_EventScript_SetHgssKantoGymLeaderBattleMusic
	release
	end

EmeraldTower_Lobby_EventScript_SetHgssKantoTrainerBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_TRAINER_KANTO
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssKantoWildBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_WILD_KANTO
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssKantoGymLeaderBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_GYM_LEADER_KANTO
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssFrontierBrainBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_FRONTIER_BRAIN
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_ChooseHgssLegendBattleMusic::
	setvar VAR_0x8004, SCROLL_MULTI_EMERALD_TOWER_MUSIC_HGSS_LEGEND
	special ShowScrollableMultichoice
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_SetHgssSuicuneBattleMusic
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_SetHgssEnteiBattleMusic
	goto_if_eq VAR_RESULT, 2, EmeraldTower_Lobby_EventScript_SetHgssRaikouBattleMusic
	goto_if_eq VAR_RESULT, 3, EmeraldTower_Lobby_EventScript_SetHgssHoOhBattleMusic
	goto_if_eq VAR_RESULT, 4, EmeraldTower_Lobby_EventScript_SetHgssLugiaBattleMusic
	goto_if_eq VAR_RESULT, 5, EmeraldTower_Lobby_EventScript_SetHgssKyogreGroudonBattleMusic
	goto_if_eq VAR_RESULT, 6, EmeraldTower_Lobby_EventScript_SetHgssArceusBattleMusic
	release
	end

EmeraldTower_Lobby_EventScript_SetHgssSuicuneBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_SUICUNE
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssEnteiBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_ENTEI
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssRaikouBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_RAIKOU
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssHoOhBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_HO_OH
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssLugiaBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_LUGIA
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssKyogreGroudonBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_KYOGRE_GROUDON
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_SetHgssArceusBattleMusic::
	setvar VAR_EMERALD_TOWER_BATTLE_MUSIC, MUS_HG_VS_ARCEUS
	goto EmeraldTower_Lobby_EventScript_BattleMusicChanged

EmeraldTower_Lobby_EventScript_BattleMusicChanged::
	msgbox EmeraldTower_Lobby_Text_BattleMusicChanged, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_BattleHost::
	lock
	faceplayer
	msgbox EmeraldTower_Lobby_Text_BattleHostIntro, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_EMERALD_TOWER_BATTLE_CATEGORY, TRUE
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_ChooseHoennLeader
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_ChooseHoennLeague
	release
	end

EmeraldTower_Lobby_EventScript_ChooseHoennLeader::
	msgbox EmeraldTower_Lobby_Text_BattleHostLeaderPrompt, MSGBOX_DEFAULT
	setvar VAR_0x8004, SCROLL_MULTI_EMERALD_TOWER_HOENN_LEADERS
	special ShowScrollableMultichoice
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_BattleRoxanne
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_BattleBrawly
	goto_if_eq VAR_RESULT, 2, EmeraldTower_Lobby_EventScript_BattleWattson
	goto_if_eq VAR_RESULT, 3, EmeraldTower_Lobby_EventScript_BattleFlannery
	goto_if_eq VAR_RESULT, 4, EmeraldTower_Lobby_EventScript_BattleNorman
	goto_if_eq VAR_RESULT, 5, EmeraldTower_Lobby_EventScript_BattleWinona
	goto_if_eq VAR_RESULT, 6, EmeraldTower_Lobby_EventScript_BattleTateAndLiza
	goto_if_eq VAR_RESULT, 7, EmeraldTower_Lobby_EventScript_BattleJuan
	release
	end

EmeraldTower_Lobby_EventScript_ChooseHoennLeague::
	msgbox EmeraldTower_Lobby_Text_BattleHostLeaguePrompt, MSGBOX_DEFAULT
	setvar VAR_0x8004, SCROLL_MULTI_EMERALD_TOWER_HOENN_LEAGUE
	special ShowScrollableMultichoice
	goto_if_eq VAR_RESULT, 0, EmeraldTower_Lobby_EventScript_BattleSidney
	goto_if_eq VAR_RESULT, 1, EmeraldTower_Lobby_EventScript_BattlePhoebe
	goto_if_eq VAR_RESULT, 2, EmeraldTower_Lobby_EventScript_BattleGlacia
	goto_if_eq VAR_RESULT, 3, EmeraldTower_Lobby_EventScript_BattleDrake
	goto_if_eq VAR_RESULT, 4, EmeraldTower_Lobby_EventScript_BattleWallace
	goto_if_eq VAR_RESULT, 5, EmeraldTower_Lobby_EventScript_BattleSteven
	release
	end

EmeraldTower_Lobby_EventScript_BattleRoxanne::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 1
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ROXANNE
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleBrawly::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 2
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRAWLY
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleWattson::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 3
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WATTSON
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleFlannery::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 4
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_FLANNERY
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleNorman::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 5
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_NORMAN
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleWinona::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 6
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WINONA
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleTateAndLiza::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 7
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_TATE
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleJuan::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 8
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUAN
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleSidney::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 9
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIDNEY
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattlePhoebe::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 10
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_PHOEBE
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleGlacia::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 11
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_GLACIA
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleDrake::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 12
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_DRAKE
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleWallace::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 13
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WALLACE
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_BattleSteven::
	setvar VAR_EMERALD_TOWER_SELECTED_TRAINER, 14
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_STEVEN
	goto EmeraldTower_Lobby_EventScript_StartArenaBattle

EmeraldTower_Lobby_EventScript_StartArenaBattle::
	msgbox EmeraldTower_Lobby_Text_BattleHostEscort, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 0
	warp MAP_EMERALD_TOWER_BATTLE_ARENA, 4, 8
	waitstate
	release
	end

EmeraldTower_Lobby_EventScript_StrategyShop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EmeraldTower_Lobby_StrategyShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_BerryShop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EmeraldTower_Lobby_BerryShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_FormChangeShop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EmeraldTower_Lobby_FormChangeShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_NatureMintShop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EmeraldTower_Lobby_NatureMintShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_MegaStoneShop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EmeraldTower_Lobby_MegaStoneShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_ZCrystalShop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EmeraldTower_Lobby_ZCrystalShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EmeraldTower_Lobby_StrategyShop:
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_BOTTLE_CAP
	.2byte ITEM_PP_UP
	.2byte ITEM_PP_MAX
	.2byte ITEM_NORMAL_GEM
	.2byte ITEM_FIRE_GEM
	.2byte ITEM_WATER_GEM
	.2byte ITEM_ELECTRIC_GEM
	.2byte ITEM_GRASS_GEM
	.2byte ITEM_ICE_GEM
	.2byte ITEM_FIGHTING_GEM
	.2byte ITEM_POISON_GEM
	.2byte ITEM_GROUND_GEM
	.2byte ITEM_FLYING_GEM
	.2byte ITEM_PSYCHIC_GEM
	.2byte ITEM_BUG_GEM
	.2byte ITEM_ROCK_GEM
	.2byte ITEM_GHOST_GEM
	.2byte ITEM_DRAGON_GEM
	.2byte ITEM_DARK_GEM
	.2byte ITEM_STEEL_GEM
	.2byte ITEM_FAIRY_GEM
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_MAGNET
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_NEVER_MELT_ICE
	.2byte ITEM_BLACK_BELT
	.2byte ITEM_POISON_BARB
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_TWISTED_SPOON
	.2byte ITEM_SILVER_POWDER
	.2byte ITEM_HARD_STONE
	.2byte ITEM_SPELL_TAG
	.2byte ITEM_DRAGON_FANG
	.2byte ITEM_BLACK_GLASSES
	.2byte ITEM_METAL_COAT
	.2byte ITEM_MACHO_BRACE
	.2byte ITEM_POWER_WEIGHT
	.2byte ITEM_POWER_BRACER
	.2byte ITEM_POWER_BELT
	.2byte ITEM_POWER_LENS
	.2byte ITEM_POWER_BAND
	.2byte ITEM_POWER_ANKLET
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_CHOICE_SPECS
	.2byte ITEM_CHOICE_SCARF
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_TOXIC_ORB
	.2byte ITEM_DAMP_ROCK
	.2byte ITEM_HEAT_ROCK
	.2byte ITEM_SMOOTH_ROCK
	.2byte ITEM_ICY_ROCK
	.2byte ITEM_ELECTRIC_SEED
	.2byte ITEM_PSYCHIC_SEED
	.2byte ITEM_MISTY_SEED
	.2byte ITEM_GRASSY_SEED
	.2byte ITEM_ABSORB_BULB
	.2byte ITEM_CELL_BATTERY
	.2byte ITEM_LUMINOUS_MOSS
	.2byte ITEM_SNOWBALL
	.2byte ITEM_BRIGHT_POWDER
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_QUICK_CLAW
	.2byte ITEM_MENTAL_HERB
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_FOCUS_BAND
	.2byte ITEM_SCOPE_LENS
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_SHELL_BELL
	.2byte ITEM_WIDE_LENS
	.2byte ITEM_MUSCLE_BAND
	.2byte ITEM_WISE_GLASSES
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_LIGHT_CLAY
	.2byte ITEM_LIFE_ORB
	.2byte ITEM_POWER_HERB
	.2byte ITEM_FOCUS_SASH
	.2byte ITEM_ZOOM_LENS
	.2byte ITEM_METRONOME
	.2byte ITEM_IRON_BALL
	.2byte ITEM_LIGHT_BALL
	.2byte ITEM_LAGGING_TAIL
	.2byte ITEM_BLACK_SLUDGE
	.2byte ITEM_GRIP_CLAW
	.2byte ITEM_STICKY_BARB
	.2byte ITEM_SHED_SHELL
	.2byte ITEM_BIG_ROOT
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_EVIOLITE
	.2byte ITEM_FLOAT_STONE
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_AIR_BALLOON
	.2byte ITEM_RED_CARD
	.2byte ITEM_RING_TARGET
	.2byte ITEM_BINDING_BAND
	.2byte ITEM_EJECT_BUTTON
	.2byte ITEM_WEAKNESS_POLICY
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_SAFETY_GOGGLES
	.2byte ITEM_ADRENALINE_ORB
	.2byte ITEM_TERRAIN_EXTENDER
	.2byte ITEM_PROTECTIVE_PADS
	.2byte ITEM_THROAT_SPRAY
	.2byte ITEM_EJECT_PACK
	.2byte ITEM_HEAVY_DUTY_BOOTS
	.2byte ITEM_BLUNDER_POLICY
	.2byte ITEM_ROOM_SERVICE
	.2byte ITEM_UTILITY_UMBRELLA
	.2byte ITEM_ABILITY_SHIELD
	.2byte ITEM_CLEAR_AMULET
	.2byte ITEM_PUNCHING_GLOVE
	.2byte ITEM_COVERT_CLOAK
	.2byte ITEM_LOADED_DICE
	.2byte ITEM_BOOSTER_ENERGY
	.2byte ITEM_MIRROR_HERB
	pokemartlistend

EmeraldTower_Lobby_BerryShop:
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_PERSIM_BERRY
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_MAGO_BERRY
	.2byte ITEM_AGUAV_BERRY
	.2byte ITEM_IAPAPA_BERRY
	.2byte ITEM_RAZZ_BERRY
	.2byte ITEM_BLUK_BERRY
	.2byte ITEM_NANAB_BERRY
	.2byte ITEM_WEPEAR_BERRY
	.2byte ITEM_PINAP_BERRY
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_TAMATO_BERRY
	.2byte ITEM_CORNN_BERRY
	.2byte ITEM_MAGOST_BERRY
	.2byte ITEM_RABUTA_BERRY
	.2byte ITEM_NOMEL_BERRY
	.2byte ITEM_SPELON_BERRY
	.2byte ITEM_PAMTRE_BERRY
	.2byte ITEM_WATMEL_BERRY
	.2byte ITEM_DURIN_BERRY
	.2byte ITEM_BELUE_BERRY
	.2byte ITEM_CHILAN_BERRY
	.2byte ITEM_OCCA_BERRY
	.2byte ITEM_PASSHO_BERRY
	.2byte ITEM_WACAN_BERRY
	.2byte ITEM_RINDO_BERRY
	.2byte ITEM_YACHE_BERRY
	.2byte ITEM_CHOPLE_BERRY
	.2byte ITEM_KEBIA_BERRY
	.2byte ITEM_SHUCA_BERRY
	.2byte ITEM_COBA_BERRY
	.2byte ITEM_PAYAPA_BERRY
	.2byte ITEM_TANGA_BERRY
	.2byte ITEM_CHARTI_BERRY
	.2byte ITEM_KASIB_BERRY
	.2byte ITEM_HABAN_BERRY
	.2byte ITEM_COLBUR_BERRY
	.2byte ITEM_BABIRI_BERRY
	.2byte ITEM_ROSELI_BERRY
	.2byte ITEM_LIECHI_BERRY
	.2byte ITEM_GANLON_BERRY
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_PETAYA_BERRY
	.2byte ITEM_APICOT_BERRY
	.2byte ITEM_LANSAT_BERRY
	.2byte ITEM_STARF_BERRY
	.2byte ITEM_ENIGMA_BERRY
	.2byte ITEM_MICLE_BERRY
	.2byte ITEM_CUSTAP_BERRY
	.2byte ITEM_JABOCA_BERRY
	.2byte ITEM_ROWAP_BERRY
	.2byte ITEM_KEE_BERRY
	.2byte ITEM_MARANGA_BERRY
	pokemartlistend

EmeraldTower_Lobby_FormChangeShop:
	.2byte ITEM_RED_NECTAR
	.2byte ITEM_YELLOW_NECTAR
	.2byte ITEM_PINK_NECTAR
	.2byte ITEM_PURPLE_NECTAR
	.2byte ITEM_FLAME_PLATE
	.2byte ITEM_SPLASH_PLATE
	.2byte ITEM_ZAP_PLATE
	.2byte ITEM_MEADOW_PLATE
	.2byte ITEM_ICICLE_PLATE
	.2byte ITEM_FIST_PLATE
	.2byte ITEM_TOXIC_PLATE
	.2byte ITEM_EARTH_PLATE
	.2byte ITEM_SKY_PLATE
	.2byte ITEM_MIND_PLATE
	.2byte ITEM_INSECT_PLATE
	.2byte ITEM_STONE_PLATE
	.2byte ITEM_SPOOKY_PLATE
	.2byte ITEM_DRACO_PLATE
	.2byte ITEM_DREAD_PLATE
	.2byte ITEM_IRON_PLATE
	.2byte ITEM_PIXIE_PLATE
	.2byte ITEM_DOUSE_DRIVE
	.2byte ITEM_SHOCK_DRIVE
	.2byte ITEM_BURN_DRIVE
	.2byte ITEM_CHILL_DRIVE
	.2byte ITEM_FIRE_MEMORY
	.2byte ITEM_WATER_MEMORY
	.2byte ITEM_ELECTRIC_MEMORY
	.2byte ITEM_GRASS_MEMORY
	.2byte ITEM_ICE_MEMORY
	.2byte ITEM_FIGHTING_MEMORY
	.2byte ITEM_POISON_MEMORY
	.2byte ITEM_GROUND_MEMORY
	.2byte ITEM_FLYING_MEMORY
	.2byte ITEM_PSYCHIC_MEMORY
	.2byte ITEM_BUG_MEMORY
	.2byte ITEM_ROCK_MEMORY
	.2byte ITEM_GHOST_MEMORY
	.2byte ITEM_DRAGON_MEMORY
	.2byte ITEM_DARK_MEMORY
	.2byte ITEM_STEEL_MEMORY
	.2byte ITEM_FAIRY_MEMORY
	.2byte ITEM_RUSTED_SWORD
	.2byte ITEM_RUSTED_SHIELD
	.2byte ITEM_ROTOM_CATALOG
	.2byte ITEM_GRACIDEA
	.2byte ITEM_REVEAL_GLASS
	.2byte ITEM_DNA_SPLICERS
	.2byte ITEM_ZYGARDE_CUBE
	.2byte ITEM_PRISON_BOTTLE
	.2byte ITEM_N_SOLARIZER
	.2byte ITEM_N_LUNARIZER
	.2byte ITEM_REINS_OF_UNITY
	.2byte ITEM_ADAMANT_CRYSTAL
	.2byte ITEM_GRISEOUS_CORE
	.2byte ITEM_LUSTROUS_GLOBE
	.2byte ITEM_AUSPICIOUS_ARMOR
	.2byte ITEM_MALICIOUS_ARMOR
	.2byte ITEM_SCROLL_OF_DARKNESS
	.2byte ITEM_SCROLL_OF_WATERS
	.2byte ITEM_BLACK_AUGURITE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_PEAT_BLOCK
	.2byte ITEM_SYRUPY_APPLE
	.2byte ITEM_UNREMARKABLE_TEACUP
	.2byte ITEM_MASTERPIECE_TEACUP
	.2byte ITEM_METAL_ALLOY
	pokemartlistend

EmeraldTower_Lobby_NatureMintShop:
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_SERIOUS_MINT
	pokemartlistend

EmeraldTower_Lobby_MegaStoneShop:
	.2byte ITEM_RED_ORB
	.2byte ITEM_BLUE_ORB
	.2byte ITEM_VENUSAURITE
	.2byte ITEM_CHARIZARDITE_X
	.2byte ITEM_CHARIZARDITE_Y
	.2byte ITEM_BLASTOISINITE
	.2byte ITEM_BEEDRILLITE
	.2byte ITEM_PIDGEOTITE
	.2byte ITEM_ALAKAZITE
	.2byte ITEM_SLOWBRONITE
	.2byte ITEM_GENGARITE
	.2byte ITEM_KANGASKHANITE
	.2byte ITEM_PINSIRITE
	.2byte ITEM_GYARADOSITE
	.2byte ITEM_AERODACTYLITE
	.2byte ITEM_MEWTWONITE_X
	.2byte ITEM_MEWTWONITE_Y
	.2byte ITEM_AMPHAROSITE
	.2byte ITEM_STEELIXITE
	.2byte ITEM_SCIZORITE
	.2byte ITEM_HERACRONITE
	.2byte ITEM_HOUNDOOMINITE
	.2byte ITEM_TYRANITARITE
	.2byte ITEM_SCEPTILITE
	.2byte ITEM_BLAZIKENITE
	.2byte ITEM_SWAMPERTITE
	.2byte ITEM_GARDEVOIRITE
	.2byte ITEM_SABLENITE
	.2byte ITEM_MAWILITE
	.2byte ITEM_AGGRONITE
	.2byte ITEM_MEDICHAMITE
	.2byte ITEM_MANECTITE
	.2byte ITEM_SHARPEDONITE
	.2byte ITEM_CAMERUPTITE
	.2byte ITEM_ALTARIANITE
	.2byte ITEM_BANETTITE
	.2byte ITEM_ABSOLITE
	.2byte ITEM_GLALITITE
	.2byte ITEM_SALAMENCITE
	.2byte ITEM_METAGROSSITE
	.2byte ITEM_LATIASITE
	.2byte ITEM_LATIOSITE
	.2byte ITEM_LOPUNNITE
	.2byte ITEM_GARCHOMPITE
	.2byte ITEM_LUCARIONITE
	.2byte ITEM_ABOMASITE
	.2byte ITEM_GALLADITE
	.2byte ITEM_AUDINITE
	.2byte ITEM_DIANCITE
	.2byte ITEM_CLEFABLITE
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_STARMINITE
	.2byte ITEM_DRAGONINITE
	.2byte ITEM_MEGANIUMITE
	.2byte ITEM_FERALIGITE
	.2byte ITEM_SKARMORITE
	.2byte ITEM_FROSLASSITE
	.2byte ITEM_EMBOARITE
	.2byte ITEM_EXCADRITE
	.2byte ITEM_SCOLIPITE
	.2byte ITEM_SCRAFTINITE
	.2byte ITEM_EELEKTROSSITE
	.2byte ITEM_CHANDELURITE
	.2byte ITEM_CHESNAUGHTITE
	.2byte ITEM_DELPHOXITE
	.2byte ITEM_GRENINJITE
	.2byte ITEM_PYROARITE
	.2byte ITEM_FLOETTITE
	.2byte ITEM_MALAMARITE
	.2byte ITEM_BARBARACITE
	.2byte ITEM_DRAGALGITE
	.2byte ITEM_HAWLUCHANITE
	.2byte ITEM_ZYGARDITE
	.2byte ITEM_DRAMPANITE
	.2byte ITEM_FALINKSITE
	.2byte ITEM_HEATRANITE
	.2byte ITEM_DARKRANITE
	.2byte ITEM_ZERAORITE
	.2byte ITEM_RAICHUNITE_X
	.2byte ITEM_RAICHUNITE_Y
	.2byte ITEM_CHIMECHITE
	.2byte ITEM_ABSOLITE_Z
	.2byte ITEM_STARAPTITE
	.2byte ITEM_GARCHOMPITE_Z
	.2byte ITEM_LUCARIONITE_Z
	.2byte ITEM_GOLURKITE
	.2byte ITEM_MEOWSTICITE
	.2byte ITEM_CRABOMINITE
	.2byte ITEM_GOLISOPITE
	.2byte ITEM_MAGEARNITE
	.2byte ITEM_SCOVILLAINITE
	.2byte ITEM_BAXCALIBRITE
	.2byte ITEM_TATSUGIRINITE
	.2byte ITEM_GLIMMORANITE
	pokemartlistend

EmeraldTower_Lobby_ZCrystalShop:
	.2byte ITEM_NORMALIUM_Z
	.2byte ITEM_FIRIUM_Z
	.2byte ITEM_WATERIUM_Z
	.2byte ITEM_ELECTRIUM_Z
	.2byte ITEM_GRASSIUM_Z
	.2byte ITEM_ICIUM_Z
	.2byte ITEM_FIGHTINIUM_Z
	.2byte ITEM_POISONIUM_Z
	.2byte ITEM_GROUNDIUM_Z
	.2byte ITEM_FLYINIUM_Z
	.2byte ITEM_PSYCHIUM_Z
	.2byte ITEM_BUGINIUM_Z
	.2byte ITEM_ROCKIUM_Z
	.2byte ITEM_GHOSTIUM_Z
	.2byte ITEM_DRAGONIUM_Z
	.2byte ITEM_DARKINIUM_Z
	.2byte ITEM_STEELIUM_Z
	.2byte ITEM_FAIRIUM_Z
	.2byte ITEM_PIKANIUM_Z
	.2byte ITEM_EEVIUM_Z
	.2byte ITEM_SNORLIUM_Z
	.2byte ITEM_MEWNIUM_Z
	.2byte ITEM_DECIDIUM_Z
	.2byte ITEM_INCINIUM_Z
	.2byte ITEM_PRIMARIUM_Z
	.2byte ITEM_LYCANIUM_Z
	.2byte ITEM_MIMIKIUM_Z
	.2byte ITEM_KOMMONIUM_Z
	.2byte ITEM_TAPUNIUM_Z
	.2byte ITEM_SOLGANIUM_Z
	.2byte ITEM_LUNALIUM_Z
	.2byte ITEM_MARSHADIUM_Z
	.2byte ITEM_ALORAICHIUM_Z
	.2byte ITEM_PIKASHUNIUM_Z
	.2byte ITEM_ULTRANECROZIUM_Z
	pokemartlistend

EmeraldTower_Lobby_Text_TowerChiefWelcome:
	.string "Welcome to the EMERALD TOWER.\p"
	.string "Here, every battle is built for\n"
	.string "strategy from the first turn.\p"
	.string "Take these. They unlock the tower's\n"
	.string "battle gimmicks.$"

EmeraldTower_Lobby_Text_TowerChiefRecruitTeam:
	.string "Now let's build your first team.\p"
	.string "You may recruit up to six POKEMON\n"
	.string "before challenging the tower.$"

EmeraldTower_Lobby_Text_TowerChiefReady:
	.string "Good. Your team is ready.\p"
	.string "Use the lobby staff whenever you want\n"
	.string "to refine your strategy.$"

EmeraldTower_Lobby_Text_TowerChiefRecruitCancel:
	.string "No problem.\p"
	.string "Come back when you want to finish\n"
	.string "building your team.$"

EmeraldTower_Lobby_Text_RecruiterIntro:
	.string "I can introduce you to six battle-ready\n"
	.string "POKEMON today.$"

EmeraldTower_Lobby_Text_RecruiterJoined:
	.string "Excellent choice!\p"
	.string "That POKEMON has joined your team.$"

EmeraldTower_Lobby_Text_RecruiterPartyFull:
	.string "Your party is full.\p"
	.string "Make room, then come see me again.$"

EmeraldTower_Lobby_Text_RecruiterCancel:
	.string "No recruitment today?\p"
	.string "Come back whenever you want.$"

EmeraldTower_Lobby_Text_BattleMusicIntro:
	.string "Pick the music that should play\n"
	.string "during tower battles.$"

EmeraldTower_Lobby_Text_BattleMusicChanged:
	.string "Done.\p"
	.string "Your next tower battle will use\n"
	.string "that track.$"

EmeraldTower_Lobby_Text_BattleHostIntro:
	.string "Ready for a 6-on-6 single battle?\p"
	.string "Choose your opponent group.$"

EmeraldTower_Lobby_Text_BattleHostLeaderPrompt:
	.string "Choose a HOENN GYM LEADER.$"

EmeraldTower_Lobby_Text_BattleHostLeaguePrompt:
	.string "Choose a HOENN LEAGUE opponent.$"

EmeraldTower_Lobby_Text_BattleHostEscort:
	.string "Your opponent is ready.\p"
	.string "I will escort you to the tower ring.$"

EmeraldTower_Lobby_Text_TowerBattleIntro:
	.string "Show me your tower strategy.$"

EmeraldTower_Lobby_Text_TowerBattleDefeat:
	.string "That was a clean win.$"

EmeraldTower_Lobby_Text_TowerBattleDone:
	.string "Battle complete.\p"
	.string "Tune your team, then come back\n"
	.string "for another match.$"
