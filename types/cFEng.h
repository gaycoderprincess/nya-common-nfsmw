class cFEng {
public:
	static inline auto& mInstance = *(cFEng**)0x91CADC;

	static inline auto IsPackagePushed = (bool(__thiscall*)(cFEng*, const char* pPackageName))0x516B50;
};