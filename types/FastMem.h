class FreeBlock;
class AllocDesc;
class FastMem {
public:
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
};
static_assert(sizeof(FastMem) == 0x32C);
static_assert(offsetof(FastMem, mBytes) == 0x114);