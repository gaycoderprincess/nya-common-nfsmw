class IGameState : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x6E9970;

	virtual bool InGameBreaker() = 0;
	virtual void RaceReset() = 0;
};