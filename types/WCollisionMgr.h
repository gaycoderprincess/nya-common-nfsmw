class WCollisionInstanceCacheList;
class WCollisionTriList;

class WCollisionMgr {
public:
	class WorldCollisionInfo;

	static inline auto GetWorldHeightAtPoint = (bool(__stdcall*)(const UMath::Vector3* pt, float* height, UMath::Vector3* normal))0x7897C0;
	static inline auto GetWorldHeightAtPointRigorous = (bool(__stdcall*)(const UMath::Vector3* pt, float* height, UMath::Vector3* normal))0x789870;
	static inline auto GetTriList = (void(__stdcall*)(WCollisionInstanceCacheList *instList, UMath::Vector3 *pt, float radius, WCollisionTriList *triList))0x787710;
};