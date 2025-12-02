class TextureInfo;
class eDynamicLightContext;
class eRenderTarget;
class ScreenEffectDB;
class Rain;
class FacePixelation;
class CameraMover;
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
};
static_assert(sizeof(CameraParams) == 0xD4);

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
};
static_assert(sizeof(Camera) == 0x290);

enum EVIEW_ID {
	EVIEW_FIRST = 0,
	EVIEW_FLAILER = 0,
	NUM_RVM_VIEWS = 1,
	EVIEW_FIRST_PLAYER = 1,
	EVIEW_FIRST_RENDER = 1,
	EVIEW_PLAYER1 = 1,
	EVIEW_PLAYER2 = 2,
	NUM_PLAYER_VIEWS = 3,
	EVIEW_LAST_RVM = 3,
	EVIEW_FIRST_RVM = 3,
	EVIEW_LAST_PLAYER = 3,
	EVIEW_PLAYER1_RVM = 3,
	EVIEW_PLAYER1_GLOW = 4,
	EVIEW_PLAYER2_GLOW = 5,
	EVIEW_PLAYER1_SPECULAR = 6,
	EVIEW_PLAYER2_SPECULAR = 7,
	EVIEW_QUADRANT_TOP_LEFT = 8,
	EVIEW_QUADRANT_TOP_RIGHT = 9,
	EVIEW_QUADRANT_BOTTOM_LEFT = 10,
	EVIEW_QUADRANT_BOTTOM_RIGHT = 11,
	EVIEW_HDR_SCENE = 12,
	EVIEW_SHADOWMAP1 = 13,
	EVIEW_SHADOWMAP2 = 14,
	EVIEW_SHADOWMATTE = 15,
	EVIEW_FIRST_ENVMAP = 16,
	EVIEW_ENVMAP0F = 16,
	EVIEW_ENVMAP0R = 17,
	EVIEW_ENVMAP0B = 18,
	EVIEW_ENVMAP0L = 19,
	EVIEW_ENVMAP0U = 20,
	NUM_RENDER_VIEWS = 21,
	EVIEW_LAST_ENVMAP = 21,
	EVIEW_LAST_RENDER = 21,
	EVIEW_LAST = 21,
	EVIEW_ENVMAP0D = 21,
	NUM_EVIEWS = 22,
	EVIEW_NONE = -1,
};

class eViewPlatInfo {
public:
	bMatrix4 ViewMatrix;
	bMatrix4 ProjectionMatrix;
	bMatrix4 ProjectionZBiasMatrix;
	bMatrix4 ViewProjectionMatrix;
	bMatrix4 ViewProjectionZBiasMatrix;
	bVector4 ClippingPlanes[6];
};

class eViewPlatInterface {
public:
	eViewPlatInfo* PlatInfo;

	static inline auto GetScreenPosition = (void(__thiscall*)(eViewPlatInterface*, bVector3* screen_position, const bVector3* world_position))0x6BE940;
};

class eView : public eViewPlatInterface {
public:
	EVIEW_ID ID; // +4
	char Active; // +8
	char LetterBox;
	char pad0;
	char pad1;
	float H; // +C
	uint8_t _10[0x14];
	int PixelMinSize; // +24
	uint8_t _28[0x8];
	bVector3 ViewDirection; // +30
	Camera* pCamera; // +40
	bTList<CameraMover> CameraMoverList; // +44
	unsigned int NumCopsInView; // +4C
	unsigned int NumCopsTotal; // +50
	unsigned int NumCopsCherry; // +54
	TextureInfo* pBlendMask; // +58
	eDynamicLightContext* WorldLightContext; // +5C
	eRenderTarget* RenderTargetTable[1]; // +60
	ScreenEffectDB* ScreenEffects; // +64
	Rain* Precipitation; // +68
	FacePixelation* facePixelation; // +6C
};
static_assert(sizeof(eView) == 0x70);

auto eViews = (eView*)0x9195E0;