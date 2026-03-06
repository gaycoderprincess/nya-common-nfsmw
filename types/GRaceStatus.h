class GCharacter;
class GVault;
class WorldModel;
class EmitterGroup;

class GTimer {
public:
	float mStartTime;
	float mTotalTime;
	bool mRunning;

	float GetTime() {
		if (mRunning) {
			return (Sim::GetTime() - mStartTime) + mTotalTime;
		}
		else {
			return mTotalTime;
		}
	}
};

class GRaceIndexData {
public:
	unsigned int mKey;
	char mEventID[10];
	int16_t mChallengeGoal;
	unsigned int mChallengeType;
	unsigned int mRaceHash;
	unsigned int mFlags;
	float mLength;
	short mLocalizationTag;
	int16_t mCash;
	int16_t mReputation;
	uint16_t mRivalBest;
	unsigned char mNumLaps;
	unsigned char mRegion;
	char mCopDensity;
	char mRaceType;
	unsigned char mMapX1;
	unsigned char mMapY1;
	unsigned char mMapX2;
	unsigned char mMapY2;
};
static_assert(sizeof(GRaceIndexData) == 0x30);

namespace GRace {
	enum Context {
		kRaceContext_QuickRace = 0,
		kRaceContext_Online = 1,
		kRaceContext_Career = 2,
		kRaceContext_Count = 3,
	};

	enum Type {
		kRaceType_P2P = 0,
		kRaceType_Circuit = 1,
		kRaceType_Drag = 2,
		kRaceType_Knockout = 3,
		kRaceType_Tollbooth = 4,
		kRaceType_SpeedTrap = 5,
		kRaceType_Checkpoint = 6,
		kRaceType_CashGrab = 7,
		kRaceType_Challenge = 8,
		kRaceType_JumpToSpeedTrap = 9,
		kRaceType_JumpToMilestone = 10,
		kRaceType_NumTypes = 11,
		kRaceType_None = -1,
	};
}

class GRaceParameters {
public:
	GRaceIndexData* mIndex;
	Attrib::Instance* mRaceRecord;
	GVault* mParentVault;
	GVault* mChildVault;

	virtual void GetCheckpointPosition(unsigned int index, UMath::Vector3* pos) = 0;
	virtual void GetCheckpointDirection(unsigned int index, UMath::Vector3* dir) = 0;

	auto GetRaceType() { auto f = (GRace::Type(__thiscall*)(GRaceParameters*))0x5FAA20; return f(this); }
	auto GetChallengeType() { auto f = (int(__thiscall*)(GRaceParameters*))0x5FA9A0; return f(this); }
	auto GetNumLaps() { auto f = (int(__thiscall*)(GRaceParameters*))0x5FBA00; return f(this); }
	auto GetIsLoopingRace() { auto f = (bool(__thiscall*)(GRaceParameters*))0x5FBEE0; return f(this); }
	auto GetIsPursuitRace() { auto f = (bool(__thiscall*)(GRaceParameters*))0x5FBE70; return f(this); }
	auto GetIsDDayRace() { auto f = (bool(__thiscall*)(GRaceParameters*))0x5FBD20; return f(this); }
	auto GetIsBossRace() { auto f = (bool(__thiscall*)(GRaceParameters*))0x5FBD90; return f(this); }
	auto GetEventID() { auto f = (const char*(__thiscall*)(GRaceParameters*))0x5FBA70; return f(this); }
	auto ExtractDirection(Attrib::Instance* collection, UMath::Vector3* dir, float rotate) {
		auto f = (const char*(__thiscall*)(GRaceParameters*, Attrib::Instance* collection, UMath::Vector3* dir, float rotate))0x5DCD00;
		return f(this, collection, dir, rotate);
	}
	auto GetStartPosition(UMath::Vector3* pos) { auto f = (void(__thiscall*)(GRaceParameters*, UMath::Vector3* pos))0x5FAD10; return f(this, pos); }
	auto GetStartDirection(UMath::Vector3* dir) { auto f = (void(__thiscall*)(GRaceParameters*, UMath::Vector3* dir))0x5FAE00; return f(this, dir); }
	auto GetFinishPosition(UMath::Vector3* pos) { auto f = (void(__thiscall*)(GRaceParameters*, UMath::Vector3* pos))0x5FAF70; return f(this, pos); }
	auto GetFinishDirection(UMath::Vector3* dir) { auto f = (void(__thiscall*)(GRaceParameters*, UMath::Vector3* dir))0x5FB060; return f(this, dir); }
	auto GetNumCheckpoints() { auto f = (int(__thiscall*)(GRaceParameters*))0x5FCA40; return f(this); }
	auto GetNumOpponents() { auto f = (int(__thiscall*)(GRaceParameters*))0x5FACD0; return f(this); }
	auto GetPlayerCarType() { auto f = (const char*(__thiscall*)(GRaceParameters*))0x5FC5C0; return f(this); }
	auto GetPlayerCarPerformance() { auto f = (float(__thiscall*)(GRaceParameters*))0x5FC620; return f(this); }
	auto GetNoPostRaceScreen() { auto f = (bool(__thiscall*)(GRaceParameters*))0x5FC320; return f(this); }
};
static_assert(sizeof(GRaceParameters) == 0x14);

