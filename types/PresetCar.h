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
auto& PresetCarList = *(bList<PresetCar>*)0x9B2BF4;

auto FindFEPresetCar = (PresetCar*(__cdecl*)(uint32_t))0x748130;