class ExplosionParams : public Sim::Param {
public:
	const UMath::Vector3* fPosition;
	float fExpansionSpeed;
	float fRadius;
	float fStartRadius;
	HMODEL fSource;
	bool fEffectSource;
	bool fDamage;
	unsigned int fTargets;

	ExplosionParams() {
		mType.mCRC = Attrib::StringHash32("ExplosionParams");
		mName.mCRC = Attrib::StringHash32("BASE");
		mData = this;
	}
};
static_assert(sizeof(ExplosionParams) == 0x2C);

class Explosion {
public:

	static inline auto Construct = (ISimable*(__cdecl*)(Sim::Param params))0x688ED0;
};