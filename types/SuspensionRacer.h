// todo
class AverageWindow {
public:
	uint8_t _0[0x38];
};

class Wheel {
public:
	WWorldPos mWorldPos;
	UMath::Vector4 mNormal;
	UMath::Vector3 mPosition;
	unsigned int mFlags;
	UMath::Vector3 mForce;
	float mAirTime;
	UMath::Vector3 mLocalArm;
	float mCompression;
	UMath::Vector3 mWorldArm;
	int pad;
	UMath::Vector3 mVelocity;
	int pad2;
	Attrib::Gen::simsurface mSurface;
	float mSurfaceStick;
	UMath::Vector4 mIntegral;

	const UMath::Vector4 &GetNormal() const {
		return mNormal;
	}

	const UMath::Vector3 &GetPosition() const {
		return mPosition;
	}

	void SetPosition(UMath::Vector3 &p) {
		mPosition = p;
	}

	void SetY(float y) {
		mPosition.y = y;
	}

	const UMath::Vector3 &GetForce() const {
		return mForce;
	}

	void SetForce(const UMath::Vector3 &f) {
		mForce = f;
	}

	void SetVelocity(const UMath::Vector3 &v) {
		mVelocity = v;
	}

	void IncAirTime(float dT) {
		mAirTime += dT;
	}

	void SetAirTime(float f) {
		mAirTime = f;
	}

	const UMath::Vector3 &GetLocalArm() const {
		return mLocalArm;
	}

	void SetLocalArm(UMath::Vector3 &arm) {
		mLocalArm = arm;
	}

	const UMath::Vector3 &GetWorldArm() const {
		return mWorldArm;
	}

	float GetCompression() const {
		return mCompression;
	}

	void SetCompression(float c) {
		mCompression = std::max(c, 0.0f);
	}

	const Attrib::Gen::simsurface *GetSurface() const {
		return &mSurface;
	}

	const UMath::Vector3 &GetVelocity() const {
		return mVelocity;
	}

	bool IsOnGround() const {
		return mCompression > 0.0f;
	}

	void UpdateTime(float dT) {
		if (mSurfaceStick <= 0.0 || dT >= mSurfaceStick) mSurfaceStick = 0.0;
		else mSurfaceStick = mSurfaceStick - dT;
	}

	auto UpdatePosition(UMath::Vector3 &body_av, UMath::Vector3 &body_lv, UMath::Matrix4 &body_matrix, UMath::Vector3 &cog, float dT, float wheel_radius, bool usecache, const WCollider *collider, float vehicle_height) { auto f = (void(__thiscall*)(Wheel*, UMath::Vector3*, UMath::Vector3*, UMath::Matrix4*, UMath::Vector3*, float, float, bool, const WCollider*, float))0x671530; return f(this, &body_av, &body_lv, &body_matrix, &cog, dT, wheel_radius, usecache, collider, vehicle_height); }
};

class Chassis : public VehicleBehavior {
public:
	struct State {
		UMath::Matrix4 matrix;
		UMath::Vector3 local_vel;
		float gas_input;
		UMath::Vector3 linear_vel;
		float brake_input;
		UMath::Vector3 angular_vel;
		float ground_effect;
		UMath::Vector3 cog;
		float ebrake_input;
		UMath::Vector3 dimension;
		float steer_input;
		UMath::Vector3 local_angular_vel;
		float slipangle;
		UMath::Vector3 inertia;
		float mass;
		UMath::Vector3 world_cog;
		float speed;
		float time;
		int flags;
		short driver_style;
		short driver_class;
		short gear;
		short blown_tires;
		float nos_boost;
		float shift_boost;
		const WCollider* collider;
		enum Flags {
			IS_STAGING = 1,
			IS_DESTROYED = 2,
		};

#ifdef NYA_MATH_H
		const UMath::Vector3 &GetRightVector() const {
			return *(UMath::Vector3*)&matrix.x;
		}
		const UMath::Vector3 &GetUpVector() const {
			return *(UMath::Vector3*)&matrix.y;
		}
		const UMath::Vector3 &GetForwardVector() const {
			return *(UMath::Vector3*)&matrix.z;
		}
		const UMath::Vector3 &GetPosition() const {
			return *(UMath::Vector3*)&matrix.p;
		}
#endif
	};
	static_assert(sizeof(State) == 0xDC);

