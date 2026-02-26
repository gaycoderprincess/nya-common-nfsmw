class IDisposable : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x404FF0;

	virtual bool IsRequired() = 0;
};