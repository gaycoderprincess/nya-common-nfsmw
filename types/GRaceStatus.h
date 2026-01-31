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

	static inline auto GetRaceType = (GRace::Type(__thiscall*)(GRaceParameters*))0x5FAA20;
	static inline auto GetChallengeType = (int(__thiscall*)(GRaceParameters*))0x5FA9A0;
	static inline auto GetNumLaps = (int(__thiscall*)(GRaceParameters*))0x5FBA00;
	static inline auto GetIsLoopingRace = (bool(__thiscall*)(GRaceParameters*))0x5FBEE0;
	static inline auto GetIsPursuitRace = (bool(__thiscall*)(GRaceParameters*))0x5FBE70;
	static inline auto GetIsDDayRace = (bool(__thiscall*)(GRaceParameters*))0x5FBD20;
	static inline auto GetIsBossRace = (bool(__thiscall*)(GRaceParameters*))0x5FBD90;
	static inline auto GetEventID = (const char*(__thiscall*)(GRaceParameters*))0x5FBA70;
	static inline auto ExtractDirection = (const char*(__stdcall*)(Attrib::Instance* collection, UMath::Vector3* dir, float rotate))0x5DCD00;
	static inline auto GetStartPosition = (void(__thiscall*)(GRaceParameters*, UMath::Vector3* pos))0x5FAD10;
	static inline auto GetStartDirection = (void(__thiscall*)(GRaceParameters*, UMath::Vector3* dir))0x5FAE00;
	static inline auto GetFinishPosition = (void(__thiscall*)(GRaceParameters*, UMath::Vector3* pos))0x5FAF70;
	static inline auto GetFinishDirection = (void(__thiscall*)(GRaceParameters*, UMath::Vector3* dir))0x5FB060;
	static inline auto GetNumCheckpoints = (int(__thiscall*)(GRaceParameters*))0x5FCA40;
	static inline auto GetNumOpponents = (int(__thiscall*)(GRaceParameters*))0x5FACD0;
	static inline auto GetPlayerCarType = (const char*(__thiscall*)(GRaceParameters*))0x5FC5C0;
	static inline auto GetPlayerCarPerformance = (float(__thiscall*)(GRaceParameters*))0x5FC620;
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

	static inline auto TotalVehicle = (void(__thiscall*)(GRacerInfo*))0x6002C0;
	static inline auto BlowEngine = (void(__thiscall*)(GRacerInfo*))0x600420;
};
static_assert(sizeof(GRacerInfo) == 0x194);

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

	static inline auto DetermineRaceLength = (void(__thiscall*)(GRaceStatus*))0x5FEF30;
	static inline auto DisableBarriers = (void(*)())0x5DBF00;
	static inline auto EnableBarriers = (void(__thiscall*)(GRaceStatus*))0x5FE330;
	static inline auto GetRaceTimeRemaining = (float(__thiscall*)(GRaceStatus*))0x5FE090;
	static inline auto CanUnspawnRoamer = (bool(__thiscall*)(GRaceStatus*, const IVehicle* roamer))0x5E8960;
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

	static inline auto GetStartupRace = (GRaceParameters*(__thiscall*)(GRaceDatabase*))0x5DCA00;
	static inline auto GetRaceFromHash = (GRaceParameters*(__thiscall*)(GRaceDatabase*, uint32_t))0x5FB710;
};
static_assert(sizeof(GRaceDatabase) == 0x40);