enum EEFFECT_ID : uint32_t {
	EEFFECT_WORLD = 0x0,
	EEFFECT_WORLDREFLECT = 0x1,
	EEFFECT_WORLDBONE = 0x2,
	EEFFECT_WORLDNORMALMAP = 0x3,
	EEFFECT_CAR = 0x4,
	EEFFECT_GLOSSYWINDOW = 0x5,
	EEFFECT_TREE = 0x6,
	EEFFECT_WORLDMIN = 0x7,
	EEFFECT_WORLDNOFOG = 0x8,
	EEFFECT_FE = 0x9,
	EEFFECT_FEMASK = 0xA,
	EEFFECT_FILTER = 0xB,
	EEFFECT_OVERBRIGHT = 0xC,
	EEFFECT_SCREENFILTER = 0xD,
	EEFFECT_RAINDROP = 0xE,
	EEFFECT_RUNWAYLIGHT = 0xF,
	EEFFECT_VISUALTREATMENT = 0x10,
	EEFFECT_WORLDPRELIT = 0x11,
	EEFFECT_PARTICLES = 0x12,
	EEFFECT_SKY = 0x13,
	EEFFECT_SHADOWMAPMESH = 0x14,
	EEFFECT_SKYBOXCURRENTGEN = 0x15,
	EEFFECT_SHADOWPOLYCURRENTGEN = 0x16,
	EEFFECT_CARSHADOWMAP = 0x17,
	//EEFFECT_WORLDDEPTH = 0x18,
	EEFFECT_WATERSEA,
	//EEFFECT_WORLDNORMALMAPDEPTH = 0x19,
	EEFFECT_GRASSNORMALMAP,
	//EEFFECT_CARSHADERDEPTH = 0x1A,
	EEFFECT_CARNORMALMAP,
	EEFFECT_DEBUGPOLY,
	EEFFECT_GRASS,
	EEFFECT_SNADOWMAPMESHDEPTH = 0x1D,
	EEFFECT_WORLDNORMALMAPNOFOG = 0x1E,
};

class eEffect {
public:
	EEFFECT_ID ID;
	uint32_t mStreamStride;
	uint32_t mTechniqueNum;
	void* mTechnique;
	uint32_t mPasses;
	int mShaderLevels[4];
	int mMaxShaderLevel;
	int mShadowLevels[4];
	int mMaxShadowLevel;
	bool mHasPixelShaders;
	bool mIsPixelShader;
	void* mParamTable;
	ID3DXEffect* hD3DXEffect;
	IDirect3DVertexDeclaration9* VertexDecl;

	virtual void dtor() = 0;
	virtual void Start() = 0;
	virtual void End() = 0;
};
auto eEffects = (eEffect**)0x93DE78;

class eEffectStaticState {
public:
	static inline auto& pCurrentEffect = *(eEffect**)0x982C80;
};

// not the official name, xan named it this
auto ParticleSetTransform = (void(__cdecl*)(UMath::Matrix4*, uint32_t))0x6C8000;