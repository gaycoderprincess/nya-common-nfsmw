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
};
static_assert(sizeof(CameraParams) == 0xD4);

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
};
static_assert(sizeof(Camera) == 0x290);

class CameraAI {
public:
	static inline auto SetAction = (void(__cdecl*)(int, const char*))0x479EB0;
};

auto Camera_SetGenericCamera = (void(__cdecl*)(const char*, const char*))0x604A50;