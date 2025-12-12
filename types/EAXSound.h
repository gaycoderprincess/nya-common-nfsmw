enum eSNDCTLSTATE {
	SNDSTATE_OFF = 0,
	SNDSTATE_PAUSE = 1,
	SNDSTATE_INGAME = 2,
	SNDSTATE_FE = 3,
	SNDSTATE_FE_UPSCREEN = 4,
	SNDSTATE_FE_SMS_MESSAGE = 5,
	SNDSTATE_NIS_STORY = 6,
	SNDSTATE_NIS_INTRO = 7,
	SNDSTATE_NIS_321 = 8,
	SNDSTATE_NIS_BLK = 9,
	SNDSTATE_NIS_ARREST = 10,
	SNDSTATE_FMV = 11,
	SNDSTATE_STOP_MUSIC = 12,
	SNDSTATE_GAMESTARTRACE = 13,
	SNDSTATE_MINILOAD = 14,
	SNDSTATE_FADEOUT = 15,
	SNDSTATE_ERROR = 16,
	SNDSTATE_SYSTEM_HUD = 17,
	MAX_SNDCTL_STATES = 18,
};

class EAXSound {
public:
	static inline auto Update = (void(__thiscall*)(EAXSound*, float t))0x4D0610;
	static inline auto ReStartRace = (void(__thiscall*)(EAXSound*, bool is321))0x4C2170;
	static inline auto CloseSound = (void(__thiscall*)(EAXSound*))0x4D09A0;
	static inline auto AreResourceLoadsPending = (bool(__thiscall*)(EAXSound*))0x4B8C40;
	static inline auto LoadInGameSoundBanks = (void(__thiscall*)(EAXSound*, const char*, const char*))0x4D1630;
	static inline auto UnLoadInGameSoundBanks = (void(__thiscall*)(EAXSound*))0x4D17E0;
};
auto& g_pEAXSound = *(EAXSound**)0x911FA8;

auto ServiceQueuedFiles = (void(__cdecl*)())0x661C70;
auto SetSoundControlState = (void(__cdecl*)(bool, eSNDCTLSTATE))0x4B9080;