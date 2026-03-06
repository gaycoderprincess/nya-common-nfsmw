class WCollisionInstance;
class WCollisionTriBlock;
class WCollisionObject;
class WCollisionInstanceCacheList : eastl::vector<WCollisionInstance*> {};
class WCollisionBarrierList : eastl::vector<WCollisionBarrierListEntry> {};
class WCollisionTriList : eastl::vector<WCollisionTriBlock*> {};
class WCollisionObjectList : eastl::vector<WCollisionObject*> {};

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