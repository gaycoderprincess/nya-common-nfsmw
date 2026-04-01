class IInductable : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x68A910;

	virtual int GetInductionType();
	virtual float InductionSpool();
	virtual float GetInductionPSI();
	virtual float GetMaxInductionPSI();
};