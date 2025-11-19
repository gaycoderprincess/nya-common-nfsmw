class WCollider;

class IRigidBody : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4039F0;

	virtual ISimable* GetOwner() = 0;
	virtual bool IsSimple() = 0;
	virtual int GetIndex() = 0;
	virtual SimableType GetSimableType() = 0;
	virtual float GetRadius() = 0;
	virtual float GetMass() = 0;
	virtual float GetOOMass() = 0;
	virtual const UMath::Vector3* GetPosition() = 0;
	virtual const UMath::Vector3* GetLinearVelocity() = 0;
	virtual const UMath::Vector3* GetAngularVelocity() = 0;
	virtual float GetSpeed() = 0;
	virtual float GetSpeedXZ() = 0;
	virtual UMath::Vector3* GetForwardVector(UMath::Vector3*) = 0;
	virtual UMath::Vector3* GetRightVector(UMath::Vector3*) = 0;
	virtual UMath::Vector3* GetUpVector(UMath::Vector3*) = 0;
	virtual UMath::Matrix4* GetMatrix4(UMath::Matrix4*) = 0;
	virtual UMath::Vector4* GetOrientation() = 0;
	virtual UMath::Vector3* GetDimension(UMath::Vector3*) = 0;
	virtual void _GetDimension(UMath::Vector3* dim) = 0;
	virtual uint32_t GetTriggerFlags() = 0;
	virtual const WCollider* GetWCollider() = 0;
	virtual void GetPointVelocity(const UMath::Vector3* position, UMath::Vector3* velocity) = 0;
	virtual void SetPosition(const UMath::Vector3 *pos) = 0;
	virtual void SetLinearVelocity(const UMath::Vector3* vel) = 0;
	virtual void SetAngularVelocity(const UMath::Vector3* vel) = 0;
	virtual void SetRadius(float radius) = 0;
	virtual void SetMass(float newMass) = 0;
	virtual void SetOrientation(const UMath::Matrix4* orientMat) = 0;
	virtual void SetOrientation(const UMath::Vector4* newOrientation) = 0;
	virtual void ModifyXPos(float offset) = 0;
	virtual void ModifyYPos(float offset) = 0;
	virtual void ModifyZPos(float offset) = 0;
	virtual void Resolve(const UMath::Vector3* force, const UMath::Vector3* torque) = 0;
	virtual void ResolveForce(const UMath::Vector3* force) = 0;
	virtual void ResolveTorque(const UMath::Vector3* torque) = 0;
	virtual void ResolveTorque(const UMath::Vector3* force, const UMath::Vector3* p) = 0;
	virtual void ResolveForce(const UMath::Vector3* force, const UMath::Vector3* p) = 0;
	virtual void PlaceObject(const UMath::Matrix4* orientMat, const UMath::Vector3* initPos) = 0;
	virtual void Accelerate(const UMath::Vector3* a, float dT) = 0;
	virtual void ConvertLocalToWorld(UMath::Vector3* val, bool translate) = 0;
	virtual void ConvertWorldToLocal(UMath::Vector3* val, bool translate) = 0;
	virtual void Debug() = 0;
};