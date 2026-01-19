class Schedule;
class ScheduleList;
class Timer {
public:
	float mStart;
};

class Scheduler {
public:
	Schedule* fSchedule_OncePerGameLoop;
	Schedule* fSchedule_SimRate;
	Schedule* fSchedule_HalfSimRate;
	Schedule* fSchedule_QuarterSimRate;
	ScheduleList* fScheduleList;
	Timer mTimer;
	float mTime;
	float mTickBank;
	float fTimeStep;
	bool fSingleStepMode;
	bool fFullSpeedMode;
	unsigned int mEventTick;

	static inline auto& fgScheduler = *(Scheduler**)0x9203B0;
};
static_assert(sizeof(Scheduler) == 0x2C);