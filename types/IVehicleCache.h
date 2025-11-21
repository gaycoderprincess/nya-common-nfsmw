enum eVehicleCacheResult {
	VCR_WANT = 0,
	VCR_DONTCARE = 1,
};

class IVehicleCache : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x404030;

	virtual const char* GetCacheName() = 0;
	virtual eVehicleCacheResult OnQueryVehicleCache(const IVehicle*, const IVehicleCache*) = 0;
	virtual void OnRemovedVehicleCache(IVehicle*) = 0;
};