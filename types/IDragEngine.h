class IDragEngine : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x68A9E0;

	virtual float GetOverRev() = 0;
	virtual float GetHeat() = 0;
};