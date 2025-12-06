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

class EPause : public Event::Event {
public:

	static EPause* Create(int a1, int a2, int a3) {
		return ((EPause*(__thiscall*)(EPause*, int, int, int))0x623A90)((EPause*)::Event::__nw(20), a1, a2, a3);
	}
};

class EQuitToFE : public Event::Event {
public:

	static EQuitToFE* Create(eGarageType a1, const char* a2) {
		return ((EQuitToFE*(__thiscall*)(EQuitToFE*, eGarageType, const char*))0x62FE40)((EQuitToFE*)::Event::__nw(16), a1, a2);
	}
};

class E911Call : public Event::Event {
public:

	static E911Call* Create() {
		return ((E911Call*(*)())0x62A490)();
	}
};

class EDDaySpeech : public Event::Event {
public:

	static EDDaySpeech* Create() {
		return ((EDDaySpeech*(*)())0x62B6B0)();
	}
};

class EResetProps : public Event::Event {
public:

	static EResetProps* Create() {
		return ((EResetProps*(*)())0x6305B0)();
	}
};