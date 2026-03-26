class eView;

struct CameraParams {
	bMatrix4 Matrix;
	bVector3 Position;
	bVector3 Direction;
	bVector3 Target;
	bVector4 NoiseFrequency1;
	bVector4 NoiseAmplitude1;
	bVector4 NoiseFrequency2;
	bVector4 NoiseAmplitude2;
	float TargetDistance;
	float FocalDistance;
	float DepthOfField;
	float NearZ;
	float FarZ;
	unsigned short FieldOfView;
	float LB_height;
	float SimTimeMultiplier;
	unsigned short DummyAngle;
	uint8_t _D4[0xC];
};
static_assert(sizeof(CameraParams) == 0xE0);

class JollyRancherResponsePacket {
public:
	int UseMatrix;
	int Pad1;
	int Pad2;
	int Pad3;
	bMatrix4 CamMatrix;
};

class Camera {
public:
	CameraParams CurrentKey;
	CameraParams PreviousKey;
	CameraParams VelocityKey;
	bool bClearVelocity;
	float ElapsedTime;
	int LastUpdateTime;
	int LastDisparateTime;
	int RenderDash;

	static inline auto& JollyRancherResponse = *(JollyRancherResponsePacket*)0x911190;
	static inline auto& StopUpdating = *(bool*)0x911020;

	auto SetCameraMatrix(const bMatrix4* m, float fTime) { auto f = (void(__thiscall*)(Camera*, const bMatrix4*, float))0x4700D0; return f(this, m, fTime); }
};
//static_assert(sizeof(Camera) == 0x290);

enum CameraMoverTypes {
	CM_NONE_TYPE = 0,
	CM_DRIVE_CUBIC = 1,
	CM_DEBUG_WORLD = 2,
	CM_ROAD_EDITOR = 3,
	CM_ORBIT_CAR = 4,
	CM_REAR_VIEW_MIRROR = 5,
	CM_TRACK_CAR = 6,
	CM_TRACK_COP = 7,
	CM_MAX = 8,
	CM_SELECT_CAR = 9,
	CM_STILL = 10,
	CM_ZONE_FREEZE = 11,
	CM_ZONE_PREVIEW = 12,
	CM_AUTO_PILOT = 13,
	CM_ICE = 14,
	CM_ANIMATION_CONTROLLER = 15,
	CM_COP_VIEW = 16,
	CM_ANIMATION_ENTITY = 17,
	CM_SHOWCASE = 18,
};

class ICollisionHandler {
public:
	virtual bool OnWCollide(const WCollisionMgr::WorldCollisionInfo*, const UMath::Vector3*, void*);
};

class CameraAnchor;
class CameraMover : public bTNode<CameraMover>, ICollisionHandler {
public:
	CameraMoverTypes Type;
	int ViewID;
	int Enabled;
	eView* pView;
	Camera* pCamera;
	int RenderDash;
	WCollider* mCollider;
	WWorldPos mWPos;
	float fAccumulatedClearance;
	float fAccumulatedAdjust;
	float fSavedAdjust;
	bVector3 vSavedForward;

	virtual void _dtor();
	virtual void Update(float);
	virtual void Render(eView *);
	virtual const CameraAnchor* GetAnchor();
	virtual void SetLookBack(bool);
	virtual void SetLookbackSpeed(float);
	virtual void SetPovType(int);
	virtual bool OutsidePOV();
	virtual bool RenderCarPOV();
	virtual float MinDistToWall();
	virtual float GetLookbackAngle();
	virtual void ResetState();
	virtual void Enable();
	virtual void Disable();
	virtual bool IsHoodCamera();
	virtual const bVector3 *GetTarget();
};
static_assert(sizeof(CameraMover) == 0x80);

struct POV {
	short Type;
	unsigned short Angle;
	float Lag;
	float Height;
	float LatOffset;
	unsigned short Fov;
	float Stiffness;
	short AllowTilting;
	float pad4[2];
};

class CameraAnchor {
public:
	bVector3 mVelocity;
	float mVelMag;
	float mTopSpeed;
	bVector3 mGeomPos;
	bVector3 mDimension;
	bVector3 mAccel;
	bMatrix4 mGeomRot;
	int mModel;
	unsigned int mWorldID;
	Attrib::Gen::simsurface mSurface;
	float mCollisionDamping;
	float mDrift;
	float mGroundCollision;
	float mObjectCollision;
	bool mIsNosEngaged;
	bool mIsBrakeEngaged;
	bool mIsDragRace;
	bool mIsOverRev;
	bool mIsTouchingGround;
	bool mIsVehicleDestroyed;
	bool mIsGearChanging;
	bool mIsCloseToRoadBlock;
	float mZoom;
	POV mPOV;
	Attrib::Gen::ecar mModelAttributes;
	Attrib::Gen::camerainfo mCameraInfoAttributes;
};

class tCubic1D {
public:
	float Val;
	float dVal;
	float ValDesired;
	float dValDesired;
	float Coeff[4];
	float time;
	float duration;
	short state;
	short flags;
};

class tCubic2D {
public:
	tCubic1D x;
	tCubic1D y;
};

class tCubic3D {
public:
	tCubic1D x;
	tCubic1D y;
	tCubic1D z;
};

template<typename T>
class tAverage {
public:
	// AverageBase
	uint8_t nSize;
	uint8_t nSlots;
	uint8_t nSamples;
	uint8_t nCurrentSlot;

	T* pData;
	T Total;
	T Average;

	virtual void _dtor();
	virtual void Recalculate();
};

class CubicCameraMover : public CameraMover {
public:
	CameraAnchor* pCar;
	tCubic1D* pFov;
	tCubic3D* pEye;
	tCubic3D* pLook;
	tCubic3D* pForward;
	tCubic3D* pUp;
	int nPovType;
	int nPovTypeUsed;
	bool bAccelLag;
	bool bLookBack;
	bool bSnapNext;
	bool bPerfectFocus;
	bool bFirstTime;
	uint32_t tLastGrounded;
	uint32_t tLastUnderVehicle;
	uint32_t tLastGearChange;
	float fIgnoreSetSnapNextTimer;
	uint8_t _B8[0x38];
	//bVector3 vSavedEye;
	//bVector2 vCameraImpcat;
	//bVector2 vCameraImpcatTimer;
	//tAverage<bVector3>* pAvgAccel;
};
static_assert(sizeof(CubicCameraMover) == 0xF0);
static_assert(offsetof(CubicCameraMover, pCar) == 0x80);
static_assert(offsetof(CubicCameraMover, bLookBack) == 0xA1);
static_assert(offsetof(CubicCameraMover, tLastGrounded) == 0xA8);
static_assert(offsetof(CubicCameraMover, tLastUnderVehicle) == 0xAC);
static_assert(offsetof(CubicCameraMover, tLastGearChange) == 0xB0);
static_assert(offsetof(CubicCameraMover, fIgnoreSetSnapNextTimer) == 0xB4);
//static_assert(offsetof(CubicCameraMover, pAvgAccel) == 0xE0);

class CameraAI {
public:
	static inline auto SetAction = (void(__cdecl*)(int, const char*))0x479EB0;
};

auto Camera_SetGenericCamera = (void(*)(const char*, const char*))0x604A50;
auto& Tweak_ForceICEReplay = *(bool*)0x91103A;