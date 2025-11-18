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

#include "types/bNode.h"
#include "types/UMath.h"
#include "types/UCOM.h"
#include "types/ListableSet.h"
#include "types/Attrib.h"
#include "types/RideInfo.h"
#include "types/FEPlayerCarDB.h"
#include "types/GarageMainScreen.h"
#include "types/UserProfile.h"
#include "types/GameFlowManager.h"
#include "types/FEMarkerManager.h"
#include "types/IPlayer.h"

auto GetLocalizedString = (const char*(__cdecl*)(uint32_t stringLabel))0x56BC10;

#include "nfsmwhooks.h"