class GRacerInfo {
public:
	HSIMABLE mhSimable;
	GCharacter* mGameCharacter;
	const char* mName;
	int mIndex;
	int mRanking;
	int mAiRanking;
	float mPctRaceComplete;
	bool mKnockedOut;
	bool mTotalled;
	bool mEngineBlown;
	bool mBusted;
	bool mChallengeComplete;
	bool mFinishedRacing;
	bool mCameraDetached;
	float mPctLapComplete;
	int mLapsCompleted;
	int mCheckpointsHitThisLap;
	int mTollboothsCrossed;
	float mTimeRemainingToBooth[16];
	int mSpeedTrapsCrossed;
	float mSpeedTrapSpeed[16];
	int mSpeedTrapPosition[16];
	float mDistToNextCheckpoint;
	float mDistanceDriven;
	float mTopSpeed;
	float mFinishingSpeed;
	float mPoundsNOSUsed;
	float mTimeCrossedLastCheck;
	float mTotalUpdateTime;
	int mNumPerfectShifts;
	int mNumTrafficCarsHit;
	float mSpeedBreakerTime;
	float mPointTotal;
	float mZeroToSixtyTime;
	float mQuarterMileTime;
	float mSplitTimes[4];
	int mSplitRankings[4];
	GTimer mRaceTimer;
	GTimer mLapTimer;
	GTimer mCheckTimer;
	UMath::Vector3 mSavedPosition;
	float mSavedHeatLevel;
	UMath::Vector3 mSavedDirection;
	float mSavedSpeed;
	bool mDNF;

	void TotalVehicle() { auto f = (void(__thiscall*)(GRacerInfo*))0x6002C0; return f(this); }
	void BlowEngine() { auto f = (void(__thiscall*)(GRacerInfo*))0x600420; return f(this); }
};
static_assert(sizeof(GRacerInfo) == 0x194);
static_assert(offsetof(GRacerInfo, mRanking) == 0x10);
static_assert(offsetof(GRacerInfo, mKnockedOut) == 0x1C);
static_assert(offsetof(GRacerInfo, mTotalled) == 0x1D);
static_assert(offsetof(GRacerInfo, mEngineBlown) == 0x1E);
static_assert(offsetof(GRacerInfo, mFinishedRacing) == 0x21);

class GRaceBin {
public:
	struct BinStats {
		unsigned short mChallengesCompleted;
		unsigned short mRacesWon;
	};

	Attrib::Instance mBinRecord;
	GVault* mChildVault;
	BinStats mStats;
};

class EventList {
public:
	unsigned int fNumEvents;
	unsigned int fPad[3];
};

class EventStaticData {
public:
	unsigned int fEventID;
	unsigned int fEventSize;
	unsigned int fDataOffset;
	unsigned int fPad;
};

class GRuntimeInstance : public Attrib::Instance {
	class ConnectedInstance {
	public:
		unsigned int mIndexedKey;
		GRuntimeInstance* mInstance;
	};

	unsigned short mFlags;
	unsigned short mNumConnected;
	ConnectedInstance* mConnected;
	GRuntimeInstance* mPrev;
	GRuntimeInstance* mNext;

	virtual void _vf0();
};
static_assert(sizeof(GRuntimeInstance) == 0x28);

class WTrigger {
public:
	UMath::Vector4 fMatRow0Width;
	unsigned int fType:4;
	unsigned int fShape:4;
	unsigned int fFlags:24;
	float fHeight;
	EventList* fEvents;
	unsigned short fIterStamp;
	unsigned short fFingerprint;
	UMath::Vector4 fMatRow2Length;
	UMath::Vector4 fPosRadius;
};

class GIcon;
class GTrigger : public GRuntimeInstance {
public:
	WTrigger mWorldTrigger;
	UMath::Vector3 mDirection;
	unsigned int mTriggerEnabled;
	eastl::vector<ISimable*> mSimObjInside;
	EventList mEventList;
	EventStaticData mEventStaticData;
	unsigned char mTriggerEventData[16];
	EmitterGroup* mParticleEffect[2];
	GIcon* mIcon;
	bool mEnabled;
	int mActivationReferences;
};
static_assert(sizeof(GTrigger) == 0xCC);

class GRaceStatus : public UCOM::Object, IVehicleCache {
public:
	enum PlayMode {
		kPlayMode_Roaming = 0,
		kPlayMode_Racing = 1,
	};

