class IAttachable : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x402820;

	virtual void Attach(UCOM::IUnknown*) = 0;
	virtual void Detach(UCOM::IUnknown*) = 0;
	virtual bool IsAttached(const UCOM::IUnknown*) = 0;
	virtual void OnAttached(IAttachable*) = 0;
	virtual void OnDetached(IAttachable*) = 0;
	virtual void* GetAttachments() = 0;
};