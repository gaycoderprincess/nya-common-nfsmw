class WCollisionTri;
class WCollisionStrip {
public:
	// this is not actually in any symbols, apparently
	int16_t pt[3]; // +0
	uint16_t numTrisOrSurfaceId; // +6

	static inline auto MakeFace = (void(__thiscall*)(WCollisionStrip*, unsigned int ind, const UMath::Vector3 *cp, WCollisionTri *retFace))0x762530;
};
static_assert(sizeof(WCollisionStrip) == 0x8);
static_assert(offsetof(WCollisionStrip, numTrisOrSurfaceId) == 0x6);

class WCollisionArticle {
public:
	unsigned short fNumStrips;
	unsigned short fStripsSize;
	unsigned short fNumEdges;
	unsigned short fEdgesSize;
	unsigned char fResolvedFlag;
	unsigned char fNumSurfaces;
	unsigned short fSurfacesSize;
	unsigned short fIntermediatObjInd;
	short fFlags;
};
static_assert(sizeof(WCollisionArticle) == 0x10);

class WCollisionStripSphere {
public:
	UMath::Vector3 fPos;
	unsigned short fRadius;
	unsigned short fOffset;
};
static_assert(sizeof(WCollisionStripSphere) == 0x10);

namespace CARP {
	struct CollisionSurface {
		unsigned char fSurface;
		unsigned char fFlags;
	};

	struct CollisionInstance {
		UMath::Vector4 fInvMatRow0Width;
		unsigned short fIterStamp;
		unsigned short fFlags;
		float fHeight;
		unsigned short fGroupNumber;
		unsigned short fRenderInstanceInd;
		const WCollisionArticle* fCollisionArticle;
		UMath::Vector4 fInvMatRow2Length;
		UMath::Vector4 fInvPosRadius;
	};
	static_assert(sizeof(CollisionInstance) == 0x40);
	static_assert(offsetof(CollisionInstance, fCollisionArticle) == 0x1C);

	struct CollisionObject {
		UMath::Vector4 fPosRadius;
		UMath::Vector4 fDimensions;
		unsigned char fType;
		unsigned char fShape;
		unsigned short fFlags;
		unsigned short fRenderInstanceInd;
		CollisionSurface fSurface;
		float fPAD[2];
		UMath::Matrix4 fMat;
	};
}

class WSurface : public CARP::CollisionSurface {};
class WCollisionObject : public CARP::CollisionObject {};

class WCollisionInstance : public CARP::CollisionInstance {
public:

	// inlined
	void MakeMatrix(UMath::Matrix4 *m, bool addXLate) {
		m->x.x = fInvMatRow0Width.x;
		m->x.y = fInvMatRow0Width.y;
		m->x.z = fInvMatRow0Width.z;
		m->xw = 0.0;
		if ((fFlags & 3) != 0) {
			m->y.x = (fInvMatRow0Width.z * fInvMatRow2Length.y) - (fInvMatRow0Width.y * fInvMatRow2Length.z);
			m->y.y = (fInvMatRow2Length.z * fInvMatRow0Width.x) - (fInvMatRow2Length.x * fInvMatRow0Width.z);
			m->y.z = (fInvMatRow2Length.x * fInvMatRow0Width.y) - (fInvMatRow2Length.y * fInvMatRow0Width.x);
		}
		else {
			m->y.x = 0.0;
			m->y.y = 1.0;
			m->y.z = 0.0;
		}
		m->yw = 0.0;
		m->z.x = fInvMatRow2Length.x;
		m->z.y = fInvMatRow2Length.y;
		m->z.z = fInvMatRow2Length.z;
		m->zw = 0.0;
		m->p.x = fInvPosRadius.x;
		m->p.y = fInvPosRadius.y;
		m->p.z = fInvPosRadius.z;
		m->pw = 1.0;
	}
};

class WCollisionTri {
public:
	UMath::Vector3 fPt0;
	Attrib::Collection* fSurfaceRef;
	UMath::Vector3 fPt1;
	uint32_t fFlags;
	UMath::Vector3 fPt2;
	WSurface fSurface;
	uint16_t PAD;
};
static_assert(sizeof(WCollisionTri) == 0x30);

class WCollisionBarrier {
public:
	UMath::Vector4 fPts[2];
};

class WCollisionBarrierListEntry {
public:
	WCollisionBarrier fB;
	Attrib::Collection* fSurfaceRef;
	float fDistanceToSq;
};

class WCollider;
class WCollisionInstanceCacheList;
class WWorldPos {
public:
	WCollisionTri fFace;
	uint32_t fFaceValid : 1;
	uint32_t fMissCount : 15;
	uint32_t fUsageCount : 16;
	float fYOffset;
	Attrib::Collection* fSurface;

	void SetTolerance(float liftAmount) {
		fYOffset = liftAmount;
	}

	static inline auto Update = (bool(__thiscall*)(WWorldPos*, UMath::Vector3* pos, UMath::Vector4* dest, bool usecache, const WCollider* collider, bool keep_valid))0x789CC0;
	static inline auto FindClosestFace = (bool(__thiscall*)(WWorldPos*, WCollisionInstanceCacheList *instList, UMath::Vector3* ptRaw, bool quitIfOnSameFace))0x786750;
};
static_assert(sizeof(WWorldPos) == 0x3C);

class bChunkCarpHeader;
class WCollisionPack {
public:
	unsigned int mSectionNumber;
	unsigned int mInstanceNum;
	WCollisionInstance* mInstanceList;
	unsigned int mObjectNum;
	WCollisionObject* mObjectList;
	bChunkCarpHeader* mCarpChunkHeader;
};
static_assert(sizeof(WCollisionPack) == 0x18);

class WCollisionAssets {
public:
	static inline auto& mCollisionPackList = *(WCollisionPack***)0x9B38A0;
};