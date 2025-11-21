class IInputPlayer : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x403F80;

	virtual void BlockInput(bool) = 0;
	virtual bool IsBlocked() = 0;
	virtual void FlushInput() = 0;
	virtual void FetchInput() = 0;
	virtual void ClearInput() = 0;
};