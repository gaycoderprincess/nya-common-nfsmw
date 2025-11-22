class ISceneryModel : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x620FE0;

	virtual void GetSceneryTransform(UMath::Matrix4*) = 0;
	virtual void RestoreScene() = 0;
	virtual int GetSpawnerID() = 0;
	virtual void WakeUp() = 0;
	virtual bool IsExcluded(uint32_t) = 0;
};