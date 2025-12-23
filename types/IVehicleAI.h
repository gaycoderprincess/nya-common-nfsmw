class SplinePath;
class WRoadNav;
class AITarget;
class IPursuit;
class IRoadBlock;

enum eLaneSelection {
	SELECT_CENTER_LANE = 0,
	SELECT_CURRENT_LANE = 1,
	SELECT_VALID_LANE = 2,
};

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
	virtual void ResetDriveToNav(eLaneSelection lane_selection) = 0;
	virtual void ResetVehicleToRoadNav(WRoadNav* other_nav) = 0;
	virtual void ResetVehicleToRoadNav(short segInd, char laneInd, float timeStep) = 0;
	virtual void ResetVehicleToRoadPos(const UMath::Vector3* position, const UMath::Vector3* forwardVector) = 0;
	virtual float GetPathDistanceRemaining() = 0;
	virtual AITarget* GetTarget() = 0;
	virtual bool GetDrivableToTargetPos() = 0;
	virtual void* GetAvoidableList() = 0;
	virtual void SetAvoidableRadius(float) = 0;
	virtual float GetTopSpeed() = 0;
	virtual float GetAcceleration(float) = 0;
	virtual bool GetWorldAvoidanceInfo(float dT, UMath::Vector3* leftCollNormal, UMath::Vector3* rightCollNormal) = 0;
	virtual WRoadNav* GetCollNav(const UMath::Vector3* forwardVector, float predictTime) = 0;
	virtual float GetLastSpawnTime() = 0;
	virtual void SetSpawned() = 0;
	virtual void UnSpawn() = 0;
	virtual bool CanRespawn(bool respawnAvailable) = 0;
	virtual Attrib::Instance* GetAttributes() = 0;
	virtual void EnableSimplePhysics() = 0;
	virtual void DisableSimplePhysics() = 0;
	virtual IPursuit* GetPursuit() = 0;
	virtual IRoadBlock* GetRoadBlock() = 0;
	virtual const UMath::Vector3* GetSeekAheadPosition() = 0;
	virtual const UMath::Vector3* GetFarFuturePosition() = 0;
	virtual const UMath::Vector3* GetFarFutureDirection() = 0;
	virtual WRoadNav* GetCurrentRoad() = 0;
	virtual WRoadNav* GetFutureRoad() = 0;
	virtual bool IsCurrentGoal(const UCrc32*) = 0;
	virtual UCrc32* GetGoalName() = 0;
	virtual bool IsCurrentAction(const UCrc32*) = 0;
	virtual UCrc32 GetActionName() = 0;
	virtual float GetSkill() = 0;
	virtual float GetShortcutSkill() = 0;
	virtual float GetPercentRaceComplete() = 0;
};