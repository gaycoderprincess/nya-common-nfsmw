class IRaceEngine : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x668390;

	virtual float GetPerfectLaunchRange(float* range) = 0;
};