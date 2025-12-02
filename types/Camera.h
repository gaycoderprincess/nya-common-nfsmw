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
	static inline auto SetCameraMatrix = (void(__thiscall*)(Camera*, const bMatrix4*, float))0x4700D0;
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

class CameraMover {// : public bTNode<CameraMover>, ICollisionHandler {
public:
	uint8_t _0[0xC];
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
};
static_assert(sizeof(CameraMover) == 0x80);

class CameraAI {
public:
	static inline auto SetAction = (void(__cdecl*)(int, const char*))0x479EB0;
};

auto Camera_SetGenericCamera = (void(__cdecl*)(const char*, const char*))0x604A50;