class IDragTransmission : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x68A830;

	virtual float GetShiftBoost() = 0;
};