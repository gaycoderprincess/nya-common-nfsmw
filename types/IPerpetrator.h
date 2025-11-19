class GRacerInfo;

class IPerpetrator : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4037E0;

	virtual float GetHeat() = 0;
	virtual void SetHeat(float heat) = 0;
	virtual Attrib::Instance* GetPursuitEscalationAttrib() = 0;
	virtual Attrib::Instance* GetPursuitLevelAttrib() = 0;
	virtual Attrib::Instance* GetPursuitSupportAttrib() = 0;
	virtual void AddCostToState(int cost) = 0;
	virtual int GetCostToState() = 0;
	virtual void SetCostToState(int cts) = 0;
	virtual bool IsRacing() = 0;
	virtual bool IsBeingPursued() = 0;
	virtual bool IsHiddenFromCars() = 0;
	virtual bool IsHiddenFromHelicopters() = 0;
	virtual bool IsPartiallyHidden() = 0;
	virtual void AddToPendingRepPointsFromCopDestruction(int amount) = 0;
	virtual void AddToPendingRepPointsNormal(int amount) = 0;
	virtual int GetPendingRepPointsNormal() = 0;
	virtual int GetPendingRepPointsFromCopDestruction() = 0;
	virtual void ClearPendingRepPoints() = 0;
	virtual void SetRacerInfo(GRacerInfo* info) = 0;
	virtual GRacerInfo* GetRacerInfo() = 0;
	virtual float GetLastTrafficHitTime() = 0;
	virtual void Set911CallTime(float time) = 0;
	virtual float Get911CallTime() = 0;
};