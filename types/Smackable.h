class Smackable {
public:
	static inline auto SimplifySort = (bool(__cdecl*)(Smackable*, Smackable*))0x6709E0;
	static inline auto Construct = (ISimable*(__cdecl*)(Sim::Param params))0x6895A0;
};
#define SMACKABLE_LIST UTL::Listable<Smackable, 160, 0x9357B8>