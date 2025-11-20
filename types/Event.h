namespace Event {
	static inline auto __nw = (void*(__cdecl*)(uint32_t size))0x627400;

	class Event {
	public:
		uint32_t fEventSize;

		virtual void _dtor();
		virtual const char* GetEventName();
	};
	static_assert(sizeof(Event) == 0x8);
}

class ERestartRace : public Event::Event {
public:

	static ERestartRace* Create() {
		return ((ERestartRace*(__thiscall*)(ERestartRace*))0x6307F0)((ERestartRace*)::Event::__nw(8));
	}
};

enum eGarageType {
	GARAGETYPE_NONE = 0,
	GARAGETYPE_MAIN_FE = 1,
	GARAGETYPE_CAREER_SAFEHOUSE = 2,
	GARAGETYPE_CUSTOMIZATION_SHOP = 3,
	GARAGETYPE_CUSTOMIZATION_SHOP_BACKROOM = 4,
	GARAGETYPE_CAR_LOT = 5,
};

class EQuitToFE : public Event::Event {
public:

	static EQuitToFE* Create(eGarageType a1, const char* a2) {
		return ((EQuitToFE*(__thiscall*)(EQuitToFE*, eGarageType, const char*))0x62FE40)((EQuitToFE*)::Event::__nw(16), a1, a2);
	}
};