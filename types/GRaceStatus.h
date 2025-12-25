enum Context {
	kRaceContext_QuickRace = 0,
	kRaceContext_Online = 1,
	kRaceContext_Career = 2,
	kRaceContext_Count = 3,
};

class GCharacter;
class GVault;
class WorldModel;
class EmitterGroup;

class GTimer {
public:
	float mStartTime;
	float mTotalTime;
	bool mRunning;
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

class GRaceParameters {
public:
	GRaceIndexData* mIndex;
	Attrib::Instance* mRaceRecord;
	GVault* mParentVault;
	GVault* mChildVault;

	virtual void _vf0();

	static inline auto GetRaceType = (int(__thiscall*)(GRaceParameters*))0x5FAA20;
	static inline auto GetNumLaps = (int(__thiscall*)(GRaceParameters*))0x5FBA00;
	static inline auto GetIsLoopingRace = (bool(__thiscall*)(GRaceParameters*))0x5FBEE0;
	static inline auto GetIsPursuitRace = (bool(__thiscall*)(GRaceParameters*))0x5FBE70;
	static inline auto GetEventID = (const char*(__thiscall*)(GRaceParameters*))0x5FBA70;
};
static_assert(sizeof(GRaceParameters) == 0x14);

class GRacerInfo {
public:
	HSIMABLE mhSimable;
	GCharacter* mGameCharacter;
	char* mName;
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
	Context mRaceContext;
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
};
//static_assert(sizeof(GRaceCustom) == 0x28);

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
	Context mStartupRaceContext;
	unsigned int mNumInitialUnlocks;
	unsigned int* mInitialUnlockHash;
	GRaceSaveInfo* mRaceScoreInfo;

	static inline auto& mObj = *(GRaceDatabase**)0x91E004;
};
static_assert(sizeof(GRaceDatabase) == 0x40);