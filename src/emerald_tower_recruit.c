#include "global.h"
#include "event_data.h"
#include "pokemon.h"

void DoEmeraldTowerRecruitSelectScreen(void);

u16 Script_EmeraldTowerIsPartyFull(void)
{
    gSpecialVar_Result = CalculatePlayerPartyCount() >= PARTY_SIZE;
    return gSpecialVar_Result;
}

u16 Script_OpenEmeraldTowerRecruitMenu(void)
{
    DoEmeraldTowerRecruitSelectScreen();
    return 0;
}
