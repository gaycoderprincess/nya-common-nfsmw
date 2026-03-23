class ISuspension : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x404040;

	virtual float GetWheelTraction(uint32_t);
	virtual int GetNumWheels();
	virtual const UMath::Vector3* GetWheelPos(uint32_t);
	virtual const UMath::Vector3* GetWheelLocalPos(uint32_t);
	virtual UMath::Vector3* GetWheelCenterPos(UMath::Vector3*, uint32_t);
	virtual float GetWheelLoad(uint32_t);
	virtual void ApplyVehicleEntryForces(bool, const UMath::Vector3*, bool);
	virtual float GetWheelRoadHeight(uint32_t);
	virtual bool IsWheelOnGround(uint32_t);
	virtual float GetCompression(uint32_t);
	virtual float GuessCompression(uint32_t, float);
	virtual float GetWheelSlip(uint32_t);
	virtual float GetToleratedSlip(uint32_t);
	virtual float GetWheelSkid(uint32_t);
	virtual float GetWheelSlipAngle(uint32_t);
	virtual const UMath::Vector4* GetWheelRoadNormal(uint32_t);
	virtual const Attrib::Instance* GetWheelRoadSurface(uint32_t);
	virtual const UMath::Vector3* GetWheelVelocity(uint32_t);
	virtual int GetNumWheelsOnGround();
	virtual float GetWheelAngularVelocity(uint32_t);
	virtual void SetWheelAngularVelocity(uint32_t, float);
	virtual float GetWheelSteer(uint32_t);
	virtual float CalculateUndersteerFactor();
	virtual float CalculateOversteerFactor();
	virtual float GetRideHeight(uint32_t idx);
	virtual float GetWheelRadius(uint32_t);
	virtual float GetMaxSteering();
	virtual void MatchSpeed(float);
	virtual float GetRenderMotion();
};