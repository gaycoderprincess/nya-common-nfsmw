#include <d3d9.h>

struct UCrc32 {
	uint32_t mCRC;
};

typedef uint32_t HSIMABLE;
typedef uint32_t HCAUSE;
typedef uint32_t HMODEL;
typedef uint32_t HSIMPROFILE;
typedef uint32_t HSIMTASK;

auto GAME_malloc = (void*(*)(size_t))0x7C66D0;
auto GAME_free = (void(*)(void*))0x7C7250;

#include "types/bNode.h"
#include "types/UMath.h"
#include "types/UCOM.h"
#include "types/ListableSet.h"
#include "types/Attrib.h"
#include "types/VehicleClass.h"
#include "types/FEManager.h"
#include "types/Event.h"
#include "types/Chyron.h"
#include "types/Physics.h"
#include "types/RideInfo.h"
#include "types/FEPlayerCarDB.h"
#include "types/GarageMainScreen.h"
#include "types/UserProfile.h"
#include "types/GameFlowManager.h"
#include "types/FEMarkerManager.h"
#include "types/WWorldPos.h"
#include "types/IAttachable.h"
#include "types/IPlayer.h"
#include "types/ISimable.h"
#include "types/IBody.h"
#include "types/IVehicle.h"
#include "types/IEngine.h"
#include "types/IRaceEngine.h"
#include "types/IDragEngine.h"
#include "types/IEngineDamage.h"
#include "types/IPerpetrator.h"
#include "types/IDamageable.h"
#include "types/IDamageableVehicle.h"
#include "types/IVehicleAI.h"
#include "types/ITrafficAI.h"
#include "types/IPursuitAI.h"
#include "types/IHumanAI.h"
#include "types/IRigidBody.h"
#include "types/ICopMgr.h"
#include "types/ITrafficMgr.h"
#include "types/IInput.h"
#include "types/IInputPlayer.h"
#include "types/IResetable.h"
#include "types/ICheater.h"
#include "types/ISpikeable.h"
#include "types/ITransmission.h"
#include "types/IDragTransmission.h"
#include "types/IRacer.h"
#include "types/IRBVehicle.h"
#include "types/ISuspension.h"
#include "types/ITiptronic.h"
#include "types/ICollisionBody.h"
#include "types/INIS.h"
#include "types/IVehicleCache.h"
#include "types/IPursuit.h"
#include "types/IGameState.h"
#include "types/ISceneryModel.h"
#include "types/IDisposable.h"
#include "types/IHud.h"
#include "types/SimSystem.h"
#include "types/GRaceStatus.h"
#include "types/EAX_CarState.h"
#include "types/SoundAI.h"
#include "types/cFEng.h"
#include "types/PVehicle.h"
#include "types/Explosion.h"
#include "types/PresetCar.h"
#include "types/AICopManager.h"
#include "types/AITrafficManager.h"
#include "types/EAXSound.h"
#include "types/Camera.h"
#include "types/eView.h"
#include "types/eModel.h"
#include "types/StringRecord.h"
#include "types/GrandSceneryCullInfo.h"
#include "types/eEffect.h"
#include "types/WCollisionMgr.h"
#include "types/WRoadNav.h"
#include "types/Scheduler.h"
#include "types/FEObject.h"
#include "types/CarPartDatabase.h"

class BuildRegion {
public:
	static inline auto IsPal = (bool(*)())0x64A110;
};

class RaceStarter {
public:
	static inline auto StartCareerFreeRoam = (void(*)())0x56C5B0;
};

class FadeScreen {
public:
	static inline auto IsFadeScreenOn = (bool(*)())0x569BB0;
};

class NISListenerActivity {
public:
	static inline auto MessageBusted = (void(__thiscall*)(NISListenerActivity*, int))0x44DC70;
};

class PauseMenu {
public:
	static inline auto IsTuningAvailable = (bool(*)())0x510900;
};

class ICEManager {
public:
	static inline auto SetGenericCameraToPlay = (void(__thiscall*)(ICEManager*, const char*, const char*))0x46E2D0;
};

class SimpleRigidBody {
public:
	static inline auto& mCount = *(int*)0x9377D0;
};
#define DISPOSABLE_LIST UTL::Listable<IDisposable, 160, 0x92CA88>

