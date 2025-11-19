typedef UMath::Vector3 bVector3;
typedef UMath::Vector4 bVector4;
typedef UMath::Matrix4 bMatrix4;

class EAX_CarState {
public:
	float mMaxTorque;
	float mMaxRPM;
	float mMinRPM;
	float mRedline;
	bMatrix4 mMatrix;
	bVector3 mVel0;
	int mRacePos;
	bVector3 mVel1;
	float mBrake;
	bVector3 mAccel;
	float mEBrake;
	float mFWSpeed;
	bool mIsShocked;
	float mHealth;
	bool mNosEmptyFlag;
	/*MovementMode mMovementMode;
	PlayerZones mPlayerZone;
	Wheel mWheel[4];
	unsigned short mSteering;
	unsigned short mAngle;
	Engine mEngine;
	Driveline mDriveline;
	SirenState mSirenState;
	bool mHotPursuit;
	Attrib::Instance mAttributes;
	Attrib::Instance mEngineInfo;
	Context mContext;
	bool mSimUpdating;
	bool mAssetsLoaded;
	const unsigned int mWorldID;
	HSIMABLE mHandle;
	unsigned int mTrailerID;
	float mOversteer;
	float mUndersteer;
	float mSlipAngle;
	float mVisualRPM;
	float mTimeSinceSeen;
	int mNISCarID;
	float mDesiredSpeed;
	ControlSource mControlSource;*/
};
auto GetClosestPlayerCar = (EAX_CarState*(__cdecl*)(bVector3*))0x4BA5C0;