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