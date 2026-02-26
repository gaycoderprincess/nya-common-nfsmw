namespace Sim {
	class Param {
	public:
		UCrc32 mType;
		UCrc32 mName;
		void* mData;
		unsigned int pad;
	};
}

class IVehicleCache;

class VehicleParams : public Sim::Param {
public:
	DriverClass carClass;
	unsigned int carType;
	const UMath::Vector3* initialVec;
	const UMath::Vector3* initialPos;
	FECustomizationRecord* customization;
	IVehicleCache* VehicleCache = nullptr;
	Physics::Info::Performance* matched = nullptr;
	unsigned int Flags = 0;

	VehicleParams() {
		mType.mCRC = Attrib::StringHash32("VehicleParams");
		mName.mCRC = Attrib::StringHash32("BASE");
		mData = this;
	}
};
static_assert(sizeof(VehicleParams) == 0x30);

class PVehicle {
public:
	uint8_t _0[0x140];
	DriverClass mDriverClass; // +140
	DriverStyle mDriverStyle; // +144

	static inline auto Construct = (ISimable*(__cdecl*)(Sim::Param params))0x689820;
	static inline auto LookupBehaviorSignature = (UCrc32*(__thiscall*)(PVehicle*, UCrc32 *result, const Attrib::StringKey *mechanic))0x67F0D0;
};
static_assert(offsetof(PVehicle, mDriverClass) == 0x140);

auto& BEHAVIOR_MECHANIC_AI = *(Attrib::StringKey*)0x92C5E8;
auto& BEHAVIOR_MECHANIC_AUDIO = *(Attrib::StringKey*)0x92C560;
auto& BEHAVIOR_MECHANIC_DAMAGE = *(Attrib::StringKey*)0x92C610;
auto& BEHAVIOR_MECHANIC_DRAW = *(Attrib::StringKey*)0x92C588;
auto& BEHAVIOR_MECHANIC_EFFECTS = *(Attrib::StringKey*)0x92C5C8;
auto& BEHAVIOR_MECHANIC_ENGINE = *(Attrib::StringKey*)0x92C598;
auto& BEHAVIOR_MECHANIC_INPUT = *(Attrib::StringKey*)0x9261B0;
auto& BEHAVIOR_MECHANIC_RESET = *(Attrib::StringKey*)0x926188;
auto& BEHAVIOR_MECHANIC_RIGIDBODY = *(Attrib::StringKey*)0x92C5D8;
auto& BEHAVIOR_MECHANIC_SUSPENSION = *(Attrib::StringKey*)0x92C650;