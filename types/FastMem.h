class FastMem {
public:
	class FreeBlock;
	class AllocDesc;

	FreeBlock* mFreeLists[64];
	const char* mName;
	unsigned int mExpansionSize;
	unsigned int mLocks;
	bool mInited;
	void* mBlock;
	unsigned int mBytes;
	unsigned int mUsed;
	unsigned int mAlloc[64];
	unsigned int mAvail[64];
	unsigned int mAllocOver;
	AllocDesc* mTrack;
	unsigned int mTrackMax;
	unsigned int mTrackCount;

	auto Alloc(size_t bytes, const char* kind) { auto f = (void*(__thiscall*)(FastMem*, size_t, const char*))0x5D29D0; return f(this, bytes, kind); }
	auto Free(void* ptr, size_t bytes, const char* kind) { auto f = (void(__thiscall*)(FastMem*, void*, size_t, const char*))0x5D0370; return f(this, ptr, bytes, kind); }
};
static_assert(sizeof(FastMem) == 0x32C);
static_assert(offsetof(FastMem, mBytes) == 0x114);

auto& gFastMem = *(FastMem*)0x925B30;