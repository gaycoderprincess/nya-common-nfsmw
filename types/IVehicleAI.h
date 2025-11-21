class SplinePath;
class WRoadNav;

class IVehicleAI : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x403700;

	virtual ISimable* GetSimable() = 0;
	virtual IVehicle* GetVehicle() = 0;
	virtual SplinePath* GetSplinePath() = 0;
	virtual void SetReverseOverride(float) = 0;
	virtual float GetReverseOverride() = 0;
	virtual uint32_t GetDriveFlags() = 0;
	virtual void ClearDriveFlags() = 0;
	virtual void DoReverse() = 0;
	virtual void DoSteering() = 0;
	virtual void DoGasBrake() = 0;
	virtual void DoDriving(uint32_t) = 0;
	virtual void DoNOS() = 0;
	virtual float GetDriveSpeed() = 0;
	virtual void SetDriveSpeed(float) = 0;
	virtual void SetDriveTarget(UMath::Vector3*) = 0;
	virtual float GetLookAhead() = 0;
	virtual const UMath::Vector3* GetDriveTarget() = 0;
	virtual WRoadNav* GetDriveToNav() = 0;
	virtual bool GetDrivableToDriveToNav() = 0;
	// todo
};