enum eVehicleList {
	VEHICLE_ALL = 0,
	VEHICLE_PLAYERS = 1,
	VEHICLE_AI = 2,
	VEHICLE_AIRACERS = 3,
	VEHICLE_AICOPS = 4,
	VEHICLE_AITRAFFIC = 5,
	VEHICLE_RACERS = 6,
	VEHICLE_REMOTE = 7,
	VEHICLE_INACTIVE = 8,
	VEHICLE_TRAILERS = 9,
	VEHICLE_MAX = 10,
};

enum DriverStyle {
	STYLE_RACING = 0,
	STYLE_DRAG = 1,
};

enum PhysicsMode {
	PHYSICS_MODE_INACTIVE = 0,
	PHYSICS_MODE_SIMULATED = 1,
	PHYSICS_MODE_EMULATED = 2,
};

enum DriverClass {
	DRIVER_HUMAN = 0,
	DRIVER_TRAFFIC = 1,
	DRIVER_COP = 2,
	DRIVER_RACER = 3,
	DRIVER_NONE = 4,
	DRIVER_NIS = 5,
	DRIVER_REMOTE = 6,
};

typedef int CarType;

namespace VehicleFX {
	enum ID {
		LIGHT_NONE = 0,
		LIGHT_LHEAD = 1,
		LIGHT_RHEAD = 2,
		LIGHT_CHEAD = 4,
		LIGHT_HEADLIGHTS = 7,
		LIGHT_LBRAKE = 8,
		LIGHT_RBRAKE = 16,
		LIGHT_CBRAKE = 32,
		LIGHT_BRAKELIGHTS = 56,
		LIGHT_LREVERSE = 64,
		LIGHT_RREVERSE = 128,
		LIGHT_REVERSE = 192,
		LIGHT_LRSIGNAL = 256,
		LIGHT_RRSIGNAL = 512,
		LIGHT_LFSIGNAL = 1024,
		LIGHT_LSIGNAL = 1280,
		LIGHT_RFSIGNAL = 2048,
		LIGHT_RSIGNAL = 2560,
		LIGHT_COPRED = 4096,
		LIGHT_COPBLUE = 8192,
		LIGHT_COPWHITE = 16384,
		LIGHT_COPS = 28672,
	};
}

class IVehicleAI;

class IVehicle : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4040E0;

	virtual ISimable* GetSimable() = 0;
	virtual const ISimable* _GetSimable() = 0;
	virtual const UMath::Vector3* GetPosition() = 0;
	virtual void SetBehaviorOverride(UCrc32* mechanic, UCrc32* behavior) = 0;
	virtual void RemoveBehaviorOverride(UCrc32* mechanic) = 0;
	virtual void CommitBehaviorOverrides() = 0;
	virtual void SetStaging(bool staging) = 0;
	virtual bool IsStaging() = 0;
	virtual void Launch() = 0;
	virtual bool GetPerfectLaunch() = 0;
	virtual void SetDriverStyle(DriverStyle style) = 0;
	virtual DriverStyle GetDriverStyle() = 0;
	virtual void SetPhysicsMode(PhysicsMode mode) = 0;
	virtual PhysicsMode GetPhysicsMode() = 0;
	virtual CarType GetModelType() = 0;
	virtual bool IsSpooled() = 0;
	virtual const UCrc32* GetVehicleClass() = 0;
	virtual const Attrib::Gen::pvehicle* GetVehicleAttributes() = 0;
	virtual const char* GetVehicleName() = 0;
	virtual uint32_t GetVehicleKey() = 0;
	virtual void SetDriverClass(DriverClass new_class) = 0;
	virtual DriverClass GetDriverClass() = 0;
	virtual bool IsLoading() = 0;
	virtual float GetOffscreenTime() = 0;
	virtual float GetOnScreenTime() = 0;
	virtual bool SetVehicleOnGround(const UMath::Vector3 *resetPos, const UMath::Vector3 *initialVec) = 0;
	virtual void ForceStopOn(uint8_t forceStopBits) = 0;
	virtual void ForceStopOff(uint8_t forceStopBits) = 0;
	virtual uint8_t GetForceStop() = 0;
	virtual bool InShock() = 0;
	virtual bool IsDestroyed() = 0;
	virtual void Activate() = 0;
	virtual void Deactivate() = 0;
	virtual bool IsActive() = 0;
	virtual float GetSpeedometer() = 0;
	virtual float GetSpeed() = 0;
	virtual void SetSpeed(float speed) = 0;
	virtual float GetAbsoluteSpeed() = 0;
	virtual bool IsGlareOn(VehicleFX::ID glare) = 0;
	virtual void GlareOn(VehicleFX::ID glare) = 0;
	virtual void GlareOff(VehicleFX::ID glare) = 0;
	virtual bool IsCollidingWithSoftBarrier() = 0;
	virtual IVehicleAI* GetAIVehiclePtr() = 0;
	virtual float GetSlipAngle() = 0;
	virtual const UMath::Vector3* GetLocalVelocity() = 0;
	virtual void ComputeHeading(UMath::Vector3* v) = 0;
	virtual bool IsAnimating() = 0;
	virtual void SetAnimating(bool animate) = 0;
	virtual bool IsOffWorld() = 0;
	virtual const FECustomizationRecord* GetCustomizations() = 0;
	virtual const Physics::Tunings* GetTunings() = 0;
	virtual void SetTunings(const Physics::Tunings* tunings) = 0;
	virtual bool GetPerformance(Physics::Info::Performance *performance) = 0;
	virtual const char* GetCacheName() = 0;
};

#define VEHICLE_LIST UTL::ListableSet<IVehicle, 20, eVehicleList, VEHICLE_MAX, 0x92CD18>
static_assert(sizeof(VEHICLE_LIST::_buckets[0]) == 0x60);