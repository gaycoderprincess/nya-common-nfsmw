class ITrafficAI : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x403950;

	virtual void StartDriving(float speed) = 0;
};