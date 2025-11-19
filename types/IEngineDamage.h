class IEngineDamage : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x604250;

	virtual bool IsBlown() = 0;
	virtual void Blow() = 0;
	virtual void Sabotage(float time) = 0;
	virtual bool IsSabotaged() = 0;
	virtual void Repair() = 0;
};