	GRacerInfo mRacerInfo[16];
	int mRacerCount;
	bool mIsLoading;
	PlayMode mPlayMode;
	GRace::Context mRaceContext;
	GRaceParameters* mRaceParms;
	GRaceBin* mRaceBin;
	GTimer mRaceMasterTimer;
	bool mPlayerPursuitInCooldown;
	float mBonusTime;
	float mTaskTime;
	bool mSuddenDeathMode;
	bool mTimeExpiredMsgSent;
	bool mActivelyRacing;
	int mLastSecondTickSent;
	WorldModel* mCheckpointModel;
	EmitterGroup* mCheckpointEmitter;
	bool mQueueBinChange;
	unsigned int mWarpWhenInFreeRoam;
	int mNumTollbooths;
	bool mScriptWaitingForLoad;
	bool mRefreshBinAfterRace;
	eastl::vector<GTrigger*> mCheckpoints;
	GTrigger* mNextCheckpoint;
	float mLapTimes[10][16];
	float mCheckTimes[10][16][16];
	float mSegmentLengths[18];
	float fRaceLength;
	float fFirstLapLength;
	float fSubsequentLapLength;
	bool mCaluclatedAdaptiveGain;
	float fCatchUpIntegral;
	float fCatchUpDerivative;
	float fCatchUpAdaptiveBonus;
	float fAveragePercentComplete;
	int nCatchUpSkillEntries;
	float aCatchUpSkillData[11];
	int nCatchUpSpreadEntries;
	float aCatchUpSpreadData[11];
	int nSpeedTraps;
	GTrigger* aSpeedTraps[16];
	bool mVehicleCacheLocked;
	bool bRaceRouteError;
	int mTrafficDensity;
	unsigned int mTrafficPattern;
	bool mHasBeenWon;

	static inline auto& fObj = *(GRaceStatus**)0x91E000;

	static inline auto DisableBarriers = (void(*)())0x5DBF00;

	auto DetermineRaceLength() { auto f = (void(__thiscall*)(GRaceStatus*))0x5FEF30; return f(this); }
	auto EnableBarriers() { auto f = (void(__thiscall*)(GRaceStatus*))0x5FE330; return f(this); }
	auto GetRaceTimeRemaining() { auto f = (float(__thiscall*)(GRaceStatus*))0x5FE090; return f(this); }
	auto CanUnspawnRoamer(const IVehicle* roamer) { auto f = (bool(__thiscall*)(GRaceStatus*, const IVehicle* roamer))0x5E8960; return f(this, roamer); }
	GRacerInfo* GetRacerInfo(int index) { auto f = (GRacerInfo*(__thiscall*)(GRaceStatus*, int))0x5DBED0; return f(this, index); }
	GRacerInfo* GetRacerInfo(ISimable* isim) { auto f = (GRacerInfo*(__thiscall*)(GRaceStatus*, ISimable*))0x5E8B20; return f(this, isim); }
};
static_assert(sizeof(GRaceStatus) == 0x4558);
static_assert(offsetof(GRaceStatus, mRaceParms) == 0x1968);
static_assert(offsetof(GRaceStatus, mCheckpoints) == 0x19A8);
static_assert(offsetof(GRaceStatus, mCheckpointModel) == 0x1990);
static_assert(offsetof(GRaceStatus, mNextCheckpoint) == 0x19B8);

class GActivity;
class GRaceCustom;
class GRaceSaveInfo;
class GState;

class GActivity : public GRuntimeInstance {
	GState* mCurrentState;
	GState* mRegisteredHandlersState;
};

class GRaceCustom : public GRaceParameters {
public:
	GActivity* mRaceActivity;
	unsigned int mNumOpponents;
	bool mReversed;
	bool mFreedByOwner;
	int mHeatLevel;
};
//static_assert(sizeof(GRaceCustom) == 0x28);
static_assert(offsetof(GRaceCustom, mReversed) == 0x1C);

class GRaceDatabase {
public:
	unsigned int mRaceCountStatic;
	unsigned int mRaceCountDynamic;
	GRaceIndexData* mRaceIndex;
	GRaceParameters* mRaceParameters;
	GRaceCustom* mRaceCustom[4];
	unsigned int mBinCount;
	GRaceBin* mBins;
	void* mGameplayClass;
	GRaceCustom* mStartupRace;
	GRace::Context mStartupRaceContext;
	unsigned int mNumInitialUnlocks;
	unsigned int* mInitialUnlockHash;
	GRaceSaveInfo* mRaceScoreInfo;

	static inline auto& mObj = *(GRaceDatabase**)0x91E004;

	auto GetStartupRace() { auto f = (GRaceParameters*(__thiscall*)(GRaceDatabase*))0x5DCA00; return f(this); }
	auto GetRaceFromHash(uint32_t hash) { auto f = (GRaceParameters*(__thiscall*)(GRaceDatabase*, uint32_t))0x5FB710; return f(this, hash); }
};
static_assert(sizeof(GRaceDatabase) == 0x40);