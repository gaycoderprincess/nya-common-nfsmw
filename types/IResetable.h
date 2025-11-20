class IResetable : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x620250;

	virtual bool HasResetPosition() = 0;
	virtual void ResetVehicle(bool manual) = 0;
	virtual void SetResetPosition(const UMath::Vector3*, const UMath::Vector3*) = 0;
	virtual void ClearResetPosition() = 0;
};