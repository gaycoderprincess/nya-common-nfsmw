class IDamageableVehicle : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x620FD0;

	virtual bool IsLightDamaged(VehicleFX::ID) = 0;
	virtual void DamageLight(VehicleFX::ID, bool) = 0;
};