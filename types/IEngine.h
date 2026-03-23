class IEngine : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x404020;

	virtual float GetRPM();
	virtual float GetRedline();
	virtual float GetMaxRPM();
	virtual float GetMinRPM();
	virtual float GetPeakTorqueRPM();
	virtual void MatchSpeed(float speed);
	virtual float GetNOSCapacity();
	virtual bool IsNOSEngaged();
	virtual float GetNOSFlowRate();
	virtual float GetNOSBoost();
	virtual bool HasNOS();
	virtual void ChargeNOS(float);
	virtual float GetMaxHorsePower();
	virtual float GetMinHorsePower();
	virtual float GetHorsePower();
};