class AITarget;

class IPursuitAI : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4038E0;

	virtual void StartPatrol() = 0;
	virtual void StartRoadBlock() = 0;
	virtual void StartFlee() = 0;
	virtual void SetInPursuit(bool) = 0;
	virtual bool GetInPursuit() = 0;
	virtual void StartPursuit(AITarget*, ISimable*) = 0;
	virtual void DoInPositionGoal() = 0;
	virtual void EndPursuit() = 0;
	virtual ISimable* GetPursuitTarget() = 0;
	virtual void StartSupportGoal() = 0;
	virtual void PursuitRequest() = 0;
	virtual void SetInFormation(bool) = 0;
	virtual bool GetInFormation() = 0;
	virtual void SetInPosition(bool) = 0;
	virtual bool GetInPosition() = 0;
	virtual void SetPursuitOffset(const UMath::Vector3*) = 0;
	virtual const UMath::Vector3* GetPursuitOffset() = 0;
	virtual void SetInPositionGoal(const UCrc32*) = 0;
	virtual const UCrc32* GetInPositionGoal() = 0;
	virtual void SetInPositionOffset(const UMath::Vector3*) = 0;
	virtual const UMath::Vector3* GetInPositionOffset() = 0;
	virtual void SetBreaker(bool) = 0;
	virtual bool GetBreaker() = 0;
	virtual void SetChicken(bool) = 0;
	virtual bool GetChicken() = 0;
	virtual void SetDamagedByPerp(bool) = 0;
	virtual bool GetDamagedByPerp() = 0;
	virtual bool GetSirenState() = 0;
	virtual float GetTimeSinceTargetSeen() = 0;
	virtual void ZeroTimeSinceTargetSeen() = 0;
	virtual void _purecall() = 0;
	virtual UCrc32 GetSupportGoal() = 0;
	virtual void SetSupportGoal(UCrc32) = 0;
	virtual void SetWithinEngagementRadius() = 0;
	virtual bool WasWithinEngagementRadius() = 0;
};