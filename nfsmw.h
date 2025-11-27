#include <d3d9.h>

struct UCrc32 {
	uint32_t mCRC;
};

typedef uint32_t HSIMABLE;
typedef uint32_t HCAUSE;
typedef uint32_t HMODEL;
typedef uint32_t HSIMPROFILE;
typedef uint32_t HSIMTASK;

#include "types/bNode.h"
#include "types/UMath.h"
#include "types/UCOM.h"
#include "types/ListableSet.h"
#include "types/Attrib.h"
#include "types/VehicleClass.h"
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
#include "types/IHud.h"
#include "types/GRaceStatus.h"
#include "types/EAX_CarState.h"
#include "types/SoundAI.h"
#include "types/cFEng.h"
#include "types/PVehicle.h"
#include "types/Explosion.h"
#include "types/PresetCar.h"
#include "types/AICopManager.h"
#include "types/SimSystem.h"
#include "types/EAXSound.h"

class FEManager {
public:
	static inline auto& mPauseRequest = *(uint32_t*)0x91CAE4;
};

class FadeScreen {
public:
	static inline auto IsFadeScreenOn = (bool(*)())0x569BB0;
};

struct StringRecord {
	uint32_t Hash;
	char* PackedString;
};

auto& NumStringRecords = *(uint32_t*)0x91CF78;
auto& RecordTable = *(StringRecord**)0x91CF80;
auto GetLocalizedString = (const char*(__cdecl*)(uint32_t stringLabel))0x56BC10;
auto SearchForString = (const char*(__fastcall*)(void*, uint32_t))0x56BB80;
auto FEngHashString = (uint32_t(__cdecl*)(const char*, ...))0x573140;
auto Camera_SetGenericCamera = (void(__cdecl*)(const char*, const char*))0x604A50;
auto GetRacingResolution = (void(__stdcall*)(int*, int*))0x6C27D0; // technically a thiscall but ecx is never used!

auto& gMoviePlayer = *(void**)0x91CB10;
auto& g_VisualTreatment = *(bool*)0x901828;

auto& CarScaleMatrix = *(UMath::Matrix4*)0x9B34B0;

#include "nfsmwhooks.h"