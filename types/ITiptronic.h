class ITiptronic : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x68A8A0;

	virtual void SportShift(GearID) = 0;
};