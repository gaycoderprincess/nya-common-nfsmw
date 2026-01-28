struct StringRecord {
	uint32_t Hash;
	const char* PackedString;
};

auto& NumStringRecords = *(uint32_t*)0x91CF78;
auto& RecordTable = *(StringRecord**)0x91CF80;
auto GetLocalizedString = (const char*(__cdecl*)(uint32_t stringLabel))0x56BC10;
auto SearchForString = (const char*(__fastcall*)(void*, uint32_t))0x56BB80;
auto CalcLanguageHash = (uint32_t(*)(const char*, GRaceParameters*))0x56E560;