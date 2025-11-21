class RacePreparationInfo;

class IRacer : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x403850;

	virtual void PrepareForRace(const RacePreparationInfo*) = 0;
	virtual void StartRace(DriverStyle) = 0;
	virtual void QuitRace() = 0;
};