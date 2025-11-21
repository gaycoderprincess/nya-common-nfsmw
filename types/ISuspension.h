class ISuspension : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x404040;

	virtual float GetWheelTraction(uint32_t) = 0;
	virtual int GetNumWheels() = 0;
	virtual const UMath::Vector3* GetWheelPos(uint32_t) = 0;
	virtual const UMath::Vector3* GetWheelLocalPos(uint32_t) = 0;
	virtual const UMath::Vector3* GetWheelCenterPos(uint32_t) = 0;
	virtual float GetWheelLoad() = 0;
	virtual void ApplyVehicleEntryForces(bool, const UMath::Vector3*, bool) = 0;
	virtual float GetWheelRoadHeight(uint32_t) = 0;
	virtual bool IsWheelOnGround(uint32_t) = 0;
	virtual float GetCompression(uint32_t) = 0;
	virtual float GuessCompression(uint32_t, float) = 0;
	virtual float GetWheelSlip(uint32_t) = 0;
	virtual float GetToleratedSlip(uint32_t) = 0;
	virtual float GetWheelSkid(uint32_t) = 0;
	virtual float GetWheelSlipAngle(uint32_t) = 0;
	virtual const UMath::Vector4* GetWheelRoadNormal(uint32_t) = 0;
	virtual const Attrib::Instance* GetWheelRoadSurface(uint32_t) = 0;
	virtual const UMath::Vector3* GetWheelVelocity(uint32_t) = 0;
	virtual int GetNumWheelsOnGround() = 0;
	virtual float GetWheelAngularVelocity(uint32_t) = 0;
	virtual void SetWheelAngularVelocity(uint32_t, float) = 0;
	virtual float GetWheelSteer(uint32_t) = 0;
	virtual float CalculateUndersteerFactor() = 0;
	virtual float CalculateOversteerFactor() = 0;
	virtual float GetRideHeight(uint32_t) = 0;
	virtual float GetWheelRadius(uint32_t) = 0;
	virtual float GetMaxSteering() = 0;
	virtual void MatchSpeed(float) = 0;
	virtual void* GetRenderMotion() = 0;
};