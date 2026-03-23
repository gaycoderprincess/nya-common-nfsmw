class IEngineDamage : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x604250;

	virtual bool IsBlown();
	virtual void Blow();
	virtual void Sabotage(float time);
	virtual bool IsSabotaged();
	virtual void Repair();
};