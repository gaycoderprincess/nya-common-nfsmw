enum GearID {
	G_REVERSE = 0,
	G_NEUTRAL = 1,
	G_FIRST = 2,
	G_SECOND = 3,
	G_THIRD = 4,
	G_FOURTH = 5,
	G_FIFTH = 6,
	G_SIXTH = 7,
	G_SEVENTH = 8,
	G_EIGHTH = 9,
	G_MAX = 10,
};

enum ShiftStatus {
	SHIFT_STATUS_NONE = 0,
	SHIFT_STATUS_NORMAL = 1,
	SHIFT_STATUS_GOOD = 2,
	SHIFT_STATUS_PERFECT = 3,
	SHIFT_STATUS_MISSED = 4,
};

enum ShiftPotential {
	SHIFT_POTENTIAL_NONE = 0,
	SHIFT_POTENTIAL_DOWN = 1,
	SHIFT_POTENTIAL_UP = 2,
	SHIFT_POTENTIAL_GOOD = 3,
	SHIFT_POTENTIAL_PERFECT = 4,
	SHIFT_POTENTIAL_MISS = 5,
};

class ITransmission : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x404010;

	virtual GearID GetGear() = 0;
	virtual GearID GetTopGear() = 0;
	virtual void Shift(GearID gear) = 0;
	virtual bool IsGearChanging() = 0;
	virtual bool IsReversing() = 0;
	virtual float GetSpeedometer() = 0;
	virtual float GetMaxSpeedometer() = 0;
	virtual float GetDriveTorque() = 0;
	virtual float GetShiftPoint(GearID from_gear, GearID to_gear) = 0;
	virtual ShiftStatus GetShiftStatus(void) = 0;
	virtual ShiftPotential GetShiftPotential(void) = 0;
};