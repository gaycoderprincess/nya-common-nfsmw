enum ePlayerList {
	PLAYER_ALL = 0,
	PLAYER_LOCAL = 1,
	PLAYER_REMOTE = 2,
	PLAYER_MAX = 3,
};

enum ePlayerHudType : uint32_t {
	PHT_NONE = 0,
	PHT_STANDARD = 1,
	PHT_DRAG = 2,
	PHT_SPLIT1 = 3,
	PHT_SPLIT2 = 4,
	PHT_DRAG_SPLIT1 = 5,
	PHT_DRAG_SPLIT2 = 6,
};

class ISimable;
class IHud;
class IFeedback;
class ISteeringWheel;

class IPlayer : public UCOM::IUnknown {
public:
	virtual ISimable* GetSimable() = 0;
	virtual bool IsLocal() = 0;
	virtual const UMath::Vector3* GetPosition() = 0;
	virtual void SetPosition(const UMath::Vector3* position) = 0;
	virtual void* GetSettings() = 0;
	virtual void SetSettings(int fe_index) = 0;
	virtual int GetSettingsIndex() = 0;
	virtual IHud* GetHud() = 0;
	virtual void SetHud(ePlayerHudType) = 0;
	virtual void SetRenderPort(int renderport) = 0;
	virtual int GetRenderPort() = 0;
	virtual void SetControllerPort(int port) = 0;
	virtual int GetControllerPort() = 0;
	virtual IFeedback* GetFFB() = 0;
	virtual ISteeringWheel* GetSteeringDevice() = 0;
	virtual bool InGameBreaker() = 0;
	virtual bool CanRechargeNOS() = 0;
	virtual void ResetGameBreaker(bool full) = 0;
	virtual void ChargeGameBreaker(float amount) = 0;
	virtual void ToggleGameBreaker() = 0;
};

#define PLAYER_LIST UTL::ListableSet<IPlayer, 8, ePlayerList, PLAYER_MAX, 0x92D848>
static_assert(sizeof(PLAYER_LIST::_buckets[0]) == 0x30);