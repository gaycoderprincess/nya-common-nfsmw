class FECarRecord {
public:
	uint32_t Handle; // +0
	uint32_t FEKey; // +4
	uint32_t VehicleKey; // +8
	uint32_t FilterBits; // +C
	int8_t Customization; // +10
	int8_t CareerHandle; // +11
	uint8_t _12[0x2];

	static inline auto GetDebugName = (const char*(__thiscall*)(FECarRecord*))0x581BF0;
	static inline auto GetType = (uint32_t(__thiscall*)(FECarRecord*))0x5816B0;
};
static_assert(sizeof(FECarRecord) == 0x14);

enum eCustomTuningType {
	CTT_SETTING_1 = 0,
	CTT_SETTING_2 = 1,
	CTT_SETTING_3 = 2,
	NUM_CUSTOM_TUNINGS = 3,
};

class PresetCar : public bTNode<PresetCar> {
public:
	char CarTypeName[32];
	char PresetName[32];
	unsigned long long FEKey;
	unsigned long long VehicleKey;
	unsigned int FilterBits;
	int PhysicsLevel;
	int PartNameHashes[139];
};
static_assert(sizeof(PresetCar) == 0x290);

auto FindFEPresetCar = (PresetCar*(__cdecl*)(uint32_t))0x748130;

class FECustomizationRecord {
public:
	short InstalledPartIndices[139];
	Physics::Upgrades::Package InstalledPhysics;
	Physics::Tunings Tunings[3];
	eCustomTuningType ActiveTuning;
	int Preset;
	uint8_t Handle;

	static inline auto Default = (void(__thiscall*)(FECustomizationRecord*))0x56F1B0;
	static inline auto BecomePreset = (void(__thiscall*)(FECustomizationRecord*, PresetCar* preset))0x56F340;
	static inline auto WriteRecordIntoRide = (void(__thiscall*)(FECustomizationRecord*, RideInfo* ride))0x56F2B0;
	static inline auto WriteRideIntoRecord = (void(__thiscall*)(FECustomizationRecord*, const RideInfo* ride))0x56F2F0;
};
static_assert(sizeof(FECustomizationRecord) == 0x198);

struct FEImpoundData {
	uint8_t mMaxBusted;
	uint8_t mTimesBusted;
	uint16_t Pad1;
};
static_assert(sizeof(FEImpoundData) == 0x4);

struct FEInfractionsData {
	uint16_t Speeding;
	uint16_t Racing;
	uint16_t Reckless;
	uint16_t Assault;
	uint16_t HitAndRun;
	uint16_t Damage;
	uint16_t Resist;
	uint16_t OffRoad;
};
static_assert(sizeof(FEInfractionsData) == 0x10);

class FECareerRecord {
public:
	uint8_t Handle; // +0
	uint8_t _1;
	FEImpoundData TheImpoundData; // +2
	uint8_t _6[0x6];
	float VehicleHeat; // +C
	uint32_t Bounty; // +10
	uint16_t NumEvadedPursuits; // +14
	uint16_t NumBustedPursuits; // +16
	FEInfractionsData UnservedInfractions; // +18
	FEInfractionsData ServedInfractions; // +28
};
static_assert(sizeof(FECareerRecord) == 0x38);

class FEPlayerCarDB {
public:
	FECarRecord CarTable[200]; // +0
	FECustomizationRecord Customizations[75]; // +FA0
	FECareerRecord CareerRecords[25]; // +8728

	static inline auto GetCarRecordByHandle = (FECarRecord*(__thiscall*)(FEPlayerCarDB*, uint32_t handle))0x56ECC0;
	static inline auto GetCustomizationRecordByHandle = (FECustomizationRecord*(__thiscall*)(FEPlayerCarDB*, int8_t handle))0x56F100;
	static inline auto GetCareerRecordByHandle = (FECareerRecord*(__thiscall*)(FEPlayerCarDB*, int8_t handle))0x56F120;

	static inline auto CreateNewCareerCar = (FECarRecord*(__thiscall*)(FEPlayerCarDB*, uint32_t fromCar))0x599D20;
	static inline auto CreateNewCustomCar = (FECarRecord*(__thiscall*)(FEPlayerCarDB*, uint32_t fromCar))0x599CF0;
	static inline auto CreateNewPresetCar = (FECarRecord*(__thiscall*)(FEPlayerCarDB*, const char* name))0x590A20;
	static inline auto AwardRivalCar = (FECarRecord*(__thiscall*)(FEPlayerCarDB*, uint32_t car))0x5A41E0;

	static inline auto BuildRideForPlayer = (void(__thiscall*)(FEPlayerCarDB*, uint32_t car, int player, RideInfo* ride))0x5910E0;
};