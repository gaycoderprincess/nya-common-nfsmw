class IHumanAI : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x403770;

	virtual void ChangeDragLanes(bool) = 0;
	virtual bool IsPlayerSteering() = 0;
	virtual bool GetAiControl() = 0;
	virtual void SetAiControl(bool ai_control) = 0;
	virtual void SetWorldMoment(const UMath::Vector3* position, float radius) = 0;
	virtual const UMath::Vector3* GetWorldMomentPosition() = 0;
	virtual float GetWorldMomentRadius() = 0;
	virtual void ClearWorldMoment() = 0;
	virtual bool IsFacingWrongWay() = 0;
};