class FreeBlock;
class AllocDesc;
class FastMem {
public:
	FreeBlock* mFreeLists[64];
	const char* mName;
	unsigned int mExpansionSize;
	unsigned int mLocks;
	bool mInited;
	void* mBlock;
	unsigned int mBytes;
	unsigned int mUsed;
	unsigned int mAlloc[64];
	unsigned int mAvail[64];
	unsigned int mAllocOver;
	AllocDesc* mTrack;
	unsigned int mTrackMax;
	unsigned int mTrackCount;
};
static_assert(sizeof(FastMem) == 0x32C);
static_assert(offsetof(FastMem, mBytes) == 0x114);

auto ExecuteRenderData = (void(*)())0x6E2F50;

auto FEngHashString = (uint32_t(*)(const char*, ...))0x573140;
auto FEHashUpper = (uint32_t(*)(const char*))0x5AF1C0;
auto bStringHashUpper = (uint32_t(*)(const char*))0x460BC0;
auto bInitTicker = (void(*)(float))0x45CDD0;
auto GetRacingResolution = (void(__stdcall*)(int*, int*))0x6C27D0; // technically a thiscall but ecx is never used!

auto Game_StartRace = (void(*)(GRuntimeInstance* raceActivity))0x60DBD0;
auto Game_AbandonRace = (void(*)())0x60DEB0;
auto Game_PlayTutorial = (void(*)())0x6124E0;

auto LZCompress = (uint32_t(*)(uint8_t *pSrc, uint32_t sourceSize, uint8_t *pDst))0x65B350;
auto LZDecompress = (uint32_t(*)(uint8_t* pSrc, uint8_t* pDst))0x650350;
auto JLZCompress = (uint32_t(*)(uint8_t *pSrc, uint32_t sourceSize, uint8_t *pDst))0x65AFF0;
auto JLZDecompress = (uint32_t(*)(uint8_t* pSrc, uint8_t* pDst))0x64DB40;
auto HUFFCompress = (uint32_t(*)(uint8_t *pSrc, uint32_t sourceSize, uint8_t *pDst))0x650120;
auto HUFF_decompress = (uint32_t(*)(uint8_t* pSrc, uint8_t* pDst))0x64DCA0;
uint32_t HUFFDecompress(uint8_t* pSrc, uint8_t* pDest) {
	auto pSrc32 = (uint32_t*)pSrc;
	if (*pSrc32 != 0x46465548 || pSrc[4] != 1) return 0;
	HUFF_decompress(pSrc + 0x10, pDest);
	return pSrc32[2];
}

auto GPS_Engage = (void(*)(const UMath::Vector3*, float))0x42C830;
auto GPS_Disengage = (void(*)())0x41ACE0;
auto& gGPSDestination = *(UMath::Vector3*)0x91E0BC;

auto& gMoviePlayer = *(void**)0x91CB10;
auto& g_MotionBlurEnable = *(bool*)0x9017DC;
auto& g_VisualTreatment = *(bool*)0x901828;
auto& g_WorldLodLevel = *(int*)0x9017F4;
auto& g_RacingResolution = *(int*)0x90181C;
auto& FirstTime = *(bool*)0x901820;

class SlotPool;
auto bNewSlotPool = (SlotPool*(*)(int slot_size, int num_slots, const char *debug_name, int memory_pool))0x4662E0;
auto& CarLoaderPoolSizes = *(uint32_t*)0x8F7EF0;

auto& Tweak_InfiniteNOS = *(bool*)0x937804;

auto& CarScaleMatrix = *(UMath::Matrix4*)0x9B34B0;
auto& DrawCars = *(bool*)0x903320;
auto& DrawSmear = *(bool*)0x8F9218;
auto& DrawLightFlares = *(bool*)0x8F2918;
auto& UnlockAllThings = *(bool*)0x926124;
auto& WorldTimeElapsed = *(float*)0x925970;

auto& SkipFE = *(bool*)0x926064;
auto& SkipFEPlayerCar = *(const char**)0x8F86A8;
auto& SkipMovies = *(bool*)0x926144;

auto& GameWindow = *(HWND*)0x982BF4;
auto& GameD3D = *(IDirect3D9**)0x982BD8;
auto& GameD3DDevice = *(IDirect3DDevice9**)0x982BDC;

#include "nfsmwhooks.h"
#include "nfsmwhelpers.h"