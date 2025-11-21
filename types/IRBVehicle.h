enum eInvulnerablitiy {
	INVULNERABLE_NONE = 0,
	INVULNERABLE_FROM_MANUAL_RESET = 1,
	INVULNERABLE_FROM_RESET = 2,
	INVULNERABLE_FROM_CONTROL_SWITCH = 3,
	INVULNERABLE_FROM_PHYSICS_SWITCH = 4,
};

class IRBVehicle : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4039E0;

	virtual void SetCollisionMass(float) = 0;
	virtual void SetCollisionCOG(const UMath::Vector3*) = 0;
	virtual void EnableObjectCollisions(bool) = 0;
	virtual void SetInvulnerability(eInvulnerablitiy, float) = 0;
	virtual eInvulnerablitiy GetInvulnerability() = 0;
	virtual void SetPlayerReactions(Attrib::Instance*) = 0;
	virtual Attrib::Instance* GetPlayerReactions() = 0;
};