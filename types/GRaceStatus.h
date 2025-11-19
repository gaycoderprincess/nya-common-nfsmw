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

	static inline auto GetNumLaps = (int(__thiscall*)(GRaceParameters*))0x5FBA00;
};

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

class GRaceStatus : public UCOM::Object, UCOM::IUnknown {
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

	static inline auto& fObj = *(GRaceStatus**)0x91E000;
};
//static_assert(sizeof(GRaceStatus) == 0x4558);