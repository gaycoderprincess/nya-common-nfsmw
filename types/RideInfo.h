class RideInfo {
public:
	uint32_t Type; // +0
	uint8_t _0[0x30C];

	static inline auto Init = (void*(__thiscall*)(RideInfo*, int type, CarRenderUsage usage, bool has_dash, bool force_low_rez))0x739A70;
	static inline auto SetRandomPaint = (void(__thiscall*)(RideInfo*))0x759800;
	static inline auto SetStockParts = (void(__thiscall*)(RideInfo*))0x7594A0;
	static inline auto SetRandomParts = (void(__thiscall*)(RideInfo*))0x75B220;
};
static_assert(sizeof(RideInfo) == 0x310);