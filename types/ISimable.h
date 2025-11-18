enum SimableType {
	SIMABLE_INVALID = 0,
	SIMABLE_VEHICLE = 1,
	SIMABLE_SMACKABLE = 2,
	SIMABLE_EXPLOSION = 3,
	SIMABLE_HUMAN = 4,
	SIMABLE_WEAPON = 5,
	SIMABLE_NEWTON = 6,
	SIMABLE_SENTRY = 7,
	SIMABLE_FRAGMENT = 8,
};

namespace Sim {
	class IEntity : public UCOM::IUnknown {};
}

typedef uint32_t HSIMABLE;
typedef uint32_t HCAUSE;

class IRigidBody;
class IModel;
class WWorldPos;
class EventSequencer;

class ISimable : public UCOM::IUnknown {
public:
	virtual SimableType GetSimableType() = 0;
	virtual void Kill() = 0;
	virtual void Attach(UCOM::IUnknown* object) = 0;
	virtual void Detach(UCOM::IUnknown* object) = 0;
	virtual void* GetAttachments() = 0;
	virtual void AttachEntity(Sim::IEntity* e) = 0;
	virtual void DetachEntity(Sim::IEntity* e) = 0;
	virtual IPlayer* GetPlayer() = 0;
	virtual bool IsPlayer() = 0;
	virtual bool IsOwnedByPlayer() = 0;
	virtual Sim::IEntity* GetEntity() = 0;
	virtual void DebugObject() = 0;
	virtual HSIMABLE GetOwnerHandle() = 0;
	virtual ISimable* GetOwner() = 0;
	virtual bool IsOwnedBy(ISimable* queriedOwner) = 0;
	virtual void SetOwnerObject(ISimable* pOwner) = 0;
	virtual Attrib::Instance* GetAttributes() = 0;
	virtual const WWorldPos* _GetWPos() = 0;
	virtual WWorldPos* GetWPos() = 0;
	virtual const IRigidBody* _GetRigidBody() = 0;
	virtual IRigidBody* GetRigidBody() = 0;
	virtual bool IsRigidBodySimple() = 0;
	virtual bool IsRigidBodyComplex() = 0;
	virtual UMath::Vector3* GetPosition() = 0;
	virtual UMath::Matrix4* GetTransform(UMath::Matrix4*) = 0;
	virtual UMath::Vector3* GetLinearVelocity(UMath::Vector3*) = 0;
	virtual UMath::Vector3* GetAngularVelocity(UMath::Vector3*) = 0;
	virtual int GetWorldID() = 0;
	virtual EventSequencer* GetEventSequencer() = 0;
	virtual void ProcessStimulus(unsigned int stimulus) = 0;
	virtual const IModel* _GetModel() = 0;
	virtual IModel* GetModel() = 0;
	virtual void SetCausality(HCAUSE from, float time) = 0;
	virtual HCAUSE GetCausality() = 0;
	virtual float GetCausalityTime() = 0;
};