	uint8_t _0[0x8];
	ICollisionBody* mRBComplex;
	IInput* mInput;
	IEngine* mEngine;
	ITransmission* mTransmission;
	IDragTransmission* mDragTrany;
	IEngineDamage* mEngineDamage;
	ISpikeable* mSpikeDamage;
	Attrib::Gen::chassis mAttributes;
	float mJumpTime;
	float mJumpAlititude;
	float mTireHeat;

	auto ComputeState(float dT, State& state) { auto f = (void(__thiscall*)(Chassis*, float, State*))0x69D4D0; return f(this, dT, &state); }
};
static_assert(offsetof(Chassis, mRBComplex) == 0x54);
static_assert(offsetof(Chassis, mTireHeat) == 0x8C);

class SuspensionRacer : public Chassis {
public:
	class Tire : public Wheel {
	public:
		const float mRadius;
		float mBrake;
		float mEBrake;
		float mAV;
		float mLoad;
		float mLateralForce;
		float mLongitudeForce;
		float mDriveTorque;
		float mBrakeTorque;
		float mLateralBoost;
		float mTractionBoost;
		float mSlip;
		float mLastTorque;
		const int mWheelIndex;
		float mRoadSpeed;
		const Attrib::Instance* mSpecs;
		const Attrib::Instance* mBrakes;
		float mAngularAcc;
		const int mAxleIndex;
		float mTraction;
		float mBottomOutTime;
		float mSlipAngle;
		UMath::Vector2 mTractionCircle;
		float mMaxSlip;
		float mGripBoost;
		float mDriftFriction;
		float mLateralSpeed;
		bool mBrakeLocked;
		enum LastRotationSign {
			WAS_POSITIVE = 0,
			WAS_ZERO = 1,
			WAS_NEGATIVE = 2,
		};
		LastRotationSign mLastSign;
		float mDragReduction;

		bool IsSlipping() const {
			return mTraction >= 1.0f;
		}

		void SetBrake(float brake) {
			mBrake = brake;
		}

		void SetEBrake(float ebrake) {
			mEBrake = ebrake;
		}

		float GetEBrake() const {
			return mEBrake;
		}

		float GetTraction() const {
			return mTraction;
		}

		float GetRoadSpeed() const {
			return mRoadSpeed;
		}

		float GetLoad() const {
			return mLoad;
		}

		float GetRadius() const {
			return mRadius;
		}

		float GetAngularVelocity() const {
			return mAV;
		}

		void SetAngularVelocity(float w) {
			mAV = w;
		}

		float GetLateralSpeed() const {
			return mLateralSpeed;
		}

		float GetCurrentSlip() const {
			return mSlip;
		}

		float GetToleratedSlip() const {
			return mMaxSlip;
		}

		void SetLateralBoost(float f) {
			mLateralBoost = f;
		}

		void SetBottomOutTime(float time) {
			mBottomOutTime = time;
		}

		void ScaleTractionBoost(float scale) {
			mTractionBoost *= scale;
		}

		void SetDriftFriction(float scale) {
			mDriftFriction = scale;
		}

		void ApplyDriveTorque(float torque) {
			if (!mBrakeLocked) {
				mDriveTorque += torque;
			}
		}

		void ApplyBrakeTorque(float torque) {
			if (!mBrakeLocked) {
				mBrakeTorque += torque;
			}
		}

		float GetTotalTorque() const {
			return mDriveTorque + mBrakeTorque;
		}

		float GetDriveTorque() const {
			return mDriveTorque;
		}

		float GetLongitudeForce() const {
			return mLongitudeForce;
		}

		bool IsBrakeLocked() const {
			return mBrakeLocked;
		}

		bool IsSteeringWheel() const {
			return mWheelIndex < 2;
		}

		void SetTractionCircle(const UMath::Vector2 &circle) {
			mTractionCircle = circle;
		}

		float GetSlipAngle() const {
			return mSlipAngle;
		}

