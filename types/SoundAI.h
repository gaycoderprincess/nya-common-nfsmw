namespace Csis {
	enum Type_pursuit_type {
		Type_pursuit_type_Generic_Speeder = 1,
		Type_pursuit_type_Possible_Wanted = 2,
		Type_pursuit_type_Hit_and_Run = 4,
		Type_pursuit_type_Reckless = 8,
		Type_pursuit_type_Unit_Rammed = 16,
	};
}

class EAXDispatch {
public:
	static inline auto Report911 = (void(__thiscall*)(EAXDispatch*, Csis::Type_pursuit_type))0x717560;
};

class SoundAI {
public:
	uint8_t _0[0xD8];
	EAXDispatch* mDispatch; // +D8

	static inline auto& mInstance = *(SoundAI**)0x993CC8;
};