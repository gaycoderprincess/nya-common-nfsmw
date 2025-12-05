struct InputControls {
	float fBanking;
	float fSteering;
	float fSteeringVertical;
	float fStrafeVertical;
	float fStrafeHorizontal;
	float fGas;
	float fBrake;
	float fHandBrake;
	bool fActionButton;
	bool fNOS;
};

class IInput : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x403F90;

	virtual void ClearInput() = 0;
	virtual InputControls* GetControls() = 0;
	virtual bool GetControlHandBrake() = 0;
	virtual bool GetControlActionButton() = 0;
	virtual void SetControlSteering(float) = 0;
	virtual void SetControlGas(float) = 0;
	virtual void SetControlBrake(float) = 0;
	virtual void SetControlNOS(bool) = 0;
	virtual void SetControlHandBrake(float) = 0;
	virtual void SetControlActionButton(bool) = 0;
	virtual void SetControlSteeringVertical(float) = 0;
	virtual void SetControlBanking(float) = 0;
	virtual float GetControlBanking() = 0;
	virtual bool IsLookBackButtonPressed() = 0;
	virtual bool IsPullBackButtonPressed() = 0;
	virtual bool IsAutomaticShift() = 0;
};