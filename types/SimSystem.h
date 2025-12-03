namespace Sim {
	enum State {
		STATE_NONE = 0,
		STATE_INITIALIZING = 1,
		STATE_ACTIVE = 3,
		STATE_IDLE = 4,
	};

	class ITaskable : public UCOM::IUnknown {
	public:
		static inline uint32_t IHandle = 0x6E81C0;
	};

	class ITimeManager : public UCOM::IUnknown {
	public:
		static inline uint32_t IHandle = 0x6E8280;

		virtual float OnManageTime(float real_time_delta, float sim_speed) = 0;
	};

	auto SetStream = (void(__cdecl*)(const UMath::Vector3* location, bool blocking))0x6F1170;
	auto GetTime = (float(__cdecl*)())0x6E8DE0;
}

class IActivity;
class SimSystem : public UCOM::Object, Sim::ITaskable {
public:
	struct StaticData {
		uint8_t _0[8];
	};

	float mScheduleStep;
	float mTimeStep;
	float mTargetSpeed;
	float mSpeed;
	int mEvent;
	Sim::State mState;
	StaticData mEventData;
	IActivity* mKernel;
	bool mInputPaused;
	HSIMTASK mWorldUpdate;
	HSIMTASK mSimStart;
	HSIMTASK mSimEnd;
	HSIMTASK mSimFrameEnd;
	Attrib::Instance mAttribs;
	UMath::Vector4 mCameras[2];
	unsigned int mCameraTargets[2];
	HSIMPROFILE mTasksProfile;
};
static_assert(sizeof(SimSystem) == 0x90);

namespace Sim {
	namespace Internal {
		auto& mSystem = *(SimSystem**)0x9885E0;
	}
}