enum ePursuitStatus {
	PS_INITIAL_CHASE = 0,
	PS_BACKUP_REQUESTED = 1,
	PS_COOL_DOWN = 2,
	PS_BUSTED = 3,
	PS_EVADED = 4,
};

enum FormationType {
	PIT = 1,
	BOX_IN = 2,
	ROLLING_BLOCK = 3,
	FOLLOW = 4,
	HELI_PURSUIT = 5,
	HERD = 6,
	STAGGER_FOLLOW = 7,
};

class IRoadBlock;

class IPursuit : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4038C0;

	virtual bool IsTarget(AITarget*) = 0;
	virtual AITarget* GetTarget() = 0;
	virtual int GetNumCops() = 0;
	virtual int GetNumHeliSpawns() = 0;
	virtual int GetNumCopsFullyEngaged() = 0;
	virtual float GetPursuitDuration() = 0;
	virtual float GetEvadeLevel() = 0;
	virtual float GetCoolDownTimeRemaining() = 0;
	virtual float GetCoolDownTimeRequired() = 0;
	virtual bool IsPerpInSight() = 0;
	virtual bool IsPursuitBailed() = 0;
	virtual bool IsCollapseActive() = 0;
	virtual bool AttemptingToReAquire() = 0;
	virtual const UMath::Vector3* GetLastKnownLocation() = 0;
	virtual IRoadBlock* GetRoadBlock() = 0;
	virtual IVehicle* GetNearestCopInRoadblock(float*) = 0;
	virtual void RequestGroundSupport() = 0;
	virtual void ClearGroundSupportRequest() = 0;
	virtual bool IsSupportVehicle(IVehicle*) = 0;
	virtual void CopRequest() = 0;
	virtual bool PendingRoadBlockRequest() = 0;
	virtual bool IsFinisherActive() = 0;
	virtual float TimeToFinisherAttempt() = 0;
	virtual float TimeUntilBusted() = 0;
	virtual bool PursuitMeterCanShowBusted() = 0;
	virtual FormationType GetFormationType() = 0;
	virtual void EndCurrentFormation() = 0;
	virtual bool ShouldEnd() = 0;
	virtual bool IsPerpBusted() = 0;
	virtual void AddVehicle(IVehicle*) = 0;
	virtual void RemoveVehicle(IVehicle*) = 0;
	virtual void AddRoadBlock(IRoadBlock*) = 0;
	virtual void RequestRoadBlock() = 0;
	virtual bool IsHeliInPursuit() = 0;
	virtual bool IsPlayerPursuit() = 0;
	virtual bool ContingentHasActiveCops() = 0;
	virtual int GetNumCopsDamaged() = 0;
	virtual int GetNumCopsDestroyed() = 0;
	virtual void IncNumCopsDestroyed(IVehicle*) = 0;
	virtual int GetTotalNumCopsInvolved() = 0;
	virtual int GetNumRoadblocksDodged() = 0;
	virtual int GetNumRoadblocksDeployed() = 0;
	virtual int GetValueOfPropertyDamaged() = 0;
	virtual int GetNumPropertyDamaged() = 0;
	virtual int GetNumTrafficCarsHit() = 0;
	virtual int GetNumSpikeStripsDodged() = 0;
	virtual int GetNumSpikeStripsDeployed() = 0;
	virtual int GetNumHeliSpikeStripDeployed() = 0;
	virtual int GetNumCopCarsDeployed() = 0;
	virtual int GetNumSupportVehiclesDeployed() = 0;
	virtual int GetNumCopsInWave() = 0;
	virtual int GetNumCopsRemainingInWave() = 0;
	virtual int GetCopDestroyedBonusMultiplier() = 0;
	virtual int GetMostRecentCopDestroyedRepPoints() = 0;
	virtual int GetMostRecentCopDestroyedType() = 0;
	virtual int CalcTotalCostToState() = 0;
	virtual void AddVehicleToContingent(IVehicle*) = 0;
	virtual void NotifyRoadblockDodged() = 0;
	virtual void NotifyRoadblockDeployed() = 0;
	virtual void NotifyCopDamaged(IVehicle*) = 0;
	virtual void NotifyPropertyDamaged(int) = 0;
	virtual void NotifyTrafficCarHit() = 0;
	virtual void NotifySpikeStripsDodged(int) = 0;
	virtual void NotifySpikeStripDeployed() = 0;
	virtual void NotifyHeliSpikeStripDeployed(int) = 0;
	virtual void NotifyCopCarDeployed() = 0;
	virtual void NotifySupportVehicleDeployed() = 0;
	virtual void BailPursuit() = 0;
	virtual ePursuitStatus GetPursuitStatus() = 0;
	virtual float GetTimeToBackupSpawned() = 0;
	virtual bool SkidHitEnabled() = 0;
	virtual float GetBackupETA() = 0;
	virtual bool GetIsAJerk() = 0;
	virtual float GetMinDistanceToTarget() = 0;
	virtual void SpikesHit(IVehicleAI*) = 0;
	virtual void EndPursuitEnteringSafehouse() = 0;
	virtual bool GetEnterSafehouseOnDone() = 0;
	virtual void LockInPursuitAttribs() = 0;
	virtual void SetBustedTimerToZero() = 0;
	virtual Attrib::Instance* GetPursuitLevelAttrib() = 0;
};