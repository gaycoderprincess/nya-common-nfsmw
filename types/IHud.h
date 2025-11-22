class IHud : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x565030;

	static inline auto DetermineHudFeatures = (uint32_t(__thiscall*)(IHud*, IPlayer*))0x57CA60;

	virtual void Update(IPlayer*, float) = 0;
	virtual void Release() = 0;
	virtual void HideAll() = 0;
	virtual void FadeAll(bool) = 0;
	virtual bool AreResourcesLoaded() = 0;
	virtual bool IsHudVisible() = 0;
	virtual void SetInPursuit(bool) = 0;
	virtual void SetHasTurbo(bool) = 0;
	virtual void JoyEnable() = 0;
	virtual void JoyDisable() = 0;
	virtual void RefreshMiniMapItems() = 0;
};