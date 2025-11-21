class ITrafficMgr : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x403A00;

	static inline auto& mInstance = *(ITrafficMgr**)0x92C674;

	virtual void FlushAllTraffic(bool) = 0;
};