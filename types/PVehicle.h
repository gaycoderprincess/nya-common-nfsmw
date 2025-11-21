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

	static inline auto Construct = (ISimable*(__cdecl*)(Sim::Param params))0x689820;
};