class TextureInfo;
class eDynamicLightContext;
class eRenderTarget;
class ScreenEffectDB;
class Rain;
class FacePixelation;
class Camera;
class CameraMover;
class eView;
class eModel;
class eLightContext;

enum EVIEW_ID {
	EVIEW_NONE = 0xFFFFFFFF,
	EVIEW_FLAILER = 0,
	EVIEW_PLAYER1,
	EVIEW_PLAYER2,
	EVIEW_PLAYER1_RVM,
	EVIEW_PLAYER1_REFLECTION,
	EVIEW_PLAYER2_REFLECTION,
	EVIEW_PLAYER1_GLOW,
	EVIEW_PLAYER2_GLOW,
	EVIEW_PLAYER1_SPECULAR,
	EVIEW_PLAYER2_SPECULAR,
	EVIEW_QUADRANT_BOTTOM_RIGHT,
	EVIEW_QUADRANT_BOTTOM_LEFT,
	EVIEW_QUADRANT_TOP_RIGHT,
	EVIEW_QUADRANT_TOP_LEFT,
	EVIEW_HDR_SCENE,
	EVIEW_SHADOWMAP1,
	EVIEW_SHADOWMAP2,
	EVIEW_SHADOWMATTE,
	EVIEW_ENVMAP0F,
	EVIEW_ENVMAP0R,
	EVIEW_ENVMAP0B,
	EVIEW_ENVMAP0L,
	EVIEW_ENVMAP0U,
	EVIEW_ENVMAP0D,

	EVIEW_FIRST = EVIEW_FLAILER,
	EVIEW_LAST = EVIEW_ENVMAP0D,
	EVIEW_FIRST_RENDER = EVIEW_PLAYER1,
	EVIEW_LAST_RENDER = EVIEW_ENVMAP0D,
	EVIEW_FIRST_PLAYER = EVIEW_PLAYER1,
	EVIEW_LAST_PLAYER = EVIEW_PLAYER2,
	EVIEW_FIRST_RVM = EVIEW_PLAYER1_RVM,
	EVIEW_LAST_RVM = EVIEW_PLAYER1_RVM,
	EVIEW_FIRST_ENVMAP = EVIEW_ENVMAP0F,
	EVIEW_LAST_ENVMAP = EVIEW_ENVMAP0D,
	NUM_EVIEWS = (EVIEW_LAST - EVIEW_FIRST) + 1,
	NUM_RENDER_VIEWS = 1 + (EVIEW_LAST_RENDER - EVIEW_FIRST_RENDER),
	NUM_PLAYER_VIEWS = 1 + (EVIEW_LAST_PLAYER - EVIEW_FIRST_PLAYER),
	NUM_RVM_VIEWS = 0x1,
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
	static inline auto Render = (void(__thiscall*)(eViewPlatInterface*, eModel* model, bMatrix4* local_world, eLightContext* light_context, unsigned int flags, bMatrix4* blending_matricies))0x6DA9B0;
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

	static inline auto GetVisibleState = (int(__thiscall*)(eView*, const bVector3* aabb_min, const bVector3* aabb_max, bMatrix4* local_world))0x6CF2B0;
};
static_assert(sizeof(eView) == 0x70);

auto eViews = (eView*)0x9195E0;

class eLightContext {
public:
	int Type;
};

class eDynamicLightContext : public eLightContext {
public:
	uint8_t _0[0x12C];
};
static_assert(sizeof(eDynamicLightContext) == 0x130);

class eShaperLightRig;
auto& ShaperLightsBackRoom = *(eShaperLightRig*)0x8F2B50;
auto& ShaperLightsCarLot = *(eShaperLightRig*)0x8F2BF0;
auto& ShaperLightsCShop = *(eShaperLightRig*)0x8F2C90;
auto& ShaperLightsQRace = *(eShaperLightRig*)0x8F2D30;
auto& ShaperLightsSafehouse = *(eShaperLightRig*)0x8F2DD0;
auto& ShaperLightsCarsInGame = *(eShaperLightRig*)0x8F2E70;
auto& ShaperLightsCharacters = *(eShaperLightRig*)0x8F2F10;

static inline auto eFrameMalloc = (void*(*)(size_t))0x405E80;
static inline auto elSetupLightContext = (int(*)(eDynamicLightContext *light_context, eShaperLightRig *shaper_lights, bMatrix4 *local_world, bMatrix4 *world_view, bVector4 *camera_world_position, eView *view))0x502520;