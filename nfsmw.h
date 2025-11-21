#include <d3d9.h>

enum CarRenderUsage : uint32_t {
	CarRenderUsage_Player,
	CarRenderUsage_RemotePlayer,
	CarRenderUsage_AIRacer,
	CarRenderUsage_AICop,
	CarRenderUsage_AITraffic,
	CarRenderUsage_AIHeli,
	carRenderUsage_NISCar,
	CarRenderUsage_Ghost,
	CarRenderUsage_Invalid,
};

struct UCrc32 {
	uint32_t mCRC;
};

#include "types/bNode.h"
#include "types/UMath.h"
#include "types/UCOM.h"
#include "types/ListableSet.h"
#include "types/Attrib.h"
#include "types/Event.h"
#include "types/Physics.h"
#include "types/RideInfo.h"
#include "types/FEPlayerCarDB.h"
#include "types/GarageMainScreen.h"
#include "types/UserProfile.h"
#include "types/GameFlowManager.h"
#include "types/FEMarkerManager.h"
#include "types/WWorldPos.h"
#include "types/IPlayer.h"
#include "types/ISimable.h"
#include "types/IBody.h"
#include "types/IVehicle.h"
#include "types/IEngine.h"
#include "types/IEngineDamage.h"
#include "types/IPerpetrator.h"
#include "types/IDamageable.h"
#include "types/IVehicleAI.h"
#include "types/ITrafficAI.h"
#include "types/IHumanAI.h"
#include "types/IRigidBody.h"
#include "types/ICopMgr.h"
#include "types/IInput.h"
#include "types/IResetable.h"
#include "types/ICheater.h"
#include "types/ISpikeable.h"
#include "types/ITransmission.h"
#include "types/INIS.h"
#include "types/GRaceStatus.h"
#include "types/EAX_CarState.h"
#include "types/SoundAI.h"
#include "types/cFEng.h"
#include "types/PVehicle.h"

class FEManager {
public:
	static inline auto& mPauseRequest = *(uint32_t*)0x91CAE4;
};

class FadeScreen {
public:
	static inline auto IsFadeScreenOn = (bool(*)())0x569BB0;
};

class EAXSound {
public:
	static inline auto ReStartRace = (void(__thiscall*)(EAXSound*, bool is321))0x4C2170;
};
auto& g_pEAXSound = *(EAXSound**)0x911FA8;

auto GetLocalizedString = (const char*(__cdecl*)(uint32_t stringLabel))0x56BC10;
auto FEngHashString = (uint32_t(__cdecl*)(const char*, ...))0x573140;
auto Camera_SetGenericCamera = (void(__cdecl*)(const char*, const char*))0x604A50;
auto SummonChyron = (void(__cdecl*)(const char*, const char*, const char*))0x595ED0;

#include "nfsmwhooks.h"