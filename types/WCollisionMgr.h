class WCollisionMgr {
public:
	static inline auto GetWorldHeightAtPoint = (bool(__stdcall*)(const UMath::Vector3* pt, float* height, UMath::Vector3* normal))0x7897C0;
	static inline auto GetWorldHeightAtPointRigorous = (bool(__stdcall*)(const UMath::Vector3* pt, float* height, UMath::Vector3* normal))0x789870;
};