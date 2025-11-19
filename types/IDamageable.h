namespace DamageZone {
	class Info;
}

class IDamageable : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x405000;

	virtual void SetInShock(float) = 0;
	virtual void SetShockForce(float) = 0;
	virtual bool InShock() = 0;
	virtual void ResetDamage() = 0;
	virtual float GetHealth() = 0;
	virtual bool IsDestroyed() = 0;
	virtual void Destroy() = 0;
	virtual DamageZone::Info* GetZoneDamage(DamageZone::Info*) = 0;
};