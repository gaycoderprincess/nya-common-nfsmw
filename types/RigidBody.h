template<typename T>
class ScratchPtr {
public:
	T** mRef;
};

class RigidBody {
public:
	class Volatile {
	public:
		UMath::Vector4 orientation;
		UMath::Vector3 position;
		unsigned short status;
		unsigned short statusPrev;
		UMath::Vector3 linearVel;
		float mass;
		UMath::Vector3 angularVel;
		float oom;
		UMath::Vector3 inertiaTensor;
		float unused1;
		UMath::Vector3 force;
		char leversInContact;
		unsigned char state;
		unsigned char index;
		char unused2;
		UMath::Vector3 torque;
		float radius;
		UMath::Matrix4 bodyMatrix;
	};

	uint8_t _0[0x78];
	ScratchPtr<RigidBody::Volatile> mData;
	Attrib::Instance mSpecs;
	UMath::Matrix4 mInvWorldTensor;
	UMath::Vector4 mGroundNormal;
	UMath::Vector3 mDimension;
	WCollider *mWCollider;
	UMath::Vector3 mCOG;

	static inline auto& mCount = *(int*)0x9377C8;
};
static_assert(offsetof(RigidBody, mData) == 0x78);
static_assert(offsetof(RigidBody, mInvWorldTensor.x) == 0x90);
static_assert(offsetof(RigidBody, mCOG) == 0xF0);

class SimpleRigidBody {
public:
	static inline auto& mCount = *(int*)0x9377D0;
};
#define DISPOSABLE_LIST UTL::Listable<IDisposable, 160, 0x92CA88>