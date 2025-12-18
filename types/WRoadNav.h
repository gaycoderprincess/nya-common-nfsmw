class AIVehicle;

// todo
class SplinePointList {
public:
	uint8_t _0[0x8];
};

class USpline {
public:
	enum SplineType {
		kSpline_Bezier = 0,
		kSpline_CatMulRom = 1,
		kSpline_Invalid = 2,
		kSpline_Count = 2,
	};

	UMath::Matrix4 fSplineMat;
	UMath::Vector4 fLookAt[2];
	SplineType fSplineType;
	SplinePointList fSplinePtList;
	uint8_t _6C[0x4];
};
static_assert(sizeof(USpline) == 0x70);

template <typename T, int capacity>
class CookieTrail {
	int mCount;
	int mLast;
	const int mCapacity;
	int pad;
	T mData[capacity];
};

class NavCookie {
public:
	enum eFlags {
		kCutByObject = 1,
		kCutFromBehind = 2,
	};

	UMath::Vector2 Left;
	UMath::Vector2 Right;
	UMath::Vector2 Forward;
	float Length;
	float Curvature;
	float LeftOffset;
	float RightOffset;
	unsigned int Flags;
	float Padding;
	UMath::Vector3 Centre;
	short SegmentParameter;
	unsigned short SegmentNumber:15;
	unsigned short SegmentNodeInd:1;
};
static_assert(sizeof(NavCookie) == 0x40);

class WRoadNav {
public:
	enum ENavType {
		kTypeNone = 0,
		kTypeTraffic = 1,
		kTypeDirection = 2,
		kTypePath = 3,
	};

	enum EPathType {
		kPathCop = 0,
		kPathNone = 1,
		kPathRacer = 2,
		kPathGPS = 3,
		kPathPlayer = 4,
		kPathChopper = 5,
		kPathRaceRoute = 6,
	};

	enum ELaneType {
		kLaneRacing = 0,
		kLaneTraffic = 1,
		kLaneDrag = 2,
		kLaneCop = 3,
		kLaneCopReckless = 4,
		kLaneReset = 5,
		kLaneStartingGrid = 6,
		kLaneAny = 7,
		kLaneMax = 8,
	};

	int nCookieIndex;
	CookieTrail<NavCookie,32>* pCookieTrail;
	NavCookie mCurrentCookie;
	float mOutOfBounds;
	bool fValid;
	bool bRaceFilter;
	bool bTrafficFilter;
	bool bCopFilter;
	bool bDecisionFilter;
	bool bCookieTrail;
	int nRoadOcclusion;
	int nAvoidableOcclusion;
	bool bOccludedFromBehind;
	float fOccludingTrailSpeed;
	bVector2 vCookieTrailBoxMin;
	bVector2 vCookieTrailBoxMax;
	ENavType fNavType;
	EPathType fPathType;
	ELaneType fLaneType;
	AIVehicle* pAIVehicle;
	float fVehicleHalfWidth;
	char fNodeInd;
	short fSegmentInd;
	float fSegTime;
	float fCurvature;
	UMath::Vector3 fPosition;
	UMath::Vector3 fLeftPosition;
	UMath::Vector3 fRightPosition;
	UMath::Vector3 fForwardVector;
	UMath::Vector3 fEndPos;
	UMath::Vector3 fStartPos;
	UMath::Vector3 fEndControl;
	UMath::Vector3 fStartControl;
	UMath::Vector3 fLeftEndPos;
	UMath::Vector3 fLeftStartPos;
	UMath::Vector3 fLeftEndControl;
	UMath::Vector3 fLeftStartControl;
	UMath::Vector3 fRightEndPos;
	UMath::Vector3 fRightStartPos;
	UMath::Vector3 fRightEndControl;
	UMath::Vector3 fRightStartControl;
	UMath::Vector3 fApexPosition;
	UMath::Vector3 fOccludedPosition;
	USpline fRoadSpline;
	USpline fLeftSpline;
	USpline fRightSpline;
	char fDeadEnd;
	char fLaneInd;
	char fFromLaneInd;
	char fToLaneInd;
	float fLaneOffset;
	float fFromLaneOffset;
	float fToLaneOffset;
	float fLaneChangeDist;
	float fLaneChangeInc;
	uint8_t _2D8[0x18];
	//bool bCrossedPathGoal;
	//unsigned short nPathGoalSegment;
	//float fPathGoalParam;
	//int nPathSegments;
	//unsigned short* pPathSegments;

	WRoadNav() {
		((void(__thiscall*)(WRoadNav*))0x77B9E0)(this);
	}
	~WRoadNav() {
		((void(__thiscall*)(WRoadNav*))0x76E220)(this);
	}

	static inline auto InitAtPoint = (bool(__thiscall*)(WRoadNav*, const UMath::Vector3* pos, const UMath::Vector3* dir, bool forceCenterLane, float dirWeight))0x7862D0;

	virtual void _dtor() {};
};
static_assert(sizeof(WRoadNav) == 0x2F0);
static_assert(offsetof(WRoadNav, fNodeInd) == 0x8C);
static_assert(offsetof(WRoadNav, fSegTime) == 0x90);
static_assert(offsetof(WRoadNav, fForwardVector) == 0xBC);
static_assert(offsetof(WRoadNav, fRoadSpline) == 0x170);
static_assert(offsetof(WRoadNav, fLeftSpline) == 0x1E0);
static_assert(offsetof(WRoadNav, fRightSpline) == 0x250);
static_assert(offsetof(WRoadNav, fLaneOffset) == 0x2C4);