class ICheater : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x405240;

	virtual float GetCatchupCheat() = 0;
};