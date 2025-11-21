class IBody : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4039D0;

	virtual UMath::Matrix4* GetTransform(UMath::Matrix4*) = 0;
	virtual UMath::Vector3* GetLinearVelocity(UMath::Vector3*) = 0;
	virtual UMath::Vector3* GetAngularVelocity(UMath::Vector3*) = 0;
	virtual UMath::Vector3* GetDimension(UMath::Vector3*) = 0;
	virtual Attrib::Instance* GetAttributes() = 0;
	virtual int GetWorldID() = 0;
};