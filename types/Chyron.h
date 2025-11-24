class Chyron {
public:
	static inline auto& mTitle = *(const char**)0x8F3C48;
	static inline auto& mArtist = *(const char**)0x8F3C4C;
	static inline auto& mAlbum = *(const char**)0x8F3C50;
};
auto SummonChyron = (void(__cdecl*)(const char*, const char*, const char*))0x595ED0;