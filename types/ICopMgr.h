class IPursuit;
class ICopMgr : public UCOM::IUnknown {
public:
	static inline auto& mInstance = *(ICopMgr**)0x92C67C;
	static inline auto& mDisableCops = *(bool*)0x90D5EC;

	virtual bool VehicleSpawningEnabled(bool) = 0;
	virtual void ResetCopsForRestart(bool) = 0;
	virtual void SetAllBustedTimersToZero() = 0;
	virtual bool PursuitIsEvaded(IPursuit*) = 0;
	virtual bool IsCopRequestPending() = 0;
	virtual bool IsCopSpawnPending() = 0;
	virtual void SpawnCop(const UMath::Vector3* InitialPos, const UMath::Vector3* InitialVec, const char* VehicleName, bool InPursuit, bool RoadBlock) = 0;
	virtual bool PlayerPursuitHasCop() = 0;
	virtual bool CanPursueRacers() = 0;
	virtual bool IsPlayerPursuitActive() = 0;
	virtual void LockoutCops(bool) = 0;
	virtual bool NoNewPursuitsOrCops() = 0;
	virtual void PursueAtHeatLevel(int) = 0;
	virtual float GetLockoutTimeRemaining() = 0;
};