		auto CheckSign() { auto f = (void(__thiscall*)(Tire*))0x68E2E0; return f(this); }
		auto CheckForBrakeLock(float ground_force) { auto f = (void(__thiscall*)(Tire*, float))0x68E220; return f(this, ground_force); }
		auto ComputeLateralForce(float load, float slip_angle) { auto f = (float(__thiscall*)(Tire*, float, float))0x68E090; return f(this, load, slip_angle); }
		auto GetPilotFactor(float speed) { auto f = (float(__thiscall*)(Tire*, float))0x68E180; return f(this, speed); }
		auto UpdateFree(float dT) { auto f = (void(__thiscall*)(Tire*, float))0x68E370; return f(this, dT); }
		auto UpdateLoaded(float lat_vel, float fwd_vel, float body_speed, float load, float dT) { auto f = (float(__thiscall*)(Tire*, float, float, float, float, float))0x69DA90; return f(this, lat_vel, fwd_vel, body_speed, load, dT); }
	};
	static_assert(sizeof(Tire) == 0x140);

	struct Drift {
		enum eState {
			D_OUT = 0,
			D_ENTER = 1,
			D_IN = 2,
			D_EXIT = 3,
		};
		eState State;
		float Value;
	};

	struct Burnout {
		int mState;
		float mBurnOutTime;
		float mTraction;
		float mBurnOutAllow;

		int GetState() {
			return mState;
		}

		float GetTraction() {
			return mTraction;
		}

		void Reset() {
			mState = 0;
			mBurnOutTime = 0.0f;
			mTraction = 1.0f;
			mBurnOutAllow = 0.0f;
		}

		void SetState(int s) {
			mState = s;
		}

		void SetBurnOutTime(float t) {
			mBurnOutTime = t;
		}

		void SetTraction(float t) {
			mTraction = t;
		}

		float GetBurnOutTime(float t) {
			return mBurnOutTime;
		}

		void DecBurnOutTime(float t) {
			mBurnOutTime -= t;
		}

		void ClearBurnOutAllow() {
			mBurnOutAllow = 0.0f;
		}

		void IncBurnOutAllow(float t) {
			mBurnOutAllow += t;
		}

		auto Update(float dT, float speedmph, float max_slip, int max_slip_wheel, float yaw) { auto f = (void(__thiscall*)(Burnout*, float, float, float, int, float))0x69EAC0; return f(this, dT, speedmph, max_slip, max_slip_wheel, yaw); }
	};

	struct Steering {
		float Previous;
		float Wheels[2];
		float Maximum;
		float LastMaximum;
		float LastInput;
		AverageWindow InputAverage;
		AverageWindow InputSpeedCoeffAverage;
		float CollisionTimer;
		float WallNoseTurn;
		float WallSideTurn;
		float YawControl;
	};

	struct Differential {
		float angular_vel[2];
		int has_traction[2];
		float bias;
		float factor;
		float torque_split[2];

		auto CalcSplit(bool a1) { auto f = (void(__thiscall*)(Differential*, bool))0x68EFA0; return f(this, a1); }
	};

	uint8_t _0[0x8];
	Attrib::Gen::tires mTireInfo;
	Attrib::Gen::brakes mBrakeInfo;
	Attrib::Gen::chassis mSuspensionInfo;
	Attrib::Gen::transmission mTranyInfo;
	IRigidBody* mRB;
	ICollisionBody* mCollisionBody;
	ITransmission* mTransmission;
	IHumanAI* mHumanAI;
	float mGameBreaker;
	unsigned int mNumWheelsOnGround;
	float mLastGroundCollision;
	Drift mDrift;
	Burnout mBurnOut;
	Steering mSteering;
	Tire* mTires[4];

	Tire &GetWheel(unsigned int i) {
		return *mTires[i];
	}

	auto CalcYawControlLimit(float speed) { auto f = (float(__thiscall*)(SuspensionRacer*, float))0x69EBF0; return f(this, speed); }
	auto DoDrifting(State& state) { auto f = (void(__thiscall*)(SuspensionRacer*, State*))0x6A9760; return f(this, &state); }
	auto DoSteering(State& state, UMath::Vector3& right, UMath::Vector3& left) { auto f = (void(__thiscall*)(SuspensionRacer*, State*, UMath::Vector3*, UMath::Vector3*))0x69E9E0; return f(this, &state, &right, &left); }
	auto TuneWheelParams(State& state) { auto f = (void(__thiscall*)(SuspensionRacer*, State*))0x6A9B40; return f(this, &state); }
};
static_assert(sizeof(SuspensionRacer::Steering) == 0x98);
static_assert(offsetof(SuspensionRacer, mTires) == 0x1B4);

auto YawFrictionBoost = (float(*)(float yaw, float ebrake, float speed, float yawcontrol, float grade))0x68EF10;