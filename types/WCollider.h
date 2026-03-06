class WCollisionInstance;
class WCollisionObject;
class WCollisionTriBlock : public eastl::vector<WCollisionTri> {};
class WCollisionInstanceCacheList : public eastl::vector<WCollisionInstance*> {};
class WCollisionBarrierList : public eastl::vector<WCollisionBarrierListEntry> {};
class WCollisionTriList : public eastl::vector<WCollisionTriBlock*> {};
class WCollisionObjectList : public eastl::vector<WCollisionObject*> {};

class WCollider {
public:
	enum eColliderShape {
		kColliderShape_Sphere = 0,
		kColliderShape_Cylinder = 1,
		kColliderShape_FORCE_INT = 0x7FFFFFFF,
	};

	UMath::Vector3 fRequestedPosition;
	float fRequestedRadius;
	UMath::Vector3 fLastRequestedPosition;
	float fLastRequestedRadius;
	UMath::Vector3 fPosition;
	float fRadius;
	UMath::Vector3 fLastRefreshedPosition;
	WCollisionInstanceCacheList fInstanceCacheList;
	WCollisionBarrierList fBarrierList;
	WCollisionTriList fTriList;
	WCollisionObjectList fObbList;
	bool fRegionInitialized;
	eColliderShape fColliderShape;
	unsigned int fTypeMask;
	unsigned int fRefCount;
	unsigned int fWorldID;
	unsigned int fExclusionFlags;

	auto PrepareRegion(uint32_t updateMask) { auto f = (void(__thiscall*)(WCollider*, uint32_t))0x789320; return f(this, updateMask); }
};
static_assert(offsetof(WCollider, fBarrierList) == 0x4C);
static_assert(offsetof(WCollider, fTriList) == 0x5C);