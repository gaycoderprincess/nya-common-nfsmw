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