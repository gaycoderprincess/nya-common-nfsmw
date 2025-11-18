struct CollisionSurface {
	unsigned char fSurface;
	unsigned char fFlags;
};

class WSurface : public CollisionSurface {};

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

class WWorldPos {
public:
	WCollisionTri fFace;
	uint32_t fFaceValid : 1;
	uint32_t fMissCount : 15;
	uint32_t fUsageCount : 16;
	float fYOffset;
	Attrib::Collection* fSurface;
};
static_assert(sizeof(WWorldPos) == 0x3C);