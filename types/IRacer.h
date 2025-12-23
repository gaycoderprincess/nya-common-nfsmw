class RacePreparationInfo {
public:
	UMath::Vector3 Position;
	float Speed;
	UMath::Vector3 Direction;
	float HeatLevel;
	uint32_t Flags;
};
static_assert(sizeof(RacePreparationInfo) == 0x24);

class IRacer : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x403850;

	virtual void PrepareForRace(const RacePreparationInfo* rpi) = 0;
	virtual void StartRace(DriverStyle style) = 0;
	virtual void QuitRace() = 0;
};