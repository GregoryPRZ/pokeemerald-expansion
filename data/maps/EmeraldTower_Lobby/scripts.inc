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
	goto_if_eq VAR_RESULT, TRUE, EmeraldTower_Lobby_EventScript_CheckPokemonBox
	giveitem ITEM_TERA_ORB

EmeraldTower_Lobby_EventScript_CheckPokemonBox::
	checkitem ITEM_POKEMON_BOX_LINK
	goto_if_eq VAR_RESULT, TRUE, EmeraldTower_Lobby_EventScript_GimmickItemSetDone
	giveitem ITEM_POKEMON_BOX_LINK

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

EmeraldTower_Lobby_EventScript_TrainerHelp::
	lock
	faceplayer
	msgbox EmeraldTower_Lobby_Text_TrainerHelp, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_RelearnerHelp::
	lock
	faceplayer
	msgbox EmeraldTower_Lobby_Text_RelearnerHelp, MSGBOX_DEFAULT
	release
	end

EmeraldTower_Lobby_EventScript_BoxesHelp::
	lock
	faceplayer
	msgbox EmeraldTower_Lobby_Text_BoxesHelp, MSGBOX_DEFAULT
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

EmeraldTower_Lobby_Text_BoxesHelp:
	.string "Unfortunately, there isn't any PC\n"
	.string "in the facility.\p"
	.string "But you can still access to\n"
	.string "your boxes in the Party Menu,\p"
	.string "by pressing 'R'.\p"
	.string "You also can access them with\n"
	.string "the Pokémon Box Link key item.$"

EmeraldTower_Lobby_Text_TrainerHelp:
	.string "Did you know you can train your\n"
	.string "Pokémon?\p"
	.string "You can do so in the Party Menu, by\n"
	.string "choosing the 'Train' option.\p"
	.string "You can change EVs, Nature and\n"
	.string "Ability of your Pokémon this way.$"

EmeraldTower_Lobby_Text_RelearnerHelp:
	.string "The move relearner can teach\n"
	.string "your Pokémon new moves!\p"
	.string "You can do so in the Summary Screen, by\n"
	.string "pressing 'Start' in the moves page.$"
